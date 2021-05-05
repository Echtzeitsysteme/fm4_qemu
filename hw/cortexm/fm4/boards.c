/*
 * Atmel SAM boards emulation.
 *
 * Copyright (c) 2014 Liviu Ionescu.
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

#include "qemu/module.h"
#include "qemu/osdep.h"

#include <hw/cortexm/board.h>
#include <hw/cortexm/fm4/mcus.h>
#include <hw/cortexm/gpio-led.h>
#include <hw/cortexm/button-gpio.h>
#include <hw/cortexm/button-reset.h>
#include <hw/cortexm/helper.h>

#if defined(CONFIG_VERBOSE)
#include "verbosity.h"
#endif

static GPIOLEDInfo fm4_s6e2cc_leds_info[] = {
    {
        .name = "led:red",
        .active_low = true,
        .colour_name = "Red",
        .x = 182,
        .y = 267,
        .w = 10,
        .h = 12,
        .gpio_path = DEVICE_PATH_FM4_GPIO,
        .irq_name = FM4_IRQ_GPIO_ODR_OUT,
        .gpio_bit = 3,
        /**/
    },
    {
        .name = "led:green",
        .active_low = true,
        .colour_name = "green",
        .x = 182,
        .y = 267,
        .w = 10,
        .h = 12,
        .gpio_path = DEVICE_PATH_FM4_GPIO,
        .irq_name = FM4_IRQ_GPIO_ODR_OUT,
        .gpio_bit = 2,
        /**/
    },
    {
        .name = "led:blue",
        .active_low = true,
        .colour_name = "blue",
        .x = 182,
        .y = 267,
        .w = 10,
        .h = 12,
        .gpio_path = DEVICE_PATH_FM4_GPIO,
        .irq_name = FM4_IRQ_GPIO_ODR_OUT,
        .gpio_bit = 4,
        /**/
    },
    {
        .name = "led:orange",
        .active_low = true,
        .colour_name = "orange",
        .x = 182,
        .y = 267,
        .w = 10,
        .h = 12,
        .gpio_path = DEVICE_PATH_FM4_GPIO,
        .irq_name = FM4_IRQ_GPIO_ODR_OUT,
        .gpio_bit = 13,
        /**/
    },
    {},
    /**/
};

static ButtonGPIOInfo fm4_s6e2cc_buttons_user_info[] = {
    {
        .name = "button:user",
        .x = 450,
        .y = 308,
        .w = 40,
        .h = 40,

        .active_low = true,
        .gpio_path = DEVICE_PATH_FM4_GPIO,
        .irq_name = FM4_IRQ_GPIO_IDR_IN,
        .gpio_bit = 0,
        /**/
    },
    {
        .name = "button:touchscreen",
        .x = 354,
        .y = 506,
        .w = 480,
        .h = 320,

        .active_low = true,
        .gpio_path = DEVICE_PATH_FM4_GPIO,
        .irq_name = FM4_IRQ_GPIO_IDR_IN,
        .gpio_bit = 1,
        /**/
    },
    {
        .name = "button:joystick_left",
        .x = 52,
        .y = 506,
        .w = 77,
        .h = 86,

        .active_low = true,
        .gpio_path = DEVICE_PATH_FM4_GPIO,
        .irq_name = FM4_IRQ_GPIO_IDR_IN,
        .gpio_bit = 2,
        /**/
    },
    {
        .name = "button:joystick_right",
        .x = 678,
        .y = 506,
        .w = 77,
        .h = 86,

        .active_low = true,
        .gpio_path = DEVICE_PATH_FM4_GPIO,
        .irq_name = FM4_IRQ_GPIO_IDR_IN,
        .gpio_bit = 3,
        /**/
    },
    {},
    /**/
};

static ButtonResetInfo fm4_s6e2cc_button_reset_info = {
    .x = 400,
    .y = 290,
    .w = 40,
    .h = 40,
};

static void fm4_board_init_callback(MachineState *machine)
{
    CortexMBoardState *board = CORTEXM_BOARD_STATE(machine);

    cortexm_board_greeting(board);

    BoardGraphicContext *board_graphic_context =
        cortexm_board_init_graphic_image(board, "FM4_176L_S6E2CC_ETH__730.jpg");

    //Initialise peripherals like display and joysticks for cppp
    cortexm_peripheral_init_graphic_image(board);

    {
        // Create the MCU.
        Object *mcu = cm_object_new_mcu(machine, TYPE_FM4S6E2CC);
        cm_object_realize(mcu);
    }

    Object *peripheral = cm_container_get_peripheral();
    // Create board LEDs.
    gpio_led_create_from_info(peripheral, fm4_s6e2cc_leds_info, board_graphic_context);
    button_gpio_create_from_info(peripheral,
                                 fm4_s6e2cc_buttons_user_info, board_graphic_context);
    button_reset_create_from_info(peripheral,
                                  &fm4_s6e2cc_button_reset_info, board_graphic_context);
}

static void fm4_board_class_init_callback(ObjectClass *oc,
                                          void *data)
{
    MachineClass *mc = MACHINE_CLASS(oc);

    mc->desc = "FM4_176L_S6E2CC_ETH__730 board";
    mc->init = fm4_board_init_callback;
}

static const TypeInfo fm4_s6e2cc_machine = {
    .name = BOARD_TYPE_NAME("FM4_176L_S6E2CC_ETH__730"),
    .parent = TYPE_CORTEXM_BOARD,
    .class_init = fm4_board_class_init_callback,
    /**/
};

/* ----- Boards inits ----- */
static void fm4_machine_init(void)
{
    type_register_static(&fm4_s6e2cc_machine);
}

type_init(fm4_machine_init);
