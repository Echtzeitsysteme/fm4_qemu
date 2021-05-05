/*
 * FM4 Cortex-M devices emulation.
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

#include <hw/cortexm/fm4/mcus.h>
#include <hw/cortexm/mcu.h>
#include <hw/cortexm/helper.h>

#include "exec/address-spaces.h"
#include "qemu/error-report.h"
#include "sysemu/sysemu.h"

#if defined(CONFIG_VERBOSE)
#include "verbosity.h"
#endif

// ----------------------------------------------------------------------------

/*
 * Define all FM4 MCUs, based on table capabilities.
 *
 * To easily reuse the definitions, each line includes a pointer
 * to the core capabilities and a pointer to the fm4 capabilities.
 * This greatly simplify adding definition that differ only in memory size.
 */

static const FM4Capabilities fm4s6e2cc = {
    .family = FM4_FAMILY_F0,

    .hsi_freq_hz = 8000000,
    .lsi_freq_hz = 40000,

    .has_periph_bitband = false,

    .num_exti = 23,

    .has_crc = true,

    .has_gpio = true,

    .has_adc = true, // 12-bit, 16+3 channels, Vref = ADC_IN17

    .has_rtc = true,

};
/**
 * @brief the name of json file is defined here 
 * 
 */
static const FM4PartInfo fm4_mcus[] = {
    {
        .name = TYPE_FM4S6E2CC,
        .cortexm = {
            .flash_size_kb = 1024,
            .sram_size_kb = 256,

            .svd_file_name = "S6E2CC-qemu.json",
            .svd_device_name = "FM4S6E2CC",
        },
        .fm4 = &fm4s6e2cc,

    },
    {}};

// ----------------------------------------------------------------------------

static void fm4_mcus_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    // Add properties here.
}

static void fm4_mcus_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    FM4DeviceClass *st_class = FM4_DEVICE_GET_CLASS(dev);
    FM4PartInfo *part_info = st_class->part_info;

    // Set additional constructor parameters, that were passed via
    // the .class_data and copied to custom class member.
    qdev_prop_set_ptr(dev, "cortexm-capabilities",
                      (void *)&part_info->cortexm);
    qdev_prop_set_ptr(dev, "fm4-capabilities", (void *)part_info->fm4);

    // Call parent realize().
    // We do not know the current typename, since it was generated
    // with a table, so we use the parent typename.

    if (!cm_device_by_name_realize(dev, errp, TYPE_FM4_DEVICE_PARENT))
    {
        return;
    }
}

static void fm4_mcus_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset().
    cm_device_by_name_reset(dev, TYPE_FM4_MCU);
}

static void fm4_mcus_class_init_callback(ObjectClass *klass, void *data)
{

    DeviceClass *dc = DEVICE_CLASS(klass);
    dc->realize = fm4_mcus_realize_callback;
    dc->reset = fm4_mcus_reset_callback;
    // dc->props = fm4_mcus_properties;

    FM4DeviceClass *st_class = (FM4DeviceClass *)(klass);
    // Copy the 'data' param, pointing to a ParamInfo, to the class
    // structure, to be retrieved by the constructor.
    st_class->part_info = data;
}

// Register all devices described in the table.
// Pass the pointer to the table element as .class_data
// to the .class_init.

static void fm4_mcus_types_init(void)
{

    int i;
    for (i = 0; fm4_mcus[i].name; ++i)
    {

        TypeInfo ti = {
            .name = fm4_mcus[i].name,
            .parent = TYPE_FM4_DEVICE_PARENT,
            .instance_init = fm4_mcus_instance_init_callback,
            .instance_size = sizeof(FM4DeviceState),
            .class_init = fm4_mcus_class_init_callback,
            .class_size = sizeof(FM4DeviceClass),
            .class_data = (void *)&fm4_mcus[i]};
        type_register(&ti);
    }
}

type_init(fm4_mcus_types_init);

// ----------------------------------------------------------------------------
