/*
 * Cortex-M Graphic support.
 *
 * Copyright (c) 2016 Liviu Ionescu.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#include <hw/cortexm/graphic.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/board.h>

#include <hw/cortexm/gpio-led.h>
#include <hw/cortexm/gpio-lcd.h>
#include <hw/cortexm/button.h>
//#include <hw/cortexm/fm4/adc0.h>
#include "qemu/timer.h"
#include "qemu/error-report.h"

#if defined(CONFIG_VERBOSE)
#include "verbosity.h"
#endif

// ----------------------------------------------------------------------------

static void cortexm_graphic_board_init_graphic_context(
    BoardGraphicContext *board_graphic_context);

static void cortexm_graphic_led_init_graphic_context(
    BoardGraphicContext *board_graphic_context,
    LEDGraphicContext *led_graphic_context, uint8_t red, uint8_t green,
    uint8_t blue);

static void cortexm_graphic_lcd_init_graphic_context(
    BoardGraphicContext *board_graphic_context,
    LCDGraphicContext *lcd_graphic_context);

static void cortexm_graphic_led_turn(BoardGraphicContext *board_graphic_context,
                                     LEDGraphicContext *led_graphic_context, bool is_on);

// Methods for s6e2cc simulation

static void cortexm_graphic_peripherals_init_graphic_context(
    BoardGraphicContext *board_graphic_context);

static void cortexm_lcd_draw_pixel(
    BoardGraphicContext *board_graphic_context,
    int xCoordinate, int yCoordinate);

static void cortexm_lcd_draw_rec(BoardGraphicContext *board_graphic_context,
                                 uint32_t coordinates, uint32_t width);

static void cortexm_lcd_text_color(BoardGraphicContext *board_graphic_context, uint16_t rgb555color);

static void cortexm_graphic_process_mouse_motion(void);

static void cortexm_graphic_process_mouse_button_down(void);

static void cortexm_graphic_process_mouse_button_up(void);

static void cortexm_process_lcd_mouse_motion(int x, int y);

static void cortexm_process_joystick_left_mouse_motion(int x, int y);

static void cortexm_process_joystick_right_mouse_motion(int x, int y);

// ----------------------------------------------------------------------------

static bool is_not_nographic = false;
static bool is_terminated = false;
static SDL_Cursor *saved_cursor = NULL;
static SDL_Cursor *button_cursor = NULL;
static ButtonState *current_button = NULL;
static ButtonState *pushed_button = NULL;

// ----------------------------------------------------------------------------

typedef struct
{
    int x;
    int y;
} MousePosition;

static BoardGraphicContext *board_graphic_context;

static void cortexm_graphic_process_event(SDL_Event *event)
{
    GPIOLEDState *state;
    GPIOLCDState *lcdstate;
    LCDPixelContext *pixelInfo;
    bool is_on;
    int exit_code;

    switch (event->type)
    {

#if defined(CONFIG_SDLABI_2_0)

    case SDL_FIRSTEVENT:
        break;

    case SDL_WINDOWEVENT:
        // Window state change
        break;
#elif defined(CONFIG_SDLABI_1_2)

#endif

    case SDL_KEYDOWN:
    case SDL_KEYUP:
        // Nothing for now
        break;

    case SDL_MOUSEMOTION:
        if (board_graphic_context != NULL)
        {
            cortexm_graphic_process_mouse_motion();
        }
        break;

    case SDL_MOUSEBUTTONDOWN:
        if (board_graphic_context != NULL)
        {
            cortexm_graphic_process_mouse_button_down();
        }
        break;

    case SDL_MOUSEBUTTONUP:
        if (board_graphic_context != NULL)
        {
            cortexm_graphic_process_mouse_button_up();
        }
        break;

    case SDL_FINGERDOWN:
    case SDL_FINGERUP:
    case SDL_FINGERMOTION:
        // case SDL_DOLLARGESTURE:
        // case SDL_DOLLARRECORD:
        // case SDL_MULTIGESTURE:
        // Nothing for now
        break;

    case SDL_QUIT:
        // Quit the program
#if defined(CONFIG_VERBOSE)
        if (verbosity_level >= VERBOSITY_COMMON)
        {
            printf("Graphic window closed. Quit.\n");
        }
#endif /* defined(CONFIG_VERBOSE) */
        cortexm_graphic_quit();
        exit(1);

    case SDL_USEREVENT:

        // User events, enqueued with SDL_PushEvent().
        switch (event->user.code)
        {

        case GRAPHIC_EVENT_BOARD_INIT:
            board_graphic_context = (BoardGraphicContext *)event->user.data1;

            if (!cortexm_graphic_board_is_graphic_context_initialised(
                    board_graphic_context))
            {
                cortexm_graphic_board_init_graphic_context(
                    board_graphic_context);
            }
            break;

        case GRAPHIC_EVENT_LED_INIT:
            state = (GPIOLEDState *)event->user.data1;

            if (!cortexm_graphic_led_is_graphic_context_initialised(
                    &(state->led_graphic_context)))
            {
                cortexm_graphic_led_init_graphic_context(
                    state->board_graphic_context,
                    &(state->led_graphic_context), state->colour.red,
                    state->colour.green, state->colour.blue);
            }
            break;

        case GRAPHIC_EVENT_LED_TURN:
            state = (GPIOLEDState *)event->user.data1;
            is_on = (bool)event->user.data2;
            cortexm_graphic_led_turn(state->board_graphic_context,
                                     &(state->led_graphic_context), is_on);
            break;

        case GRAPHIC_EVENT_QUIT:
            cortexm_graphic_quit();
            break;

        case GRAPHIC_EVENT_EXIT:
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpointer-to-int-cast"
            exit_code = (int)event->user.data1;
#pragma GCC diagnostic pop
            cortexm_graphic_quit();
            exit(exit_code);

        case GRAPHIC_EVENT_PERIPHERALS:
            board_graphic_context = (BoardGraphicContext *)event->user.data1;
            cortexm_graphic_peripherals_init_graphic_context(board_graphic_context);
            break;

        case GRAPHIC_EVENT_DRAW_PIXEL:

            cortexm_lcd_draw_pixel(board_graphic_context, (int)event->user.data1, (int)event->user.data2);

            break;

        case GRAPHIC_EVENT_DRAW_REC:

            cortexm_lcd_draw_rec(board_graphic_context, (uint32_t)event->user.data1, (uint32_t)event->user.data2);

            break;

        case GRAPHIC_EVENT_SET_LCD_TEXT_COLOR:

            cortexm_lcd_text_color(board_graphic_context, (uint16_t)event->user.data1);

            break;

        default:
            qemu_log_mask(LOG_UNIMP, "Unimplemented user event %d\n",
                          event->user.code);
        }
        break;

    default:
        qemu_log_mask(LOG_UNIMP, "Other event 0x%X\n", event->type);
        break;
    }
}

