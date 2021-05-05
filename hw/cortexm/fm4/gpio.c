/*
 * FM4- GPIO(0) emulation.
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

#include <hw/cortexm/fm4/gpio.h>
#include <hw/cortexm/fm4/exti.h>
#include <hw/cortexm/fm4/mcu.h>
//#include <hw/cortexm/fm4/syscfg.h> ??   to be added
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>
#include <hw/cortexm/gpio-lcd.h>
#include "qemu/bitops.h"

#define ILI9341_PAGEADDRSET 0x2B
#define ILI9341_COLADDRSET 0x2A
#define ILI9341_MEMORYWRITE 0x2C
#define PAGE_TRANSFER 2
#define COL_TRANSFER 4
#define color 5
#define output 6
// ----- Generated code -------------------------------------------------------
//
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void fm4s6e2cc_gpio_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
    FM4GPIOState *state = FM4_GPIO_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers.
    state->u.e2.reg.pfr0 = cm_object_get_child_by_name(obj, "PFR0");
    state->u.e2.reg.pfr1 = cm_object_get_child_by_name(obj, "PFR1");
    state->u.e2.reg.pfr2 = cm_object_get_child_by_name(obj, "PFR2");
    state->u.e2.reg.pfr3 = cm_object_get_child_by_name(obj, "PFR3");
    state->u.e2.reg.pfr4 = cm_object_get_child_by_name(obj, "PFR4");
    state->u.e2.reg.pfr5 = cm_object_get_child_by_name(obj, "PFR5");
    state->u.e2.reg.pfr6 = cm_object_get_child_by_name(obj, "PFR6");
    state->u.e2.reg.pfr7 = cm_object_get_child_by_name(obj, "PFR7");
    state->u.e2.reg.pfr8 = cm_object_get_child_by_name(obj, "PFR8");
    state->u.e2.reg.pfr9 = cm_object_get_child_by_name(obj, "PFR9");
    state->u.e2.reg.pfra = cm_object_get_child_by_name(obj, "PFRA");
    state->u.e2.reg.pfrb = cm_object_get_child_by_name(obj, "PFRB");
    state->u.e2.reg.pfrc = cm_object_get_child_by_name(obj, "PFRC");
    state->u.e2.reg.pfrd = cm_object_get_child_by_name(obj, "PFRD");
    state->u.e2.reg.pfre = cm_object_get_child_by_name(obj, "PFRE");
    state->u.e2.reg.pfrf = cm_object_get_child_by_name(obj, "PFRF");
    state->u.e2.reg.pcr0 = cm_object_get_child_by_name(obj, "PCR0");
    state->u.e2.reg.pcr1 = cm_object_get_child_by_name(obj, "PCR1");
    state->u.e2.reg.pcr2 = cm_object_get_child_by_name(obj, "PCR2");
    state->u.e2.reg.pcr3 = cm_object_get_child_by_name(obj, "PCR3");
    state->u.e2.reg.pcr4 = cm_object_get_child_by_name(obj, "PCR4");
    state->u.e2.reg.pcr5 = cm_object_get_child_by_name(obj, "PCR5");
    state->u.e2.reg.pcr6 = cm_object_get_child_by_name(obj, "PCR6");
    state->u.e2.reg.pcr7 = cm_object_get_child_by_name(obj, "PCR7");
    state->u.e2.reg.pcr8 = cm_object_get_child_by_name(obj, "PCR8");
    state->u.e2.reg.pcr9 = cm_object_get_child_by_name(obj, "PCR9");
    state->u.e2.reg.pcra = cm_object_get_child_by_name(obj, "PCRA");
    state->u.e2.reg.pcrb = cm_object_get_child_by_name(obj, "PCRB");
    state->u.e2.reg.pcrc = cm_object_get_child_by_name(obj, "PCRC");
    state->u.e2.reg.pcrd = cm_object_get_child_by_name(obj, "PCRD");
    state->u.e2.reg.pcre = cm_object_get_child_by_name(obj, "PCRE");
    state->u.e2.reg.pcrf = cm_object_get_child_by_name(obj, "PCRF");
    state->u.e2.reg.ddr0 = cm_object_get_child_by_name(obj, "DDR0");
    state->u.e2.reg.ddr1 = cm_object_get_child_by_name(obj, "DDR1");
    state->u.e2.reg.ddr2 = cm_object_get_child_by_name(obj, "DDR2");
    state->u.e2.reg.ddr3 = cm_object_get_child_by_name(obj, "DDR3");
    state->u.e2.reg.ddr4 = cm_object_get_child_by_name(obj, "DDR4");
    state->u.e2.reg.ddr5 = cm_object_get_child_by_name(obj, "DDR5");
    state->u.e2.reg.ddr6 = cm_object_get_child_by_name(obj, "DDR6");
    state->u.e2.reg.ddr7 = cm_object_get_child_by_name(obj, "DDR7");
    state->u.e2.reg.ddr8 = cm_object_get_child_by_name(obj, "DDR8");
    state->u.e2.reg.ddr9 = cm_object_get_child_by_name(obj, "DDR9");
    state->u.e2.reg.ddra = cm_object_get_child_by_name(obj, "DDRA");
    state->u.e2.reg.ddrb = cm_object_get_child_by_name(obj, "DDRB");
    state->u.e2.reg.ddrc = cm_object_get_child_by_name(obj, "DDRC");
    state->u.e2.reg.ddrd = cm_object_get_child_by_name(obj, "DDRD");
    state->u.e2.reg.ddre = cm_object_get_child_by_name(obj, "DDRE");
    state->u.e2.reg.ddrf = cm_object_get_child_by_name(obj, "DDRF");
    state->u.e2.reg.pdir0 = cm_object_get_child_by_name(obj, "PDIR0");
    state->u.e2.reg.pdir1 = cm_object_get_child_by_name(obj, "PDIR1");
    state->u.e2.reg.pdir2 = cm_object_get_child_by_name(obj, "PDIR2");
    state->u.e2.reg.pdir3 = cm_object_get_child_by_name(obj, "PDIR3");
    state->u.e2.reg.pdir4 = cm_object_get_child_by_name(obj, "PDIR4");
    state->u.e2.reg.pdir5 = cm_object_get_child_by_name(obj, "PDIR5");
    state->u.e2.reg.pdir6 = cm_object_get_child_by_name(obj, "PDIR6");
    state->u.e2.reg.pdir7 = cm_object_get_child_by_name(obj, "PDIR7");
    state->u.e2.reg.pdir8 = cm_object_get_child_by_name(obj, "PDIR8");
    state->u.e2.reg.pdir9 = cm_object_get_child_by_name(obj, "PDIR9");
    state->u.e2.reg.pdira = cm_object_get_child_by_name(obj, "PDIRA");
    state->u.e2.reg.pdirb = cm_object_get_child_by_name(obj, "PDIRB");
    state->u.e2.reg.pdirc = cm_object_get_child_by_name(obj, "PDIRC");
    state->u.e2.reg.pdird = cm_object_get_child_by_name(obj, "PDIRD");
    state->u.e2.reg.pdire = cm_object_get_child_by_name(obj, "PDIRE");
    state->u.e2.reg.pdirf = cm_object_get_child_by_name(obj, "PDIRF");
    state->u.e2.reg.pdor0 = cm_object_get_child_by_name(obj, "PDOR0");
    state->u.e2.reg.pdor1 = cm_object_get_child_by_name(obj, "PDOR1");
    state->u.e2.reg.pdor2 = cm_object_get_child_by_name(obj, "PDOR2");
    state->u.e2.reg.pdor3 = cm_object_get_child_by_name(obj, "PDOR3");
    state->u.e2.reg.pdor4 = cm_object_get_child_by_name(obj, "PDOR4");
    state->u.e2.reg.pdor5 = cm_object_get_child_by_name(obj, "PDOR5");
    state->u.e2.reg.pdor6 = cm_object_get_child_by_name(obj, "PDOR6");
    state->u.e2.reg.pdor7 = cm_object_get_child_by_name(obj, "PDOR7");
    state->u.e2.reg.pdor8 = cm_object_get_child_by_name(obj, "PDOR8");
    state->u.e2.reg.pdor9 = cm_object_get_child_by_name(obj, "PDOR9");
    state->u.e2.reg.pdora = cm_object_get_child_by_name(obj, "PDORA");
    state->u.e2.reg.pdorb = cm_object_get_child_by_name(obj, "PDORB");
    state->u.e2.reg.pdorc = cm_object_get_child_by_name(obj, "PDORC");
    state->u.e2.reg.pdord = cm_object_get_child_by_name(obj, "PDORD");
    state->u.e2.reg.pdore = cm_object_get_child_by_name(obj, "PDORE");
    state->u.e2.reg.pdorf = cm_object_get_child_by_name(obj, "PDORF");
    state->u.e2.reg.ade = cm_object_get_child_by_name(obj, "ADE");
    state->u.e2.reg.spsr = cm_object_get_child_by_name(obj, "SPSR");
    state->u.e2.reg.epfr00 = cm_object_get_child_by_name(obj, "EPFR00");
    state->u.e2.reg.epfr01 = cm_object_get_child_by_name(obj, "EPFR01");
    state->u.e2.reg.epfr02 = cm_object_get_child_by_name(obj, "EPFR02");
    state->u.e2.reg.epfr03 = cm_object_get_child_by_name(obj, "EPFR03");
    state->u.e2.reg.epfr04 = cm_object_get_child_by_name(obj, "EPFR04");
    state->u.e2.reg.epfr05 = cm_object_get_child_by_name(obj, "EPFR05");
    state->u.e2.reg.epfr06 = cm_object_get_child_by_name(obj, "EPFR06");
    state->u.e2.reg.epfr07 = cm_object_get_child_by_name(obj, "EPFR07");
    state->u.e2.reg.epfr08 = cm_object_get_child_by_name(obj, "EPFR08");
    state->u.e2.reg.epfr09 = cm_object_get_child_by_name(obj, "EPFR09");
    state->u.e2.reg.epfr10 = cm_object_get_child_by_name(obj, "EPFR10");
    state->u.e2.reg.epfr11 = cm_object_get_child_by_name(obj, "EPFR11");
    state->u.e2.reg.epfr12 = cm_object_get_child_by_name(obj, "EPFR12");
    state->u.e2.reg.epfr13 = cm_object_get_child_by_name(obj, "EPFR13");
    state->u.e2.reg.epfr14 = cm_object_get_child_by_name(obj, "EPFR14");
    state->u.e2.reg.epfr15 = cm_object_get_child_by_name(obj, "EPFR15");
    state->u.e2.reg.epfr16 = cm_object_get_child_by_name(obj, "EPFR16");
    state->u.e2.reg.epfr17 = cm_object_get_child_by_name(obj, "EPFR17");
    state->u.e2.reg.epfr18 = cm_object_get_child_by_name(obj, "EPFR18");
    state->u.e2.reg.epfr19 = cm_object_get_child_by_name(obj, "EPFR19");
    state->u.e2.reg.epfr20 = cm_object_get_child_by_name(obj, "EPFR20");
    state->u.e2.reg.epfr21 = cm_object_get_child_by_name(obj, "EPFR21");
    state->u.e2.reg.epfr22 = cm_object_get_child_by_name(obj, "EPFR22");
    state->u.e2.reg.epfr23 = cm_object_get_child_by_name(obj, "EPFR23");
    state->u.e2.reg.epfr24 = cm_object_get_child_by_name(obj, "EPFR24");
    state->u.e2.reg.epfr25 = cm_object_get_child_by_name(obj, "EPFR25");
    state->u.e2.reg.epfr26 = cm_object_get_child_by_name(obj, "EPFR26");
    state->u.e2.reg.pzr0 = cm_object_get_child_by_name(obj, "PZR0");
    state->u.e2.reg.pzr1 = cm_object_get_child_by_name(obj, "PZR1");
    state->u.e2.reg.pzr2 = cm_object_get_child_by_name(obj, "PZR2");
    state->u.e2.reg.pzr3 = cm_object_get_child_by_name(obj, "PZR3");
    state->u.e2.reg.pzr4 = cm_object_get_child_by_name(obj, "PZR4");
    state->u.e2.reg.pzr5 = cm_object_get_child_by_name(obj, "PZR5");
    state->u.e2.reg.pzr6 = cm_object_get_child_by_name(obj, "PZR6");
    state->u.e2.reg.pzr7 = cm_object_get_child_by_name(obj, "PZR7");
    state->u.e2.reg.pzr8 = cm_object_get_child_by_name(obj, "PZR8");
    state->u.e2.reg.pzr9 = cm_object_get_child_by_name(obj, "PZR9");
    state->u.e2.reg.pzra = cm_object_get_child_by_name(obj, "PZRA");
    state->u.e2.reg.pzrb = cm_object_get_child_by_name(obj, "PZRB");
    state->u.e2.reg.pzrc = cm_object_get_child_by_name(obj, "PZRC");
    state->u.e2.reg.pzrd = cm_object_get_child_by_name(obj, "PZRD");
    state->u.e2.reg.pzre = cm_object_get_child_by_name(obj, "PZRE");
    state->u.e2.reg.pzrf = cm_object_get_child_by_name(obj, "PZRF");
    state->u.e2.reg.pdsr0 = cm_object_get_child_by_name(obj, "PDSR0");
    state->u.e2.reg.pdsr1 = cm_object_get_child_by_name(obj, "PDSR1");
    state->u.e2.reg.pdsr2 = cm_object_get_child_by_name(obj, "PDSR2");
    state->u.e2.reg.pdsr3 = cm_object_get_child_by_name(obj, "PDSR3");
    state->u.e2.reg.pdsr4 = cm_object_get_child_by_name(obj, "PDSR4");
    state->u.e2.reg.pdsr5 = cm_object_get_child_by_name(obj, "PDSR5");
    state->u.e2.reg.pdsr6 = cm_object_get_child_by_name(obj, "PDSR6");
    state->u.e2.reg.pdsr7 = cm_object_get_child_by_name(obj, "PDSR7");
    state->u.e2.reg.pdsr8 = cm_object_get_child_by_name(obj, "PDSR8");
    state->u.e2.reg.pdsr9 = cm_object_get_child_by_name(obj, "PDSR9");
    state->u.e2.reg.pdsra = cm_object_get_child_by_name(obj, "PDSRA");
    state->u.e2.reg.pdsrb = cm_object_get_child_by_name(obj, "PDSRB");
    state->u.e2.reg.pdsrc = cm_object_get_child_by_name(obj, "PDSRC");
    state->u.e2.reg.pdsrd = cm_object_get_child_by_name(obj, "PDSRD");
    state->u.e2.reg.pdsre = cm_object_get_child_by_name(obj, "PDSRE");
    state->u.e2.reg.pdsrf = cm_object_get_child_by_name(obj, "PDSRF");

    // PFR0bitfields.
    //     state->u.e2.fld.pfr0.p00= cm_object_get_child_by_name(state->u.e2.reg.pfr0, "P00");
    //     state->u.e2.fld.pfr0.p01= cm_object_get_child_by_name(state->u.e2.reg.pfr0, "P01");
    //     state->u.e2.fld.pfr0.p02= cm_object_get_child_by_name(state->u.e2.reg.pfr0, "P02");
    //     state->u.e2.fld.pfr0.p03= cm_object_get_child_by_name(state->u.e2.reg.pfr0, "P03");
    //     state->u.e2.fld.pfr0.p04= cm_object_get_child_by_name(state->u.e2.reg.pfr0, "P04");
    //     state->u.e2.fld.pfr0.p08= cm_object_get_child_by_name(state->u.e2.reg.pfr0, "P08");
    //     state->u.e2.fld.pfr0.p09= cm_object_get_child_by_name(state->u.e2.reg.pfr0, "P09");
    //     state->u.e2.fld.pfr0.p0a= cm_object_get_child_by_name(state->u.e2.reg.pfr0, "P0A");

    //     // PFR1bitfields.
    //     state->u.e2.fld.pfr1.p10= cm_object_get_child_by_name(state->u.e2.reg.pfr1, "P10");
    //     state->u.e2.fld.pfr1.p11= cm_object_get_child_by_name(state->u.e2.reg.pfr1, "P11");
    //     state->u.e2.fld.pfr1.p12= cm_object_get_child_by_name(state->u.e2.reg.pfr1, "P12");
    //     state->u.e2.fld.pfr1.p13= cm_object_get_child_by_name(state->u.e2.reg.pfr1, "P13");
    //     state->u.e2.fld.pfr1.p14= cm_object_get_child_by_name(state->u.e2.reg.pfr1, "P14");
    //     state->u.e2.fld.pfr1.p15= cm_object_get_child_by_name(state->u.e2.reg.pfr1, "P15");
    //     state->u.e2.fld.pfr1.p16= cm_object_get_child_by_name(state->u.e2.reg.pfr1, "P16");
    //     state->u.e2.fld.pfr1.p17= cm_object_get_child_by_name(state->u.e2.reg.pfr1, "P17");
    //     state->u.e2.fld.pfr1.p18= cm_object_get_child_by_name(state->u.e2.reg.pfr1, "P18");
    //     state->u.e2.fld.pfr1.p19= cm_object_get_child_by_name(state->u.e2.reg.pfr1, "P19");
    //     state->u.e2.fld.pfr1.p1a= cm_object_get_child_by_name(state->u.e2.reg.pfr1, "P1A");
    //     state->u.e2.fld.pfr1.p1b= cm_object_get_child_by_name(state->u.e2.reg.pfr1, "P1B");
    //     state->u.e2.fld.pfr1.p1c= cm_object_get_child_by_name(state->u.e2.reg.pfr1, "P1C");
    //     state->u.e2.fld.pfr1.p1d= cm_object_get_child_by_name(state->u.e2.reg.pfr1, "P1D");
    //     state->u.e2.fld.pfr1.p1e= cm_object_get_child_by_name(state->u.e2.reg.pfr1, "P1E");
    //     state->u.e2.fld.pfr1.p1f= cm_object_get_child_by_name(state->u.e2.reg.pfr1, "P1F");

    //     // PFR2bitfields.
    //     state->u.e2.fld.pfr2.p20= cm_object_get_child_by_name(state->u.e2.reg.pfr2, "P20");
    //     state->u.e2.fld.pfr2.p21= cm_object_get_child_by_name(state->u.e2.reg.pfr2, "P21");
    //     state->u.e2.fld.pfr2.p22= cm_object_get_child_by_name(state->u.e2.reg.pfr2, "P22");
    //     state->u.e2.fld.pfr2.p23= cm_object_get_child_by_name(state->u.e2.reg.pfr2, "P23");
    //     state->u.e2.fld.pfr2.p24= cm_object_get_child_by_name(state->u.e2.reg.pfr2, "P24");
    //     state->u.e2.fld.pfr2.p25= cm_object_get_child_by_name(state->u.e2.reg.pfr2, "P25");
    //     state->u.e2.fld.pfr2.p26= cm_object_get_child_by_name(state->u.e2.reg.pfr2, "P26");
    //     state->u.e2.fld.pfr2.p27= cm_object_get_child_by_name(state->u.e2.reg.pfr2, "P27");
    //     state->u.e2.fld.pfr2.p28= cm_object_get_child_by_name(state->u.e2.reg.pfr2, "P28");
    //     state->u.e2.fld.pfr2.p29= cm_object_get_child_by_name(state->u.e2.reg.pfr2, "P29");
    //     state->u.e2.fld.pfr2.p2a= cm_object_get_child_by_name(state->u.e2.reg.pfr2, "P2A");

    //     // PFR3bitfields.
    //     state->u.e2.fld.pfr3.p30= cm_object_get_child_by_name(state->u.e2.reg.pfr3, "P30");
    //     state->u.e2.fld.pfr3.p31= cm_object_get_child_by_name(state->u.e2.reg.pfr3, "P31");
    //     state->u.e2.fld.pfr3.p32= cm_object_get_child_by_name(state->u.e2.reg.pfr3, "P32");
    //     state->u.e2.fld.pfr3.p33= cm_object_get_child_by_name(state->u.e2.reg.pfr3, "P33");
    //     state->u.e2.fld.pfr3.p34= cm_object_get_child_by_name(state->u.e2.reg.pfr3, "P34");
    //     state->u.e2.fld.pfr3.p35= cm_object_get_child_by_name(state->u.e2.reg.pfr3, "P35");
    //     state->u.e2.fld.pfr3.p36= cm_object_get_child_by_name(state->u.e2.reg.pfr3, "P36");
    //     state->u.e2.fld.pfr3.p37= cm_object_get_child_by_name(state->u.e2.reg.pfr3, "P37");
    //     state->u.e2.fld.pfr3.p38= cm_object_get_child_by_name(state->u.e2.reg.pfr3, "P38");
    //     state->u.e2.fld.pfr3.p39= cm_object_get_child_by_name(state->u.e2.reg.pfr3, "P39");
    //     state->u.e2.fld.pfr3.p3a= cm_object_get_child_by_name(state->u.e2.reg.pfr3, "P3A");
    //     state->u.e2.fld.pfr3.p3b= cm_object_get_child_by_name(state->u.e2.reg.pfr3, "P3B");
    //     state->u.e2.fld.pfr3.p3c= cm_object_get_child_by_name(state->u.e2.reg.pfr3, "P3C");
    //     state->u.e2.fld.pfr3.p3d= cm_object_get_child_by_name(state->u.e2.reg.pfr3, "P3D");
    //     state->u.e2.fld.pfr3.p3e= cm_object_get_child_by_name(state->u.e2.reg.pfr3, "P3E");

    //     // PFR4bitfields.
    //     state->u.e2.fld.pfr4.p40= cm_object_get_child_by_name(state->u.e2.reg.pfr4, "P40");
    //     state->u.e2.fld.pfr4.p41= cm_object_get_child_by_name(state->u.e2.reg.pfr4, "P41");
    //     state->u.e2.fld.pfr4.p42= cm_object_get_child_by_name(state->u.e2.reg.pfr4, "P42");
    //     state->u.e2.fld.pfr4.p43= cm_object_get_child_by_name(state->u.e2.reg.pfr4, "P43");
    //     state->u.e2.fld.pfr4.p44= cm_object_get_child_by_name(state->u.e2.reg.pfr4, "P44");
    //     state->u.e2.fld.pfr4.p45= cm_object_get_child_by_name(state->u.e2.reg.pfr4, "P45");
    //     state->u.e2.fld.pfr4.p46= cm_object_get_child_by_name(state->u.e2.reg.pfr4, "P46");
    //     state->u.e2.fld.pfr4.p47= cm_object_get_child_by_name(state->u.e2.reg.pfr4, "P47");
    //     state->u.e2.fld.pfr4.p48= cm_object_get_child_by_name(state->u.e2.reg.pfr4, "P48");
    //     state->u.e2.fld.pfr4.p49= cm_object_get_child_by_name(state->u.e2.reg.pfr4, "P49");
    //     state->u.e2.fld.pfr4.p4a= cm_object_get_child_by_name(state->u.e2.reg.pfr4, "P4A");
    //     state->u.e2.fld.pfr4.p4b= cm_object_get_child_by_name(state->u.e2.reg.pfr4, "P4B");
    //     state->u.e2.fld.pfr4.p4c= cm_object_get_child_by_name(state->u.e2.reg.pfr4, "P4C");
    //     state->u.e2.fld.pfr4.p4d= cm_object_get_child_by_name(state->u.e2.reg.pfr4, "P4D");
    //     state->u.e2.fld.pfr4.p4e= cm_object_get_child_by_name(state->u.e2.reg.pfr4, "P4E");

    //     // PFR5bitfields.
    //     state->u.e2.fld.pfr5.p50= cm_object_get_child_by_name(state->u.e2.reg.pfr5, "P50");
    //     state->u.e2.fld.pfr5.p51= cm_object_get_child_by_name(state->u.e2.reg.pfr5, "P51");
    //     state->u.e2.fld.pfr5.p52= cm_object_get_child_by_name(state->u.e2.reg.pfr5, "P52");
    //     state->u.e2.fld.pfr5.p53= cm_object_get_child_by_name(state->u.e2.reg.pfr5, "P53");
    //     state->u.e2.fld.pfr5.p54= cm_object_get_child_by_name(state->u.e2.reg.pfr5, "P54");
    //     state->u.e2.fld.pfr5.p55= cm_object_get_child_by_name(state->u.e2.reg.pfr5, "P55");
    //     state->u.e2.fld.pfr5.p56= cm_object_get_child_by_name(state->u.e2.reg.pfr5, "P56");
    //     state->u.e2.fld.pfr5.p57= cm_object_get_child_by_name(state->u.e2.reg.pfr5, "P57");
    //     state->u.e2.fld.pfr5.p58= cm_object_get_child_by_name(state->u.e2.reg.pfr5, "P58");
    //     state->u.e2.fld.pfr5.p59= cm_object_get_child_by_name(state->u.e2.reg.pfr5, "P59");
    //     state->u.e2.fld.pfr5.p5a= cm_object_get_child_by_name(state->u.e2.reg.pfr5, "P5A");
    //     state->u.e2.fld.pfr5.p5b= cm_object_get_child_by_name(state->u.e2.reg.pfr5, "P5B");
    //     state->u.e2.fld.pfr5.p5c= cm_object_get_child_by_name(state->u.e2.reg.pfr5, "P5C");
    //     state->u.e2.fld.pfr5.p5d= cm_object_get_child_by_name(state->u.e2.reg.pfr5, "P5D");
    //     state->u.e2.fld.pfr5.p5e= cm_object_get_child_by_name(state->u.e2.reg.pfr5, "P5E");
    //     state->u.e2.fld.pfr5.p5f= cm_object_get_child_by_name(state->u.e2.reg.pfr5, "P5F");

    //     // PFR6bitfields.
    //     state->u.e2.fld.pfr6.p60= cm_object_get_child_by_name(state->u.e2.reg.pfr6, "P60");
    //     state->u.e2.fld.pfr6.p61= cm_object_get_child_by_name(state->u.e2.reg.pfr6, "P61");
    //     state->u.e2.fld.pfr6.p62= cm_object_get_child_by_name(state->u.e2.reg.pfr6, "P62");
    //     state->u.e2.fld.pfr6.p63= cm_object_get_child_by_name(state->u.e2.reg.pfr6, "P63");
    //     state->u.e2.fld.pfr6.p64= cm_object_get_child_by_name(state->u.e2.reg.pfr6, "P64");
    //     state->u.e2.fld.pfr6.p65= cm_object_get_child_by_name(state->u.e2.reg.pfr6, "P65");
    //     state->u.e2.fld.pfr6.p66= cm_object_get_child_by_name(state->u.e2.reg.pfr6, "P66");
    //     state->u.e2.fld.pfr6.p67= cm_object_get_child_by_name(state->u.e2.reg.pfr6, "P67");
    //     state->u.e2.fld.pfr6.p68= cm_object_get_child_by_name(state->u.e2.reg.pfr6, "P68");
    //     state->u.e2.fld.pfr6.p69= cm_object_get_child_by_name(state->u.e2.reg.pfr6, "P69");
    //     state->u.e2.fld.pfr6.p6a= cm_object_get_child_by_name(state->u.e2.reg.pfr6, "P6A");
    //     state->u.e2.fld.pfr6.p6b= cm_object_get_child_by_name(state->u.e2.reg.pfr6, "P6B");
    //     state->u.e2.fld.pfr6.p6c= cm_object_get_child_by_name(state->u.e2.reg.pfr6, "P6C");
    //     state->u.e2.fld.pfr6.p6d= cm_object_get_child_by_name(state->u.e2.reg.pfr6, "P6D");
    //     state->u.e2.fld.pfr6.p6e= cm_object_get_child_by_name(state->u.e2.reg.pfr6, "P6E");

    //     // PFR7bitfields.
    //     state->u.e2.fld.pfr7.p70= cm_object_get_child_by_name(state->u.e2.reg.pfr7, "P70");
    //     state->u.e2.fld.pfr7.p71= cm_object_get_child_by_name(state->u.e2.reg.pfr7, "P71");
    //     state->u.e2.fld.pfr7.p72= cm_object_get_child_by_name(state->u.e2.reg.pfr7, "P72");
    //     state->u.e2.fld.pfr7.p73= cm_object_get_child_by_name(state->u.e2.reg.pfr7, "P73");
    //     state->u.e2.fld.pfr7.p74= cm_object_get_child_by_name(state->u.e2.reg.pfr7, "P74");
    //     state->u.e2.fld.pfr7.p75= cm_object_get_child_by_name(state->u.e2.reg.pfr7, "P75");
    //     state->u.e2.fld.pfr7.p76= cm_object_get_child_by_name(state->u.e2.reg.pfr7, "P76");
    //     state->u.e2.fld.pfr7.p77= cm_object_get_child_by_name(state->u.e2.reg.pfr7, "P77");
    //     state->u.e2.fld.pfr7.p78= cm_object_get_child_by_name(state->u.e2.reg.pfr7, "P78");
    //     state->u.e2.fld.pfr7.p79= cm_object_get_child_by_name(state->u.e2.reg.pfr7, "P79");
    //     state->u.e2.fld.pfr7.p7a= cm_object_get_child_by_name(state->u.e2.reg.pfr7, "P7A");
    //     state->u.e2.fld.pfr7.p7b= cm_object_get_child_by_name(state->u.e2.reg.pfr7, "P7B");
    //     state->u.e2.fld.pfr7.p7c= cm_object_get_child_by_name(state->u.e2.reg.pfr7, "P7C");
    //     state->u.e2.fld.pfr7.p7d= cm_object_get_child_by_name(state->u.e2.reg.pfr7, "P7D");
    //     state->u.e2.fld.pfr7.p7e= cm_object_get_child_by_name(state->u.e2.reg.pfr7, "P7E");

    //     // PFR8bitfields.
    //     state->u.e2.fld.pfr8.p80= cm_object_get_child_by_name(state->u.e2.reg.pfr8, "P80");
    //     state->u.e2.fld.pfr8.p81= cm_object_get_child_by_name(state->u.e2.reg.pfr8, "P81");
    //     state->u.e2.fld.pfr8.p82= cm_object_get_child_by_name(state->u.e2.reg.pfr8, "P82");
    //     state->u.e2.fld.pfr8.p83= cm_object_get_child_by_name(state->u.e2.reg.pfr8, "P83");

    //     // PFR9bitfields.
    //     state->u.e2.fld.pfr9.p90= cm_object_get_child_by_name(state->u.e2.reg.pfr9, "P90");
    //     state->u.e2.fld.pfr9.p91= cm_object_get_child_by_name(state->u.e2.reg.pfr9, "P91");
    //     state->u.e2.fld.pfr9.p92= cm_object_get_child_by_name(state->u.e2.reg.pfr9, "P92");
    //     state->u.e2.fld.pfr9.p93= cm_object_get_child_by_name(state->u.e2.reg.pfr9, "P93");
    //     state->u.e2.fld.pfr9.p94= cm_object_get_child_by_name(state->u.e2.reg.pfr9, "P94");
    //     state->u.e2.fld.pfr9.p95= cm_object_get_child_by_name(state->u.e2.reg.pfr9, "P95");
    //     state->u.e2.fld.pfr9.p96= cm_object_get_child_by_name(state->u.e2.reg.pfr9, "P96");
    //     state->u.e2.fld.pfr9.p97= cm_object_get_child_by_name(state->u.e2.reg.pfr9, "P97");

    //     // PFRAbitfields.
    //     state->u.e2.fld.pfra.pa0= cm_object_get_child_by_name(state->u.e2.reg.pfra, "PA0");
    //     state->u.e2.fld.pfra.pa1= cm_object_get_child_by_name(state->u.e2.reg.pfra, "PA1");
    //     state->u.e2.fld.pfra.pa2= cm_object_get_child_by_name(state->u.e2.reg.pfra, "PA2");
    //     state->u.e2.fld.pfra.pa3= cm_object_get_child_by_name(state->u.e2.reg.pfra, "PA3");
    //     state->u.e2.fld.pfra.pa4= cm_object_get_child_by_name(state->u.e2.reg.pfra, "PA4");
    //     state->u.e2.fld.pfra.pa5= cm_object_get_child_by_name(state->u.e2.reg.pfra, "PA5");
    //     state->u.e2.fld.pfra.pa6= cm_object_get_child_by_name(state->u.e2.reg.pfra, "PA6");
    //     state->u.e2.fld.pfra.pa7= cm_object_get_child_by_name(state->u.e2.reg.pfra, "PA7");
    //     state->u.e2.fld.pfra.pa8= cm_object_get_child_by_name(state->u.e2.reg.pfra, "PA8");
    //     state->u.e2.fld.pfra.pa9= cm_object_get_child_by_name(state->u.e2.reg.pfra, "PA9");
    //     state->u.e2.fld.pfra.paa= cm_object_get_child_by_name(state->u.e2.reg.pfra, "PAA");
    //     state->u.e2.fld.pfra.pab= cm_object_get_child_by_name(state->u.e2.reg.pfra, "PAB");
    //     state->u.e2.fld.pfra.pac= cm_object_get_child_by_name(state->u.e2.reg.pfra, "PAC");
    //     state->u.e2.fld.pfra.pad= cm_object_get_child_by_name(state->u.e2.reg.pfra, "PAD");
    //     state->u.e2.fld.pfra.pae= cm_object_get_child_by_name(state->u.e2.reg.pfra, "PAE");
    //     state->u.e2.fld.pfra.paf= cm_object_get_child_by_name(state->u.e2.reg.pfra, "PAF");

    //     // PFRBbitfields.
    //     state->u.e2.fld.pfrb.pb0= cm_object_get_child_by_name(state->u.e2.reg.pfrb, "PB0");
    //     state->u.e2.fld.pfrb.pb1= cm_object_get_child_by_name(state->u.e2.reg.pfrb, "PB1");
    //     state->u.e2.fld.pfrb.pb2= cm_object_get_child_by_name(state->u.e2.reg.pfrb, "PB2");
    //     state->u.e2.fld.pfrb.pb3= cm_object_get_child_by_name(state->u.e2.reg.pfrb, "PB3");
    //     state->u.e2.fld.pfrb.pb4= cm_object_get_child_by_name(state->u.e2.reg.pfrb, "PB4");
    //     state->u.e2.fld.pfrb.pb5= cm_object_get_child_by_name(state->u.e2.reg.pfrb, "PB5");
    //     state->u.e2.fld.pfrb.pb6= cm_object_get_child_by_name(state->u.e2.reg.pfrb, "PB6");
    //     state->u.e2.fld.pfrb.pb7= cm_object_get_child_by_name(state->u.e2.reg.pfrb, "PB7");
    //     state->u.e2.fld.pfrb.pb8= cm_object_get_child_by_name(state->u.e2.reg.pfrb, "PB8");
    //     state->u.e2.fld.pfrb.pb9= cm_object_get_child_by_name(state->u.e2.reg.pfrb, "PB9");
    //     state->u.e2.fld.pfrb.pba= cm_object_get_child_by_name(state->u.e2.reg.pfrb, "PBA");
    //     state->u.e2.fld.pfrb.pbb= cm_object_get_child_by_name(state->u.e2.reg.pfrb, "PBB");
    //     state->u.e2.fld.pfrb.pbc= cm_object_get_child_by_name(state->u.e2.reg.pfrb, "PBC");
    //     state->u.e2.fld.pfrb.pbd= cm_object_get_child_by_name(state->u.e2.reg.pfrb, "PBD");
    //     state->u.e2.fld.pfrb.pbe= cm_object_get_child_by_name(state->u.e2.reg.pfrb, "PBE");
    //     state->u.e2.fld.pfrb.pbf= cm_object_get_child_by_name(state->u.e2.reg.pfrb, "PBF");

    //     // PFRCbitfields.
    //     state->u.e2.fld.pfrc.pc0= cm_object_get_child_by_name(state->u.e2.reg.pfrc, "PC0");
    //     state->u.e2.fld.pfrc.pc1= cm_object_get_child_by_name(state->u.e2.reg.pfrc, "PC1");
    //     state->u.e2.fld.pfrc.pc2= cm_object_get_child_by_name(state->u.e2.reg.pfrc, "PC2");
    //     state->u.e2.fld.pfrc.pc3= cm_object_get_child_by_name(state->u.e2.reg.pfrc, "PC3");
    //     state->u.e2.fld.pfrc.pc4= cm_object_get_child_by_name(state->u.e2.reg.pfrc, "PC4");
    //     state->u.e2.fld.pfrc.pc5= cm_object_get_child_by_name(state->u.e2.reg.pfrc, "PC5");
    //     state->u.e2.fld.pfrc.pc6= cm_object_get_child_by_name(state->u.e2.reg.pfrc, "PC6");
    //     state->u.e2.fld.pfrc.pc7= cm_object_get_child_by_name(state->u.e2.reg.pfrc, "PC7");
    //     state->u.e2.fld.pfrc.pc8= cm_object_get_child_by_name(state->u.e2.reg.pfrc, "PC8");
    //     state->u.e2.fld.pfrc.pc9= cm_object_get_child_by_name(state->u.e2.reg.pfrc, "PC9");
    //     state->u.e2.fld.pfrc.pca= cm_object_get_child_by_name(state->u.e2.reg.pfrc, "PCA");
    //     state->u.e2.fld.pfrc.pcb= cm_object_get_child_by_name(state->u.e2.reg.pfrc, "PCB");
    //     state->u.e2.fld.pfrc.pcc= cm_object_get_child_by_name(state->u.e2.reg.pfrc, "PCC");
    //     state->u.e2.fld.pfrc.pcd= cm_object_get_child_by_name(state->u.e2.reg.pfrc, "PCD");
    //     state->u.e2.fld.pfrc.pce= cm_object_get_child_by_name(state->u.e2.reg.pfrc, "PCE");
    //     state->u.e2.fld.pfrc.pcf= cm_object_get_child_by_name(state->u.e2.reg.pfrc, "PCF");

    //     // PFRDbitfields.
    //     state->u.e2.fld.pfrd.pd0= cm_object_get_child_by_name(state->u.e2.reg.pfrd, "PD0");
    //     state->u.e2.fld.pfrd.pd1= cm_object_get_child_by_name(state->u.e2.reg.pfrd, "PD1");
    //     state->u.e2.fld.pfrd.pd2= cm_object_get_child_by_name(state->u.e2.reg.pfrd, "PD2");

    //     // PFREbitfields.
    //     state->u.e2.fld.pfre.pe0= cm_object_get_child_by_name(state->u.e2.reg.pfre, "PE0");
    //     state->u.e2.fld.pfre.pe2= cm_object_get_child_by_name(state->u.e2.reg.pfre, "PE2");
    //     state->u.e2.fld.pfre.pe3= cm_object_get_child_by_name(state->u.e2.reg.pfre, "PE3");

    //     // PFRFbitfields.
    //     state->u.e2.fld.pfrf.pf0= cm_object_get_child_by_name(state->u.e2.reg.pfrf, "PF0");
    //     state->u.e2.fld.pfrf.pf1= cm_object_get_child_by_name(state->u.e2.reg.pfrf, "PF1");
    //     state->u.e2.fld.pfrf.pf2= cm_object_get_child_by_name(state->u.e2.reg.pfrf, "PF2");
    //     state->u.e2.fld.pfrf.pf3= cm_object_get_child_by_name(state->u.e2.reg.pfrf, "PF3");
    //     state->u.e2.fld.pfrf.pf4= cm_object_get_child_by_name(state->u.e2.reg.pfrf, "PF4");
    //     state->u.e2.fld.pfrf.pf5= cm_object_get_child_by_name(state->u.e2.reg.pfrf, "PF5");
    //     state->u.e2.fld.pfrf.pf6= cm_object_get_child_by_name(state->u.e2.reg.pfrf, "PF6");
    //     state->u.e2.fld.pfrf.pf7= cm_object_get_child_by_name(state->u.e2.reg.pfrf, "PF7");
    //     state->u.e2.fld.pfrf.pf8= cm_object_get_child_by_name(state->u.e2.reg.pfrf, "PF8");
    //     state->u.e2.fld.pfrf.pf9= cm_object_get_child_by_name(state->u.e2.reg.pfrf, "PF9");
    //     state->u.e2.fld.pfrf.pfa= cm_object_get_child_by_name(state->u.e2.reg.pfrf, "PFA");
    //     state->u.e2.fld.pfrf.pfb= cm_object_get_child_by_name(state->u.e2.reg.pfrf, "PFB");
    //     state->u.e2.fld.pfrf.pfc= cm_object_get_child_by_name(state->u.e2.reg.pfrf, "PFC");

    //     // PCR0bitfields.

    //     // PCR1bitfields.

    //     // PCR2bitfields.

    //     // PCR3bitfields.

    //     // PCR4bitfields.

    //     // PCR5bitfields.

    //     // PCR6bitfields.

    //     // PCR7bitfields.

    //     // PCR8bitfields.

    //     // PCR9bitfields.

    //     // PCRAbitfields.

    //     // PCRBbitfields.

    //     // PCRCbitfields.

    //     // PCRDbitfields.

    //     // PCREbitfields.

    //     // PCRFbitfields.

    //     // DDR0bitfields.
    //   /*  state->u.e2.fld.ddr0.p00= cm_object_get_child_by_name(state->u.e2.reg.ddr0, "P00");
    //     state->u.e2.fld.ddr0.p01= cm_object_get_child_by_name(state->u.e2.reg.ddr0, "P01");
    //     state->u.e2.fld.ddr0.p02= cm_object_get_child_by_name(state->u.e2.reg.ddr0, "P02");
    //     state->u.e2.fld.ddr0.p03= cm_object_get_child_by_name(state->u.e2.reg.ddr0, "P03");
    //     state->u.e2.fld.ddr0.p04= cm_object_get_child_by_name(state->u.e2.reg.ddr0, "P04");
    //     state->u.e2.fld.ddr0.p05= cm_object_get_child_by_name(state->u.e2.reg.ddr0, "P05");
    //     state->u.e2.fld.ddr0.p06= cm_object_get_child_by_name(state->u.e2.reg.ddr0, "P06");
    //     state->u.e2.fld.ddr0.p07= cm_object_get_child_by_name(state->u.e2.reg.ddr0, "P07");
    //     state->u.e2.fld.ddr0.p08= cm_object_get_child_by_name(state->u.e2.reg.ddr0, "P08");
    //     state->u.e2.fld.ddr0.p09= cm_object_get_child_by_name(state->u.e2.reg.ddr0, "P09");
    //     state->u.e2.fld.ddr0.p0a= cm_object_get_child_by_name(state->u.e2.reg.ddr0, "P0A");
    //   */

    //     // DDR1bitfields.

    //     // DDR2bitfields.

    //     // DDR3bitfields.

    //     // DDR4bitfields.

    //     // DDR5bitfields.

    //     // DDR6bitfields.

    //     // DDR7bitfields.

    //     // DDR8bitfields.

    //     // DDR9bitfields.

    //     // DDRAbitfields.

    //     // DDRBbitfields.

    //     // DDRCbitfields.

    //     // DDRDbitfields.

    //     // DDREbitfields.

    //     // DDRFbitfields.

    //     // PDIR0bitfields.

    //     // PDIR1bitfields.

    //     // PDIR2bitfields.

    //     // PDIR3bitfields.

    //     // PDIR4bitfields.

    //     // PDIR5bitfields.

    //     // PDIR6bitfields.

    //     // PDIR7bitfields.

    //     // PDIR8bitfields.

    //     // PDIR9bitfields.

    //     // PDIRAbitfields.

    //     // PDIRBbitfields.

    //     // PDIRCbitfields.

    //     // PDIRDbitfields.

    //     // PDIREbitfields.

    //     // PDIRFbitfields.

    //     // PDOR0bitfields.

    //     // PDOR1bitfields.

    //     // PDOR2bitfields.

    //     // PDOR3bitfields.

    //     // PDOR4bitfields.

    //     // PDOR5bitfields.

    //     // PDOR6bitfields.

    //     // PDOR7bitfields.

    //     // PDOR8bitfields.

    //     // PDOR9bitfields.

    //     // PDORAbitfields.

    //     // PDORBbitfields.

    //     // PDORCbitfields.

    //     // PDORDbitfields.

    //     // PDOREbitfields.

    //     // PDORFbitfields.

    //     // ADEbitfields.
    //     state->u.e2.fld.ade.an00= cm_object_get_child_by_name(state->u.e2.reg.ade, "AN00");
    //     state->u.e2.fld.ade.an01= cm_object_get_child_by_name(state->u.e2.reg.ade, "AN01");
    //     state->u.e2.fld.ade.an02= cm_object_get_child_by_name(state->u.e2.reg.ade, "AN02");
    //     state->u.e2.fld.ade.an03= cm_object_get_child_by_name(state->u.e2.reg.ade, "AN03");
    //     state->u.e2.fld.ade.an04= cm_object_get_child_by_name(state->u.e2.reg.ade, "AN04");
    //     state->u.e2.fld.ade.an05= cm_object_get_child_by_name(state->u.e2.reg.ade, "AN05");
    //     state->u.e2.fld.ade.an06= cm_object_get_child_by_name(state->u.e2.reg.ade, "AN06");
    //     state->u.e2.fld.ade.an07= cm_object_get_child_by_name(state->u.e2.reg.ade, "AN07");
    //     state->u.e2.fld.ade.an08= cm_object_get_child_by_name(state->u.e2.reg.ade, "AN08");
    //     state->u.e2.fld.ade.an09= cm_object_get_child_by_name(state->u.e2.reg.ade, "AN09");
    //     state->u.e2.fld.ade.an10= cm_object_get_child_by_name(state->u.e2.reg.ade, "AN10");
    //     state->u.e2.fld.ade.an11= cm_object_get_child_by_name(state->u.e2.reg.ade, "AN11");
    //     state->u.e2.fld.ade.an12= cm_object_get_child_by_name(state->u.e2.reg.ade, "AN12");
    //     state->u.e2.fld.ade.an13= cm_object_get_child_by_name(state->u.e2.reg.ade, "AN13");
    //     state->u.e2.fld.ade.an14= cm_object_get_child_by_name(state->u.e2.reg.ade, "AN14");
    //     state->u.e2.fld.ade.an15= cm_object_get_child_by_name(state->u.e2.reg.ade, "AN15");
    //     state->u.e2.fld.ade.an16= cm_object_get_child_by_name(state->u.e2.reg.ade, "AN16");
    //     state->u.e2.fld.ade.an17= cm_object_get_child_by_name(state->u.e2.reg.ade, "AN17");
    //     state->u.e2.fld.ade.an18= cm_object_get_child_by_name(state->u.e2.reg.ade, "AN18");
    //     state->u.e2.fld.ade.an19= cm_object_get_child_by_name(state->u.e2.reg.ade, "AN19");
    //     state->u.e2.fld.ade.an20= cm_object_get_child_by_name(state->u.e2.reg.ade, "AN20");
    //     state->u.e2.fld.ade.an21= cm_object_get_child_by_name(state->u.e2.reg.ade, "AN21");
    //     state->u.e2.fld.ade.an22= cm_object_get_child_by_name(state->u.e2.reg.ade, "AN22");
    //     state->u.e2.fld.ade.an23= cm_object_get_child_by_name(state->u.e2.reg.ade, "AN23");
    //     state->u.e2.fld.ade.an24= cm_object_get_child_by_name(state->u.e2.reg.ade, "AN24");
    //     state->u.e2.fld.ade.an25= cm_object_get_child_by_name(state->u.e2.reg.ade, "AN25");
    //     state->u.e2.fld.ade.an26= cm_object_get_child_by_name(state->u.e2.reg.ade, "AN26");
    //     state->u.e2.fld.ade.an27= cm_object_get_child_by_name(state->u.e2.reg.ade, "AN27");
    //     state->u.e2.fld.ade.an28= cm_object_get_child_by_name(state->u.e2.reg.ade, "AN28");
    //     state->u.e2.fld.ade.an29= cm_object_get_child_by_name(state->u.e2.reg.ade, "AN29");
    //     state->u.e2.fld.ade.an30= cm_object_get_child_by_name(state->u.e2.reg.ade, "AN30");
    //     state->u.e2.fld.ade.an31= cm_object_get_child_by_name(state->u.e2.reg.ade, "AN31");

    //     // SPSRbitfields.
    //     state->u.e2.fld.spsr.mainxc= cm_object_get_child_by_name(state->u.e2.reg.spsr, "MAINXC");
    //     state->u.e2.fld.spsr.usb0c= cm_object_get_child_by_name(state->u.e2.reg.spsr, "USB0C");
    //     state->u.e2.fld.spsr.usb1c= cm_object_get_child_by_name(state->u.e2.reg.spsr, "USB1C");

    //     // EPFR00bitfields.
    //     state->u.e2.fld.epfr00.nmis= cm_object_get_child_by_name(state->u.e2.reg.epfr00, "NMIS");
    //     state->u.e2.fld.epfr00.croute= cm_object_get_child_by_name(state->u.e2.reg.epfr00, "CROUTE");
    //     state->u.e2.fld.epfr00.rtccoe= cm_object_get_child_by_name(state->u.e2.reg.epfr00, "RTCCOE");
    //     state->u.e2.fld.epfr00.suboute= cm_object_get_child_by_name(state->u.e2.reg.epfr00, "SUBOUTE");
    //     state->u.e2.fld.epfr00.usbp0e= cm_object_get_child_by_name(state->u.e2.reg.epfr00, "USBP0E");
    //     state->u.e2.fld.epfr00.usbp1e= cm_object_get_child_by_name(state->u.e2.reg.epfr00, "USBP1E");
    //     state->u.e2.fld.epfr00.jtagen0b= cm_object_get_child_by_name(state->u.e2.reg.epfr00, "JTAGEN0B");
    //     state->u.e2.fld.epfr00.jtagen1s= cm_object_get_child_by_name(state->u.e2.reg.epfr00, "JTAGEN1S");
    //     state->u.e2.fld.epfr00.trc0e= cm_object_get_child_by_name(state->u.e2.reg.epfr00, "TRC0E");
    //     state->u.e2.fld.epfr00.trc1e= cm_object_get_child_by_name(state->u.e2.reg.epfr00, "TRC1E");
    //     state->u.e2.fld.epfr00.trc2e= cm_object_get_child_by_name(state->u.e2.reg.epfr00, "TRC2E");
    //     state->u.e2.fld.epfr00.trc3e= cm_object_get_child_by_name(state->u.e2.reg.epfr00, "TRC3E");

    //     // EPFR01bitfields.
    //     state->u.e2.fld.epfr01.rto00e= cm_object_get_child_by_name(state->u.e2.reg.epfr01, "RTO00E");
    //     state->u.e2.fld.epfr01.rto01e= cm_object_get_child_by_name(state->u.e2.reg.epfr01, "RTO01E");
    //     state->u.e2.fld.epfr01.rto02e= cm_object_get_child_by_name(state->u.e2.reg.epfr01, "RTO02E");
    //     state->u.e2.fld.epfr01.rto03e= cm_object_get_child_by_name(state->u.e2.reg.epfr01, "RTO03E");
    //     state->u.e2.fld.epfr01.rto04e= cm_object_get_child_by_name(state->u.e2.reg.epfr01, "RTO04E");
    //     state->u.e2.fld.epfr01.rto05e= cm_object_get_child_by_name(state->u.e2.reg.epfr01, "RTO05E");
    //     state->u.e2.fld.epfr01.dtti0c= cm_object_get_child_by_name(state->u.e2.reg.epfr01, "DTTI0C");
    //     state->u.e2.fld.epfr01.dtti0s= cm_object_get_child_by_name(state->u.e2.reg.epfr01, "DTTI0S");
    //     state->u.e2.fld.epfr01.frck0s= cm_object_get_child_by_name(state->u.e2.reg.epfr01, "FRCK0S");
    //     state->u.e2.fld.epfr01.ic00s= cm_object_get_child_by_name(state->u.e2.reg.epfr01, "IC00S");
    //     state->u.e2.fld.epfr01.ic01s= cm_object_get_child_by_name(state->u.e2.reg.epfr01, "IC01S");
    //     state->u.e2.fld.epfr01.ic02s= cm_object_get_child_by_name(state->u.e2.reg.epfr01, "IC02S");
    //     state->u.e2.fld.epfr01.ic03s= cm_object_get_child_by_name(state->u.e2.reg.epfr01, "IC03S");

    //     // EPFR02bitfields.
    //     state->u.e2.fld.epfr02.rto10e= cm_object_get_child_by_name(state->u.e2.reg.epfr02, "RTO10E");
    //     state->u.e2.fld.epfr02.rto11e= cm_object_get_child_by_name(state->u.e2.reg.epfr02, "RTO11E");
    //     state->u.e2.fld.epfr02.rto12e= cm_object_get_child_by_name(state->u.e2.reg.epfr02, "RTO12E");
    //     state->u.e2.fld.epfr02.rto13e= cm_object_get_child_by_name(state->u.e2.reg.epfr02, "RTO13E");
    //     state->u.e2.fld.epfr02.rto14e= cm_object_get_child_by_name(state->u.e2.reg.epfr02, "RTO14E");
    //     state->u.e2.fld.epfr02.rto15e= cm_object_get_child_by_name(state->u.e2.reg.epfr02, "RTO15E");
    //     state->u.e2.fld.epfr02.dtti1c= cm_object_get_child_by_name(state->u.e2.reg.epfr02, "DTTI1C");
    //     state->u.e2.fld.epfr02.dtti1s= cm_object_get_child_by_name(state->u.e2.reg.epfr02, "DTTI1S");
    //     state->u.e2.fld.epfr02.frck1s= cm_object_get_child_by_name(state->u.e2.reg.epfr02, "FRCK1S");
    //     state->u.e2.fld.epfr02.ic10s= cm_object_get_child_by_name(state->u.e2.reg.epfr02, "IC10S");
    //     state->u.e2.fld.epfr02.ic11s= cm_object_get_child_by_name(state->u.e2.reg.epfr02, "IC11S");
    //     state->u.e2.fld.epfr02.ic12s= cm_object_get_child_by_name(state->u.e2.reg.epfr02, "IC12S");
    //     state->u.e2.fld.epfr02.ic13s= cm_object_get_child_by_name(state->u.e2.reg.epfr02, "IC13S");

    //     // EPFR03bitfields.
    //     state->u.e2.fld.epfr03.rto20e= cm_object_get_child_by_name(state->u.e2.reg.epfr03, "RTO20E");
    //     state->u.e2.fld.epfr03.rto21e= cm_object_get_child_by_name(state->u.e2.reg.epfr03, "RTO21E");
    //     state->u.e2.fld.epfr03.rto22e= cm_object_get_child_by_name(state->u.e2.reg.epfr03, "RTO22E");
    //     state->u.e2.fld.epfr03.rto23e= cm_object_get_child_by_name(state->u.e2.reg.epfr03, "RTO23E");
    //     state->u.e2.fld.epfr03.rto24e= cm_object_get_child_by_name(state->u.e2.reg.epfr03, "RTO24E");
    //     state->u.e2.fld.epfr03.rto25e= cm_object_get_child_by_name(state->u.e2.reg.epfr03, "RTO25E");
    //     state->u.e2.fld.epfr03.dtti2c= cm_object_get_child_by_name(state->u.e2.reg.epfr03, "DTTI2C");
    //     state->u.e2.fld.epfr03.dtti2s= cm_object_get_child_by_name(state->u.e2.reg.epfr03, "DTTI2S");
    //     state->u.e2.fld.epfr03.frck2s= cm_object_get_child_by_name(state->u.e2.reg.epfr03, "FRCK2S");
    //     state->u.e2.fld.epfr03.ic20s= cm_object_get_child_by_name(state->u.e2.reg.epfr03, "IC20S");
    //     state->u.e2.fld.epfr03.ic21s= cm_object_get_child_by_name(state->u.e2.reg.epfr03, "IC21S");
    //     state->u.e2.fld.epfr03.ic22s= cm_object_get_child_by_name(state->u.e2.reg.epfr03, "IC22S");
    //     state->u.e2.fld.epfr03.ic23s= cm_object_get_child_by_name(state->u.e2.reg.epfr03, "IC23S");

    //     // EPFR04bitfields.
    //     state->u.e2.fld.epfr04.tioa0e= cm_object_get_child_by_name(state->u.e2.reg.epfr04, "TIOA0E");
    //     state->u.e2.fld.epfr04.tiob0s= cm_object_get_child_by_name(state->u.e2.reg.epfr04, "TIOB0S");
    //     state->u.e2.fld.epfr04.tioa1s= cm_object_get_child_by_name(state->u.e2.reg.epfr04, "TIOA1S");
    //     state->u.e2.fld.epfr04.tioa1e= cm_object_get_child_by_name(state->u.e2.reg.epfr04, "TIOA1E");
    //     state->u.e2.fld.epfr04.tiob1s= cm_object_get_child_by_name(state->u.e2.reg.epfr04, "TIOB1S");
    //     state->u.e2.fld.epfr04.tioa2e= cm_object_get_child_by_name(state->u.e2.reg.epfr04, "TIOA2E");
    //     state->u.e2.fld.epfr04.tiob2s= cm_object_get_child_by_name(state->u.e2.reg.epfr04, "TIOB2S");
    //     state->u.e2.fld.epfr04.tioa3s= cm_object_get_child_by_name(state->u.e2.reg.epfr04, "TIOA3S");
    //     state->u.e2.fld.epfr04.tioa3e= cm_object_get_child_by_name(state->u.e2.reg.epfr04, "TIOA3E");
    //     state->u.e2.fld.epfr04.tiob3s= cm_object_get_child_by_name(state->u.e2.reg.epfr04, "TIOB3S");

    //     // EPFR05bitfields.
    //     state->u.e2.fld.epfr05.tioa4e= cm_object_get_child_by_name(state->u.e2.reg.epfr05, "TIOA4E");
    //     state->u.e2.fld.epfr05.tiob4s= cm_object_get_child_by_name(state->u.e2.reg.epfr05, "TIOB4S");
    //     state->u.e2.fld.epfr05.tioa5s= cm_object_get_child_by_name(state->u.e2.reg.epfr05, "TIOA5S");
    //     state->u.e2.fld.epfr05.tioa5e= cm_object_get_child_by_name(state->u.e2.reg.epfr05, "TIOA5E");
    //     state->u.e2.fld.epfr05.tiob5s= cm_object_get_child_by_name(state->u.e2.reg.epfr05, "TIOB5S");
    //     state->u.e2.fld.epfr05.tioa6e= cm_object_get_child_by_name(state->u.e2.reg.epfr05, "TIOA6E");
    //     state->u.e2.fld.epfr05.tiob6s= cm_object_get_child_by_name(state->u.e2.reg.epfr05, "TIOB6S");
    //     state->u.e2.fld.epfr05.tioa7s= cm_object_get_child_by_name(state->u.e2.reg.epfr05, "TIOA7S");
    //     state->u.e2.fld.epfr05.tioa7e= cm_object_get_child_by_name(state->u.e2.reg.epfr05, "TIOA7E");
    //     state->u.e2.fld.epfr05.tiob7s= cm_object_get_child_by_name(state->u.e2.reg.epfr05, "TIOB7S");

    //     // EPFR06bitfields.
    //     state->u.e2.fld.epfr06.eint00s= cm_object_get_child_by_name(state->u.e2.reg.epfr06, "EINT00S");
    //     state->u.e2.fld.epfr06.eint01s= cm_object_get_child_by_name(state->u.e2.reg.epfr06, "EINT01S");
    //     state->u.e2.fld.epfr06.eint02s= cm_object_get_child_by_name(state->u.e2.reg.epfr06, "EINT02S");
    //     state->u.e2.fld.epfr06.eint03s= cm_object_get_child_by_name(state->u.e2.reg.epfr06, "EINT03S");
    //     state->u.e2.fld.epfr06.eint04s= cm_object_get_child_by_name(state->u.e2.reg.epfr06, "EINT04S");
    //     state->u.e2.fld.epfr06.eint05s= cm_object_get_child_by_name(state->u.e2.reg.epfr06, "EINT05S");
    //     state->u.e2.fld.epfr06.eint06s= cm_object_get_child_by_name(state->u.e2.reg.epfr06, "EINT06S");
    //     state->u.e2.fld.epfr06.eint07s= cm_object_get_child_by_name(state->u.e2.reg.epfr06, "EINT07S");
    //     state->u.e2.fld.epfr06.eint08s= cm_object_get_child_by_name(state->u.e2.reg.epfr06, "EINT08S");
    //     state->u.e2.fld.epfr06.eint09s= cm_object_get_child_by_name(state->u.e2.reg.epfr06, "EINT09S");
    //     state->u.e2.fld.epfr06.eint10s= cm_object_get_child_by_name(state->u.e2.reg.epfr06, "EINT10S");
    //     state->u.e2.fld.epfr06.eint11s= cm_object_get_child_by_name(state->u.e2.reg.epfr06, "EINT11S");
    //     state->u.e2.fld.epfr06.eint12s= cm_object_get_child_by_name(state->u.e2.reg.epfr06, "EINT12S");
    //     state->u.e2.fld.epfr06.eint13s= cm_object_get_child_by_name(state->u.e2.reg.epfr06, "EINT13S");
    //     state->u.e2.fld.epfr06.eint14s= cm_object_get_child_by_name(state->u.e2.reg.epfr06, "EINT14S");
    //     state->u.e2.fld.epfr06.eint15s= cm_object_get_child_by_name(state->u.e2.reg.epfr06, "EINT15S");

    //     // EPFR07bitfields.
    //     state->u.e2.fld.epfr07.sin0s= cm_object_get_child_by_name(state->u.e2.reg.epfr07, "SIN0S");
    //     state->u.e2.fld.epfr07.sot0b= cm_object_get_child_by_name(state->u.e2.reg.epfr07, "SOT0B");
    //     state->u.e2.fld.epfr07.sck0b= cm_object_get_child_by_name(state->u.e2.reg.epfr07, "SCK0B");
    //     state->u.e2.fld.epfr07.sin1s= cm_object_get_child_by_name(state->u.e2.reg.epfr07, "SIN1S");
    //     state->u.e2.fld.epfr07.sot1b= cm_object_get_child_by_name(state->u.e2.reg.epfr07, "SOT1B");
    //     state->u.e2.fld.epfr07.sck1b= cm_object_get_child_by_name(state->u.e2.reg.epfr07, "SCK1B");
    //     state->u.e2.fld.epfr07.sin2s= cm_object_get_child_by_name(state->u.e2.reg.epfr07, "SIN2S");
    //     state->u.e2.fld.epfr07.sot2b= cm_object_get_child_by_name(state->u.e2.reg.epfr07, "SOT2B");
    //     state->u.e2.fld.epfr07.sck2b= cm_object_get_child_by_name(state->u.e2.reg.epfr07, "SCK2B");
    //     state->u.e2.fld.epfr07.sin3s= cm_object_get_child_by_name(state->u.e2.reg.epfr07, "SIN3S");
    //     state->u.e2.fld.epfr07.sot3b= cm_object_get_child_by_name(state->u.e2.reg.epfr07, "SOT3B");
    //     state->u.e2.fld.epfr07.sck3b= cm_object_get_child_by_name(state->u.e2.reg.epfr07, "SCK3B");

    //     // EPFR08bitfields.
    //     state->u.e2.fld.epfr08.rts4e= cm_object_get_child_by_name(state->u.e2.reg.epfr08, "RTS4E");
    //     state->u.e2.fld.epfr08.cts4s= cm_object_get_child_by_name(state->u.e2.reg.epfr08, "CTS4S");
    //     state->u.e2.fld.epfr08.sin4s= cm_object_get_child_by_name(state->u.e2.reg.epfr08, "SIN4S");
    //     state->u.e2.fld.epfr08.sot4b= cm_object_get_child_by_name(state->u.e2.reg.epfr08, "SOT4B");
    //     state->u.e2.fld.epfr08.sck4b= cm_object_get_child_by_name(state->u.e2.reg.epfr08, "SCK4B");
    //     state->u.e2.fld.epfr08.sin5s= cm_object_get_child_by_name(state->u.e2.reg.epfr08, "SIN5S");
    //     state->u.e2.fld.epfr08.sot5b= cm_object_get_child_by_name(state->u.e2.reg.epfr08, "SOT5B");
    //     state->u.e2.fld.epfr08.sck5b= cm_object_get_child_by_name(state->u.e2.reg.epfr08, "SCK5B");
    //     state->u.e2.fld.epfr08.sin6s= cm_object_get_child_by_name(state->u.e2.reg.epfr08, "SIN6S");
    //     state->u.e2.fld.epfr08.sot6b= cm_object_get_child_by_name(state->u.e2.reg.epfr08, "SOT6B");
    //     state->u.e2.fld.epfr08.sck6b= cm_object_get_child_by_name(state->u.e2.reg.epfr08, "SCK6B");
    //     state->u.e2.fld.epfr08.sin7s= cm_object_get_child_by_name(state->u.e2.reg.epfr08, "SIN7S");
    //     state->u.e2.fld.epfr08.sot7b= cm_object_get_child_by_name(state->u.e2.reg.epfr08, "SOT7B");
    //     state->u.e2.fld.epfr08.sck7b= cm_object_get_child_by_name(state->u.e2.reg.epfr08, "SCK7B");
    //     state->u.e2.fld.epfr08.rts5e= cm_object_get_child_by_name(state->u.e2.reg.epfr08, "RTS5E");
    //     state->u.e2.fld.epfr08.cts5s= cm_object_get_child_by_name(state->u.e2.reg.epfr08, "CTS5S");

    //     // EPFR09bitfields.
    //     state->u.e2.fld.epfr09.qain0s= cm_object_get_child_by_name(state->u.e2.reg.epfr09, "QAIN0S");
    //     state->u.e2.fld.epfr09.qbin0s= cm_object_get_child_by_name(state->u.e2.reg.epfr09, "QBIN0S");
    //     state->u.e2.fld.epfr09.qzin0s= cm_object_get_child_by_name(state->u.e2.reg.epfr09, "QZIN0S");
    //     state->u.e2.fld.epfr09.qain1s= cm_object_get_child_by_name(state->u.e2.reg.epfr09, "QAIN1S");
    //     state->u.e2.fld.epfr09.qbin1s= cm_object_get_child_by_name(state->u.e2.reg.epfr09, "QBIN1S");
    //     state->u.e2.fld.epfr09.qzin1s= cm_object_get_child_by_name(state->u.e2.reg.epfr09, "QZIN1S");
    //     state->u.e2.fld.epfr09.adtrg0s= cm_object_get_child_by_name(state->u.e2.reg.epfr09, "ADTRG0S");
    //     state->u.e2.fld.epfr09.adtrg1s= cm_object_get_child_by_name(state->u.e2.reg.epfr09, "ADTRG1S");
    //     state->u.e2.fld.epfr09.adtrg2s= cm_object_get_child_by_name(state->u.e2.reg.epfr09, "ADTRG2S");
    //     state->u.e2.fld.epfr09.crx0s= cm_object_get_child_by_name(state->u.e2.reg.epfr09, "CRX0S");
    //     state->u.e2.fld.epfr09.ctx0e= cm_object_get_child_by_name(state->u.e2.reg.epfr09, "CTX0E");
    //     state->u.e2.fld.epfr09.crx1s= cm_object_get_child_by_name(state->u.e2.reg.epfr09, "CRX1S");
    //     state->u.e2.fld.epfr09.ctx1e= cm_object_get_child_by_name(state->u.e2.reg.epfr09, "CTX1E");

    //     // EPFR10bitfields.
    //     state->u.e2.fld.epfr10.uedefb= cm_object_get_child_by_name(state->u.e2.reg.epfr10, "UEDEFB");
    //     state->u.e2.fld.epfr10.uedthb= cm_object_get_child_by_name(state->u.e2.reg.epfr10, "UEDTHB");
    //     state->u.e2.fld.epfr10.ueclke= cm_object_get_child_by_name(state->u.e2.reg.epfr10, "UECLKE");
    //     state->u.e2.fld.epfr10.uewexe= cm_object_get_child_by_name(state->u.e2.reg.epfr10, "UEWEXE");
    //     state->u.e2.fld.epfr10.uedqme= cm_object_get_child_by_name(state->u.e2.reg.epfr10, "UEDQME");
    //     state->u.e2.fld.epfr10.ueoexe= cm_object_get_child_by_name(state->u.e2.reg.epfr10, "UEOEXE");
    //     state->u.e2.fld.epfr10.ueflse= cm_object_get_child_by_name(state->u.e2.reg.epfr10, "UEFLSE");
    //     state->u.e2.fld.epfr10.uecs1e= cm_object_get_child_by_name(state->u.e2.reg.epfr10, "UECS1E");
    //     state->u.e2.fld.epfr10.uecs2e= cm_object_get_child_by_name(state->u.e2.reg.epfr10, "UECS2E");
    //     state->u.e2.fld.epfr10.uecs3e= cm_object_get_child_by_name(state->u.e2.reg.epfr10, "UECS3E");
    //     state->u.e2.fld.epfr10.uecs4e= cm_object_get_child_by_name(state->u.e2.reg.epfr10, "UECS4E");
    //     state->u.e2.fld.epfr10.uecs5e= cm_object_get_child_by_name(state->u.e2.reg.epfr10, "UECS5E");
    //     state->u.e2.fld.epfr10.uecs6e= cm_object_get_child_by_name(state->u.e2.reg.epfr10, "UECS6E");
    //     state->u.e2.fld.epfr10.uecs7e= cm_object_get_child_by_name(state->u.e2.reg.epfr10, "UECS7E");
    //     state->u.e2.fld.epfr10.ueaooe= cm_object_get_child_by_name(state->u.e2.reg.epfr10, "UEAOOE");
    //     state->u.e2.fld.epfr10.uea08e= cm_object_get_child_by_name(state->u.e2.reg.epfr10, "UEA08E");
    //     state->u.e2.fld.epfr10.uea09e= cm_object_get_child_by_name(state->u.e2.reg.epfr10, "UEA09E");
    //     state->u.e2.fld.epfr10.uea10e= cm_object_get_child_by_name(state->u.e2.reg.epfr10, "UEA10E");
    //     state->u.e2.fld.epfr10.uea11e= cm_object_get_child_by_name(state->u.e2.reg.epfr10, "UEA11E");
    //     state->u.e2.fld.epfr10.uea12e= cm_object_get_child_by_name(state->u.e2.reg.epfr10, "UEA12E");
    //     state->u.e2.fld.epfr10.uea13e= cm_object_get_child_by_name(state->u.e2.reg.epfr10, "UEA13E");
    //     state->u.e2.fld.epfr10.uea14e= cm_object_get_child_by_name(state->u.e2.reg.epfr10, "UEA14E");
    //     state->u.e2.fld.epfr10.uea15e= cm_object_get_child_by_name(state->u.e2.reg.epfr10, "UEA15E");
    //     state->u.e2.fld.epfr10.uea16e= cm_object_get_child_by_name(state->u.e2.reg.epfr10, "UEA16E");
    //     state->u.e2.fld.epfr10.uea17e= cm_object_get_child_by_name(state->u.e2.reg.epfr10, "UEA17E");
    //     state->u.e2.fld.epfr10.uea18e= cm_object_get_child_by_name(state->u.e2.reg.epfr10, "UEA18E");
    //     state->u.e2.fld.epfr10.uea19e= cm_object_get_child_by_name(state->u.e2.reg.epfr10, "UEA19E");
    //     state->u.e2.fld.epfr10.uea20e= cm_object_get_child_by_name(state->u.e2.reg.epfr10, "UEA20E");
    //     state->u.e2.fld.epfr10.uea21e= cm_object_get_child_by_name(state->u.e2.reg.epfr10, "UEA21E");
    //     state->u.e2.fld.epfr10.uea22e= cm_object_get_child_by_name(state->u.e2.reg.epfr10, "UEA22E");
    //     state->u.e2.fld.epfr10.uea23e= cm_object_get_child_by_name(state->u.e2.reg.epfr10, "UEA23E");
    //     state->u.e2.fld.epfr10.uea24e= cm_object_get_child_by_name(state->u.e2.reg.epfr10, "UEA24E");

    //     // EPFR11bitfields.
    //     state->u.e2.fld.epfr11.uealee= cm_object_get_child_by_name(state->u.e2.reg.epfr11, "UEALEE");
    //     state->u.e2.fld.epfr11.uecs0e= cm_object_get_child_by_name(state->u.e2.reg.epfr11, "UECS0E");
    //     state->u.e2.fld.epfr11.uea01e= cm_object_get_child_by_name(state->u.e2.reg.epfr11, "UEA01E");
    //     state->u.e2.fld.epfr11.uea02e= cm_object_get_child_by_name(state->u.e2.reg.epfr11, "UEA02E");
    //     state->u.e2.fld.epfr11.uea03e= cm_object_get_child_by_name(state->u.e2.reg.epfr11, "UEA03E");
    //     state->u.e2.fld.epfr11.uea04e= cm_object_get_child_by_name(state->u.e2.reg.epfr11, "UEA04E");
    //     state->u.e2.fld.epfr11.uea05e= cm_object_get_child_by_name(state->u.e2.reg.epfr11, "UEA05E");
    //     state->u.e2.fld.epfr11.uea06e= cm_object_get_child_by_name(state->u.e2.reg.epfr11, "UEA06E");
    //     state->u.e2.fld.epfr11.uea07e= cm_object_get_child_by_name(state->u.e2.reg.epfr11, "UEA07E");
    //     state->u.e2.fld.epfr11.ued00b= cm_object_get_child_by_name(state->u.e2.reg.epfr11, "UED00B");
    //     state->u.e2.fld.epfr11.ued01b= cm_object_get_child_by_name(state->u.e2.reg.epfr11, "UED01B");
    //     state->u.e2.fld.epfr11.ued02b= cm_object_get_child_by_name(state->u.e2.reg.epfr11, "UED02B");
    //     state->u.e2.fld.epfr11.ued03b= cm_object_get_child_by_name(state->u.e2.reg.epfr11, "UED03B");
    //     state->u.e2.fld.epfr11.ued04b= cm_object_get_child_by_name(state->u.e2.reg.epfr11, "UED04B");
    //     state->u.e2.fld.epfr11.ued05b= cm_object_get_child_by_name(state->u.e2.reg.epfr11, "UED05B");
    //     state->u.e2.fld.epfr11.ued06b= cm_object_get_child_by_name(state->u.e2.reg.epfr11, "UED06B");
    //     state->u.e2.fld.epfr11.ued07b= cm_object_get_child_by_name(state->u.e2.reg.epfr11, "UED07B");
    //     state->u.e2.fld.epfr11.ued08b= cm_object_get_child_by_name(state->u.e2.reg.epfr11, "UED08B");
    //     state->u.e2.fld.epfr11.ued09b= cm_object_get_child_by_name(state->u.e2.reg.epfr11, "UED09B");
    //     state->u.e2.fld.epfr11.ued10b= cm_object_get_child_by_name(state->u.e2.reg.epfr11, "UED10B");
    //     state->u.e2.fld.epfr11.ued11b= cm_object_get_child_by_name(state->u.e2.reg.epfr11, "UED11B");
    //     state->u.e2.fld.epfr11.ued12b= cm_object_get_child_by_name(state->u.e2.reg.epfr11, "UED12B");
    //     state->u.e2.fld.epfr11.ued13b= cm_object_get_child_by_name(state->u.e2.reg.epfr11, "UED13B");
    //     state->u.e2.fld.epfr11.ued14b= cm_object_get_child_by_name(state->u.e2.reg.epfr11, "UED14B");
    //     state->u.e2.fld.epfr11.ued15b= cm_object_get_child_by_name(state->u.e2.reg.epfr11, "UED15B");
    //     state->u.e2.fld.epfr11.uerlc= cm_object_get_child_by_name(state->u.e2.reg.epfr11, "UERLC");

    //     // EPFR12bitfields.
    //     state->u.e2.fld.epfr12.tioa8e= cm_object_get_child_by_name(state->u.e2.reg.epfr12, "TIOA8E");
    //     state->u.e2.fld.epfr12.tiob8s= cm_object_get_child_by_name(state->u.e2.reg.epfr12, "TIOB8S");
    //     state->u.e2.fld.epfr12.tioa9s= cm_object_get_child_by_name(state->u.e2.reg.epfr12, "TIOA9S");
    //     state->u.e2.fld.epfr12.tioa9e= cm_object_get_child_by_name(state->u.e2.reg.epfr12, "TIOA9E");
    //     state->u.e2.fld.epfr12.tiob9s= cm_object_get_child_by_name(state->u.e2.reg.epfr12, "TIOB9S");
    //     state->u.e2.fld.epfr12.tioa10e= cm_object_get_child_by_name(state->u.e2.reg.epfr12, "TIOA10E");
    //     state->u.e2.fld.epfr12.tiob10s= cm_object_get_child_by_name(state->u.e2.reg.epfr12, "TIOB10S");
    //     state->u.e2.fld.epfr12.tioa11s= cm_object_get_child_by_name(state->u.e2.reg.epfr12, "TIOA11S");
    //     state->u.e2.fld.epfr12.tioa11e= cm_object_get_child_by_name(state->u.e2.reg.epfr12, "TIOA11E");
    //     state->u.e2.fld.epfr12.tiob11s= cm_object_get_child_by_name(state->u.e2.reg.epfr12, "TIOB11S");

    //     // EPFR13bitfields.
    //     state->u.e2.fld.epfr13.tioa12e= cm_object_get_child_by_name(state->u.e2.reg.epfr13, "TIOA12E");
    //     state->u.e2.fld.epfr13.tiob12s= cm_object_get_child_by_name(state->u.e2.reg.epfr13, "TIOB12S");
    //     state->u.e2.fld.epfr13.tioa13s= cm_object_get_child_by_name(state->u.e2.reg.epfr13, "TIOA13S");
    //     state->u.e2.fld.epfr13.tioa13e= cm_object_get_child_by_name(state->u.e2.reg.epfr13, "TIOA13E");
    //     state->u.e2.fld.epfr13.tiob13s= cm_object_get_child_by_name(state->u.e2.reg.epfr13, "TIOB13S");
    //     state->u.e2.fld.epfr13.tioa14e= cm_object_get_child_by_name(state->u.e2.reg.epfr13, "TIOA14E");
    //     state->u.e2.fld.epfr13.tiob14s= cm_object_get_child_by_name(state->u.e2.reg.epfr13, "TIOB14S");
    //     state->u.e2.fld.epfr13.tioa15s= cm_object_get_child_by_name(state->u.e2.reg.epfr13, "TIOA15S");
    //     state->u.e2.fld.epfr13.tioa15e= cm_object_get_child_by_name(state->u.e2.reg.epfr13, "TIOA15E");
    //     state->u.e2.fld.epfr13.tiob15s= cm_object_get_child_by_name(state->u.e2.reg.epfr13, "TIOB15S");

    //     // EPFR14bitfields.
    //     state->u.e2.fld.epfr14.qain2s= cm_object_get_child_by_name(state->u.e2.reg.epfr14, "QAIN2S");
    //     state->u.e2.fld.epfr14.qbin2s= cm_object_get_child_by_name(state->u.e2.reg.epfr14, "QBIN2S");
    //     state->u.e2.fld.epfr14.qzin2s= cm_object_get_child_by_name(state->u.e2.reg.epfr14, "QZIN2S");
    //     state->u.e2.fld.epfr14.e_td0e= cm_object_get_child_by_name(state->u.e2.reg.epfr14, "E_TD0E");
    //     state->u.e2.fld.epfr14.e_td1e= cm_object_get_child_by_name(state->u.e2.reg.epfr14, "E_TD1E");
    //     state->u.e2.fld.epfr14.e_te0e= cm_object_get_child_by_name(state->u.e2.reg.epfr14, "E_TE0E");
    //     state->u.e2.fld.epfr14.e_te1e= cm_object_get_child_by_name(state->u.e2.reg.epfr14, "E_TE1E");
    //     state->u.e2.fld.epfr14.e_mc0e= cm_object_get_child_by_name(state->u.e2.reg.epfr14, "E_MC0E");
    //     state->u.e2.fld.epfr14.e_mc1b= cm_object_get_child_by_name(state->u.e2.reg.epfr14, "E_MC1B");
    //     state->u.e2.fld.epfr14.e_md0b= cm_object_get_child_by_name(state->u.e2.reg.epfr14, "E_MD0B");
    //     state->u.e2.fld.epfr14.e_md1b= cm_object_get_child_by_name(state->u.e2.reg.epfr14, "E_MD1B");
    //     state->u.e2.fld.epfr14.e_cke= cm_object_get_child_by_name(state->u.e2.reg.epfr14, "E_CKE");
    //     state->u.e2.fld.epfr14.e_pse= cm_object_get_child_by_name(state->u.e2.reg.epfr14, "E_PSE");
    //     state->u.e2.fld.epfr14.e_splc= cm_object_get_child_by_name(state->u.e2.reg.epfr14, "E_SPLC");

    //     // EPFR15bitfields.
    //     state->u.e2.fld.epfr15.eint16s= cm_object_get_child_by_name(state->u.e2.reg.epfr15, "EINT16S");
    //     state->u.e2.fld.epfr15.eint17s= cm_object_get_child_by_name(state->u.e2.reg.epfr15, "EINT17S");
    //     state->u.e2.fld.epfr15.eint18s= cm_object_get_child_by_name(state->u.e2.reg.epfr15, "EINT18S");
    //     state->u.e2.fld.epfr15.eint19s= cm_object_get_child_by_name(state->u.e2.reg.epfr15, "EINT19S");
    //     state->u.e2.fld.epfr15.eint20s= cm_object_get_child_by_name(state->u.e2.reg.epfr15, "EINT20S");
    //     state->u.e2.fld.epfr15.eint21s= cm_object_get_child_by_name(state->u.e2.reg.epfr15, "EINT21S");
    //     state->u.e2.fld.epfr15.eint22s= cm_object_get_child_by_name(state->u.e2.reg.epfr15, "EINT22S");
    //     state->u.e2.fld.epfr15.eint23s= cm_object_get_child_by_name(state->u.e2.reg.epfr15, "EINT23S");
    //     state->u.e2.fld.epfr15.eint24s= cm_object_get_child_by_name(state->u.e2.reg.epfr15, "EINT24S");
    //     state->u.e2.fld.epfr15.eint25s= cm_object_get_child_by_name(state->u.e2.reg.epfr15, "EINT25S");
    //     state->u.e2.fld.epfr15.eint26s= cm_object_get_child_by_name(state->u.e2.reg.epfr15, "EINT26S");
    //     state->u.e2.fld.epfr15.eint27s= cm_object_get_child_by_name(state->u.e2.reg.epfr15, "EINT27S");
    //     state->u.e2.fld.epfr15.eint28s= cm_object_get_child_by_name(state->u.e2.reg.epfr15, "EINT28S");
    //     state->u.e2.fld.epfr15.eint29s= cm_object_get_child_by_name(state->u.e2.reg.epfr15, "EINT29S");
    //     state->u.e2.fld.epfr15.eint30s= cm_object_get_child_by_name(state->u.e2.reg.epfr15, "EINT30S");
    //     state->u.e2.fld.epfr15.eint31s= cm_object_get_child_by_name(state->u.e2.reg.epfr15, "EINT31S");

    //     // EPFR16bitfields.
    //     state->u.e2.fld.epfr16.scs6b= cm_object_get_child_by_name(state->u.e2.reg.epfr16, "SCS6B");
    //     state->u.e2.fld.epfr16.scs7b= cm_object_get_child_by_name(state->u.e2.reg.epfr16, "SCS7B");
    //     state->u.e2.fld.epfr16.sin8s= cm_object_get_child_by_name(state->u.e2.reg.epfr16, "SIN8S");
    //     state->u.e2.fld.epfr16.sot8b= cm_object_get_child_by_name(state->u.e2.reg.epfr16, "SOT8B");
    //     state->u.e2.fld.epfr16.sck8b= cm_object_get_child_by_name(state->u.e2.reg.epfr16, "SCK8B");
    //     state->u.e2.fld.epfr16.sin9s= cm_object_get_child_by_name(state->u.e2.reg.epfr16, "SIN9S");
    //     state->u.e2.fld.epfr16.sot9b= cm_object_get_child_by_name(state->u.e2.reg.epfr16, "SOT9B");
    //     state->u.e2.fld.epfr16.sck9b= cm_object_get_child_by_name(state->u.e2.reg.epfr16, "SCK9B");
    //     state->u.e2.fld.epfr16.sin10s= cm_object_get_child_by_name(state->u.e2.reg.epfr16, "SIN10S");
    //     state->u.e2.fld.epfr16.sot10b= cm_object_get_child_by_name(state->u.e2.reg.epfr16, "SOT10B");
    //     state->u.e2.fld.epfr16.sck10b= cm_object_get_child_by_name(state->u.e2.reg.epfr16, "SCK10B");
    //     state->u.e2.fld.epfr16.sin11s= cm_object_get_child_by_name(state->u.e2.reg.epfr16, "SIN11S");
    //     state->u.e2.fld.epfr16.sot11b= cm_object_get_child_by_name(state->u.e2.reg.epfr16, "SOT11B");
    //     state->u.e2.fld.epfr16.sck11b= cm_object_get_child_by_name(state->u.e2.reg.epfr16, "SCK11B");
    //     state->u.e2.fld.epfr16.sfmpac= cm_object_get_child_by_name(state->u.e2.reg.epfr16, "SFMPAC");
    //     state->u.e2.fld.epfr16.sfmpbc= cm_object_get_child_by_name(state->u.e2.reg.epfr16, "SFMPBC");

    //     // EPFR17bitfields.
    //     state->u.e2.fld.epfr17.sin12s= cm_object_get_child_by_name(state->u.e2.reg.epfr17, "SIN12S");
    //     state->u.e2.fld.epfr17.sot12b= cm_object_get_child_by_name(state->u.e2.reg.epfr17, "SOT12B");
    //     state->u.e2.fld.epfr17.sck12b= cm_object_get_child_by_name(state->u.e2.reg.epfr17, "SCK12B");
    //     state->u.e2.fld.epfr17.sin13s= cm_object_get_child_by_name(state->u.e2.reg.epfr17, "SIN13S");
    //     state->u.e2.fld.epfr17.sot13b= cm_object_get_child_by_name(state->u.e2.reg.epfr17, "SOT13B");
    //     state->u.e2.fld.epfr17.sck13b= cm_object_get_child_by_name(state->u.e2.reg.epfr17, "SCK13B");
    //     state->u.e2.fld.epfr17.sin14s= cm_object_get_child_by_name(state->u.e2.reg.epfr17, "SIN14S");
    //     state->u.e2.fld.epfr17.sot14b= cm_object_get_child_by_name(state->u.e2.reg.epfr17, "SOT14B");
    //     state->u.e2.fld.epfr17.sck14b= cm_object_get_child_by_name(state->u.e2.reg.epfr17, "SCK14B");
    //     state->u.e2.fld.epfr17.sin15s= cm_object_get_child_by_name(state->u.e2.reg.epfr17, "SIN15S");
    //     state->u.e2.fld.epfr17.sot15b= cm_object_get_child_by_name(state->u.e2.reg.epfr17, "SOT15B");
    //     state->u.e2.fld.epfr17.sck15b= cm_object_get_child_by_name(state->u.e2.reg.epfr17, "SCK15B");

    //     // EPFR18bitfields.
    //     state->u.e2.fld.epfr18.cecr0b= cm_object_get_child_by_name(state->u.e2.reg.epfr18, "CECR0B");
    //     state->u.e2.fld.epfr18.cecr1b= cm_object_get_child_by_name(state->u.e2.reg.epfr18, "CECR1B");
    //     state->u.e2.fld.epfr18.qain3s= cm_object_get_child_by_name(state->u.e2.reg.epfr18, "QAIN3S");
    //     state->u.e2.fld.epfr18.qbin3s= cm_object_get_child_by_name(state->u.e2.reg.epfr18, "QBIN3S");
    //     state->u.e2.fld.epfr18.qzin3s= cm_object_get_child_by_name(state->u.e2.reg.epfr18, "QZIN3S");
    //     state->u.e2.fld.epfr18.sdclke= cm_object_get_child_by_name(state->u.e2.reg.epfr18, "SDCLKE");
    //     state->u.e2.fld.epfr18.sdcmdb= cm_object_get_child_by_name(state->u.e2.reg.epfr18, "SDCMDB");
    //     state->u.e2.fld.epfr18.sddata0b= cm_object_get_child_by_name(state->u.e2.reg.epfr18, "SDDATA0B");
    //     state->u.e2.fld.epfr18.sddata1b= cm_object_get_child_by_name(state->u.e2.reg.epfr18, "SDDATA1B");
    //     state->u.e2.fld.epfr18.sddata2b= cm_object_get_child_by_name(state->u.e2.reg.epfr18, "SDDATA2B");
    //     state->u.e2.fld.epfr18.sddata3b= cm_object_get_child_by_name(state->u.e2.reg.epfr18, "SDDATA3B");
    //     state->u.e2.fld.epfr18.sdcds= cm_object_get_child_by_name(state->u.e2.reg.epfr18, "SDCDS");
    //     state->u.e2.fld.epfr18.sdwps= cm_object_get_child_by_name(state->u.e2.reg.epfr18, "SDWPS");

    //     // EPFR19bitfields.

    //     // EPFR20bitfields.
    //     state->u.e2.fld.epfr20.uesmcke= cm_object_get_child_by_name(state->u.e2.reg.epfr20, "UESMCKE");
    //     state->u.e2.fld.epfr20.uesmcee= cm_object_get_child_by_name(state->u.e2.reg.epfr20, "UESMCEE");
    //     state->u.e2.fld.epfr20.uerase= cm_object_get_child_by_name(state->u.e2.reg.epfr20, "UERASE");
    //     state->u.e2.fld.epfr20.uecase= cm_object_get_child_by_name(state->u.e2.reg.epfr20, "UECASE");
    //     state->u.e2.fld.epfr20.uedwexe= cm_object_get_child_by_name(state->u.e2.reg.epfr20, "UEDWEXE");
    //     state->u.e2.fld.epfr20.uecsxe= cm_object_get_child_by_name(state->u.e2.reg.epfr20, "UECSXE");
    //     state->u.e2.fld.epfr20.uedqm2e= cm_object_get_child_by_name(state->u.e2.reg.epfr20, "UEDQM2E");
    //     state->u.e2.fld.epfr20.uedqm3e= cm_object_get_child_by_name(state->u.e2.reg.epfr20, "UEDQM3E");
    //     state->u.e2.fld.epfr20.uedthhb= cm_object_get_child_by_name(state->u.e2.reg.epfr20, "UEDTHHB");
    //     state->u.e2.fld.epfr20.ued16b= cm_object_get_child_by_name(state->u.e2.reg.epfr20, "UED16B");
    //     state->u.e2.fld.epfr20.ued17b= cm_object_get_child_by_name(state->u.e2.reg.epfr20, "UED17B");
    //     state->u.e2.fld.epfr20.ued18b= cm_object_get_child_by_name(state->u.e2.reg.epfr20, "UED18B");
    //     state->u.e2.fld.epfr20.ued19b= cm_object_get_child_by_name(state->u.e2.reg.epfr20, "UED19B");
    //     state->u.e2.fld.epfr20.ued20b= cm_object_get_child_by_name(state->u.e2.reg.epfr20, "UED20B");
    //     state->u.e2.fld.epfr20.ued21b= cm_object_get_child_by_name(state->u.e2.reg.epfr20, "UED21B");
    //     state->u.e2.fld.epfr20.ued22b= cm_object_get_child_by_name(state->u.e2.reg.epfr20, "UED22B");
    //     state->u.e2.fld.epfr20.ued23b= cm_object_get_child_by_name(state->u.e2.reg.epfr20, "UED23B");
    //     state->u.e2.fld.epfr20.ued24b= cm_object_get_child_by_name(state->u.e2.reg.epfr20, "UED24B");
    //     state->u.e2.fld.epfr20.ued25b= cm_object_get_child_by_name(state->u.e2.reg.epfr20, "UED25B");
    //     state->u.e2.fld.epfr20.ued26b= cm_object_get_child_by_name(state->u.e2.reg.epfr20, "UED26B");
    //     state->u.e2.fld.epfr20.ued27b= cm_object_get_child_by_name(state->u.e2.reg.epfr20, "UED27B");
    //     state->u.e2.fld.epfr20.ued28b= cm_object_get_child_by_name(state->u.e2.reg.epfr20, "UED28B");
    //     state->u.e2.fld.epfr20.ued29b= cm_object_get_child_by_name(state->u.e2.reg.epfr20, "UED29B");
    //     state->u.e2.fld.epfr20.ued30b= cm_object_get_child_by_name(state->u.e2.reg.epfr20, "UED30B");
    //     state->u.e2.fld.epfr20.ued31b= cm_object_get_child_by_name(state->u.e2.reg.epfr20, "UED31B");

    //     // EPFR21bitfields.

    //     // EPFR22bitfields.

    //     // EPFR23bitfields.
    //     state->u.e2.fld.epfr23.scs60e= cm_object_get_child_by_name(state->u.e2.reg.epfr23, "SCS60E");
    //     state->u.e2.fld.epfr23.scs61e= cm_object_get_child_by_name(state->u.e2.reg.epfr23, "SCS61E");
    //     state->u.e2.fld.epfr23.scs62e= cm_object_get_child_by_name(state->u.e2.reg.epfr23, "SCS62E");
    //     state->u.e2.fld.epfr23.scs63e= cm_object_get_child_by_name(state->u.e2.reg.epfr23, "SCS63E");
    //     state->u.e2.fld.epfr23.scs70e= cm_object_get_child_by_name(state->u.e2.reg.epfr23, "SCS70E");
    //     state->u.e2.fld.epfr23.scs71e= cm_object_get_child_by_name(state->u.e2.reg.epfr23, "SCS71E");
    //     state->u.e2.fld.epfr23.scs72e= cm_object_get_child_by_name(state->u.e2.reg.epfr23, "SCS72E");
    //     state->u.e2.fld.epfr23.scs73e= cm_object_get_child_by_name(state->u.e2.reg.epfr23, "SCS73E");

    //     // EPFR24bitfields.
    //     state->u.e2.fld.epfr24.i2sm4_mclk0s= cm_object_get_child_by_name(state->u.e2.reg.epfr24, "I2SM4_MCLK0S");
    //     state->u.e2.fld.epfr24.i2sm4_mclk0e= cm_object_get_child_by_name(state->u.e2.reg.epfr24, "I2SM4_MCLK0E");
    //     state->u.e2.fld.epfr24.i2sm4_sck0b= cm_object_get_child_by_name(state->u.e2.reg.epfr24, "I2SM4_SCK0B");
    //     state->u.e2.fld.epfr24.i2sm4_ws0b= cm_object_get_child_by_name(state->u.e2.reg.epfr24, "I2SM4_WS0B");
    //     state->u.e2.fld.epfr24.i2sm4_sdi0s= cm_object_get_child_by_name(state->u.e2.reg.epfr24, "I2SM4_SDI0S");
    //     state->u.e2.fld.epfr24.i2sm4_sdo0e= cm_object_get_child_by_name(state->u.e2.reg.epfr24, "I2SM4_SDO0E");

    //     // EPFR25bitfields.
    //     state->u.e2.fld.epfr25.mcrx2s= cm_object_get_child_by_name(state->u.e2.reg.epfr25, "MCRX2S");
    //     state->u.e2.fld.epfr25.mctx2e= cm_object_get_child_by_name(state->u.e2.reg.epfr25, "MCTX2E");

    //     // EPFR26bitfields.
    //     state->u.e2.fld.epfr26.q_scke= cm_object_get_child_by_name(state->u.e2.reg.epfr26, "Q_SCKE");
    //     state->u.e2.fld.epfr26.q_cs0e= cm_object_get_child_by_name(state->u.e2.reg.epfr26, "Q_CS0E");
    //     state->u.e2.fld.epfr26.q_cs1e= cm_object_get_child_by_name(state->u.e2.reg.epfr26, "Q_CS1E");
    //     state->u.e2.fld.epfr26.q_cs2e= cm_object_get_child_by_name(state->u.e2.reg.epfr26, "Q_CS2E");
    //     state->u.e2.fld.epfr26.q_cs3e= cm_object_get_child_by_name(state->u.e2.reg.epfr26, "Q_CS3E");
    //     state->u.e2.fld.epfr26.q_io0b= cm_object_get_child_by_name(state->u.e2.reg.epfr26, "Q_IO0B");
    //     state->u.e2.fld.epfr26.q_io1b= cm_object_get_child_by_name(state->u.e2.reg.epfr26, "Q_IO1B");
    //     state->u.e2.fld.epfr26.q_io2b= cm_object_get_child_by_name(state->u.e2.reg.epfr26, "Q_IO2B");
    //     state->u.e2.fld.epfr26.q_io3b= cm_object_get_child_by_name(state->u.e2.reg.epfr26, "Q_IO3B");

    // PZR0bitfields.

    // PZR1bitfields.

    // PZR2bitfields.

    // PZR3bitfields.

    // PZR4bitfields.

    // PZR5bitfields.

    // PZR6bitfields.

    // PZR7bitfields.

    // PZR8bitfields.

    // PZR9bitfields.

    // PZRAbitfields.

    // PZRBbitfields.

    // PZRCbitfields.

    // PZRDbitfields.

    // PZREbitfields.

    // PZRFbitfields.

    // PDSR0bitfields.

    // PDSR1bitfields.

    // PDSR2bitfields.

    // PDSR3bitfields.

    // PDSR4bitfields.

    // PDSR5bitfields.

    // PDSR6bitfields.

    // PDSR7bitfields.

    // PDSR8bitfields.

    // PDSR9bitfields.

    // PDSRAbitfields.

    // PDSRBbitfields.

    // PDSRCbitfields.

    // PDSRDbitfields.

    // PDSREbitfields.

    // PDSRFbitfields.
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// ----- Private --------------------------------------------------------------

