/*
 * FM4- FLASH_IF(Flash Memory) emulation.
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

#include <hw/cortexm/fm4/flash_if.h>
#include <hw/cortexm/fm4/mcu.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>

// ----- Generated code -------------------------------------------------------
//
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void fm4s6e2cc_flash_if_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
    FM4FLASH_IFState *state = FM4_FLASH_IF_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);

    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers.
    state->u.e2.reg.faszr = cm_object_get_child_by_name(obj, "FASZR");
    state->u.e2.reg.frwtr = cm_object_get_child_by_name(obj, "FRWTR");
    state->u.e2.reg.fstr = cm_object_get_child_by_name(obj, "FSTR");
    state->u.e2.reg.fsyndn = cm_object_get_child_by_name(obj, "FSYNDN");
    state->u.e2.reg.fbfcr = cm_object_get_child_by_name(obj, "FBFCR");
    state->u.e2.reg.ficr = cm_object_get_child_by_name(obj, "FICR");
    state->u.e2.reg.fisr = cm_object_get_child_by_name(obj, "FISR");
    state->u.e2.reg.ficlr = cm_object_get_child_by_name(obj, "FICLR");
    state->u.e2.reg.dfctrlr = cm_object_get_child_by_name(obj, "DFCTRLR");
    state->u.e2.reg.crtrmm = cm_object_get_child_by_name(obj, "CRTRMM");
    state->u.e2.reg.fgpdm1 = cm_object_get_child_by_name(obj, "FGPDM1");
    state->u.e2.reg.fgpdm2 = cm_object_get_child_by_name(obj, "FGPDM2");
    state->u.e2.reg.fgpdm3 = cm_object_get_child_by_name(obj, "FGPDM3");
    state->u.e2.reg.fgpdm4 = cm_object_get_child_by_name(obj, "FGPDM4");

    // FASZRbitfields.
    state->u.e2.fld.faszr.asz = cm_object_get_child_by_name(state->u.e2.reg.faszr, "ASZ");

    // FRWTRbitfields.
    state->u.e2.fld.frwtr.rwt = cm_object_get_child_by_name(state->u.e2.reg.frwtr, "RWT");

    // FSTRbitfields.
    state->u.e2.fld.fstr.rdy = cm_object_get_child_by_name(state->u.e2.reg.fstr, "RDY");
    state->u.e2.fld.fstr.hng = cm_object_get_child_by_name(state->u.e2.reg.fstr, "HNG");
    state->u.e2.fld.fstr.err = cm_object_get_child_by_name(state->u.e2.reg.fstr, "ERR");

    // FSYNDNbitfields.
    state->u.e2.fld.fsyndn.sd = cm_object_get_child_by_name(state->u.e2.reg.fsyndn, "SD");

    // FBFCRbitfields.
    state->u.e2.fld.fbfcr.be = cm_object_get_child_by_name(state->u.e2.reg.fbfcr, "BE");
    state->u.e2.fld.fbfcr.bs = cm_object_get_child_by_name(state->u.e2.reg.fbfcr, "BS");

    // FICRbitfields.
    state->u.e2.fld.ficr.rdyie = cm_object_get_child_by_name(state->u.e2.reg.ficr, "RDYIE");
    state->u.e2.fld.ficr.hangie = cm_object_get_child_by_name(state->u.e2.reg.ficr, "HANGIE");
    state->u.e2.fld.ficr.errie = cm_object_get_child_by_name(state->u.e2.reg.ficr, "ERRIE");

    // FISRbitfields.
    state->u.e2.fld.fisr.rdyif = cm_object_get_child_by_name(state->u.e2.reg.fisr, "RDYIF");
    state->u.e2.fld.fisr.hangif = cm_object_get_child_by_name(state->u.e2.reg.fisr, "HANGIF");
    state->u.e2.fld.fisr.errif = cm_object_get_child_by_name(state->u.e2.reg.fisr, "ERRIF");

    // FICLRbitfields.
    state->u.e2.fld.ficlr.rdyic = cm_object_get_child_by_name(state->u.e2.reg.ficlr, "RDYIC");
    state->u.e2.fld.ficlr.hangic = cm_object_get_child_by_name(state->u.e2.reg.ficlr, "HANGIC");
    state->u.e2.fld.ficlr.erric = cm_object_get_child_by_name(state->u.e2.reg.ficlr, "ERRIC");

    // DFCTRLRbitfields.
    state->u.e2.fld.dfctrlr.dfe = cm_object_get_child_by_name(state->u.e2.reg.dfctrlr, "DFE");
    state->u.e2.fld.dfctrlr.rme = cm_object_get_child_by_name(state->u.e2.reg.dfctrlr, "RME");
    state->u.e2.fld.dfctrlr.wkey = cm_object_get_child_by_name(state->u.e2.reg.dfctrlr, "WKEY");

    // CRTRMMbitfields.
    state->u.e2.fld.crtrmm.trmm = cm_object_get_child_by_name(state->u.e2.reg.crtrmm, "TRMM");
    state->u.e2.fld.crtrmm.ttrmm = cm_object_get_child_by_name(state->u.e2.reg.crtrmm, "TTRMM");

    // FGPDM1bitfields.
    state->u.e2.fld.fgpdm1.gpd1 = cm_object_get_child_by_name(state->u.e2.reg.fgpdm1, "GPD1");

    // FGPDM2bitfields.
    state->u.e2.fld.fgpdm2.gpd2 = cm_object_get_child_by_name(state->u.e2.reg.fgpdm2, "GPD2");

    // FGPDM3bitfields.
    state->u.e2.fld.fgpdm3.gpd3 = cm_object_get_child_by_name(state->u.e2.reg.fgpdm3, "GPD3");

    // FGPDM4bitfields.
    state->u.e2.fld.fgpdm4.gpd4 = cm_object_get_child_by_name(state->u.e2.reg.fgpdm4, "GPD4");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// ----- Private --------------------------------------------------------------

#if 0
static peripheral_register_t fm4_flash_if_xxx_pre_write_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    FM4FLASH_IFState *state = FM4_FLASH_IF_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);

    // TODO: Add code to adjust the value (like applying some masks,
    // for example prevent setting interrupts not enabled).
    // Also process cleared/set by write 1/0 bits.
    // The returned value will be stored in the register value.

    return full_value;
}

static void fm4_flash_if_xxx_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    FM4FLASH_IFState *state = FM4_FLASH_IF_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);
    // The new register value is full_value, the old one is prev_value.

    // TODO: Add code to send the value to the consumer.
}

static peripheral_register_t fm4_flash_if_xxx_pre_read_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size)
{
    FM4FLASH_IFState *state = FM4_FLASH_IF_STATE(periph);

    peripheral_register_t value = 0;

    // Add code to get the value from the producer, and return it.

    // This value, possibly masked, will be stored in the register
    // and returned when the register is read.
    return value;
}

static void fm4_flash_if_xxx_post_read_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size)
{
    FM4FLASH_IFState *state = FM4_FLASH_IF_STATE(periph);

    peripheral_register_t value = peripheral_register_get_raw_value(reg);

    // TODO: add code to perform the post read actions, like clearing some bits.
}
#endif

// ----------------------------------------------------------------------------

// TODO: remove this if the peripheral is always enabled.
static bool fm4_flash_if_is_enabled(Object *obj)
{
    FM4FLASH_IFState *state = FM4_FLASH_IF_STATE(obj);

    if (register_bitfield_is_non_zero(state->enabling_bit))
    {
        return true; // Positive logic, bit == 1 means enabled.
    }

    // Not enabled
    return false;
}

static void fm4_flash_if_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    FM4FLASH_IFState *state = FM4_FLASH_IF_STATE(obj);

    // Capabilities are not yet available.

    // TODO: remove this if the peripheral is always enabled.
    state->enabling_bit = NULL;

    // TODO: Add code to initialise all members.
}

static void fm4_flash_if_realize_callback(DeviceState *dev, Error **errp)
{

    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_FM4_FLASH_IF))
    {
        return;
    }

    FM4MCUState *mcu = fm4_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    FM4FLASH_IFState *state = FM4_FLASH_IF_STATE(dev);
    // First thing first: get capabilities from MCU, needed everywhere.
    state->capabilities = mcu->capabilities;

    // Also keep a local pointer, to access them easier.
    const FM4Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    const char *periph_name = "FLASH_IF";

    svd_set_peripheral_address_block(cm_state->svd_json, periph_name, obj);

    peripheral_create_memory_region(obj);

    cm_object_property_set_int(obj, 4, "register-size-bytes");
    cm_object_property_set_bool(obj, true, "is-little-endian");

    fm4s6e2cc_flash_if_create_objects(obj, cm_state->svd_json, periph_name); //stopped here

    peripheral_prepare_registers(obj);
}

static void fm4_flash_if_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset(); this will reset all children registers.
    cm_device_parent_reset(dev, TYPE_FM4_FLASH_IF);
}

static void fm4_flash_if_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = fm4_flash_if_reset_callback;
    dc->realize = fm4_flash_if_realize_callback;

    // TODO: remove this if the peripheral is always enabled.
    PeripheralClass *per_class = PERIPHERAL_CLASS(klass);
    per_class->is_enabled = fm4_flash_if_is_enabled;
}

static const TypeInfo fm4_flash_if_type_info = {
    .name = TYPE_FM4_FLASH_IF,
    .parent = TYPE_FM4_FLASH_IF_PARENT,
    .instance_init = fm4_flash_if_instance_init_callback,
    .instance_size = sizeof(FM4FLASH_IFState),
    .class_init = fm4_flash_if_class_init_callback,
    .class_size = sizeof(FM4FLASH_IFClass)};

static void fm4_flash_if_register_types(void)
{
    type_register_static(&fm4_flash_if_type_info);
}

type_init(fm4_flash_if_register_types);

// ----------------------------------------------------------------------------