#if defined(USE_GRAPHIC_POLL_EVENT)
static QEMUTimer *event_loop_timer;
#endif /* defined(USE_GRAPHIC_POLL_EVENT) */

#if defined(USE_GRAPHIC_POLL_EVENT)
void cortexm_graphic_init_timer(void)
{
    if (is_not_nographic)
    {
        return;
    }

    // The event loop will be processed from time to time.
    event_loop_timer = timer_new_ms(QEMU_CLOCK_REALTIME,
                                    (void (*)(void *))cortexm_graphic_event_loop, &event_loop_timer);
    timer_mod(event_loop_timer, qemu_clock_get_ms(QEMU_CLOCK_REALTIME));
}
#endif /* defined(USE_GRAPHIC_POLL_EVENT) */

void cortexm_graphic_event_loop(void)
{
#if !defined(USE_GRAPHIC_POLL_EVENT)
    qemu_log_function_name();
#endif

#if defined(CONFIG_SDL)

    SDL_Event event;

#if !defined(USE_GRAPHIC_POLL_EVENT)

#if defined(CONFIG_SDLABI_2_0)
    // Raise graphic responsiveness.
    SDL_SetThreadPriority(SDL_THREAD_PRIORITY_HIGH);
#endif

    while (SDL_WaitEvent(&event))
    {
        cortexm_graphic_process_event(&event);
    }

#else

    while (SDL_PollEvent(&event))
    {
        cortexm_graphic_process_event(&event);
    }

    timer_mod(event_loop_timer, qemu_clock_get_ms(QEMU_CLOCK_REALTIME) + 10);

#endif /* !defined(defined(USE_GRAPHIC_POLL_EVENT)) */

#endif /* defined(CONFIG_SDL) */
}

// Called from different threads to enqueue jobs via the event loop.
// This ensures all graphic primitives are executed on the allowed thread.
int cortexm_graphic_enqueue_event(int code, void *data1, void *data2)
{
    qemu_log_mask(LOG_FUNC, "%s(%d)\n", __FUNCTION__, code);

#if defined(CONFIG_SDL)

    SDL_Event event;

    event.type = SDL_USEREVENT;
    event.user.code = code;
    event.user.data1 = data1;
    event.user.data2 = data2;

    // TODO: if multi-thread access is needed, add a mutex.
    int ret = SDL_PushEvent(&event);

#if defined(CONFIG_SDLABI_2_0)
    // Used to give the scheduler a chance to yield.
    SDL_Delay(1);
#endif

    return ret;

#else

    return 0;

#endif /* defined(CONFIG_SDL) */
}

// ----------------------------------------------------------------------------

static inline bool cortexm_graphic_mouse_is_in_button(MousePosition *mp,
                                                      ButtonState *button_state)
{
    if ((mp->x >= button_state->position.x_left) && (mp->x <= button_state->position.x_right) && (mp->y >= button_state->position.y_top) && (mp->y <= button_state->position.y_bottom))
    {
        return true;
    }
    else
    {
        return false;
    }
}

