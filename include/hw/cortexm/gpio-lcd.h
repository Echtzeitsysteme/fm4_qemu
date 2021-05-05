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

#ifndef GPIO_LCD_H_
#define GPIO_LCD_H_

#include "qemu/osdep.h"

#include "hw/qdev.h"
#include "qemu/typedefs.h"
#include "hw/sysbus.h"

#include <hw/cortexm/graphic.h>

// ----------------------------------------------------------------------------

#define IRQ_GPIO_LCD_IN "lcd-in"

// ----------------------------------------------------------------------------

#define DEFINE_PROP_GPIO_LCD_PTR(_n, _s, _f) \
    DEFINE_PROP(_n, _s, _f, qdev_prop_ptr, GPIOLCDInfo *)

// ----------------------------------------------------------------------------

typedef struct
{

    const char *name; /* NULL for table end. */

    /* Centre of the LCD. */
    uint32_t x;
    uint32_t y;
    /* Size of the rectangle to lit. */
    uint32_t w;
    uint32_t h;

    bool active_low;

    const char *gpio_path;
    const char *irq_name;
    int gpio_bit;

} GPIOLCDInfo;

// ----------------------------------------------------------------------------

#define TYPE_GPIO_LCD "gpio-lcd"

// Parent definitions.
// TODO: Change this to TYPE_DEVICE
#define TYPE_GPIO_LCD_PARENT TYPE_SYS_BUS_DEVICE
typedef SysBusDeviceClass GPIOLCDParentClass;
typedef SysBusDevice GPIOLCDParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define GPIO_LCD_GET_CLASS(obj) \
    OBJECT_GET_CLASS(GPIOLCDClass, (obj), TYPE_GPIO_LCD)
#define GPIO_LCD_CLASS(klass) \
    OBJECT_CLASS_CHECK(GPIOLCDClass, (klass), TYPE_GPIO_LCD)

typedef struct GPIOLCDClass
{
    // private:
    GPIOLCDParentClass parent_class;
    // public:

} GPIOLCDClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define GPIO_LCD_STATE(obj) \
    OBJECT_CHECK(GPIOLCDState, (obj), TYPE_GPIO_LCD)

/*
 * The LCD has a single incoming interrupt; connect the source,
 * usually a GPIO outgoing interrupt, to it.
 *
 * Properties:
 * - active-low (bool)
 * - x,y (int)
 */
typedef struct
{
    // private:
    GPIOLCDParentState parent_obj;
    // public:

    bool active_low;
    int xCoordinate;
    int yCoordinate;
#if defined(CONFIG_SDL)
    LCDGraphicContext lcd_graphic_context;
    BoardGraphicContext *board_graphic_context;
#endif /* defined(CONFIG_SDL) */

} GPIOLCDState;

void draw_lcd_rec_callback(int x, int y, int x2, int y2, uint16_t color);
void draw_lcd_callback(int x, int y, uint16_t color);

//Object **
void gpio_lcd_create_from_info(Object *parent, GPIOLCDInfo *info_array,
                               BoardGraphicContext *graphic_context);

// ----------------------------------------------------------------------------

#endif /* GPIO_LCD_H_ */