#if 0
static peripheral_register_t fm4_gpio_xxx_pre_write_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    FM4GPIOState *state = FM4_GPIO_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);

    // TODO: Add code to adjust the value (like applying some masks,
    // for example prevent setting interrupts not enabled).
    // Also process cleared/set by write 1/0 bits.
    // The returned value will be stored in the register value.

    return full_value;
}

static void fm4_gpio_xxx_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    FM4GPIOState *state = FM4_GPIO_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);
    // The new register value is full_value, the old one is prev_value.

    // TODO: Add code to send the value to the consumer.
}

static peripheral_register_t fm4_gpio_xxx_pre_read_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size)
{
    FM4GPIOState *state = FM4_GPIO_STATE(periph);

    peripheral_register_t value = 0;

    // Add code to get the value from the producer, and return it.

    // This value, possibly masked, will be stored in the register
    // and returned when the register is read.
    return value;
}

static void fm4_gpio_xxx_post_read_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size)
{
    FM4GPIOState *state = FM4_GPIO_STATE(periph);

    peripheral_register_t value = peripheral_register_get_raw_value(reg);

    // TODO: add code to perform the post read actions, like clearing some bits.
}
#endif

// ----------------------------------------------------------------------------

// If EXTI is sensitive to this GPIO pin, set interrupt.
static void fm4_gpio_set_exti_irq(FM4GPIOState *state, int pin, int level)
{
    assert(pin < 16);

    const FM4Capabilities *capabilities = state->capabilities;

    peripheral_register_t exti = 0;

    //   exti = register_bitfield_read_value(state->syscfg->exticr.exti[pin]);

    //  if (exti == (state->port_index - FM4_PORT_GPIO)) {
    //     cm_irq_set(state->exti_irq[pin], level);
    //  }
}