static void cortexm_graphic_process_mouse_motion(void)
{
    MousePosition mp;
    int i;

    SDL_GetMouseState(&mp.x, &mp.y);
    if (current_button == NULL)
    {
        // Previously not in a button, enumerate all, maybe one matches.
        for (i = 0; i < board_graphic_context->buttons_array_length; ++i)
        {
            if (cortexm_graphic_mouse_is_in_button(&mp,
                                                   board_graphic_context->buttons[i]))
            {
                // Mouse entered the button.
                current_button = board_graphic_context->buttons[i];

                saved_cursor = SDL_GetCursor();
                SDL_SetCursor(button_cursor);

                break;
            }
        }
    }
    else
    {
        // Previously in a button, check if still in.
        if (!cortexm_graphic_mouse_is_in_button(&mp, current_button))
        {
            // Mouse exited the button.
            current_button = NULL;
            SDL_SetCursor(saved_cursor);
            saved_cursor = NULL;
        }
        // Check if button is in left joystick "button"
        else if (pushed_button != NULL && current_button->position.x_left == 114)
        {
            cortexm_process_lcd_mouse_motion(mp.x, mp.y);
        }
        // Check if button is in lcd "button"
        else if (pushed_button != NULL && current_button->position.x_left == 14)
        {
            cortexm_process_joystick_left_mouse_motion(mp.x, mp.y);
        }
        // Check if button is in right joystick "button"
        else if (pushed_button != NULL && current_button->position.x_left == 640)
        {
            cortexm_process_joystick_right_mouse_motion(mp.x, mp.y);
        }
    }
}

// Method stores mouse position as lcd coordinates in class variables
static void cortexm_process_lcd_mouse_motion(int x, int y)
{
    // coordinates get adjusted by offset to start at (0,0) of lcd
    x_ = x - 114;
    y_ = -y - 1 + 320 + 346;
}

// Method stores mouse position as coordinates of left joystick in class variables
static void cortexm_process_joystick_left_mouse_motion(int x, int y)
{
    // x = 190 - (x - 52);
    // y = 190 + y - 506;
    // => Center position (190,190);

    // Multiplication to scale to 0,255
    // Case differetiation because 255-190 != 190-0 (distance to the right maximum is not equal to distance to left minimum)
    left_joystick_used = true;
    if (x - 52 > 0)
        x_joystick_left = 190 - (int)(4.94 * (x - 52));
    else
        x_joystick_left = 190 - (int)(1.69 * (x - 52));

    if (y - 506 > 0)
        y_joystick_left = 190 + (int)(1.51 * (y - 506));
    else
        y_joystick_left = 190 + (int)(4.42 * (y - 506));
}
// Method stores mouse position as coordinates of right joystick in class variables
static void cortexm_process_joystick_right_mouse_motion(int x, int y)
{
    // x = 190 + x - 678
    // y = 190 + y - 506
    // => Center position (190,190);

    // Multiplication to scale to 0,255
    // Case differetiation because 255-190 != 190-0 (distance to the right maximum is not equal to distance to left minimum)
    right_joystick_used = true;
    if (x - 678 > 0)
        x_joystick_right = 190 - (int)(4.94 * (x - 678));
    else
        x_joystick_right = 190 - (int)(1.69 * (x - 678));

    if (y - 506 > 0)
        y_joystick_right = 190 + (int)(1.51 * (y - 506));
    else
        y_joystick_right = 190 + (int)(4.42 * (y - 506));
}

// Returns x coordinate of lcd
int get_x_()
{
    return x_;
}

// Returns y coordinate of lcd
int get_y_()
{
    return y_;
}

// Returns x coordinate of left joystick
int get_x_joystick_left()
{
    return x_joystick_left;
}

// Returns y coordinate of left joystick
int get_y_joystick_left()
{
    return y_joystick_left;
}

// Returns x coordinate of right joystick
int get_x_joystick_right()
{
    return x_joystick_right;
}

// Returns y coordinate of right joystick
int get_y_joystick_right()
{
    return y_joystick_right;
}

/**
 * Just one joystick can be used at the same time but check for both booleans is more flexible in joystick usage handling
 * Can not be calculated out of coordinates because both left and right coordinates are adjusted to be in range from 0 to 255
 * (Independent of joystick position after adjustment)
 */

// Returns true if left joystick is used
bool get_left_joystick_used()
{
    return left_joystick_used;
}

// Returns true if right joystick is used
bool get_right_joystick_used()
{
    return right_joystick_used;
}

static void cortexm_graphic_process_mouse_button_down(void)
{
#if 1
    MousePosition mp;
    SDL_GetMouseState(&mp.x, &mp.y);
    qemu_log_mask(LOG_FUNC, "%s() %d,%d\n", __FUNCTION__, mp.x, mp.y);
#endif

    if (current_button != NULL)
    {

        ButtonClass *klass = BUTTON_GET_CLASS(current_button);
        // Perform the down() action associated with the current button.
        if (current_button != NULL && current_button->position.x_left == 114)
        {
            // Check if lcd "button" is being pushed
            cortexm_process_lcd_mouse_motion(mp.x, mp.y);
        }
        else if (current_button != NULL && current_button->position.x_left == 14)
        {
            // Check if left joystick is being pushed (used)
            left_joystick_used = true;
            cortexm_process_joystick_left_mouse_motion(mp.x, mp.y);
        }
        else if (current_button != NULL && current_button->position.x_left == 640)
        {
            // Check if right jostick is being pushed (used)
            right_joystick_used = true;
            cortexm_process_joystick_right_mouse_motion(mp.x, mp.y);
        }
        klass->down(current_button);
        pushed_button = current_button;
    }
}

