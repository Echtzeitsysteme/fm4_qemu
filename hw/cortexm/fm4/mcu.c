/*
 * FM4 Cortex-M device emulation.
 *
 * Copyright (c) 2014 Liviu Ionescu.
 * Copyright (c) 2010 Andre Beckus.
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

#include <hw/cortexm/fm4/mcu.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>
#include <hw/cortexm/bitband.h>
#include <hw/cortexm/json-parser.h>

#include "qemu/error-report.h"

#if defined(CONFIG_VERBOSE)
#include "verbosity.h"
#endif

// ----- Public ---------------------------------------------------------------

// ----- Private --------------------------------------------------------------

// Create children GPIO nodes.
// Public names are "/machine/fm4/GPIO".

// Constructor for all FM4 devices, based on capabilities.

static void fm4_mcu_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_FM4_MCU))
    {
        return;
    }

    FM4MCUState *state = FM4_MCU_STATE(dev);
    FM4Capabilities *capabilities = g_new0(FM4Capabilities, 1);

    if (state->param_capabilities)
    {
        // Copy R/O structure to a local R/W copy, to update it.
        memcpy(capabilities, state->param_capabilities,
               sizeof(FM4Capabilities));
    }

    assert(capabilities != NULL);
    state->capabilities = capabilities;

    CortexMState *cm_state = CORTEXM_MCU_STATE(dev);
    // const char *svd_device_name = cm_state->capabilities->svd_device_name;

    const char *family;

    // Devices will be addressed below "/machine/mcu/fm4".
    state->container = container_get(OBJECT(dev), "/fm4");
    /*
    // RCC; assume the presence in SVD is enough.
    if (svd_has_named_peripheral(cm_state->svd_json, "CRG"))
    {
        // RCC will be named "/machine/mcu/fm4/RCC"
        Object *crg = cm_object_new(state->container, "CRG", TYPE_FM4_CRG);
        cm_object_realize(crg); // problem

        state->crg = DEVICE(crg);
    }

    // FLASH; assume the presence in SVD is enough.
    if (svd_has_named_peripheral(cm_state->svd_json, "FLASH_IF"))
    {
        // FLASH will be named "/machine/mcu/fm4/FLASH"
        Object *flash = cm_object_new(state->container, "FLASH_IF", TYPE_FM4_FLASH_IF);

        cm_object_realize(flash);

        state->flash = DEVICE(flash);
    }

    // EXTI; assume the presence in SVD is enough.
    if (svd_has_named_peripheral(cm_state->svd_json, "EXTI"))
    {
        // EXTI will be named "/machine/mcu/fm4/EXTI".
        // It is referred by the GPIOs, to forward interrupts, so
        // it must be constructed before the GPIOs.
        Object *exti = cm_object_new(state->container, "EXTI",
                                     TYPE_FM4_EXTI);

        cm_object_realize(exti);

        state->exti = DEVICE(exti);
    }
*/
    if (svd_has_named_peripheral(cm_state->svd_json, "ADC0"))
    {

        Object *adc0 = cm_object_new(state->container, "ADC0",
                                     TYPE_FM4_ADC0);
        object_property_set_int(adc0, FM4_ADC0, "port-index", NULL);
        cm_object_realize(adc0);

        state->adc0[0] = DEVICE(adc0);
    }
    if (svd_has_named_peripheral(cm_state->svd_json, "ADC1"))
    {
        Object *adc1 = cm_object_new(state->container, "ADC1",
                                     TYPE_FM4_ADC0);
        object_property_set_int(adc1, FM4_ADC1, "port-index", NULL);
        cm_object_realize(adc1);

        state->adc0[1] = DEVICE(adc1);
        // object_property_set_int(gpio, index, "port-index", NULL);
    }

    // GPIO
    if (capabilities->has_gpio && svd_has_named_peripheral(cm_state->svd_json, "GPIO"))
    {

        Object *gpio = cm_object_new(state->container, "GPIO", TYPE_FM4_GPIO);
        cm_object_realize(gpio);
        state->gpio = DEVICE(gpio);
    }

    // TODO: add more devices.
}

static int fm4_mcu_reset_object(Object *obj, void *opaque)
{
    if (cm_object_is_instance_of_typename(obj, TYPE_DEVICE))
    {
        device_reset(DEVICE(obj));
    }
    return 0; // Non-0 will break the iterator.
}

static void fm4_mcu_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset().
    cm_device_parent_reset(dev, TYPE_FM4_MCU);

    FM4MCUState *state = FM4_MCU_STATE(dev);

    object_child_foreach(state->container, fm4_mcu_reset_object, NULL);
}

// Virtual function, overriding (in fact extending) the Cortex-M code.
static void fm4_mcu_memory_regions_create_callback(DeviceState *dev)
{
    qemu_log_function_name();
    // Create the parent (Cortex-M) memory regions
    CortexMClass *parent_class = CORTEXM_MCU_CLASS(
        object_class_by_name(TYPE_CORTEXM_MCU));
    parent_class->memory_regions_create(dev);
}

// TODO: get rid of the pointer property.
#define DEFINE_PROP_FM4CAPABILITIES_PTR(_n, _s, _f) \
    DEFINE_PROP(_n, _s, _f, qdev_prop_ptr, const FM4Capabilities *)

static Property fm4_mcu_properties[] = {
    DEFINE_PROP_FM4CAPABILITIES_PTR("fm4-capabilities",
                                    FM4MCUState, param_capabilities),
    DEFINE_PROP_END_OF_LIST(), /**/
};

static void fm4_mcu_instance_init_callback(Object *obj)
{
    qemu_log_function_name();
    FM4MCUState *state = FM4_MCU_STATE(obj);

    cm_object_property_add_uint32(obj, "hse-freq-hz", &state->hse_freq_hz);
    state->hse_freq_hz = 0;

    cm_object_property_add_uint32(obj, "lse-freq-hz", &state->lse_freq_hz);
    state->lse_freq_hz = 0;
}

static void fm4_mcu_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);
    dc->realize = fm4_mcu_realize_callback;
    dc->reset = fm4_mcu_reset_callback;

    dc->props = fm4_mcu_properties;

    CortexMClass *cm_class = CORTEXM_MCU_CLASS(klass);
    cm_class->memory_regions_create = fm4_mcu_memory_regions_create_callback;
}

static const TypeInfo fm4_mcu_type_info = {
    .abstract = true,
    .name = TYPE_FM4_MCU,
    .parent = TYPE_FM4_MCU_PARENT,
    .instance_init = fm4_mcu_instance_init_callback,
    .instance_size = sizeof(FM4MCUState),
    .class_init = fm4_mcu_class_init_callback,
    .class_size = sizeof(FM4MCUClass)};

// ----- Type inits. -----

static void fm4_type_init(void)
{

    type_register_static(&fm4_mcu_type_info);
}

type_init(fm4_type_init);

// ----------------------------------------------------------------------------