// Identify ODR bits that changed, then notify listeners (like LEDs)
// and trigger interrupts.

static void fm4_gpio_set_odr_irqs(FM4GPIOState *state, uint16_t old_odr,
                                  uint16_t new_odr, int port)
{
    uint16_t changed = old_odr ^ new_odr;
    uint16_t changed_out;
    switch (port)
    {
    case 0:
    { //   2  3  4  green red blue

        changed_out = changed & state->dir_mask;
        uint16_t mask = 1;
        if (changed_out)
        {
            int pin;

            for (pin = 0; pin < FM4_GPIO_PIN_COUNT; pin++, mask <<= 1)
            {
                // If the value of this pin has changed, then update
                // the output IRQ.
                if ((changed_out & mask) != 0)
                {
                    int level = (new_odr & mask) ? 1 : 0;

                    cm_irq_set(state->odr_irq[pin], level);
                }
            }
        }
        break;
    }

    case 1:
    {
        changed_out = changed & state->dir_mask1;
        uint16_t mask = 1;
        //  if (changed_out) {
        int pin;
        for (pin = 0; pin < FM4_GPIO_PIN_COUNT; pin++, mask <<= 1)
        {
            // If the value of this pin has changed, then update
            // the output IRQ.
            if ((changed_out & mask) != 0)
            {
                int level = (new_odr & mask) ? 1 : 0;

                // cm_irq_set(state->odr_irq[pin], level);

                //fm4_gpio_set_exti_irq(state, pin, level);  //TODO
            }
        }
        //   }
        break;
    }

    default:
        break;
    }
    // Compute pins that changed value.

    // Filter changed pins that are outputs - do not touch input pins.
}