static void cortexm_graphic_process_mouse_button_up(void)
{
    if (pushed_button != NULL)
    {

        ButtonClass *klass = BUTTON_GET_CLASS(pushed_button);

        // No joystick used
        left_joystick_used = false;
        right_joystick_used = false;

        // Joystick idle position
        x_joystick_left = 190;
        y_joystick_left = 190;

        x_joystick_right = 190;
        y_joystick_right = 190;

        // Perform the up() action associated with the previously pushed button.
        // None in case of joystick and lcd
        klass->up(pushed_button);
        pushed_button = NULL;
    }
}

// ----------------------------------------------------------------------------

// Called indirectly via the event loop, to clean the board graphic context.
void cortexm_graphic_quit(void)
{
    qemu_log_function_name();

    if (is_not_nographic || is_terminated)
    {
        return;
    }

#if defined(CONFIG_SDL)

    if (cortexm_board_is_initialized())
    {
        CortexMBoardState *board = cortexm_board_get();
        if (board != NULL)
        {
            BoardGraphicContext *board_graphic_context =
                &(board->graphic_context);

            if (cortexm_graphic_board_is_graphic_context_initialised(
                    board_graphic_context))
            {

#if defined(CONFIG_SDLABI_2_0)

                if (board_graphic_context->renderer != NULL)
                {
                    qemu_log_mask(LOG_FUNC, "%s() SDL_DestroyRenderer()\n",
                                  __FUNCTION__);
                    SDL_DestroyRenderer(board_graphic_context->renderer);
                }

                if (board_graphic_context->window != NULL)
                {
                    qemu_log_mask(LOG_FUNC, "%s() SDL_DestroyWindow()\n",
                                  __FUNCTION__);
                    SDL_DestroyWindow(board_graphic_context->window);
                }

#elif defined(CONFIG_SDLABI_1_2)

#endif /* defined(CONFIG_SDLABI_) */
            }
        }
        // Prevent subsequent destroys.
        cortexm_board_clear();
    }

    qemu_log_mask(LOG_FUNC, "%s() SDL_Quit()\n", __FUNCTION__);
    SDL_Quit();

    is_terminated = true;

#endif /* defined(CONFIG_SDL) */
}

// ----------------------------------------------------------------------------

static QemuThread start_thread;

// Called via the atexit() mechanism, to clean the board graphic context.
static void cortexm_graphic_atexit(void)
{
    if (qemu_thread_is_self(&start_thread))
    {
        // If running on the main thread, directly quit.
        cortexm_graphic_quit();
    }
    else
    {
        // If on another thread, defer to main thread and wait.
        cortexm_graphic_enqueue_event(GRAPHIC_EVENT_QUIT, NULL, NULL);

        while (!is_terminated)
        {
            qemu_log_mask(LOG_FUNC, "%s() wait\n", __FUNCTION__);
            SDL_Delay(100);
        }
    }
}

// Start the graphic subsystem. From this moment on, the event queue
// must be available to enqueue requests, even if the requests will
// be processed when the event loop is entered (at the end of main()).
void cortexm_graphic_start(bool nographic)
{
    qemu_log_function_name();

    is_not_nographic = nographic;

    if (is_not_nographic)
    {
        return;
    }

#if defined(CONFIG_SDL)

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        error_printf("Unable to initialize SDL:  %s\n", SDL_GetError());
        exit(1);
    }

    atexit(cortexm_graphic_atexit);

#endif /* defined(CONFIG_SDL) */

    qemu_thread_get_self(&start_thread);
}

// ----------------------------------------------------------------------------

void cortexm_graphic_board_clear_graphic_context(
    BoardGraphicContext *board_graphic_context)
{
    qemu_log_function_name();

    board_graphic_context->picture_file_name = NULL;
    board_graphic_context->picture_file_absolute_path = NULL;
    board_graphic_context->window_caption = NULL;

    board_graphic_context->buttons = NULL;
    board_graphic_context->buttons_array_capacity = 0;
    board_graphic_context->buttons_array_length = 0;

#if defined(CONFIG_SDL)

#if defined(CONFIG_SDLABI_2_0)
    board_graphic_context->window = NULL;
    board_graphic_context->renderer = NULL;
    board_graphic_context->texture = NULL;
    board_graphic_context->surface = NULL;
#elif defined(CONFIG_SDLABI_1_2)
    board_graphic_context->surface = NULL;
#endif

#endif /* defined(CONFIG_SDL) */
}

bool cortexm_graphic_board_is_graphic_context_initialised(
    BoardGraphicContext *board_graphic_context)
{
    return (board_graphic_context->surface != NULL);
}

/**
 * Methods calculateds rgb888 color of rgb555 color and saves it to board graphic context
 */
static void cortexm_lcd_text_color(BoardGraphicContext *board_graphic_context, uint16_t rgb555color)
{

    uint8_t r = ((((rgb555color >> 11) & 0x1F) * 527) + 23) >> 6;
    uint8_t g = ((((rgb555color >> 5) & 0x3F) * 259) + 33) >> 6;
    uint8_t b = (((rgb555color & 0x1F) * 527) + 23) >> 6;

    uint32_t RGB888 = r << 16 | g << 8 | b;

    board_graphic_context->lcd_text_color = RGB888;
}

