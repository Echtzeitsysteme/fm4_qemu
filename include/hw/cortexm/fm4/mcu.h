/*
 * FM4 Cortex-M devices emulation.
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


/*
The blinky projects generated by the Eclipse Embedded CDT templates (and all STM32 HAL projects) use the SysTick to measure time, so any realistic emulation should support SysTick. xPack QEMU Arm not only does this, but also provides relatively accurate time intervals, and the SysTick exception can be used from simple time measuring to driving a real-time scheduler with a reasonable number of task switches per second (1000 Hz is OK).


*/
#ifndef FM4_MCU_H_
#define FM4_MCU_H_

#include "qemu/osdep.h"

#include "hw/boards.h"
#include <hw/cortexm/mcu.h>
#include <hw/cortexm/fm4/adc0.h>
#include <hw/cortexm/fm4/crg.h>
#include <hw/cortexm/fm4/flash_if.h>
#include <hw/cortexm/fm4/gpio.h>
#include <hw/cortexm/fm4/exti.h>
#include <hw/cortexm/fm4/rtc.h>
#include <hw/cortexm/parson.h>

// ----------------------------------------------------------------------------

#define TYPE_FM4_MCU "fm4-mcu"

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_FM4_MCU_PARENT TYPE_CORTEXM_MCU
typedef CortexMClass FM4MCUParentClass;
typedef CortexMState FM4MCUParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define FM4_MCU_GET_CLASS(obj) \
    OBJECT_GET_CLASS(FM4MCUClass, (obj), TYPE_FM4_MCU)
#define FM4_MCU_CLASS(klass) \
    OBJECT_CLASS_CHECK(FM4MCUClass, (klass), TYPE_FM4_MCU)

typedef struct FM4MCUClass {
    // private:
    FM4MCUParentClass parent_class;
    // public:

} FM4MCUClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define FM4_MCU_STATE(obj) \
    OBJECT_CHECK(FM4MCUState, (obj), TYPE_FM4_MCU)

typedef struct FM4MCUState {
    // private:
    FM4MCUParentState parent_obj;
    // public:

    // Constructor parameters.
    const FM4Capabilities *param_capabilities;

    // Specific FM4 capabilities; Cortex-M capabilities are separate.
    const FM4Capabilities *capabilities;

    Object *container;

    DeviceState *crg;

    // These two properties are duplicated from RCC, to allow
    // setting them before the object exist.
    uint32_t hse_freq_hz;
    uint32_t lse_freq_hz;

    DeviceState *flash;
   // DeviceState *pwr;
    DeviceState *exti;
    DeviceState *rtc;
    //DeviceState *syscfg;
   // DeviceState *afio; // For FM4F1 only.

    DeviceState *gpio;
    DeviceState *adc0[3];
    int num_gpio;
   // DeviceState *usart[FM4_MAX_USART];

} FM4MCUState;

// ------ Public --------------------------------------------------------------

/*
 * Might be deprecated in the future; peripherals are named and can be
 * obtained by name.
 */

/*G_INLINE_FUNC DeviceState *fm4_mcu_get_rcc_dev(DeviceState *dev)
{
    return DEVICE((FM4_MCU_STATE(dev)->rcc));
}*/

G_INLINE_FUNC DeviceState *fm4_mcu_get_gpio_dev(DeviceState *dev,
        int port_index)
{
    assert(port_index < FM4_MAX_GPIO);
    return DEVICE((FM4_MCU_STATE(dev)->gpio));
}

G_INLINE_FUNC FM4MCUState *fm4_mcu_get(void)
{
    return FM4_MCU_STATE(object_resolve_path("/machine/mcu", NULL));
}

// ----------------------------------------------------------------------------

#endif /* FM4_MCU_H_ */