static void fm4_gpio_set_pcr_irqs(FM4GPIOState *state, uint16_t old_odr,
                                  uint16_t new_odr)
{
    // Compute pins that changed value.
    uint16_t changed = old_odr ^ new_odr;

    // Filter changed pins that are outputs - do not touch input pins.
    uint16_t changed_out = changed; //& state->dir_mask;   //?????

    uint16_t mask = 1;
    Object *pdir = state->u.e2.reg.pdir0;
    assert(pdir);

    //  uint16_t pcr_value = peripheral_register_get_raw_value(pcr);

    //  if (changed_out) {
    int pin;
    for (pin = 0; pin < FM4_GPIO_PIN_COUNT; pin++, mask <<= 1)
    {
        // If the value of this pin has changed, then update
        // the output IRQ.
        if ((changed_out & mask) != 0)
        {
            int level = (new_odr & mask) ? 1 : 0;

            // cm_irq_set(state->odr_irq[pin], level);
            peripheral_register_or_raw_value(pdir, (1 << pin));

            //fm4_gpio_set_exti_irq(state, pin, level);  //TODO
        }
    }
    //   }
}

static uint32_t fm4_gpio_get_config_bits(uint32_t value, uint32_t bit)
{
    assert(bit < 16);
    return (value >> bit) & 0x1;
}