// Method to draw a rectangle on lcd
cortexm_lcd_draw_rec(BoardGraphicContext *board_graphic_context, uint32_t coordinates, uint32_t width)
{
#if defined(CONFIG_SDL)
#if defined(CONFIG_SDLABI_2_0)

    // 32 bit coordinates persists of 16 bit x coordinate and 16 bit y coordinate
    uint16_t xCoordinate = coordinates >> 16;
    uint16_t yCoordinate = (coordinates << 16) >> 16;

    // 32 bit width persists of 16 bit xWidht (widht) and 16 bit yWidht (height)
    uint16_t xWidth = width >> 16;
    uint16_t yWidth = (width << 16) >> 16;

    // Rectangle of display background
    SDL_Rect rect_display_background;
    rect_display_background.x = 114;
    rect_display_background.y = 346;
    rect_display_background.w = 480;
    rect_display_background.h = 320;

    // Create SDL rectangle which should be painted
    SDL_Rect pixel_rect;
    pixel_rect.x = rect_display_background.x + xCoordinate;
    pixel_rect.y = rect_display_background.y + rect_display_background.h - 1 - yWidth - yCoordinate;
    pixel_rect.w = xWidth + 1;
    pixel_rect.h = yWidth + 1;

    // Get renderer and window of board graphic context
    SDL_Renderer *renderer = board_graphic_context->renderer;
    SDL_Window *win = board_graphic_context->window;

    // Function to test background position
    // SDL_FillRect(SDL_GetWindowSurface(win), &rect_display_background, 0xFFF1FFFF);

    // SDL fucntion to draw rectangle on window surface in lcd text color
    SDL_FillRect(SDL_GetWindowSurface(win), &pixel_rect, board_graphic_context->lcd_text_color);

    // Safe the new surface in board graphic context
    board_graphic_context->surface = SDL_GetWindowSurface(win);

    SDL_Texture *end_texture = SDL_CreateTextureFromSurface(renderer, SDL_GetWindowSurface(win));
    if (end_texture == NULL)
    {
        error_printf("Could not create texture: %s\n", SDL_GetError());
        exit(1);
    }

    // Safe new texture in board graphic context
    board_graphic_context->texture = end_texture;

    // Update screen
    SDL_RenderCopy(renderer, end_texture, NULL, NULL);
    SDL_RenderPresent(renderer);

#elif defined(CONFIG_SDLABI_1_2)
    SDL_Flip(board_graphic_context->surface);
#endif
    SDL_DestroyTexture(end_texture);
#endif /* defined(CONFIG_SDL) */
}

// Method to draw a pixel on lcd
static void cortexm_lcd_draw_pixel(BoardGraphicContext *board_graphic_context,
                                   int xCoordinate, int yCoordinate)
{

#if defined(CONFIG_SDL)
#if defined(CONFIG_SDLABI_2_0)

    // Rectangle of display background
    SDL_Rect rect_display_background;
    rect_display_background.x = 114;
    rect_display_background.y = 346;
    rect_display_background.w = 480;
    rect_display_background.h = 320;

    // SDL rectangle representing a pixel
    SDL_Rect pixel_rect;
    pixel_rect.x = rect_display_background.x + xCoordinate;
    pixel_rect.y = rect_display_background.y + rect_display_background.h - 1 - (yCoordinate); //-319);
    pixel_rect.w = 1;
    pixel_rect.h = 1;

    // Get renderer, window and surface of board graphic context
    SDL_Renderer *renderer = board_graphic_context->renderer;
    SDL_Window *win = board_graphic_context->window;
    board_graphic_context->surface = SDL_GetWindowSurface(win);

    // Function to test background position
    // SDL_FillRect(SDL_GetWindowSurface(win), &rect_display_background, 0xFFF1FFFF);

    // SDl fucntion to draw a pixel in text color
    SDL_FillRect(SDL_GetWindowSurface(win), &pixel_rect, board_graphic_context->lcd_text_color);

    // Save new surface
    board_graphic_context->surface = SDL_GetWindowSurface(win);

    SDL_Texture *end_texture = SDL_CreateTextureFromSurface(renderer, SDL_GetWindowSurface(win));
    if (end_texture == NULL)
    {
        error_printf("Could not create texture: %s\n", SDL_GetError());
        exit(1);
    }

    // Save new texture
    board_graphic_context->texture = end_texture;

    // Update screen
    SDL_RenderCopy(renderer, end_texture, NULL, NULL);
    SDL_RenderPresent(renderer);

#elif defined(CONFIG_SDLABI_1_2)
    SDL_Flip(board_graphic_context->surface);
#endif
    SDL_DestroyTexture(end_texture);
#endif /* defined(CONFIG_SDL) */
}

