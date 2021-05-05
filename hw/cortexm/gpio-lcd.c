/*
 * GPIO connected LCD device emulation.
 *
 * Copyright (c) 2015 Liviu Ionescu.
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

#include <hw/cortexm/gpio-lcd.h>
#include <hw/cortexm/helper.h>

#if defined(CONFIG_VERBOSE)
#include "verbosity.h"
#endif

/*
 * This class implements a LCD connected to a GPIO device.
 */

// ----- Public ---------------------------------------------------------------
// Create a number of LCDs, using details from an array of Info structures.
//Object **
void gpio_lcd_create_from_info(Object *parent, GPIOLCDInfo *info_array,
                               BoardGraphicContext *graphic_context)
{
    GPIOLCDInfo *info;

    for (info = info_array; info->name; info++)
    {
        // Create the board LCD
        Object *lcd = cm_object_new(parent, info->name, TYPE_GPIO_LCD);

        cm_object_property_set_bool(lcd, info->active_low, "active-low");

#if defined(CONFIG_SDL)

        if (info->w && info->h)
        {
            // Compute corner coordinate from centre coordinate.
            cm_object_property_set_int(lcd, info->x - (info->w / 2), "x");
            cm_object_property_set_int(lcd, info->y - (info->h / 2), "y");
            cm_object_property_set_int(lcd, info->w, "w");
            cm_object_property_set_int(lcd, info->h, "h");
        }

        // Remember the graphic context in each LCD
        // Remember the board graphic context in each LCD.
        GPIO_LCD_STATE(lcd)->board_graphic_context = graphic_context;

#endif /* defined(CONFIG_SDL) */

        cm_object_realize(lcd);

        if (info->gpio_path)
        {
            // Connect the outgoing interrupt of the GPIO bit to the (only)
            // incoming interrupt of this LCD.
            cm_irq_connect(cm_device_by_name(info->gpio_path), info->irq_name, //noteworthy?
                           info->gpio_bit, DEVICE(lcd), IRQ_GPIO_LCD_IN, 0);
        }

#if defined(CONFIG_VERBOSE)
        if (verbosity_level >= VERBOSITY_DETAILED)
        {
            printf("'%s'", object_get_canonical_path(lcd));
            if (info->w && info->h)
            {
                printf(" %d*%d @(%d,%d)", info->w, info->h, info->x, info->y);
            }
            printf(" active %s", info->active_low ? "low" : "high");
            if (info->gpio_path)
            {
                printf(" '%s',%d", info->gpio_path, info->gpio_bit);
            }
            printf("\n");
        }
#endif /* defined(CONFIG_VERBOSE) */
    }
}

// ----- Private --------------------------------------------------------------

// Callback used to notify the LCD status change.
static void gpio_lcd_irq_handler(void *opaque, int n, int level)
{
    GPIOLCDState *state = GPIO_LCD_STATE(opaque);

    // There should be only one IRQ for the LCD
    assert(n == 0);

    // No further implementation needed at the moment
    // Compare with gpio-led or button-gpio
}

static void gpio_lcd_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    GPIOLCDState *state = GPIO_LCD_STATE(obj);

    cm_object_property_add_bool(obj, "active-low", &state->active_low);

#if defined(CONFIG_SDL)

    // Set properties of rectangle field of GPIOLCDState
    cm_object_property_add_int16(obj, "x",
                                 (const int16_t *)&state->lcd_graphic_context.rectangle.x);
    cm_object_property_add_int16(obj, "y",
                                 (const int16_t *)&state->lcd_graphic_context.rectangle.y);
    cm_object_property_add_uint16(obj, "w",
                                  (const uint16_t *)&state->lcd_graphic_context.rectangle.w);
    cm_object_property_add_uint16(obj, "h",
                                  (const uint16_t *)&state->lcd_graphic_context.rectangle.h);

#endif /* defined(CONFIG_SDL) */

    // Create a single incoming irq.
    cm_irq_init_in(DEVICE(obj), gpio_lcd_irq_handler, IRQ_GPIO_LCD_IN, 1);

    // The connection will be done by the machine.
    // A helper class is gpio_lcd_connect().

    // Explicitly start with the graphic context cleared.
    //cortexm_graphic_lcd_clear_graphic_context(&(state->lcd_graphic_context));
}

static void gpio_lcd_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_GPIO_LCD))
    {
        return;
    }
}

// Queues an draw rectangle event with specified color
void draw_lcd_rec_callback(int x, int y, int x2, int y2, uint16_t color)
{

    qemu_log_function_name();

    // x and y parameters specify the area and position of the rectangle
    // 16 bit per coordinate, shifted into 32 bit as x-y-pair
    int xSize = x2 - x;
    int ySize = y2 - y;
    uint32_t size = xSize << 16;
    size = size ^ ySize;
    uint32_t coordinates = x << 16;
    coordinates = coordinates ^ y;

#if defined(CONFIG_SDL)

    // Set text color
    cortexm_graphic_enqueue_event(GRAPHIC_EVENT_SET_LCD_TEXT_COLOR, color, NULL);

    // Draw rectangle
    cortexm_graphic_enqueue_event(GRAPHIC_EVENT_DRAW_REC, (void *)coordinates, (void *)size);

#endif /* defined(CONFIG_SDL) */
}

// Queues an draw pixel event with specified color and position
void draw_lcd_callback(int x, int y, uint16_t color)
{

    qemu_log_function_name();

#if defined(CONFIG_SDL)

    // Set text color
    cortexm_graphic_enqueue_event(GRAPHIC_EVENT_SET_LCD_TEXT_COLOR, color, NULL);

    // Draw pixel
    cortexm_graphic_enqueue_event(GRAPHIC_EVENT_DRAW_PIXEL, (void *)x, (void *)y);

#endif /* defined(CONFIG_SDL) */
}

static void gpio_lcd_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->realize = gpio_lcd_realize_callback;
}

static const TypeInfo gpio_lcd_type_info = {
    .name = TYPE_GPIO_LCD,
    .parent = TYPE_GPIO_LCD_PARENT,
    .instance_size = sizeof(GPIOLCDState),
    .instance_init = gpio_lcd_instance_init_callback,
    .class_init = gpio_lcd_class_init_callback,
    .class_size = sizeof(GPIOLCDClass)
    /**/
};

static void gpio_lcd_type_init(void)
{
    type_register_static(&gpio_lcd_type_info);
}

type_init(gpio_lcd_type_init);

// ----------------------------------------------------------------------------
