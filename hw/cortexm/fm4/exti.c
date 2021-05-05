/*
 * FM4- EXTI(External Interrupt and NMI Control) emulation.
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

#include <hw/cortexm/fm4/exti.h>
#include <hw/cortexm/fm4/mcu.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>

// ----- Generated code -------------------------------------------------------
//
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void fm4s6e2cc_exti_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
    FM4EXTIState *state = FM4_EXTI_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers.
    state->u.e2.reg.enir = cm_object_get_child_by_name(obj, "ENIR");
    state->u.e2.reg.eirr = cm_object_get_child_by_name(obj, "EIRR");
    state->u.e2.reg.eicl = cm_object_get_child_by_name(obj, "EICL");
    state->u.e2.reg.elvr = cm_object_get_child_by_name(obj, "ELVR");
    state->u.e2.reg.elvr1 = cm_object_get_child_by_name(obj, "ELVR1");
    state->u.e2.reg.nmirr = cm_object_get_child_by_name(obj, "NMIRR");
    state->u.e2.reg.nmicl = cm_object_get_child_by_name(obj, "NMICL");

    // ENIRbitfields.
    state->u.e2.fld.enir.en0 = cm_object_get_child_by_name(state->u.e2.reg.enir, "EN0");
    state->u.e2.fld.enir.en1 = cm_object_get_child_by_name(state->u.e2.reg.enir, "EN1");
    state->u.e2.fld.enir.en2 = cm_object_get_child_by_name(state->u.e2.reg.enir, "EN2");
    state->u.e2.fld.enir.en3 = cm_object_get_child_by_name(state->u.e2.reg.enir, "EN3");
    state->u.e2.fld.enir.en4 = cm_object_get_child_by_name(state->u.e2.reg.enir, "EN4");
    state->u.e2.fld.enir.en5 = cm_object_get_child_by_name(state->u.e2.reg.enir, "EN5");
    state->u.e2.fld.enir.en6 = cm_object_get_child_by_name(state->u.e2.reg.enir, "EN6");
    state->u.e2.fld.enir.en7 = cm_object_get_child_by_name(state->u.e2.reg.enir, "EN7");
    state->u.e2.fld.enir.en8 = cm_object_get_child_by_name(state->u.e2.reg.enir, "EN8");
    state->u.e2.fld.enir.en9 = cm_object_get_child_by_name(state->u.e2.reg.enir, "EN9");
    state->u.e2.fld.enir.en10 = cm_object_get_child_by_name(state->u.e2.reg.enir, "EN10");
    state->u.e2.fld.enir.en11 = cm_object_get_child_by_name(state->u.e2.reg.enir, "EN11");
    state->u.e2.fld.enir.en12 = cm_object_get_child_by_name(state->u.e2.reg.enir, "EN12");
    state->u.e2.fld.enir.en13 = cm_object_get_child_by_name(state->u.e2.reg.enir, "EN13");
    state->u.e2.fld.enir.en14 = cm_object_get_child_by_name(state->u.e2.reg.enir, "EN14");
    state->u.e2.fld.enir.en15 = cm_object_get_child_by_name(state->u.e2.reg.enir, "EN15");
    state->u.e2.fld.enir.en16 = cm_object_get_child_by_name(state->u.e2.reg.enir, "EN16");
    state->u.e2.fld.enir.en17 = cm_object_get_child_by_name(state->u.e2.reg.enir, "EN17");
    state->u.e2.fld.enir.en18 = cm_object_get_child_by_name(state->u.e2.reg.enir, "EN18");
    state->u.e2.fld.enir.en19 = cm_object_get_child_by_name(state->u.e2.reg.enir, "EN19");
    state->u.e2.fld.enir.en20 = cm_object_get_child_by_name(state->u.e2.reg.enir, "EN20");
    state->u.e2.fld.enir.en21 = cm_object_get_child_by_name(state->u.e2.reg.enir, "EN21");
    state->u.e2.fld.enir.en22 = cm_object_get_child_by_name(state->u.e2.reg.enir, "EN22");
    state->u.e2.fld.enir.en23 = cm_object_get_child_by_name(state->u.e2.reg.enir, "EN23");
    state->u.e2.fld.enir.en24 = cm_object_get_child_by_name(state->u.e2.reg.enir, "EN24");
    state->u.e2.fld.enir.en25 = cm_object_get_child_by_name(state->u.e2.reg.enir, "EN25");
    state->u.e2.fld.enir.en26 = cm_object_get_child_by_name(state->u.e2.reg.enir, "EN26");
    state->u.e2.fld.enir.en27 = cm_object_get_child_by_name(state->u.e2.reg.enir, "EN27");
    state->u.e2.fld.enir.en28 = cm_object_get_child_by_name(state->u.e2.reg.enir, "EN28");
    state->u.e2.fld.enir.en29 = cm_object_get_child_by_name(state->u.e2.reg.enir, "EN29");
    state->u.e2.fld.enir.en30 = cm_object_get_child_by_name(state->u.e2.reg.enir, "EN30");
    state->u.e2.fld.enir.en31 = cm_object_get_child_by_name(state->u.e2.reg.enir, "EN31");

    // EIRRbitfields.
    state->u.e2.fld.eirr.er0 = cm_object_get_child_by_name(state->u.e2.reg.eirr, "ER0");
    state->u.e2.fld.eirr.er1 = cm_object_get_child_by_name(state->u.e2.reg.eirr, "ER1");
    state->u.e2.fld.eirr.er2 = cm_object_get_child_by_name(state->u.e2.reg.eirr, "ER2");
    state->u.e2.fld.eirr.er3 = cm_object_get_child_by_name(state->u.e2.reg.eirr, "ER3");
    state->u.e2.fld.eirr.er4 = cm_object_get_child_by_name(state->u.e2.reg.eirr, "ER4");
    state->u.e2.fld.eirr.er5 = cm_object_get_child_by_name(state->u.e2.reg.eirr, "ER5");
    state->u.e2.fld.eirr.er6 = cm_object_get_child_by_name(state->u.e2.reg.eirr, "ER6");
    state->u.e2.fld.eirr.er7 = cm_object_get_child_by_name(state->u.e2.reg.eirr, "ER7");
    state->u.e2.fld.eirr.er8 = cm_object_get_child_by_name(state->u.e2.reg.eirr, "ER8");
    state->u.e2.fld.eirr.er9 = cm_object_get_child_by_name(state->u.e2.reg.eirr, "ER9");
    state->u.e2.fld.eirr.er10 = cm_object_get_child_by_name(state->u.e2.reg.eirr, "ER10");
    state->u.e2.fld.eirr.er11 = cm_object_get_child_by_name(state->u.e2.reg.eirr, "ER11");
    state->u.e2.fld.eirr.er12 = cm_object_get_child_by_name(state->u.e2.reg.eirr, "ER12");
    state->u.e2.fld.eirr.er13 = cm_object_get_child_by_name(state->u.e2.reg.eirr, "ER13");
    state->u.e2.fld.eirr.er14 = cm_object_get_child_by_name(state->u.e2.reg.eirr, "ER14");
    state->u.e2.fld.eirr.er15 = cm_object_get_child_by_name(state->u.e2.reg.eirr, "ER15");
    state->u.e2.fld.eirr.er16 = cm_object_get_child_by_name(state->u.e2.reg.eirr, "ER16");
    state->u.e2.fld.eirr.er17 = cm_object_get_child_by_name(state->u.e2.reg.eirr, "ER17");
    state->u.e2.fld.eirr.er18 = cm_object_get_child_by_name(state->u.e2.reg.eirr, "ER18");
    state->u.e2.fld.eirr.er19 = cm_object_get_child_by_name(state->u.e2.reg.eirr, "ER19");
    state->u.e2.fld.eirr.er20 = cm_object_get_child_by_name(state->u.e2.reg.eirr, "ER20");
    state->u.e2.fld.eirr.er21 = cm_object_get_child_by_name(state->u.e2.reg.eirr, "ER21");
    state->u.e2.fld.eirr.er22 = cm_object_get_child_by_name(state->u.e2.reg.eirr, "ER22");
    state->u.e2.fld.eirr.er23 = cm_object_get_child_by_name(state->u.e2.reg.eirr, "ER23");
    state->u.e2.fld.eirr.er24 = cm_object_get_child_by_name(state->u.e2.reg.eirr, "ER24");
    state->u.e2.fld.eirr.er25 = cm_object_get_child_by_name(state->u.e2.reg.eirr, "ER25");
    state->u.e2.fld.eirr.er26 = cm_object_get_child_by_name(state->u.e2.reg.eirr, "ER26");
    state->u.e2.fld.eirr.er27 = cm_object_get_child_by_name(state->u.e2.reg.eirr, "ER27");
    state->u.e2.fld.eirr.er28 = cm_object_get_child_by_name(state->u.e2.reg.eirr, "ER28");
    state->u.e2.fld.eirr.er29 = cm_object_get_child_by_name(state->u.e2.reg.eirr, "ER29");
    state->u.e2.fld.eirr.er30 = cm_object_get_child_by_name(state->u.e2.reg.eirr, "ER30");
    state->u.e2.fld.eirr.er31 = cm_object_get_child_by_name(state->u.e2.reg.eirr, "ER31");

    // EICLbitfields.
    state->u.e2.fld.eicl.ecl0 = cm_object_get_child_by_name(state->u.e2.reg.eicl, "ECL0");
    state->u.e2.fld.eicl.ecl1 = cm_object_get_child_by_name(state->u.e2.reg.eicl, "ECL1");
    state->u.e2.fld.eicl.ecl2 = cm_object_get_child_by_name(state->u.e2.reg.eicl, "ECL2");
    state->u.e2.fld.eicl.ecl3 = cm_object_get_child_by_name(state->u.e2.reg.eicl, "ECL3");
    state->u.e2.fld.eicl.ecl4 = cm_object_get_child_by_name(state->u.e2.reg.eicl, "ECL4");
    state->u.e2.fld.eicl.ecl5 = cm_object_get_child_by_name(state->u.e2.reg.eicl, "ECL5");
    state->u.e2.fld.eicl.ecl6 = cm_object_get_child_by_name(state->u.e2.reg.eicl, "ECL6");
    state->u.e2.fld.eicl.ecl7 = cm_object_get_child_by_name(state->u.e2.reg.eicl, "ECL7");
    state->u.e2.fld.eicl.ecl8 = cm_object_get_child_by_name(state->u.e2.reg.eicl, "ECL8");
    state->u.e2.fld.eicl.ecl9 = cm_object_get_child_by_name(state->u.e2.reg.eicl, "ECL9");
    state->u.e2.fld.eicl.ecl10 = cm_object_get_child_by_name(state->u.e2.reg.eicl, "ECL10");
    state->u.e2.fld.eicl.ecl11 = cm_object_get_child_by_name(state->u.e2.reg.eicl, "ECL11");
    state->u.e2.fld.eicl.ecl12 = cm_object_get_child_by_name(state->u.e2.reg.eicl, "ECL12");
    state->u.e2.fld.eicl.ecl13 = cm_object_get_child_by_name(state->u.e2.reg.eicl, "ECL13");
    state->u.e2.fld.eicl.ecl14 = cm_object_get_child_by_name(state->u.e2.reg.eicl, "ECL14");
    state->u.e2.fld.eicl.ecl15 = cm_object_get_child_by_name(state->u.e2.reg.eicl, "ECL15");
    state->u.e2.fld.eicl.ecl16 = cm_object_get_child_by_name(state->u.e2.reg.eicl, "ECL16");
    state->u.e2.fld.eicl.ecl17 = cm_object_get_child_by_name(state->u.e2.reg.eicl, "ECL17");
    state->u.e2.fld.eicl.ecl18 = cm_object_get_child_by_name(state->u.e2.reg.eicl, "ECL18");
    state->u.e2.fld.eicl.ecl19 = cm_object_get_child_by_name(state->u.e2.reg.eicl, "ECL19");
    state->u.e2.fld.eicl.ecl20 = cm_object_get_child_by_name(state->u.e2.reg.eicl, "ECL20");
    state->u.e2.fld.eicl.ecl21 = cm_object_get_child_by_name(state->u.e2.reg.eicl, "ECL21");
    state->u.e2.fld.eicl.ecl22 = cm_object_get_child_by_name(state->u.e2.reg.eicl, "ECL22");
    state->u.e2.fld.eicl.ecl23 = cm_object_get_child_by_name(state->u.e2.reg.eicl, "ECL23");
    state->u.e2.fld.eicl.ecl24 = cm_object_get_child_by_name(state->u.e2.reg.eicl, "ECL24");
    state->u.e2.fld.eicl.ecl25 = cm_object_get_child_by_name(state->u.e2.reg.eicl, "ECL25");
    state->u.e2.fld.eicl.ecl26 = cm_object_get_child_by_name(state->u.e2.reg.eicl, "ECL26");
    state->u.e2.fld.eicl.ecl27 = cm_object_get_child_by_name(state->u.e2.reg.eicl, "ECL27");
    state->u.e2.fld.eicl.ecl28 = cm_object_get_child_by_name(state->u.e2.reg.eicl, "ECL28");
    state->u.e2.fld.eicl.ecl29 = cm_object_get_child_by_name(state->u.e2.reg.eicl, "ECL29");
    state->u.e2.fld.eicl.ecl30 = cm_object_get_child_by_name(state->u.e2.reg.eicl, "ECL30");
    state->u.e2.fld.eicl.ecl31 = cm_object_get_child_by_name(state->u.e2.reg.eicl, "ECL31");

    // ELVRbitfields.
    state->u.e2.fld.elvr.la0 = cm_object_get_child_by_name(state->u.e2.reg.elvr, "LA0");
    state->u.e2.fld.elvr.lb0 = cm_object_get_child_by_name(state->u.e2.reg.elvr, "LB0");
    state->u.e2.fld.elvr.la1 = cm_object_get_child_by_name(state->u.e2.reg.elvr, "LA1");
    state->u.e2.fld.elvr.lb1 = cm_object_get_child_by_name(state->u.e2.reg.elvr, "LB1");
    state->u.e2.fld.elvr.la2 = cm_object_get_child_by_name(state->u.e2.reg.elvr, "LA2");
    state->u.e2.fld.elvr.lb2 = cm_object_get_child_by_name(state->u.e2.reg.elvr, "LB2");
    state->u.e2.fld.elvr.la3 = cm_object_get_child_by_name(state->u.e2.reg.elvr, "LA3");
    state->u.e2.fld.elvr.lb3 = cm_object_get_child_by_name(state->u.e2.reg.elvr, "LB3");
    state->u.e2.fld.elvr.la4 = cm_object_get_child_by_name(state->u.e2.reg.elvr, "LA4");
    state->u.e2.fld.elvr.lb4 = cm_object_get_child_by_name(state->u.e2.reg.elvr, "LB4");
    state->u.e2.fld.elvr.la5 = cm_object_get_child_by_name(state->u.e2.reg.elvr, "LA5");
    state->u.e2.fld.elvr.lb5 = cm_object_get_child_by_name(state->u.e2.reg.elvr, "LB5");
    state->u.e2.fld.elvr.la6 = cm_object_get_child_by_name(state->u.e2.reg.elvr, "LA6");
    state->u.e2.fld.elvr.lb6 = cm_object_get_child_by_name(state->u.e2.reg.elvr, "LB6");
    state->u.e2.fld.elvr.la7 = cm_object_get_child_by_name(state->u.e2.reg.elvr, "LA7");
    state->u.e2.fld.elvr.lb7 = cm_object_get_child_by_name(state->u.e2.reg.elvr, "LB7");
    state->u.e2.fld.elvr.la8 = cm_object_get_child_by_name(state->u.e2.reg.elvr, "LA8");
    state->u.e2.fld.elvr.lb8 = cm_object_get_child_by_name(state->u.e2.reg.elvr, "LB8");
    state->u.e2.fld.elvr.la9 = cm_object_get_child_by_name(state->u.e2.reg.elvr, "LA9");
    state->u.e2.fld.elvr.lb9 = cm_object_get_child_by_name(state->u.e2.reg.elvr, "LB9");
    state->u.e2.fld.elvr.la10 = cm_object_get_child_by_name(state->u.e2.reg.elvr, "LA10");
    state->u.e2.fld.elvr.lb10 = cm_object_get_child_by_name(state->u.e2.reg.elvr, "LB10");
    state->u.e2.fld.elvr.la11 = cm_object_get_child_by_name(state->u.e2.reg.elvr, "LA11");
    state->u.e2.fld.elvr.lb11 = cm_object_get_child_by_name(state->u.e2.reg.elvr, "LB11");
    state->u.e2.fld.elvr.la12 = cm_object_get_child_by_name(state->u.e2.reg.elvr, "LA12");
    state->u.e2.fld.elvr.lb12 = cm_object_get_child_by_name(state->u.e2.reg.elvr, "LB12");
    state->u.e2.fld.elvr.la13 = cm_object_get_child_by_name(state->u.e2.reg.elvr, "LA13");
    state->u.e2.fld.elvr.lb13 = cm_object_get_child_by_name(state->u.e2.reg.elvr, "LB13");
    state->u.e2.fld.elvr.la14 = cm_object_get_child_by_name(state->u.e2.reg.elvr, "LA14");
    state->u.e2.fld.elvr.lb14 = cm_object_get_child_by_name(state->u.e2.reg.elvr, "LB14");
    state->u.e2.fld.elvr.la15 = cm_object_get_child_by_name(state->u.e2.reg.elvr, "LA15");
    state->u.e2.fld.elvr.lb15 = cm_object_get_child_by_name(state->u.e2.reg.elvr, "LB15");

    // ELVR1bitfields.
    state->u.e2.fld.elvr1.la16 = cm_object_get_child_by_name(state->u.e2.reg.elvr1, "LA16");
    state->u.e2.fld.elvr1.lb16 = cm_object_get_child_by_name(state->u.e2.reg.elvr1, "LB16");
    state->u.e2.fld.elvr1.la17 = cm_object_get_child_by_name(state->u.e2.reg.elvr1, "LA17");
    state->u.e2.fld.elvr1.lb17 = cm_object_get_child_by_name(state->u.e2.reg.elvr1, "LB17");
    state->u.e2.fld.elvr1.la18 = cm_object_get_child_by_name(state->u.e2.reg.elvr1, "LA18");
    state->u.e2.fld.elvr1.lb18 = cm_object_get_child_by_name(state->u.e2.reg.elvr1, "LB18");
    state->u.e2.fld.elvr1.la19 = cm_object_get_child_by_name(state->u.e2.reg.elvr1, "LA19");
    state->u.e2.fld.elvr1.lb19 = cm_object_get_child_by_name(state->u.e2.reg.elvr1, "LB19");
    state->u.e2.fld.elvr1.la20 = cm_object_get_child_by_name(state->u.e2.reg.elvr1, "LA20");
    state->u.e2.fld.elvr1.lb20 = cm_object_get_child_by_name(state->u.e2.reg.elvr1, "LB20");
    state->u.e2.fld.elvr1.la21 = cm_object_get_child_by_name(state->u.e2.reg.elvr1, "LA21");
    state->u.e2.fld.elvr1.lb21 = cm_object_get_child_by_name(state->u.e2.reg.elvr1, "LB21");
    state->u.e2.fld.elvr1.la22 = cm_object_get_child_by_name(state->u.e2.reg.elvr1, "LA22");
    state->u.e2.fld.elvr1.lb22 = cm_object_get_child_by_name(state->u.e2.reg.elvr1, "LB22");
    state->u.e2.fld.elvr1.la23 = cm_object_get_child_by_name(state->u.e2.reg.elvr1, "LA23");
    state->u.e2.fld.elvr1.lb23 = cm_object_get_child_by_name(state->u.e2.reg.elvr1, "LB23");
    state->u.e2.fld.elvr1.la24 = cm_object_get_child_by_name(state->u.e2.reg.elvr1, "LA24");
    state->u.e2.fld.elvr1.lb24 = cm_object_get_child_by_name(state->u.e2.reg.elvr1, "LB24");
    state->u.e2.fld.elvr1.la25 = cm_object_get_child_by_name(state->u.e2.reg.elvr1, "LA25");
    state->u.e2.fld.elvr1.lb25 = cm_object_get_child_by_name(state->u.e2.reg.elvr1, "LB25");
    state->u.e2.fld.elvr1.la26 = cm_object_get_child_by_name(state->u.e2.reg.elvr1, "LA26");
    state->u.e2.fld.elvr1.lb26 = cm_object_get_child_by_name(state->u.e2.reg.elvr1, "LB26");
    state->u.e2.fld.elvr1.la27 = cm_object_get_child_by_name(state->u.e2.reg.elvr1, "LA27");
    state->u.e2.fld.elvr1.lb27 = cm_object_get_child_by_name(state->u.e2.reg.elvr1, "LB27");
    state->u.e2.fld.elvr1.la28 = cm_object_get_child_by_name(state->u.e2.reg.elvr1, "LA28");
    state->u.e2.fld.elvr1.lb28 = cm_object_get_child_by_name(state->u.e2.reg.elvr1, "LB28");
    state->u.e2.fld.elvr1.la29 = cm_object_get_child_by_name(state->u.e2.reg.elvr1, "LA29");
    state->u.e2.fld.elvr1.lb29 = cm_object_get_child_by_name(state->u.e2.reg.elvr1, "LB29");
    state->u.e2.fld.elvr1.la30 = cm_object_get_child_by_name(state->u.e2.reg.elvr1, "LA30");
    state->u.e2.fld.elvr1.lb30 = cm_object_get_child_by_name(state->u.e2.reg.elvr1, "LB30");
    state->u.e2.fld.elvr1.la31 = cm_object_get_child_by_name(state->u.e2.reg.elvr1, "LA31");
    state->u.e2.fld.elvr1.lb31 = cm_object_get_child_by_name(state->u.e2.reg.elvr1, "LB31");

    // NMIRRbitfields.
    state->u.e2.fld.nmirr.nr = cm_object_get_child_by_name(state->u.e2.reg.nmirr, "NR");

    // NMICLbitfields.
    state->u.e2.fld.nmicl.ncl = cm_object_get_child_by_name(state->u.e2.reg.nmicl, "NCL");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// ----- Private --------------------------------------------------------------

#if 0
static peripheral_register_t fm4_exti_xxx_pre_write_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    FM4EXTIState *state = FM4_EXTI_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);

    // TODO: Add code to adjust the value (like applying some masks,
    // for example prevent setting interrupts not enabled).
    // Also process cleared/set by write 1/0 bits.
    // The returned value will be stored in the register value.

    return full_value;
}

static void fm4_exti_xxx_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    FM4EXTIState *state = FM4_EXTI_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);
    // The new register value is full_value, the old one is prev_value.

    // TODO: Add code to send the value to the consumer.
}

static peripheral_register_t fm4_exti_xxx_pre_read_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size)
{
    FM4EXTIState *state = FM4_EXTI_STATE(periph);

    peripheral_register_t value = 0;

    // Add code to get the value from the producer, and return it.

    // This value, possibly masked, will be stored in the register
    // and returned when the register is read.
    return value;
}

static void fm4_exti_xxx_post_read_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size)
{
    FM4EXTIState *state = FM4_EXTI_STATE(periph);

    peripheral_register_t value = peripheral_register_get_raw_value(reg);

    // TODO: add code to perform the post read actions, like clearing some bits.
}
#endif

// ----------------------------------------------------------------------------

static void fm4_exti_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    // FM4EXTIState *state = FM4_EXTI_STATE(obj);

    // Capabilities are not yet available.
}

static void fm4_exti_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();
    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_FM4_EXTI))
    {
        return;
    }

    FM4MCUState *mcu = fm4_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    FM4EXTIState *state = FM4_EXTI_STATE(dev);
    // First thing first: get capabilities from MCU, needed everywhere.
    state->capabilities = mcu->capabilities;

    // Also keep a local pointer, to access them easier.
    const FM4Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    const char *periph_name = "EXTI";

    svd_set_peripheral_address_block(cm_state->svd_json, periph_name, obj);
    peripheral_create_memory_region(obj);

    // TODO: remove this if the peripheral is always enabled.
    //char enabling_bit_name[FM4_RCC_SIZEOF_ENABLING_BITFIELD];

    //  switch (capabilities->family) {
    //  case FM4_FAMILY_E2:

    // if (capabilities->e2.is_2cc) {

    fm4s6e2cc_exti_create_objects(obj, cm_state->svd_json, periph_name);

    // TODO: add actions.
    // cm_object_property_set_str(state->u.e2.fld.xxx.fff, "GGG", "follows");
    // cm_object_property_set_str(state->u.e2.fld.xxx.fff, "GGG", "cleared-by");

    // TODO: add callbacks.
    // peripheral_register_set_pre_read(state->e2.reg.xxx, &fm4_exti_xxx_pre_read_callback);
    // peripheral_register_set_post_read(state->e2.reg.xxx, &fm4_exti_xxx_post_read_callback);
    // peripheral_register_set_pre_read(state->e2.reg.xxx, &fm4_exti_xxx_pret_read_callback);
    // peripheral_register_set_post_write(state->e2.reg.xxx, &fm4_exti_xxx_post_write_callback);

    // TODO: add interrupts.

    // TODO: remove this if the peripheral is always enabled.
    // snprintf(enabling_bit_name, sizeof(enabling_bit_name) - 1,
    //     DEVICE_PATH_FM4_RCC "/AHB1ENR/EXTIEN");

    // } //else {
    //   assert(false);
    // }

    //   break;

    /*default:
        assert(false);
        break;
    }*/

    // TODO: remove this if the peripheral is always enabled.
    // state->enabling_bit = OBJECT(cm_device_by_name(enabling_bit_name));

    peripheral_prepare_registers(obj); //stop here
}

static void fm4_exti_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset(); this will reset all children registers.
    cm_device_parent_reset(dev, TYPE_FM4_EXTI);
}

static void fm4_exti_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = fm4_exti_reset_callback;
    dc->realize = fm4_exti_realize_callback;
}

static const TypeInfo fm4_exti_type_info = {
    .name = TYPE_FM4_EXTI,
    .parent = TYPE_FM4_EXTI_PARENT,
    .instance_init = fm4_exti_instance_init_callback,
    .instance_size = sizeof(FM4EXTIState),
    .class_init = fm4_exti_class_init_callback,
    .class_size = sizeof(FM4EXTIClass)};

static void fm4_exti_register_types(void)
{
    type_register_static(&fm4_exti_type_info);
}

type_init(fm4_exti_register_types);

// ----------------------------------------------------------------------------