/*
 * FM4- RTC(REAL-TIME CLOCK) emulation.
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

#include <hw/cortexm/fm4/rtc.h>
#include <hw/cortexm/fm4/mcu.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>

// ----- Generated code -------------------------------------------------------
//
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void fm4s6e2cc_rtc_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
    FM4RTCState *state = FM4_RTC_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers.
    state->u.e2.reg.wtcr10 = cm_object_get_child_by_name(obj, "WTCR10");
    state->u.e2.reg.wtcr11 = cm_object_get_child_by_name(obj, "WTCR11");
    state->u.e2.reg.wtcr12 = cm_object_get_child_by_name(obj, "WTCR12");
    state->u.e2.reg.wtcr13 = cm_object_get_child_by_name(obj, "WTCR13");
    state->u.e2.reg.wtcr20 = cm_object_get_child_by_name(obj, "WTCR20");
    state->u.e2.reg.wtcr21 = cm_object_get_child_by_name(obj, "WTCR21");
    state->u.e2.reg.wtsr = cm_object_get_child_by_name(obj, "WTSR");
    state->u.e2.reg.wtmir = cm_object_get_child_by_name(obj, "WTMIR");
    state->u.e2.reg.wthr = cm_object_get_child_by_name(obj, "WTHR");
    state->u.e2.reg.wtdr = cm_object_get_child_by_name(obj, "WTDR");
    state->u.e2.reg.wtdw = cm_object_get_child_by_name(obj, "WTDW");
    state->u.e2.reg.wtmor = cm_object_get_child_by_name(obj, "WTMOR");
    state->u.e2.reg.wtyr = cm_object_get_child_by_name(obj, "WTYR");
    state->u.e2.reg.almir = cm_object_get_child_by_name(obj, "ALMIR");
    state->u.e2.reg.alhr = cm_object_get_child_by_name(obj, "ALHR");
    state->u.e2.reg.aldr = cm_object_get_child_by_name(obj, "ALDR");
    state->u.e2.reg.almor = cm_object_get_child_by_name(obj, "ALMOR");
    state->u.e2.reg.alyr = cm_object_get_child_by_name(obj, "ALYR");
    state->u.e2.reg.wttr0 = cm_object_get_child_by_name(obj, "WTTR0");
    state->u.e2.reg.wttr1 = cm_object_get_child_by_name(obj, "WTTR1");
    state->u.e2.reg.wttr2 = cm_object_get_child_by_name(obj, "WTTR2");
    state->u.e2.reg.wtcal0 = cm_object_get_child_by_name(obj, "WTCAL0");
    state->u.e2.reg.wtcal1 = cm_object_get_child_by_name(obj, "WTCAL1");
    state->u.e2.reg.wtcalen = cm_object_get_child_by_name(obj, "WTCALEN");
    state->u.e2.reg.wtdiv = cm_object_get_child_by_name(obj, "WTDIV");
    state->u.e2.reg.wtdiven = cm_object_get_child_by_name(obj, "WTDIVEN");
    state->u.e2.reg.wtcalprd = cm_object_get_child_by_name(obj, "WTCALPRD");
    state->u.e2.reg.wtcosel = cm_object_get_child_by_name(obj, "WTCOSEL");
    state->u.e2.reg.vb_clkdiv = cm_object_get_child_by_name(obj, "VB_CLKDIV");
    state->u.e2.reg.wtosccnt = cm_object_get_child_by_name(obj, "WTOSCCNT");
    state->u.e2.reg.ccs = cm_object_get_child_by_name(obj, "CCS");
    state->u.e2.reg.ccb = cm_object_get_child_by_name(obj, "CCB");
    state->u.e2.reg.boost = cm_object_get_child_by_name(obj, "BOOST");
    state->u.e2.reg.ewkup = cm_object_get_child_by_name(obj, "EWKUP");
    state->u.e2.reg.vdet = cm_object_get_child_by_name(obj, "VDET");
    state->u.e2.reg.hibrst = cm_object_get_child_by_name(obj, "HIBRST");
    state->u.e2.reg.vbpfr = cm_object_get_child_by_name(obj, "VBPFR");
    state->u.e2.reg.vbpcr = cm_object_get_child_by_name(obj, "VBPCR");
    state->u.e2.reg.vbddr = cm_object_get_child_by_name(obj, "VBDDR");
    state->u.e2.reg.vbdir = cm_object_get_child_by_name(obj, "VBDIR");
    state->u.e2.reg.vbdor = cm_object_get_child_by_name(obj, "VBDOR");
    state->u.e2.reg.vbpzr = cm_object_get_child_by_name(obj, "VBPZR");
    state->u.e2.reg.breg00 = cm_object_get_child_by_name(obj, "BREG00");
    state->u.e2.reg.breg01 = cm_object_get_child_by_name(obj, "BREG01");
    state->u.e2.reg.breg02 = cm_object_get_child_by_name(obj, "BREG02");
    state->u.e2.reg.breg03 = cm_object_get_child_by_name(obj, "BREG03");
    state->u.e2.reg.breg04 = cm_object_get_child_by_name(obj, "BREG04");
    state->u.e2.reg.breg05 = cm_object_get_child_by_name(obj, "BREG05");
    state->u.e2.reg.breg06 = cm_object_get_child_by_name(obj, "BREG06");
    state->u.e2.reg.breg07 = cm_object_get_child_by_name(obj, "BREG07");
    state->u.e2.reg.breg08 = cm_object_get_child_by_name(obj, "BREG08");
    state->u.e2.reg.breg09 = cm_object_get_child_by_name(obj, "BREG09");
    state->u.e2.reg.breg0a = cm_object_get_child_by_name(obj, "BREG0A");
    state->u.e2.reg.breg0b = cm_object_get_child_by_name(obj, "BREG0B");
    state->u.e2.reg.breg0c = cm_object_get_child_by_name(obj, "BREG0C");
    state->u.e2.reg.breg0d = cm_object_get_child_by_name(obj, "BREG0D");
    state->u.e2.reg.breg0e = cm_object_get_child_by_name(obj, "BREG0E");
    state->u.e2.reg.breg0f = cm_object_get_child_by_name(obj, "BREG0F");
    state->u.e2.reg.breg10 = cm_object_get_child_by_name(obj, "BREG10");
    state->u.e2.reg.breg11 = cm_object_get_child_by_name(obj, "BREG11");
    state->u.e2.reg.breg12 = cm_object_get_child_by_name(obj, "BREG12");
    state->u.e2.reg.breg13 = cm_object_get_child_by_name(obj, "BREG13");
    state->u.e2.reg.breg14 = cm_object_get_child_by_name(obj, "BREG14");
    state->u.e2.reg.breg15 = cm_object_get_child_by_name(obj, "BREG15");
    state->u.e2.reg.breg16 = cm_object_get_child_by_name(obj, "BREG16");
    state->u.e2.reg.breg17 = cm_object_get_child_by_name(obj, "BREG17");
    state->u.e2.reg.breg18 = cm_object_get_child_by_name(obj, "BREG18");
    state->u.e2.reg.breg19 = cm_object_get_child_by_name(obj, "BREG19");
    state->u.e2.reg.breg1a = cm_object_get_child_by_name(obj, "BREG1A");
    state->u.e2.reg.breg1b = cm_object_get_child_by_name(obj, "BREG1B");
    state->u.e2.reg.breg1c = cm_object_get_child_by_name(obj, "BREG1C");
    state->u.e2.reg.breg1d = cm_object_get_child_by_name(obj, "BREG1D");
    state->u.e2.reg.breg1e = cm_object_get_child_by_name(obj, "BREG1E");
    state->u.e2.reg.breg1f = cm_object_get_child_by_name(obj, "BREG1F");
    state->u.e2.reg.breg20 = cm_object_get_child_by_name(obj, "BREG20");
    state->u.e2.reg.breg21 = cm_object_get_child_by_name(obj, "BREG21");
    state->u.e2.reg.breg22 = cm_object_get_child_by_name(obj, "BREG22");
    state->u.e2.reg.breg23 = cm_object_get_child_by_name(obj, "BREG23");
    state->u.e2.reg.breg24 = cm_object_get_child_by_name(obj, "BREG24");
    state->u.e2.reg.breg25 = cm_object_get_child_by_name(obj, "BREG25");
    state->u.e2.reg.breg26 = cm_object_get_child_by_name(obj, "BREG26");
    state->u.e2.reg.breg27 = cm_object_get_child_by_name(obj, "BREG27");
    state->u.e2.reg.breg28 = cm_object_get_child_by_name(obj, "BREG28");
    state->u.e2.reg.breg29 = cm_object_get_child_by_name(obj, "BREG29");
    state->u.e2.reg.breg2a = cm_object_get_child_by_name(obj, "BREG2A");
    state->u.e2.reg.breg2b = cm_object_get_child_by_name(obj, "BREG2B");
    state->u.e2.reg.breg2c = cm_object_get_child_by_name(obj, "BREG2C");
    state->u.e2.reg.breg2d = cm_object_get_child_by_name(obj, "BREG2D");
    state->u.e2.reg.breg2e = cm_object_get_child_by_name(obj, "BREG2E");
    state->u.e2.reg.breg2f = cm_object_get_child_by_name(obj, "BREG2F");
    state->u.e2.reg.breg30 = cm_object_get_child_by_name(obj, "BREG30");
    state->u.e2.reg.breg31 = cm_object_get_child_by_name(obj, "BREG31");
    state->u.e2.reg.breg32 = cm_object_get_child_by_name(obj, "BREG32");
    state->u.e2.reg.breg33 = cm_object_get_child_by_name(obj, "BREG33");
    state->u.e2.reg.breg34 = cm_object_get_child_by_name(obj, "BREG34");
    state->u.e2.reg.breg35 = cm_object_get_child_by_name(obj, "BREG35");
    state->u.e2.reg.breg36 = cm_object_get_child_by_name(obj, "BREG36");
    state->u.e2.reg.breg37 = cm_object_get_child_by_name(obj, "BREG37");
    state->u.e2.reg.breg38 = cm_object_get_child_by_name(obj, "BREG38");
    state->u.e2.reg.breg39 = cm_object_get_child_by_name(obj, "BREG39");
    state->u.e2.reg.breg3a = cm_object_get_child_by_name(obj, "BREG3A");
    state->u.e2.reg.breg3b = cm_object_get_child_by_name(obj, "BREG3B");
    state->u.e2.reg.breg3c = cm_object_get_child_by_name(obj, "BREG3C");
    state->u.e2.reg.breg3d = cm_object_get_child_by_name(obj, "BREG3D");
    state->u.e2.reg.breg3e = cm_object_get_child_by_name(obj, "BREG3E");
    state->u.e2.reg.breg3f = cm_object_get_child_by_name(obj, "BREG3F");
    state->u.e2.reg.breg40 = cm_object_get_child_by_name(obj, "BREG40");
    state->u.e2.reg.breg41 = cm_object_get_child_by_name(obj, "BREG41");
    state->u.e2.reg.breg42 = cm_object_get_child_by_name(obj, "BREG42");
    state->u.e2.reg.breg43 = cm_object_get_child_by_name(obj, "BREG43");
    state->u.e2.reg.breg44 = cm_object_get_child_by_name(obj, "BREG44");
    state->u.e2.reg.breg45 = cm_object_get_child_by_name(obj, "BREG45");
    state->u.e2.reg.breg46 = cm_object_get_child_by_name(obj, "BREG46");
    state->u.e2.reg.breg47 = cm_object_get_child_by_name(obj, "BREG47");
    state->u.e2.reg.breg48 = cm_object_get_child_by_name(obj, "BREG48");
    state->u.e2.reg.breg49 = cm_object_get_child_by_name(obj, "BREG49");
    state->u.e2.reg.breg4a = cm_object_get_child_by_name(obj, "BREG4A");
    state->u.e2.reg.breg4b = cm_object_get_child_by_name(obj, "BREG4B");
    state->u.e2.reg.breg4c = cm_object_get_child_by_name(obj, "BREG4C");
    state->u.e2.reg.breg4d = cm_object_get_child_by_name(obj, "BREG4D");
    state->u.e2.reg.breg4e = cm_object_get_child_by_name(obj, "BREG4E");
    state->u.e2.reg.breg4f = cm_object_get_child_by_name(obj, "BREG4F");
    state->u.e2.reg.breg50 = cm_object_get_child_by_name(obj, "BREG50");
    state->u.e2.reg.breg51 = cm_object_get_child_by_name(obj, "BREG51");
    state->u.e2.reg.breg52 = cm_object_get_child_by_name(obj, "BREG52");
    state->u.e2.reg.breg53 = cm_object_get_child_by_name(obj, "BREG53");
    state->u.e2.reg.breg54 = cm_object_get_child_by_name(obj, "BREG54");
    state->u.e2.reg.breg55 = cm_object_get_child_by_name(obj, "BREG55");
    state->u.e2.reg.breg56 = cm_object_get_child_by_name(obj, "BREG56");
    state->u.e2.reg.breg57 = cm_object_get_child_by_name(obj, "BREG57");
    state->u.e2.reg.breg58 = cm_object_get_child_by_name(obj, "BREG58");
    state->u.e2.reg.breg59 = cm_object_get_child_by_name(obj, "BREG59");
    state->u.e2.reg.breg5a = cm_object_get_child_by_name(obj, "BREG5A");
    state->u.e2.reg.breg5b = cm_object_get_child_by_name(obj, "BREG5B");
    state->u.e2.reg.breg5c = cm_object_get_child_by_name(obj, "BREG5C");
    state->u.e2.reg.breg5d = cm_object_get_child_by_name(obj, "BREG5D");
    state->u.e2.reg.breg5e = cm_object_get_child_by_name(obj, "BREG5E");
    state->u.e2.reg.breg5f = cm_object_get_child_by_name(obj, "BREG5F");
    state->u.e2.reg.breg60 = cm_object_get_child_by_name(obj, "BREG60");
    state->u.e2.reg.breg61 = cm_object_get_child_by_name(obj, "BREG61");
    state->u.e2.reg.breg62 = cm_object_get_child_by_name(obj, "BREG62");
    state->u.e2.reg.breg63 = cm_object_get_child_by_name(obj, "BREG63");
    state->u.e2.reg.breg64 = cm_object_get_child_by_name(obj, "BREG64");
    state->u.e2.reg.breg65 = cm_object_get_child_by_name(obj, "BREG65");
    state->u.e2.reg.breg66 = cm_object_get_child_by_name(obj, "BREG66");
    state->u.e2.reg.breg67 = cm_object_get_child_by_name(obj, "BREG67");
    state->u.e2.reg.breg68 = cm_object_get_child_by_name(obj, "BREG68");
    state->u.e2.reg.breg69 = cm_object_get_child_by_name(obj, "BREG69");
    state->u.e2.reg.breg6a = cm_object_get_child_by_name(obj, "BREG6A");
    state->u.e2.reg.breg6b = cm_object_get_child_by_name(obj, "BREG6B");
    state->u.e2.reg.breg6c = cm_object_get_child_by_name(obj, "BREG6C");
    state->u.e2.reg.breg6d = cm_object_get_child_by_name(obj, "BREG6D");
    state->u.e2.reg.breg6e = cm_object_get_child_by_name(obj, "BREG6E");
    state->u.e2.reg.breg6f = cm_object_get_child_by_name(obj, "BREG6F");
    state->u.e2.reg.breg70 = cm_object_get_child_by_name(obj, "BREG70");
    state->u.e2.reg.breg71 = cm_object_get_child_by_name(obj, "BREG71");
    state->u.e2.reg.breg72 = cm_object_get_child_by_name(obj, "BREG72");
    state->u.e2.reg.breg73 = cm_object_get_child_by_name(obj, "BREG73");
    state->u.e2.reg.breg74 = cm_object_get_child_by_name(obj, "BREG74");
    state->u.e2.reg.breg75 = cm_object_get_child_by_name(obj, "BREG75");
    state->u.e2.reg.breg76 = cm_object_get_child_by_name(obj, "BREG76");
    state->u.e2.reg.breg77 = cm_object_get_child_by_name(obj, "BREG77");
    state->u.e2.reg.breg78 = cm_object_get_child_by_name(obj, "BREG78");
    state->u.e2.reg.breg79 = cm_object_get_child_by_name(obj, "BREG79");
    state->u.e2.reg.breg7a = cm_object_get_child_by_name(obj, "BREG7A");
    state->u.e2.reg.breg7b = cm_object_get_child_by_name(obj, "BREG7B");
    state->u.e2.reg.breg7c = cm_object_get_child_by_name(obj, "BREG7C");
    state->u.e2.reg.breg7d = cm_object_get_child_by_name(obj, "BREG7D");
    state->u.e2.reg.breg7e = cm_object_get_child_by_name(obj, "BREG7E");
    state->u.e2.reg.breg7f = cm_object_get_child_by_name(obj, "BREG7F");

    // WTCR10bitfields.
    state->u.e2.fld.wtcr10.st = cm_object_get_child_by_name(state->u.e2.reg.wtcr10, "ST");
    state->u.e2.fld.wtcr10.run = cm_object_get_child_by_name(state->u.e2.reg.wtcr10, "RUN");
    state->u.e2.fld.wtcr10.srst = cm_object_get_child_by_name(state->u.e2.reg.wtcr10, "SRST");
    state->u.e2.fld.wtcr10.scst = cm_object_get_child_by_name(state->u.e2.reg.wtcr10, "SCST");
    state->u.e2.fld.wtcr10.scrst = cm_object_get_child_by_name(state->u.e2.reg.wtcr10, "SCRST");
    state->u.e2.fld.wtcr10.busy = cm_object_get_child_by_name(state->u.e2.reg.wtcr10, "BUSY");
    state->u.e2.fld.wtcr10.trans = cm_object_get_child_by_name(state->u.e2.reg.wtcr10, "TRANS");

    // WTCR11bitfields.
    state->u.e2.fld.wtcr11.mien = cm_object_get_child_by_name(state->u.e2.reg.wtcr11, "MIEN");
    state->u.e2.fld.wtcr11.hen = cm_object_get_child_by_name(state->u.e2.reg.wtcr11, "HEN");
    state->u.e2.fld.wtcr11.den = cm_object_get_child_by_name(state->u.e2.reg.wtcr11, "DEN");
    state->u.e2.fld.wtcr11.moen = cm_object_get_child_by_name(state->u.e2.reg.wtcr11, "MOEN");
    state->u.e2.fld.wtcr11.yen = cm_object_get_child_by_name(state->u.e2.reg.wtcr11, "YEN");

    // WTCR12bitfields.
    state->u.e2.fld.wtcr12.intssi = cm_object_get_child_by_name(state->u.e2.reg.wtcr12, "INTSSI");
    state->u.e2.fld.wtcr12.intsi = cm_object_get_child_by_name(state->u.e2.reg.wtcr12, "INTSI");
    state->u.e2.fld.wtcr12.intmi = cm_object_get_child_by_name(state->u.e2.reg.wtcr12, "INTMI");
    state->u.e2.fld.wtcr12.inthi = cm_object_get_child_by_name(state->u.e2.reg.wtcr12, "INTHI");
    state->u.e2.fld.wtcr12.inttmi = cm_object_get_child_by_name(state->u.e2.reg.wtcr12, "INTTMI");
    state->u.e2.fld.wtcr12.intali = cm_object_get_child_by_name(state->u.e2.reg.wtcr12, "INTALI");
    state->u.e2.fld.wtcr12.interi = cm_object_get_child_by_name(state->u.e2.reg.wtcr12, "INTERI");
    state->u.e2.fld.wtcr12.intcri = cm_object_get_child_by_name(state->u.e2.reg.wtcr12, "INTCRI");

    // WTCR13bitfields.
    state->u.e2.fld.wtcr13.intssie = cm_object_get_child_by_name(state->u.e2.reg.wtcr13, "INTSSIE");
    state->u.e2.fld.wtcr13.intsie = cm_object_get_child_by_name(state->u.e2.reg.wtcr13, "INTSIE");
    state->u.e2.fld.wtcr13.intmie = cm_object_get_child_by_name(state->u.e2.reg.wtcr13, "INTMIE");
    state->u.e2.fld.wtcr13.inthie = cm_object_get_child_by_name(state->u.e2.reg.wtcr13, "INTHIE");
    state->u.e2.fld.wtcr13.inttmie = cm_object_get_child_by_name(state->u.e2.reg.wtcr13, "INTTMIE");
    state->u.e2.fld.wtcr13.intalie = cm_object_get_child_by_name(state->u.e2.reg.wtcr13, "INTALIE");
    state->u.e2.fld.wtcr13.interie = cm_object_get_child_by_name(state->u.e2.reg.wtcr13, "INTERIE");
    state->u.e2.fld.wtcr13.intcrie = cm_object_get_child_by_name(state->u.e2.reg.wtcr13, "INTCRIE");

    // WTCR20bitfields.
    state->u.e2.fld.wtcr20.cread = cm_object_get_child_by_name(state->u.e2.reg.wtcr20, "CREAD");
    state->u.e2.fld.wtcr20.cwrite = cm_object_get_child_by_name(state->u.e2.reg.wtcr20, "CWRITE");
    state->u.e2.fld.wtcr20.bread = cm_object_get_child_by_name(state->u.e2.reg.wtcr20, "BREAD");
    state->u.e2.fld.wtcr20.bwrite = cm_object_get_child_by_name(state->u.e2.reg.wtcr20, "BWRITE");
    state->u.e2.fld.wtcr20.pread = cm_object_get_child_by_name(state->u.e2.reg.wtcr20, "PREAD");
    state->u.e2.fld.wtcr20.pwrite = cm_object_get_child_by_name(state->u.e2.reg.wtcr20, "PWRITE");

    // WTCR21bitfields.
    state->u.e2.fld.wtcr21.tmst = cm_object_get_child_by_name(state->u.e2.reg.wtcr21, "TMST");
    state->u.e2.fld.wtcr21.tmen = cm_object_get_child_by_name(state->u.e2.reg.wtcr21, "TMEN");
    state->u.e2.fld.wtcr21.tmrun = cm_object_get_child_by_name(state->u.e2.reg.wtcr21, "TMRUN");

    // WTSRbitfields.
    state->u.e2.fld.wtsr.s = cm_object_get_child_by_name(state->u.e2.reg.wtsr, "S");
    state->u.e2.fld.wtsr.ts = cm_object_get_child_by_name(state->u.e2.reg.wtsr, "TS");

    // WTMIRbitfields.
    state->u.e2.fld.wtmir.mi = cm_object_get_child_by_name(state->u.e2.reg.wtmir, "MI");
    state->u.e2.fld.wtmir.tmi = cm_object_get_child_by_name(state->u.e2.reg.wtmir, "TMI");

    // WTHRbitfields.
    state->u.e2.fld.wthr.h = cm_object_get_child_by_name(state->u.e2.reg.wthr, "H");
    state->u.e2.fld.wthr.th = cm_object_get_child_by_name(state->u.e2.reg.wthr, "TH");

    // WTDRbitfields.
    state->u.e2.fld.wtdr.d = cm_object_get_child_by_name(state->u.e2.reg.wtdr, "D");
    state->u.e2.fld.wtdr.td = cm_object_get_child_by_name(state->u.e2.reg.wtdr, "TD");

    // WTDWbitfields.
    state->u.e2.fld.wtdw.dw = cm_object_get_child_by_name(state->u.e2.reg.wtdw, "DW");

    // WTMORbitfields.
    state->u.e2.fld.wtmor.mo = cm_object_get_child_by_name(state->u.e2.reg.wtmor, "MO");
    state->u.e2.fld.wtmor.tmo0 = cm_object_get_child_by_name(state->u.e2.reg.wtmor, "TMO0");

    // WTYRbitfields.
    state->u.e2.fld.wtyr.y = cm_object_get_child_by_name(state->u.e2.reg.wtyr, "Y");
    state->u.e2.fld.wtyr.ty = cm_object_get_child_by_name(state->u.e2.reg.wtyr, "TY");

    // ALMIRbitfields.
    state->u.e2.fld.almir.ami = cm_object_get_child_by_name(state->u.e2.reg.almir, "AMI");
    state->u.e2.fld.almir.tami = cm_object_get_child_by_name(state->u.e2.reg.almir, "TAMI");

    // ALHRbitfields.
    state->u.e2.fld.alhr.ah = cm_object_get_child_by_name(state->u.e2.reg.alhr, "AH");
    state->u.e2.fld.alhr.tah = cm_object_get_child_by_name(state->u.e2.reg.alhr, "TAH");

    // ALDRbitfields.
    state->u.e2.fld.aldr.ad = cm_object_get_child_by_name(state->u.e2.reg.aldr, "AD");
    state->u.e2.fld.aldr.tad = cm_object_get_child_by_name(state->u.e2.reg.aldr, "TAD");

    // ALMORbitfields.
    state->u.e2.fld.almor.amo = cm_object_get_child_by_name(state->u.e2.reg.almor, "AMO");
    state->u.e2.fld.almor.tamo0 = cm_object_get_child_by_name(state->u.e2.reg.almor, "TAMO0");

    // ALYRbitfields.
    state->u.e2.fld.alyr.ay = cm_object_get_child_by_name(state->u.e2.reg.alyr, "AY");
    state->u.e2.fld.alyr.tay = cm_object_get_child_by_name(state->u.e2.reg.alyr, "TAY");

    // WTTR0bitfields.
    state->u.e2.fld.wttr0.tm = cm_object_get_child_by_name(state->u.e2.reg.wttr0, "TM");

    // WTTR1bitfields.
    state->u.e2.fld.wttr1.tm = cm_object_get_child_by_name(state->u.e2.reg.wttr1, "TM");

    // WTTR2bitfields.
    state->u.e2.fld.wttr2.tm = cm_object_get_child_by_name(state->u.e2.reg.wttr2, "TM");

    // WTCAL0bitfields.
    state->u.e2.fld.wtcal0.wtcal0 = cm_object_get_child_by_name(state->u.e2.reg.wtcal0, "WTCAL0");

    // WTCAL1bitfields.
    state->u.e2.fld.wtcal1.wtcal1 = cm_object_get_child_by_name(state->u.e2.reg.wtcal1, "WTCAL1");

    // WTCALENbitfields.
    state->u.e2.fld.wtcalen.wtcalen = cm_object_get_child_by_name(state->u.e2.reg.wtcalen, "WTCALEN");

    // WTDIVbitfields.
    state->u.e2.fld.wtdiv.wtdiv = cm_object_get_child_by_name(state->u.e2.reg.wtdiv, "WTDIV");

    // WTDIVENbitfields.
    state->u.e2.fld.wtdiven.wtdiven = cm_object_get_child_by_name(state->u.e2.reg.wtdiven, "WTDIVEN");
    state->u.e2.fld.wtdiven.wtdivrdy = cm_object_get_child_by_name(state->u.e2.reg.wtdiven, "WTDIVRDY");

    // WTCALPRDbitfields.
    state->u.e2.fld.wtcalprd.wtcalprd = cm_object_get_child_by_name(state->u.e2.reg.wtcalprd, "WTCALPRD");

    // WTCOSELbitfields.
    state->u.e2.fld.wtcosel.wtcosel = cm_object_get_child_by_name(state->u.e2.reg.wtcosel, "WTCOSEL");

    // VB_CLKDIVbitfields.
    state->u.e2.fld.vb_clkdiv.div = cm_object_get_child_by_name(state->u.e2.reg.vb_clkdiv, "DIV");

    // WTOSCCNTbitfields.
    state->u.e2.fld.wtosccnt.soscex = cm_object_get_child_by_name(state->u.e2.reg.wtosccnt, "SOSCEX");
    state->u.e2.fld.wtosccnt.soscntl = cm_object_get_child_by_name(state->u.e2.reg.wtosccnt, "SOSCNTL");

    // CCSbitfields.
    state->u.e2.fld.ccs.ccs = cm_object_get_child_by_name(state->u.e2.reg.ccs, "CCS");

    // CCBbitfields.
    state->u.e2.fld.ccb.ccb = cm_object_get_child_by_name(state->u.e2.reg.ccb, "CCB");

    // BOOSTbitfields.
    state->u.e2.fld.boost.boost = cm_object_get_child_by_name(state->u.e2.reg.boost, "BOOST");

    // EWKUPbitfields.
    state->u.e2.fld.ewkup.wup0 = cm_object_get_child_by_name(state->u.e2.reg.ewkup, "WUP0");

    // VDETbitfields.
    state->u.e2.fld.vdet.pon = cm_object_get_child_by_name(state->u.e2.reg.vdet, "PON");

    // HIBRSTbitfields.
    state->u.e2.fld.hibrst.hibrst = cm_object_get_child_by_name(state->u.e2.reg.hibrst, "HIBRST");

    // VBPFRbitfields.
    state->u.e2.fld.vbpfr.vpfr0 = cm_object_get_child_by_name(state->u.e2.reg.vbpfr, "VPFR0");
    state->u.e2.fld.vbpfr.vpfr1 = cm_object_get_child_by_name(state->u.e2.reg.vbpfr, "VPFR1");
    state->u.e2.fld.vbpfr.vpfr2 = cm_object_get_child_by_name(state->u.e2.reg.vbpfr, "VPFR2");
    state->u.e2.fld.vbpfr.vpfr3 = cm_object_get_child_by_name(state->u.e2.reg.vbpfr, "VPFR3");
    state->u.e2.fld.vbpfr.spsr = cm_object_get_child_by_name(state->u.e2.reg.vbpfr, "SPSR");

    // VBPCRbitfields.
    state->u.e2.fld.vbpcr.vpcr0 = cm_object_get_child_by_name(state->u.e2.reg.vbpcr, "VPCR0");
    state->u.e2.fld.vbpcr.vpcr1 = cm_object_get_child_by_name(state->u.e2.reg.vbpcr, "VPCR1");
    state->u.e2.fld.vbpcr.vpcr2 = cm_object_get_child_by_name(state->u.e2.reg.vbpcr, "VPCR2");
    state->u.e2.fld.vbpcr.vpcr3 = cm_object_get_child_by_name(state->u.e2.reg.vbpcr, "VPCR3");

    // VBDDRbitfields.
    state->u.e2.fld.vbddr.vddr0 = cm_object_get_child_by_name(state->u.e2.reg.vbddr, "VDDR0");
    state->u.e2.fld.vbddr.vddr1 = cm_object_get_child_by_name(state->u.e2.reg.vbddr, "VDDR1");
    state->u.e2.fld.vbddr.vddr2 = cm_object_get_child_by_name(state->u.e2.reg.vbddr, "VDDR2");
    state->u.e2.fld.vbddr.vddr3 = cm_object_get_child_by_name(state->u.e2.reg.vbddr, "VDDR3");

    // VBDIRbitfields.
    state->u.e2.fld.vbdir.vdir0 = cm_object_get_child_by_name(state->u.e2.reg.vbdir, "VDIR0");
    state->u.e2.fld.vbdir.vdir1 = cm_object_get_child_by_name(state->u.e2.reg.vbdir, "VDIR1");
    state->u.e2.fld.vbdir.vdir2 = cm_object_get_child_by_name(state->u.e2.reg.vbdir, "VDIR2");
    state->u.e2.fld.vbdir.vdir3 = cm_object_get_child_by_name(state->u.e2.reg.vbdir, "VDIR3");

    // VBDORbitfields.
    state->u.e2.fld.vbdor.vdor0 = cm_object_get_child_by_name(state->u.e2.reg.vbdor, "VDOR0");
    state->u.e2.fld.vbdor.vdor1 = cm_object_get_child_by_name(state->u.e2.reg.vbdor, "VDOR1");
    state->u.e2.fld.vbdor.vdor2 = cm_object_get_child_by_name(state->u.e2.reg.vbdor, "VDOR2");
    state->u.e2.fld.vbdor.vdor3 = cm_object_get_child_by_name(state->u.e2.reg.vbdor, "VDOR3");

    // VBPZRbitfields.
    state->u.e2.fld.vbpzr.vpzr0 = cm_object_get_child_by_name(state->u.e2.reg.vbpzr, "VPZR0");
    state->u.e2.fld.vbpzr.vpzr1 = cm_object_get_child_by_name(state->u.e2.reg.vbpzr, "VPZR1");

    // BREG00bitfields.

    // BREG01bitfields.

    // BREG02bitfields.

    // BREG03bitfields.

    // BREG04bitfields.

    // BREG05bitfields.

    // BREG06bitfields.

    // BREG07bitfields.

    // BREG08bitfields.

    // BREG09bitfields.

    // BREG0Abitfields.

    // BREG0Bbitfields.

    // BREG0Cbitfields.

    // BREG0Dbitfields.

    // BREG0Ebitfields.

    // BREG0Fbitfields.

    // BREG10bitfields.

    // BREG11bitfields.

    // BREG12bitfields.

    // BREG13bitfields.

    // BREG14bitfields.

    // BREG15bitfields.

    // BREG16bitfields.

    // BREG17bitfields.

    // BREG18bitfields.

    // BREG19bitfields.

    // BREG1Abitfields.

    // BREG1Bbitfields.

    // BREG1Cbitfields.

    // BREG1Dbitfields.

    // BREG1Ebitfields.

    // BREG1Fbitfields.

    // BREG20bitfields.

    // BREG21bitfields.

    // BREG22bitfields.

    // BREG23bitfields.

    // BREG24bitfields.

    // BREG25bitfields.

    // BREG26bitfields.

    // BREG27bitfields.

    // BREG28bitfields.

    // BREG29bitfields.

    // BREG2Abitfields.

    // BREG2Bbitfields.

    // BREG2Cbitfields.

    // BREG2Dbitfields.

    // BREG2Ebitfields.

    // BREG2Fbitfields.

    // BREG30bitfields.

    // BREG31bitfields.

    // BREG32bitfields.

    // BREG33bitfields.

    // BREG34bitfields.

    // BREG35bitfields.

    // BREG36bitfields.

    // BREG37bitfields.

    // BREG38bitfields.

    // BREG39bitfields.

    // BREG3Abitfields.

    // BREG3Bbitfields.

    // BREG3Cbitfields.

    // BREG3Dbitfields.

    // BREG3Ebitfields.

    // BREG3Fbitfields.

    // BREG40bitfields.

    // BREG41bitfields.

    // BREG42bitfields.

    // BREG43bitfields.

    // BREG44bitfields.

    // BREG45bitfields.

    // BREG46bitfields.

    // BREG47bitfields.

    // BREG48bitfields.

    // BREG49bitfields.

    // BREG4Abitfields.

    // BREG4Bbitfields.

    // BREG4Cbitfields.

    // BREG4Dbitfields.

    // BREG4Ebitfields.

    // BREG4Fbitfields.

    // BREG50bitfields.

    // BREG51bitfields.

    // BREG52bitfields.

    // BREG53bitfields.

    // BREG54bitfields.

    // BREG55bitfields.

    // BREG56bitfields.

    // BREG57bitfields.

    // BREG58bitfields.

    // BREG59bitfields.

    // BREG5Abitfields.

    // BREG5Bbitfields.

    // BREG5Cbitfields.

    // BREG5Dbitfields.

    // BREG5Ebitfields.

    // BREG5Fbitfields.

    // BREG60bitfields.

    // BREG61bitfields.

    // BREG62bitfields.

    // BREG63bitfields.

    // BREG64bitfields.

    // BREG65bitfields.

    // BREG66bitfields.

    // BREG67bitfields.

    // BREG68bitfields.

    // BREG69bitfields.

    // BREG6Abitfields.

    // BREG6Bbitfields.

    // BREG6Cbitfields.

    // BREG6Dbitfields.

    // BREG6Ebitfields.

    // BREG6Fbitfields.

    // BREG70bitfields.

    // BREG71bitfields.

    // BREG72bitfields.

    // BREG73bitfields.

    // BREG74bitfields.

    // BREG75bitfields.

    // BREG76bitfields.

    // BREG77bitfields.

    // BREG78bitfields.

    // BREG79bitfields.

    // BREG7Abitfields.

    // BREG7Bbitfields.

    // BREG7Cbitfields.

    // BREG7Dbitfields.

    // BREG7Ebitfields.

    // BREG7Fbitfields.
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// ----- Private --------------------------------------------------------------

#if 0
static peripheral_register_t fm4_rtc_xxx_pre_write_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    FM4RTCState *state = FM4_RTC_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);

    // TODO: Add code to adjust the value (like applying some masks,
    // for example prevent setting interrupts not enabled).
    // Also process cleared/set by write 1/0 bits.
    // The returned value will be stored in the register value.

    return full_value;
}

static void fm4_rtc_xxx_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    FM4RTCState *state = FM4_RTC_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);
    // The new register value is full_value, the old one is prev_value.

    // TODO: Add code to send the value to the consumer.
}

static peripheral_register_t fm4_rtc_xxx_pre_read_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size)
{
    FM4RTCState *state = FM4_RTC_STATE(periph);

    peripheral_register_t value = 0;

    // Add code to get the value from the producer, and return it.

    // This value, possibly masked, will be stored in the register
    // and returned when the register is read.
    return value;
}

static void fm4_rtc_xxx_post_read_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size)
{
    FM4RTCState *state = FM4_RTC_STATE(periph);

    peripheral_register_t value = peripheral_register_get_raw_value(reg);

    // TODO: add code to perform the post read actions, like clearing some bits.
}
#endif

// ----------------------------------------------------------------------------

// TODO: remove this if the peripheral is always enabled.
static bool fm4_rtc_is_enabled(Object *obj)
{
    FM4RTCState *state = FM4_RTC_STATE(obj);

    if (register_bitfield_is_non_zero(state->enabling_bit))
    {
        return true; // Positive logic, bit == 1 means enabled.
    }

    // Not enabled
    return false;
}

static void fm4_rtc_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    FM4RTCState *state = FM4_RTC_STATE(obj);

    // Capabilities are not yet available.

    // TODO: remove this if the peripheral is always enabled.
    state->enabling_bit = NULL;

    // TODO: Add code to initialise all members.
}

static void fm4_rtc_realize_callback(DeviceState *dev, Error **errp)
{
    printf("742 fm4_rtc_realize_callback\n");
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_FM4_RTC))
    {
        return;
    }

    FM4MCUState *mcu = fm4_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    FM4RTCState *state = FM4_RTC_STATE(dev);
    // First thing first: get capabilities from MCU, needed everywhere.
    state->capabilities = mcu->capabilities;

    // Also keep a local pointer, to access them easier.
    const FM4Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    const char *periph_name = "RTC";

    svd_set_peripheral_address_block(cm_state->svd_json, periph_name, obj);
    peripheral_create_memory_region(obj);

    // TODO: remove this if the peripheral is always enabled.
    //  char enabling_bit_name[FM4_RCC_SIZEOF_ENABLING_BITFIELD];

    printf("771 fm4_rtc_realize_callback\n");
    fm4s6e2cc_rtc_create_objects(obj, cm_state->svd_json, periph_name);
    printf("773 fm4_rtc_realize_callback\n");
    // TODO: add actions.
    // cm_object_property_set_str(state->u.e2.fld.xxx.fff, "GGG", "follows");
    // cm_object_property_set_str(state->u.e2.fld.xxx.fff, "GGG", "cleared-by");

    // TODO: add callbacks.
    // peripheral_register_set_pre_read(state->e2.reg.xxx, &fm4_rtc_xxx_pre_read_callback);
    // peripheral_register_set_post_read(state->e2.reg.xxx, &fm4_rtc_xxx_post_read_callback);
    // peripheral_register_set_pre_read(state->e2.reg.xxx, &fm4_rtc_xxx_pret_read_callback);
    // peripheral_register_set_post_write(state->e2.reg.xxx, &fm4_rtc_xxx_post_write_callback);

    // TODO: add interrupts.

    // TODO: remove this if the peripheral is always enabled.
    /*  snprintf(enabling_bit_name, sizeof(enabling_bit_name) - 1,
                DEVICE_PATH_FM4_RCC "/AHB1ENR/RTCEN");

 

    // TODO: remove this if the peripheral is always enabled.
    state->enabling_bit = OBJECT(cm_device_by_name(enabling_bit_name));
*/
    peripheral_prepare_registers(obj); //stop here
    printf("796 fm4_rtc_realize_callback\n");
}

static void fm4_rtc_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset(); this will reset all children registers.
    cm_device_parent_reset(dev, TYPE_FM4_RTC);
}

static void fm4_rtc_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = fm4_rtc_reset_callback;
    dc->realize = fm4_rtc_realize_callback;

    // TODO: remove this if the peripheral is always enabled.
    PeripheralClass *per_class = PERIPHERAL_CLASS(klass);
    per_class->is_enabled = fm4_rtc_is_enabled;
}

static const TypeInfo fm4_rtc_type_info = {
    .name = TYPE_FM4_RTC,
    .parent = TYPE_FM4_RTC_PARENT,
    .instance_init = fm4_rtc_instance_init_callback,
    .instance_size = sizeof(FM4RTCState),
    .class_init = fm4_rtc_class_init_callback,
    .class_size = sizeof(FM4RTCClass)};

static void fm4_rtc_register_types(void)
{
    type_register_static(&fm4_rtc_type_info);
}

type_init(fm4_rtc_register_types);

// ----------------------------------------------------------------------------