// Method to initialise extrea peripherals like lcd or joysticks
static void cortexm_graphic_peripherals_init_graphic_context(
    BoardGraphicContext *board_graphic_context)
{
    qemu_log_function_name();

#if defined(CONFIG_SDL)

#if 0
    const char *fullname = qemu_find_file(QEMU_FILE_TYPE_GRAPHICS,
            board_graphic_context->picture_file_name);
    if (fullname == NULL) {
        error_printf("Image file '%s' not found.\n",
                board_graphic_context->picture_file_name);
        exit(1);
    }
#endif

    // Set datatype of images
    int res = IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
    if ((res & (IMG_INIT_JPG | IMG_INIT_PNG)) != (IMG_INIT_JPG | IMG_INIT_PNG))
    {
        error_printf("IMG_init failed (%s).\n", IMG_GetError());
        exit(1);
    }

    // A better SDL_LoadBMP().
    SDL_Surface *board_bitmap = IMG_Load(
        board_graphic_context->picture_file_absolute_path);
    if (board_bitmap == NULL)
    {
        error_printf("Cannot load image file '%s' (%s).\n",
                     board_graphic_context->picture_file_absolute_path,
                     IMG_GetError());
        exit(1);
    }

    // Get full datapath of display (lcd) image and calculate bitmap
    const char *displayFullPath = qemu_find_file(QEMU_FILE_TYPE_GRAPHICS, "fm4Display.png");
    if (displayFullPath == NULL)
    {
        error_printf("Picture file '%s' not found.\n", "fm4Display.png");
        exit(1);
    }
    SDL_Surface *display_bitmap = IMG_Load(
        displayFullPath);
    if (display_bitmap == NULL)
    {
        error_printf("Cannot load image file '%s' (%s).\n",
                     displayFullPath,
                     IMG_GetError());
        exit(1);
    }
    // Get full datapath of joystick image and calculate bitmap
    const char *joystickFullPath = qemu_find_file(QEMU_FILE_TYPE_GRAPHICS, "Joystick.png");
    if (joystickFullPath == NULL)
    {
        error_printf("Picture file '%s' not found.\n", "fm4Display.png");
        exit(1);
    }
    SDL_Surface *joystick_bitmap = IMG_Load(
        joystickFullPath);
    if (joystick_bitmap == NULL)
    {
        error_printf("Cannot load image file '%s' (%s).\n",
                     joystickFullPath,
                     IMG_GetError());
        exit(1);
    }
#if defined(CONFIG_SDLABI_2_0)
    //Resize window for new peripherals
    SDL_Window *win = board_graphic_context->window;
    SDL_SetWindowSize(win, board_bitmap->w, (board_bitmap->h) + (display_bitmap->h));
    board_graphic_context->window = win;

    // Get renderer
    SDL_Renderer *renderer = board_graphic_context->renderer;

    // Convert bitmap to SDL surface in correct format (RGB888)
    SDL_Surface *board_bitmap_rgb = SDL_ConvertSurfaceFormat(board_bitmap,
                                                             SDL_PIXELFORMAT_RGB888, 0);
    if (board_bitmap_rgb == 0)
    {
        error_printf("Could not create surface: %s\n", SDL_GetError());
        exit(1);
    }

    SDL_Surface *display_bitmap_rgb = SDL_ConvertSurfaceFormat(display_bitmap,
                                                               SDL_PIXELFORMAT_RGB888, 0);
    if (display_bitmap_rgb == 0)
    {
        error_printf("Could not create surface: %s\n", SDL_GetError());
        exit(1);
    }

    SDL_Surface *joystick_bitmap_rgb = SDL_ConvertSurfaceFormat(joystick_bitmap,
                                                                SDL_PIXELFORMAT_RGB888, 0);
    if (joystick_bitmap == 0)
    {
        error_printf("Could not create surface: %s\n", SDL_GetError());
        exit(1);
    }

    // SDL rectangle representing position of the simulated board
    SDL_Rect board_rect;
    board_rect.x = 0;
    board_rect.y = 0;
    board_rect.w = board_bitmap->w;
    board_rect.h = board_bitmap->h;

    // SDL rectangle representing position of the lcd display
    SDL_Rect display_rect;
    display_rect.x = ((board_bitmap->w) / 2) - ((display_bitmap->w) / 2);
    display_rect.y = board_bitmap->h;
    display_rect.w = display_bitmap->w;
    display_rect.h = display_bitmap->h;

    // SDL rectangle representing position of the left joystick
    SDL_Rect joystick_rect_one;
    joystick_rect_one.x = ((((board_bitmap->w) / 2) - ((display_bitmap->w) / 2)) / 2) - ((joystick_bitmap->w) / 2);
    joystick_rect_one.y = board_bitmap->h + ((display_bitmap->h) / 2) - ((joystick_bitmap->h) / 2);
    joystick_rect_one.w = joystick_bitmap->w;
    joystick_rect_one.h = joystick_bitmap->h;

    // SDL rectangle representing position of the right joystick
    SDL_Rect joystick_rect_two;
    joystick_rect_two.x = ((board_bitmap->w) / 2) - ((display_bitmap->w) / 2) + (display_bitmap->w) + ((((board_bitmap->w) / 2) - ((display_bitmap->w) / 2)) / 2) - ((joystick_bitmap->w) / 2);
    joystick_rect_two.y = board_bitmap->h + ((display_bitmap->h) / 2) - ((joystick_bitmap->h) / 2);
    joystick_rect_two.w = joystick_bitmap->w;
    joystick_rect_two.h = joystick_bitmap->h;

    // Save board grapic surface (Not necessary?)
    board_graphic_context->surface = SDL_GetWindowSurface(win);

    // Fill unused background with white and blit other surfaces to screen
    SDL_FillRect(SDL_GetWindowSurface(win), NULL, 0xFFFFFFFF);
    SDL_BlitSurface(board_bitmap, NULL, SDL_GetWindowSurface(win), &board_rect);
    SDL_BlitSurface(display_bitmap, NULL, SDL_GetWindowSurface(win), &display_rect);
    SDL_BlitSurface(joystick_bitmap, NULL, SDL_GetWindowSurface(win), &joystick_rect_one);
    SDL_BlitSurface(joystick_bitmap, NULL, SDL_GetWindowSurface(win), &joystick_rect_two);

    // Save new graphic surface
    board_graphic_context->surface = SDL_GetWindowSurface(win);
    SDL_Texture *end_texture = SDL_CreateTextureFromSurface(renderer, SDL_GetWindowSurface(win));
    if (end_texture == NULL)
    {
        error_printf("Could not create texture: %s\n", SDL_GetError());
        exit(1);
    }

    // Save new texture
    board_graphic_context->texture = end_texture;

    SDL_RenderCopy(renderer, end_texture, NULL, NULL);
    SDL_RenderPresent(renderer);

#elif defined(CONFIG_SDLABI_1_2)
    SDL_WM_SetCaption(board_graphic_context->window_caption, NULL);

    SDL_Surface *screen = SDL_SetVideoMode(board_bitmap->w, board_bitmap->h, 32,
                                           SDL_DOUBLEBUF);
    SDL_Surface *board_surface = SDL_DisplayFormat(board_bitmap);
    /* Apply image to screen */
    SDL_BlitSurface(board_surface, NULL, screen, NULL);
    SDL_BlitSurface(display_surface, NULL, screen, NULL);
    /* Update screen */
    SDL_Flip(screen);

    board_graphic_context->surface = screen;

#endif /* defined(CONFIG_SDLABI_*) */

    SDL_FreeSurface(board_bitmap);
    SDL_FreeSurface(display_bitmap);
    SDL_FreeSurface(joystick_bitmap);

    button_cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);
    if (button_cursor == NULL)
    {
        error_printf("Could not create cursor: %s\n", SDL_GetError());
        exit(1);
    }