static void fm4_gpio_update_dir_mask(FM4GPIOState *state, int port)
{
    switch (port)
    {
    case 0:
    {
        uint32_t moder = peripheral_register_get_raw_value(state->u.e2.reg.ddr3);
        int bit;
        uint32_t mode;
        for (bit = 0; bit < 16; bit++)
        {
            mode = fm4_gpio_get_config_bits(moder, bit);
            // If the mode is 1, the bit is output. Otherwise, it
            // is input or has alternate functions.

            if (mode == 1)
            {
                state->dir_mask |= (1 << bit); // Output pin
            }
            else
            {
                state->dir_mask &= ~(1 << bit); // Input pin
            }
        }
        break;
    }
    case 1:
    {
        uint32_t moder = peripheral_register_get_raw_value(state->u.e2.reg.ddr1);
        int bit;
        uint32_t mode;
        for (bit = 0; bit < 16; bit++)
        {
            mode = fm4_gpio_get_config_bits(moder, bit);
            // If the mode is 1, the bit is output. Otherwise, it
            // is input or has alternate functions.

            if (mode == 1)
            {
                state->dir_mask1 |= (1 << bit); // Output pin
            }
            else
            {
                state->dir_mask1 &= ~(1 << bit); // Input pin
            }
        }
        break;
    }
    default:
        printf("no port is given");
        break;
    }
}

