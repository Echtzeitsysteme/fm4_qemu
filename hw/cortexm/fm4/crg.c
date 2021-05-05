/*
 * FM4- CRG(Clock Unit Registers) emulation.
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

#include <hw/cortexm/fm4/crg.h>
#include <hw/cortexm/fm4/mcu.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>

// ----- Generated code -------------------------------------------------------
//
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void fm4s6e2cc_crg_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
    FM4CRGState *state = FM4_CRG_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers.
    state->u.e2.reg.scm_ctl = cm_object_get_child_by_name(obj, "SCM_CTL");
    state->u.e2.reg.scm_str = cm_object_get_child_by_name(obj, "SCM_STR");
    state->u.e2.reg.stb_ctl = cm_object_get_child_by_name(obj, "STB_CTL");
    state->u.e2.reg.rst_str = cm_object_get_child_by_name(obj, "RST_STR");
    state->u.e2.reg.bsc_psr = cm_object_get_child_by_name(obj, "BSC_PSR");
    state->u.e2.reg.apbc0_psr = cm_object_get_child_by_name(obj, "APBC0_PSR");
    state->u.e2.reg.apbc1_psr = cm_object_get_child_by_name(obj, "APBC1_PSR");
    state->u.e2.reg.apbc2_psr = cm_object_get_child_by_name(obj, "APBC2_PSR");
    state->u.e2.reg.swc_psr = cm_object_get_child_by_name(obj, "SWC_PSR");
    state->u.e2.reg.ttc_psr = cm_object_get_child_by_name(obj, "TTC_PSR");
    state->u.e2.reg.csw_tmr = cm_object_get_child_by_name(obj, "CSW_TMR");
    state->u.e2.reg.psw_tmr = cm_object_get_child_by_name(obj, "PSW_TMR");
    state->u.e2.reg.pll_ctl1 = cm_object_get_child_by_name(obj, "PLL_CTL1");
    state->u.e2.reg.pll_ctl2 = cm_object_get_child_by_name(obj, "PLL_CTL2");
    state->u.e2.reg.csv_ctl = cm_object_get_child_by_name(obj, "CSV_CTL");
    state->u.e2.reg.csv_str = cm_object_get_child_by_name(obj, "CSV_STR");
    state->u.e2.reg.fcswh_ctl = cm_object_get_child_by_name(obj, "FCSWH_CTL");
    state->u.e2.reg.fcswl_ctl = cm_object_get_child_by_name(obj, "FCSWL_CTL");
    state->u.e2.reg.fcswd_ctl = cm_object_get_child_by_name(obj, "FCSWD_CTL");
    state->u.e2.reg.dbwdt_ctl = cm_object_get_child_by_name(obj, "DBWDT_CTL");
    state->u.e2.reg.int_enr = cm_object_get_child_by_name(obj, "INT_ENR");
    state->u.e2.reg.int_str = cm_object_get_child_by_name(obj, "INT_STR");
    state->u.e2.reg.int_clr = cm_object_get_child_by_name(obj, "INT_CLR");

    // SCM_CTLbitfields.
    state->u.e2.fld.scm_ctl.mosce = cm_object_get_child_by_name(state->u.e2.reg.scm_ctl, "MOSCE");
    state->u.e2.fld.scm_ctl.sosce = cm_object_get_child_by_name(state->u.e2.reg.scm_ctl, "SOSCE");
    state->u.e2.fld.scm_ctl.plle = cm_object_get_child_by_name(state->u.e2.reg.scm_ctl, "PLLE");
    state->u.e2.fld.scm_ctl.rcs = cm_object_get_child_by_name(state->u.e2.reg.scm_ctl, "RCS");

    // SCM_STRbitfields.
    state->u.e2.fld.scm_str.mordy = cm_object_get_child_by_name(state->u.e2.reg.scm_str, "MORDY");
    state->u.e2.fld.scm_str.sordy = cm_object_get_child_by_name(state->u.e2.reg.scm_str, "SORDY");
    state->u.e2.fld.scm_str.plrdy = cm_object_get_child_by_name(state->u.e2.reg.scm_str, "PLRDY");
    state->u.e2.fld.scm_str.rcm = cm_object_get_child_by_name(state->u.e2.reg.scm_str, "RCM");

    // STB_CTLbitfields.
    state->u.e2.fld.stb_ctl.stm = cm_object_get_child_by_name(state->u.e2.reg.stb_ctl, "STM");
    state->u.e2.fld.stb_ctl.dstm = cm_object_get_child_by_name(state->u.e2.reg.stb_ctl, "DSTM");
    state->u.e2.fld.stb_ctl.spl = cm_object_get_child_by_name(state->u.e2.reg.stb_ctl, "SPL");
    state->u.e2.fld.stb_ctl.key = cm_object_get_child_by_name(state->u.e2.reg.stb_ctl, "KEY");

    // RST_STRbitfields.
    state->u.e2.fld.rst_str.ponr = cm_object_get_child_by_name(state->u.e2.reg.rst_str, "PONR");
    state->u.e2.fld.rst_str.initx = cm_object_get_child_by_name(state->u.e2.reg.rst_str, "INITX");
    state->u.e2.fld.rst_str.swdt = cm_object_get_child_by_name(state->u.e2.reg.rst_str, "SWDT");
    state->u.e2.fld.rst_str.hwdt = cm_object_get_child_by_name(state->u.e2.reg.rst_str, "HWDT");
    state->u.e2.fld.rst_str.csvr = cm_object_get_child_by_name(state->u.e2.reg.rst_str, "CSVR");
    state->u.e2.fld.rst_str.fcsr = cm_object_get_child_by_name(state->u.e2.reg.rst_str, "FCSR");
    state->u.e2.fld.rst_str.srst = cm_object_get_child_by_name(state->u.e2.reg.rst_str, "SRST");

    // BSC_PSRbitfields.
    state->u.e2.fld.bsc_psr.bsr = cm_object_get_child_by_name(state->u.e2.reg.bsc_psr, "BSR");

    // APBC0_PSRbitfields.
    state->u.e2.fld.apbc0_psr.apbc0 = cm_object_get_child_by_name(state->u.e2.reg.apbc0_psr, "APBC0");

    // APBC1_PSRbitfields.
    state->u.e2.fld.apbc1_psr.apbc1 = cm_object_get_child_by_name(state->u.e2.reg.apbc1_psr, "APBC1");
    state->u.e2.fld.apbc1_psr.apbc1rst = cm_object_get_child_by_name(state->u.e2.reg.apbc1_psr, "APBC1RST");
    state->u.e2.fld.apbc1_psr.apbc1en = cm_object_get_child_by_name(state->u.e2.reg.apbc1_psr, "APBC1EN");

    // APBC2_PSRbitfields.
    state->u.e2.fld.apbc2_psr.apbc2 = cm_object_get_child_by_name(state->u.e2.reg.apbc2_psr, "APBC2");
    state->u.e2.fld.apbc2_psr.apbc2rst = cm_object_get_child_by_name(state->u.e2.reg.apbc2_psr, "APBC2RST");
    state->u.e2.fld.apbc2_psr.apbc2en = cm_object_get_child_by_name(state->u.e2.reg.apbc2_psr, "APBC2EN");

    // SWC_PSRbitfields.
    state->u.e2.fld.swc_psr.swds = cm_object_get_child_by_name(state->u.e2.reg.swc_psr, "SWDS");

    // TTC_PSRbitfields.
    state->u.e2.fld.ttc_psr.ttc = cm_object_get_child_by_name(state->u.e2.reg.ttc_psr, "TTC");

    // CSW_TMRbitfields.
    state->u.e2.fld.csw_tmr.mowt = cm_object_get_child_by_name(state->u.e2.reg.csw_tmr, "MOWT");
    state->u.e2.fld.csw_tmr.sowt = cm_object_get_child_by_name(state->u.e2.reg.csw_tmr, "SOWT");

    // PSW_TMRbitfields.
    state->u.e2.fld.psw_tmr.powt = cm_object_get_child_by_name(state->u.e2.reg.psw_tmr, "POWT");
    state->u.e2.fld.psw_tmr.pinc = cm_object_get_child_by_name(state->u.e2.reg.psw_tmr, "PINC");

    // PLL_CTL1bitfields.
    state->u.e2.fld.pll_ctl1.pllm = cm_object_get_child_by_name(state->u.e2.reg.pll_ctl1, "PLLM");
    state->u.e2.fld.pll_ctl1.pllk = cm_object_get_child_by_name(state->u.e2.reg.pll_ctl1, "PLLK");

    // PLL_CTL2bitfields.
    state->u.e2.fld.pll_ctl2.plln = cm_object_get_child_by_name(state->u.e2.reg.pll_ctl2, "PLLN");

    // CSV_CTLbitfields.
    state->u.e2.fld.csv_ctl.mcsve = cm_object_get_child_by_name(state->u.e2.reg.csv_ctl, "MCSVE");
    state->u.e2.fld.csv_ctl.scsve = cm_object_get_child_by_name(state->u.e2.reg.csv_ctl, "SCSVE");
    state->u.e2.fld.csv_ctl.fcsde = cm_object_get_child_by_name(state->u.e2.reg.csv_ctl, "FCSDE");
    state->u.e2.fld.csv_ctl.fcsre = cm_object_get_child_by_name(state->u.e2.reg.csv_ctl, "FCSRE");
    state->u.e2.fld.csv_ctl.fcd = cm_object_get_child_by_name(state->u.e2.reg.csv_ctl, "FCD");

    // CSV_STRbitfields.
    state->u.e2.fld.csv_str.mcmf = cm_object_get_child_by_name(state->u.e2.reg.csv_str, "MCMF");
    state->u.e2.fld.csv_str.scmf = cm_object_get_child_by_name(state->u.e2.reg.csv_str, "SCMF");

    // FCSWH_CTLbitfields.
    state->u.e2.fld.fcswh_ctl.fwh = cm_object_get_child_by_name(state->u.e2.reg.fcswh_ctl, "FWH");

    // FCSWL_CTLbitfields.
    state->u.e2.fld.fcswl_ctl.fwl = cm_object_get_child_by_name(state->u.e2.reg.fcswl_ctl, "FWL");

    // FCSWD_CTLbitfields.
    state->u.e2.fld.fcswd_ctl.fwd = cm_object_get_child_by_name(state->u.e2.reg.fcswd_ctl, "FWD");

    // DBWDT_CTLbitfields.
    state->u.e2.fld.dbwdt_ctl.dpswbe = cm_object_get_child_by_name(state->u.e2.reg.dbwdt_ctl, "DPSWBE");
    state->u.e2.fld.dbwdt_ctl.dphwbe = cm_object_get_child_by_name(state->u.e2.reg.dbwdt_ctl, "DPHWBE");

    // INT_ENRbitfields.
    state->u.e2.fld.int_enr.mcse = cm_object_get_child_by_name(state->u.e2.reg.int_enr, "MCSE");
    state->u.e2.fld.int_enr.scse = cm_object_get_child_by_name(state->u.e2.reg.int_enr, "SCSE");
    state->u.e2.fld.int_enr.pcse = cm_object_get_child_by_name(state->u.e2.reg.int_enr, "PCSE");
    state->u.e2.fld.int_enr.fcse = cm_object_get_child_by_name(state->u.e2.reg.int_enr, "FCSE");

    // INT_STRbitfields.
    state->u.e2.fld.int_str.mcsi = cm_object_get_child_by_name(state->u.e2.reg.int_str, "MCSI");
    state->u.e2.fld.int_str.scsi = cm_object_get_child_by_name(state->u.e2.reg.int_str, "SCSI");
    state->u.e2.fld.int_str.pcsi = cm_object_get_child_by_name(state->u.e2.reg.int_str, "PCSI");
    state->u.e2.fld.int_str.fcsi = cm_object_get_child_by_name(state->u.e2.reg.int_str, "FCSI");

    // INT_CLRbitfields.
    state->u.e2.fld.int_clr.mcsc = cm_object_get_child_by_name(state->u.e2.reg.int_clr, "MCSC");
    state->u.e2.fld.int_clr.scsc = cm_object_get_child_by_name(state->u.e2.reg.int_clr, "SCSC");
    state->u.e2.fld.int_clr.pcsc = cm_object_get_child_by_name(state->u.e2.reg.int_clr, "PCSC");
    state->u.e2.fld.int_clr.fcsc = cm_object_get_child_by_name(state->u.e2.reg.int_clr, "FCSC");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// ----- Private --------------------------------------------------------------

#if 0
static peripheral_register_t fm4_crg_xxx_pre_write_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    FM4CRGState *state = FM4_CRG_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);

    // TODO: Add code to adjust the value (like applying some masks,
    // for example prevent setting interrupts not enabled).
    // Also process cleared/set by write 1/0 bits.
    // The returned value will be stored in the register value.

    return full_value;
}

static void fm4_crg_xxx_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    FM4CRGState *state = FM4_CRG_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);
    // The new register value is full_value, the old one is prev_value.

    // TODO: Add code to send the value to the consumer.
}

static peripheral_register_t fm4_crg_xxx_pre_read_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size)
{
    FM4CRGState *state = FM4_CRG_STATE(periph);

    peripheral_register_t value = 0;

    // Add code to get the value from the producer, and return it.

    // This value, possibly masked, will be stored in the register
    // and returned when the register is read.
    return value;
}

static void fm4_crg_xxx_post_read_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size)
{
    FM4CRGState *state = FM4_CRG_STATE(periph);

    peripheral_register_t value = peripheral_register_get_raw_value(reg);

    // TODO: add code to perform the post read actions, like clearing some bits.
}
#endif

// ----------------------------------------------------------------------------

static void fm4_crg_instance_init_callback(Object *obj)
{
    qemu_log_function_name();
}

static void fm4_crg_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_FM4_CRG))
    {
        return;
    }

    FM4MCUState *mcu = fm4_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    FM4CRGState *state = FM4_CRG_STATE(dev);
    // First thing first: get capabilities from MCU, needed everywhere.
    state->capabilities = mcu->capabilities;

    // Also keep a local pointer, to access them easier.
    const FM4Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    const char *periph_name = "CRG";

    svd_set_peripheral_address_block(cm_state->svd_json, periph_name, obj); //problem

    peripheral_create_memory_region(obj);

    // TODO: remove this if the peripheral is always enabled.
    //  char enabling_bit_name[FM4_CRG_SIZEOF_ENABLING_BITFIELD];

    fm4s6e2cc_crg_create_objects(obj, cm_state->svd_json, periph_name);

    // TODO: add actions.
    // cm_object_property_set_str(state->u.e2.fld.xxx.fff, "GGG", "follows");
    // cm_object_property_set_str(state->u.e2.fld.xxx.fff, "GGG", "cleared-by");

    // TODO: add callbacks.
    // peripheral_register_set_pre_read(state->e2.reg.xxx, &fm4_crg_xxx_pre_read_callback);
    // peripheral_register_set_post_read(state->e2.reg.xxx, &fm4_crg_xxx_post_read_callback);
    // peripheral_register_set_pre_read(state->e2.reg.xxx, &fm4_crg_xxx_pret_read_callback);
    // peripheral_register_set_post_write(state->e2.reg.xxx, &fm4_crg_xxx_post_write_callback);

    // TODO: add interrupts.

    // TODO: remove this if the peripheral is always enabled.
    /*    snprintf(enabling_bit_name, sizeof(enabling_bit_name) - 1,
                DEVICE_PATH_FM4_CRG "/AHB1ENR/CRGEN");

*/
    peripheral_prepare_registers(obj);
}

static void fm4_crg_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset(); this will reset all children registers.
    cm_device_parent_reset(dev, TYPE_FM4_CRG);
}

static void fm4_crg_class_init_callback(ObjectClass *klass, void *data)
{

    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = fm4_crg_reset_callback;
    dc->realize = fm4_crg_realize_callback;
}

static const TypeInfo fm4_crg_type_info = {
    .name = TYPE_FM4_CRG,
    .parent = TYPE_FM4_CRG_PARENT,
    .instance_init = fm4_crg_instance_init_callback,
    .instance_size = sizeof(FM4CRGState),
    .class_init = fm4_crg_class_init_callback,
    .class_size = sizeof(FM4CRGClass)};

static void fm4_crg_register_types(void)
{
    type_register_static(&fm4_crg_type_info);
}

type_init(fm4_crg_register_types);

// ----------------------------------------------------------------------------