#endif /* defined(CONFIG_SDL) */
}

// Same method as before without extra peripherals
// Can be used to simulate/test other/new boards without peripheral graphics
static void cortexm_graphic_board_init_graphic_context(
    BoardGraphicContext *board_graphic_context)
{
    qemu_log_function_name();

#if defined(CONFIG_SDL)

#if 0
    const char *fullname = qemu_find_file(QEMU_FILE_TYPE_GRAPHICS,
            board_graphic_context->picture_file_name);
    if (fullname == NULL) {
        error_printf("Image file '%s' not found.\n",
                board_graphic_context->picture_file_name);
        exit(1);
    }
#endif

    int res = IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
    if ((res & (IMG_INIT_JPG | IMG_INIT_PNG)) != (IMG_INIT_JPG | IMG_INIT_PNG))
    {
        error_printf("IMG_init failed (%s).\n", IMG_GetError());
        exit(1);
    }
    // A better SDL_LoadBMP().
    SDL_Surface *board_bitmap = IMG_Load(
        board_graphic_context->picture_file_absolute_path);
    if (board_bitmap == NULL)
    {
        error_printf("Cannot load image file '%s' (%s).\n",
                     board_graphic_context->picture_file_absolute_path,
                     IMG_GetError());
        exit(1);
    }

#if defined(CONFIG_SDLABI_2_0)

    SDL_Window *win = SDL_CreateWindow(board_graphic_context->window_caption,
                                       SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, board_bitmap->w,
                                       board_bitmap->h, 0);
    if (win == NULL)
    {
        error_printf("Could not create window: %s\n", SDL_GetError());
        exit(1);
    }
    board_graphic_context->window = win;

    SDL_Renderer *renderer = SDL_CreateRenderer(win, -1,
                                                SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        error_printf("Could not create renderer: %s\n", SDL_GetError());
        exit(1);
    }
    board_graphic_context->renderer = renderer;

    SDL_Surface *board_bitmap_rgb = SDL_ConvertSurfaceFormat(board_bitmap,
                                                             SDL_PIXELFORMAT_RGB888, 0);
    if (board_bitmap_rgb == 0)
    {
        error_printf("Could not create surface: %s\n", SDL_GetError());
        exit(1);
    }
    board_graphic_context->surface = board_bitmap_rgb;

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer,
                                                        board_bitmap_rgb);
    if (texture == NULL)
    {
        error_printf("Could not create texture: %s\n", SDL_GetError());
        exit(1);
    }
    board_graphic_context->texture = texture;

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);

#elif defined(CONFIG_SDLABI_1_2)

    SDL_WM_SetCaption(board_graphic_context->window_caption, NULL);
    SDL_Surface *screen = SDL_SetVideoMode(board_bitmap->w, board_bitmap->h, 32,
                                           SDL_DOUBLEBUF);
    SDL_Surface *board_surface = SDL_DisplayFormat(board_bitmap);

    /* Apply image to screen */
    SDL_BlitSurface(board_surface, NULL, screen, NULL);
    /* Update screen */
    SDL_Flip(screen);

    board_graphic_context->surface = screen;

#endif /* defined(CONFIG_SDLABI_*) */

    SDL_FreeSurface(board_bitmap);

    button_cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);
    if (button_cursor == NULL)
    {
        error_printf("Could not create cursor: %s\n", SDL_GetError());
        exit(1);
    }