// Callback fired when a GPIO input pin changes state (based
// on an external stimulus from the machine).
static void fm4_gpio_in_irq_handler(void *opaque, int n, int level)
{
    qemu_log_mask(LOG_FUNC, "%s(%d,%d) \n", __FUNCTION__, n, level);

    assert(n < 16);

    FM4GPIOState *state = FM4_GPIO_STATE(opaque);
    unsigned pin = n;

    assert(pin < FM4_GPIO_PIN_COUNT);

    const FM4Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *pdir0;
    pdir0 = state->u.e2.reg.pdir0;

    // TODO: check if a mutex is needed,
    // this can be called from the graphic thread.

    if (level == 0)
    {
        // Set the DIR bit.
        peripheral_register_and_raw_value(pdir0, ~(1 << pin));
    }
    else
    {
        // clear the DIR bit.
        peripheral_register_or_raw_value(pdir0, (1 << pin));
    }

    fm4_gpio_set_exti_irq(state, pin, level);
}

static void fm4_gpio_ddr1_post_write_callback(Object *reg, Object *periph,
                                              uint32_t addr, uint32_t offset, unsigned size,
                                              peripheral_register_t value, peripheral_register_t full_value)
{
    FM4GPIOState *state = FM4_GPIO_STATE(periph);
    fm4_gpio_update_dir_mask(state, 1);
}

static void fm4_gpio_pdor2_post_write_callback(Object *reg, Object *periph,
                                               uint32_t addr, uint32_t offset, unsigned size,
                                               peripheral_register_t value, peripheral_register_t full_value)
{
    FM4GPIOState *state = FM4_GPIO_STATE(periph);
    TOUCH_XP_ = full_value & 0x00000001;
    TOUCH_YP_ = (full_value >> 1) & 0x00000001;
}

bool get_TOUCH_X_()
{
    return TOUCH_XP_;
}
bool get_TOUCH_Y_()
{
    return TOUCH_YP_;
}

static void fm4_gpio_pdor1_post_write_callback(Object *reg, Object *periph,
                                               uint32_t addr, uint32_t offset, unsigned size,
                                               peripheral_register_t value, peripheral_register_t full_value)
{

    FM4GPIOState *state = FM4_GPIO_STATE(periph);

    if (flag_state == false)
    {
        pixel_state = full_value;
    }
    else
    {
        t |= full_value;
    }

    switch (pixel_state) //  state machine for retrieving the pixel coordinates
    {
    case ILI9341_PAGEADDRSET:
    {
        pixel_state = PAGE_TRANSFER;
        flag_state = true;
        t = 0;
        count = 0;

        break;
    }
    case PAGE_TRANSFER:
    {
        if (count == 3)
        {
            t_x_end = t;
            t_x_start = t >> 16;
            flag_state = false;
        }
        else
        {
            t <<= 8;
            count++;
        }

        break;
    }
    case ILI9341_COLADDRSET:
    {
        pixel_state = COL_TRANSFER;
        flag_state = true;
        t = 0;
        count = 0;

        break;
    }
    case COL_TRANSFER:
    {
        if (count == 3)
        {
            t_y_end = t;
            t_y_start = t >> 16;
            flag_state = false;
        }
        else
        {
            t <<= 8;
            count++;
        }
        break;
    }
    case ILI9341_MEMORYWRITE:
    {

        pixel_state = color;
        flag_state = true;
        t = 0;
        count = 0;
        break;
    }
    case color:
    {
        if (count == 1)
        {
            color_ = t;

            if ((t_x_end == 479 && t_y_end == 319 && pixel_or_rec && ((t_y_start != 0) || (t_x_start != 0))))
                draw_lcd_callback(t_x_start, t_y_start, color_);
            else
                draw_lcd_rec_callback(t_x_start, t_y_start, t_x_end, t_y_end, color_);
            flag_state = false;
        }
        else
        {
            pixel_state = color;
            t <<= 8;
            count++;
        }
        break;
    }
    default:
        break;
    }
}