#endif /* defined(CONFIG_SDL) */
}

#define DEFAULT_BUTTONS_CAPACITY (2)

void cortexm_graphic_board_add_button(
    BoardGraphicContext *board_graphic_context, ButtonState *button_state)
{
    if (board_graphic_context->buttons_array_length >= board_graphic_context->buttons_array_capacity)
    {
        if (board_graphic_context->buttons_array_capacity == 0)
        {
            // Allocate initial array of pointers to buttons.
            board_graphic_context->buttons = g_malloc0_n(
                DEFAULT_BUTTONS_CAPACITY, sizeof(Object *));
            board_graphic_context->buttons_array_capacity =
                DEFAULT_BUTTONS_CAPACITY;
        }
        else
        {
            // Double the size of the array of pointers to buttons.
            board_graphic_context->buttons = g_realloc_n(
                board_graphic_context->buttons,
                2 * board_graphic_context->buttons_array_capacity,
                sizeof(Object *));
            board_graphic_context->buttons_array_capacity *= 2;
        }
    }

    assert(
        board_graphic_context->buttons_array_length < board_graphic_context->buttons_array_capacity);

    board_graphic_context->buttons[board_graphic_context->buttons_array_length++] =
        button_state;
}

// ----------------------------------------------------------------------------

void cortexm_graphic_led_clear_graphic_context(
    LEDGraphicContext *led_graphic_context)
{
    qemu_log_function_name();

    led_graphic_context->crop_on = NULL;
    led_graphic_context->crop_off = NULL;
}

bool cortexm_graphic_led_is_graphic_context_initialised(
    LEDGraphicContext *led_graphic_context)
{
    return (led_graphic_context->crop_on != NULL);
}

static void cortexm_graphic_led_init_graphic_context(
    BoardGraphicContext *board_graphic_context,
    LEDGraphicContext *led_graphic_context, uint8_t red, uint8_t green,
    uint8_t blue)
{
    qemu_log_function_name();

#if defined(CONFIG_SDL)

    SDL_Surface *surface = board_graphic_context->surface;
    SDL_Rect *rectangle = &(led_graphic_context->rectangle);

#if defined(CONFIG_SDLABI_2_0)

    led_graphic_context->crop_off = SDL_ConvertSurfaceFormat(surface,
                                                             SDL_PIXELFORMAT_RGB888, 0);

    led_graphic_context->crop_on = SDL_ConvertSurfaceFormat(surface,
                                                            SDL_PIXELFORMAT_RGB888, 0);

#elif defined(CONFIG_SDLABI_1_2)

    led_graphic_context->crop_off = SDL_CreateRGBSurface(surface->flags,
                                                         rectangle->w, rectangle->h, surface->format->BitsPerPixel,
                                                         surface->format->Rmask, surface->format->Gmask,
                                                         surface->format->Bmask, surface->format->Amask);

    led_graphic_context->crop_on = SDL_CreateRGBSurface(surface->flags,
                                                        rectangle->w, rectangle->h, surface->format->BitsPerPixel,
                                                        surface->format->Rmask, surface->format->Gmask,
                                                        surface->format->Bmask, surface->format->Amask);

#endif

    // Copy bitmap from original picture.
    SDL_BlitSurface(board_graphic_context->surface, rectangle,
                    led_graphic_context->crop_off, 0);

    Uint32 colour = SDL_MapRGB(led_graphic_context->crop_on->format, red, green,
                               blue);

    // Fill with uniform colour.
    SDL_FillRect(led_graphic_context->crop_on, NULL, colour);

#endif /* defined(CONFIG_SDL) */
}

static void cortexm_graphic_led_turn(BoardGraphicContext *board_graphic_context,
                                     LEDGraphicContext *led_graphic_context, bool is_on)
{
    qemu_log_mask(LOG_FUNC, "%s(%s)\n", __FUNCTION__, is_on ? "on" : "off");

#if defined(CONFIG_SDL)
    SDL_Surface *crop =
        is_on ? led_graphic_context->crop_on : led_graphic_context->crop_off;

#if defined(CONFIG_SDLABI_2_0)

    board_graphic_context->surface = SDL_GetWindowSurface(board_graphic_context->window);
    SDL_Texture *end_texture = SDL_CreateTextureFromSurface(board_graphic_context->renderer, SDL_GetWindowSurface(board_graphic_context->window));
    if (end_texture == NULL)
    {
        error_printf("Could not create texture: %s\n", SDL_GetError());
        exit(1);
    }

    SDL_UpdateTexture(end_texture,
                      &(led_graphic_context->rectangle), crop->pixels, crop->pitch);

    board_graphic_context->texture = end_texture;

    SDL_RenderCopy(board_graphic_context->renderer, end_texture, NULL, NULL);
    SDL_RenderPresent(board_graphic_context->renderer);

#elif defined(CONFIG_SDLABI_1_2)
    SDL_BlitSurface(crop, NULL, board_graphic_context->surface,
                    &(led_graphic_context->rectangle));
    SDL_Flip(board_graphic_context->surface);
#endif
    SDL_DestroyTexture(end_texture);
#endif /* defined(CONFIG_SDL) */
}

// ----------------------------------------------------------------------------