static void fm4_gpio_ddr3_post_write_callback(Object *reg, Object *periph,
                                              uint32_t addr, uint32_t offset, unsigned size,
                                              peripheral_register_t value, peripheral_register_t full_value)
{
    FM4GPIOState *state = FM4_GPIO_STATE(periph);

    fm4_gpio_update_dir_mask(state, 0);
}

static void fm4_gpio_pdor3_post_write_callback(Object *reg, Object *periph,
                                               uint32_t addr, uint32_t offset, unsigned size,
                                               peripheral_register_t value, peripheral_register_t full_value)
{

    FM4GPIOState *state = FM4_GPIO_STATE(periph);

    Object *pdor = state->u.e2.reg.pdor3;
    assert(pdor);

    uint16_t prev_value = peripheral_register_get_raw_prev_value(pdor);
    uint16_t mask = 1 << 14;
    // 'value' may be have any size, use full_word.

    fm4_gpio_set_odr_irqs(state, prev_value, full_value, 0);
    if ((full_value && mask) == 1)
        pixel_or_rec = true;
    else
        pixel_or_rec = false;
}

static void fm4_gpio_pcr0_post_write_callback(Object *reg, Object *periph,
                                              uint32_t addr, uint32_t offset, unsigned size,
                                              peripheral_register_t value, peripheral_register_t full_value)
{

    FM4GPIOState *state = FM4_GPIO_STATE(periph);
    Object *pcr = state->u.e2.reg.pcr0;
    assert(pcr);

    uint16_t prev_value = peripheral_register_get_raw_prev_value(pcr);

    // cm_irq_set(state->odr_irq[pin], level);
    fm4_gpio_set_pcr_irqs(state, prev_value, full_value);
}

// TODO: remove this if the peripheral is always enabled.
static bool fm4_gpio_is_enabled(Object *obj)
{
    FM4GPIOState *state = FM4_GPIO_STATE(obj);

    if (register_bitfield_is_non_zero(state->enabling_bit))
    {
        return true; // Positive logic, bit == 1 means enabled.
    }

    // Not enabled
    return false;
}

static void fm4_gpio_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    FM4GPIOState *state = FM4_GPIO_STATE(obj);

    // Capabilities are not yet available.

    cm_object_property_add_int(obj, "port-index",
                               (const int *)&state->port_index);
    state->port_index = FM4_PORT_GPIO_UNDEFINED;

    cm_irq_init_in(DEVICE(obj), fm4_gpio_in_irq_handler,
                   FM4_IRQ_GPIO_IDR_IN, FM4_GPIO_PIN_COUNT);

    // Outgoing interrupts, machine devices like LEDs might
    // be connected here.
    cm_irq_init_out(DEVICE(obj), state->odr_irq, FM4_IRQ_GPIO_ODR_OUT,
                    FM4_GPIO_PIN_COUNT);

    cm_irq_init_out(DEVICE(obj), state->odr_irq_lcd, FM4_IRQ_GPIO_ODR_OUT,
                    FM4_GPIO_PIN_COUNT);

    state->dir_mask = 0;
    state->dir_mask1 = 0;
    state->u.e2.reg.ddr3 = NULL;
    state->u.e2.reg.pdor3 = NULL;
    state->u.e2.reg.pdir0 = NULL;
}

static void fm4_gpio_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_FM4_GPIO))
    {
        return;
    }

    FM4MCUState *mcu = fm4_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);
    // char enabling_bit_name[FM4_RCC_SIZEOF_ENABLING_BITFIELD];
    FM4GPIOState *state = FM4_GPIO_STATE(dev);
    // First thing first: get capabilities from MCU, needed everywhere.
    state->capabilities = mcu->capabilities;

    // Also keep a local pointer, to access them easier.
    const FM4Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    const char *periph_name = "GPIO";

    svd_set_peripheral_address_block(cm_state->svd_json, periph_name, obj);
    peripheral_create_memory_region(obj);

    // Must be defined before creating registers.
    cm_object_property_set_int(obj, 4, "register-size-bytes");
    cm_object_property_set_bool(obj, true, "is-little-endian");

    fm4s6e2cc_gpio_create_objects(obj, cm_state->svd_json, periph_name);

    /**
     * @brief below are callback functions linked to its corresponding register
     * 
     */
    peripheral_register_set_post_write(state->u.e2.reg.ddr3, // LED and button
                                       &fm4_gpio_ddr3_post_write_callback);

    peripheral_register_set_post_write(state->u.e2.reg.pdor3, // LED and button
                                       &fm4_gpio_pdor3_post_write_callback);

    peripheral_register_set_post_write(state->u.e2.reg.pcr0, //  pull-up resistor callback used now for initializing button to a high value, needed for proper functioning of the button
                                       &fm4_gpio_pcr0_post_write_callback);

    peripheral_register_set_post_write(state->u.e2.reg.ddr1, // LCD
                                       &fm4_gpio_ddr1_post_write_callback);

    peripheral_register_set_post_write(state->u.e2.reg.pdor1, //  LCD
                                       &fm4_gpio_pdor1_post_write_callback);

    peripheral_register_set_post_write(state->u.e2.reg.pdor2, //  LCD
                                       &fm4_gpio_pdor2_post_write_callback);

    peripheral_prepare_registers(obj);
}

Object *fm4_gpio_create(Object *parent, fm4_gpio_index_t index)
{
    if ((int)index >= FM4_PORT_GPIO_UNDEFINED)
    {
        hw_error("Cannot assign GPIO%c: QEMU supports only %d ports\n",
                 'A' + index, FM4_PORT_GPIO_UNDEFINED);
    }
    Object *gpio = cm_object_new(parent, "GPIO", TYPE_FM4_GPIO);

    object_property_set_int(gpio, index, "port-index", NULL);

    cm_object_realize(gpio);

    return gpio;
}

static void fm4_gpio_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset(); this will reset all children registers.
    cm_device_parent_reset(dev, TYPE_FM4_GPIO);
}

static void fm4_gpio_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = fm4_gpio_reset_callback;
    dc->realize = fm4_gpio_realize_callback;
}

static const TypeInfo fm4_gpio_type_info = {
    .name = TYPE_FM4_GPIO,
    .parent = TYPE_FM4_GPIO_PARENT,
    .instance_init = fm4_gpio_instance_init_callback,
    .instance_size = sizeof(FM4GPIOState),
    .class_init = fm4_gpio_class_init_callback,
    .class_size = sizeof(FM4GPIOClass)};

static void fm4_gpio_register_types(void)
{
    type_register_static(&fm4_gpio_type_info);
}

type_init(fm4_gpio_register_types);

// ----------------------------------------------------------------------------
