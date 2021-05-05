/*
 * FM4- ADC0(ADC0 Registers) emulation.
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
#include <hw/cortexm/graphic.h>
#include <hw/cortexm/fm4/gpio.h>
#include <hw/cortexm/fm4/adc0.h>
#include <hw/cortexm/fm4/mcu.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>

extern int x_, y_;

// ----- Generated code -------------------------------------------------------
//
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void fm4s6e2cc_adc0_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
    FM4ADC0State *state = FM4_ADC0_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers.
    state->u.e2.reg.adcr = cm_object_get_child_by_name(obj, "ADCR");
    state->u.e2.reg.adsr = cm_object_get_child_by_name(obj, "ADSR");
    state->u.e2.reg.sccr = cm_object_get_child_by_name(obj, "SCCR");
    state->u.e2.reg.sfns = cm_object_get_child_by_name(obj, "SFNS");
    state->u.e2.reg.scfd = cm_object_get_child_by_name(obj, "SCFD");
    state->u.e2.reg.scis3 = cm_object_get_child_by_name(obj, "SCIS3");
    state->u.e2.reg.scis2 = cm_object_get_child_by_name(obj, "SCIS2");
    state->u.e2.reg.scis1 = cm_object_get_child_by_name(obj, "SCIS1");
    state->u.e2.reg.scis0 = cm_object_get_child_by_name(obj, "SCIS0");
    state->u.e2.reg.pfns = cm_object_get_child_by_name(obj, "PFNS");
    state->u.e2.reg.pccr = cm_object_get_child_by_name(obj, "PCCR");
    state->u.e2.reg.pcfd = cm_object_get_child_by_name(obj, "PCFD");
    state->u.e2.reg.pcis = cm_object_get_child_by_name(obj, "PCIS");
    state->u.e2.reg.cmpcr = cm_object_get_child_by_name(obj, "CMPCR");
    state->u.e2.reg.cmpd = cm_object_get_child_by_name(obj, "CMPD");
    state->u.e2.reg.adss3 = cm_object_get_child_by_name(obj, "ADSS3");
    state->u.e2.reg.adss2 = cm_object_get_child_by_name(obj, "ADSS2");
    state->u.e2.reg.adss1 = cm_object_get_child_by_name(obj, "ADSS1");
    state->u.e2.reg.adss0 = cm_object_get_child_by_name(obj, "ADSS0");
    state->u.e2.reg.adst1 = cm_object_get_child_by_name(obj, "ADST1");
    state->u.e2.reg.adst0 = cm_object_get_child_by_name(obj, "ADST0");
    state->u.e2.reg.adct = cm_object_get_child_by_name(obj, "ADCT");
    state->u.e2.reg.prtsl = cm_object_get_child_by_name(obj, "PRTSL");
    state->u.e2.reg.sctsl = cm_object_get_child_by_name(obj, "SCTSL");
    state->u.e2.reg.adcen = cm_object_get_child_by_name(obj, "ADCEN");
    state->u.e2.reg.wcmrcot = cm_object_get_child_by_name(obj, "WCMRCOT");
    state->u.e2.reg.wcmrcif = cm_object_get_child_by_name(obj, "WCMRCIF");
    state->u.e2.reg.wcmpcr = cm_object_get_child_by_name(obj, "WCMPCR");
    state->u.e2.reg.wcmpsr = cm_object_get_child_by_name(obj, "WCMPSR");
    state->u.e2.reg.wcmpdl = cm_object_get_child_by_name(obj, "WCMPDL");
    state->u.e2.reg.wcmpdh = cm_object_get_child_by_name(obj, "WCMPDH");

    // ADCRbitfields.
    state->u.e2.fld.adcr.ovrie = cm_object_get_child_by_name(state->u.e2.reg.adcr, "OVRIE");
    state->u.e2.fld.adcr.cmpie = cm_object_get_child_by_name(state->u.e2.reg.adcr, "CMPIE");
    state->u.e2.fld.adcr.pcie = cm_object_get_child_by_name(state->u.e2.reg.adcr, "PCIE");
    state->u.e2.fld.adcr.scie = cm_object_get_child_by_name(state->u.e2.reg.adcr, "SCIE");
    state->u.e2.fld.adcr.cmpif = cm_object_get_child_by_name(state->u.e2.reg.adcr, "CMPIF");
    state->u.e2.fld.adcr.pcif = cm_object_get_child_by_name(state->u.e2.reg.adcr, "PCIF");
    state->u.e2.fld.adcr.scif = cm_object_get_child_by_name(state->u.e2.reg.adcr, "SCIF");

    // ADSRbitfields.
    state->u.e2.fld.adsr.scs = cm_object_get_child_by_name(state->u.e2.reg.adsr, "SCS");
    state->u.e2.fld.adsr.pcs = cm_object_get_child_by_name(state->u.e2.reg.adsr, "PCS");
    state->u.e2.fld.adsr.pcns = cm_object_get_child_by_name(state->u.e2.reg.adsr, "PCNS");
    state->u.e2.fld.adsr.fdas = cm_object_get_child_by_name(state->u.e2.reg.adsr, "FDAS");
    state->u.e2.fld.adsr.adstp = cm_object_get_child_by_name(state->u.e2.reg.adsr, "ADSTP");

    // SCCRbitfields.
    state->u.e2.fld.sccr.sstr = cm_object_get_child_by_name(state->u.e2.reg.sccr, "SSTR");
    state->u.e2.fld.sccr.shen = cm_object_get_child_by_name(state->u.e2.reg.sccr, "SHEN");
    state->u.e2.fld.sccr.rpt = cm_object_get_child_by_name(state->u.e2.reg.sccr, "RPT");
    state->u.e2.fld.sccr.sfclr = cm_object_get_child_by_name(state->u.e2.reg.sccr, "SFCLR");
    state->u.e2.fld.sccr.sovr = cm_object_get_child_by_name(state->u.e2.reg.sccr, "SOVR");
    state->u.e2.fld.sccr.sful = cm_object_get_child_by_name(state->u.e2.reg.sccr, "SFUL");
    state->u.e2.fld.sccr.semp = cm_object_get_child_by_name(state->u.e2.reg.sccr, "SEMP");

    // SFNSbitfields.
    state->u.e2.fld.sfns.sfs = cm_object_get_child_by_name(state->u.e2.reg.sfns, "SFS");

    // SCFDbitfields.
    state->u.e2.fld.scfd.sc = cm_object_get_child_by_name(state->u.e2.reg.scfd, "SC");
    state->u.e2.fld.scfd.rs = cm_object_get_child_by_name(state->u.e2.reg.scfd, "RS");
    state->u.e2.fld.scfd.invl = cm_object_get_child_by_name(state->u.e2.reg.scfd, "INVL");
    state->u.e2.fld.scfd.sd = cm_object_get_child_by_name(state->u.e2.reg.scfd, "SD");

    // SCIS3bitfields.
    state->u.e2.fld.scis3.an24 = cm_object_get_child_by_name(state->u.e2.reg.scis3, "AN24");
    state->u.e2.fld.scis3.an25 = cm_object_get_child_by_name(state->u.e2.reg.scis3, "AN25");
    state->u.e2.fld.scis3.an26 = cm_object_get_child_by_name(state->u.e2.reg.scis3, "AN26");
    state->u.e2.fld.scis3.an27 = cm_object_get_child_by_name(state->u.e2.reg.scis3, "AN27");
    state->u.e2.fld.scis3.an28 = cm_object_get_child_by_name(state->u.e2.reg.scis3, "AN28");
    state->u.e2.fld.scis3.an29 = cm_object_get_child_by_name(state->u.e2.reg.scis3, "AN29");
    state->u.e2.fld.scis3.an30 = cm_object_get_child_by_name(state->u.e2.reg.scis3, "AN30");
    state->u.e2.fld.scis3.an31 = cm_object_get_child_by_name(state->u.e2.reg.scis3, "AN31");

    // SCIS2bitfields.
    state->u.e2.fld.scis2.an16 = cm_object_get_child_by_name(state->u.e2.reg.scis2, "AN16");
    state->u.e2.fld.scis2.an17 = cm_object_get_child_by_name(state->u.e2.reg.scis2, "AN17");
    state->u.e2.fld.scis2.an18 = cm_object_get_child_by_name(state->u.e2.reg.scis2, "AN18");
    state->u.e2.fld.scis2.an19 = cm_object_get_child_by_name(state->u.e2.reg.scis2, "AN19");
    state->u.e2.fld.scis2.an20 = cm_object_get_child_by_name(state->u.e2.reg.scis2, "AN20");
    state->u.e2.fld.scis2.an21 = cm_object_get_child_by_name(state->u.e2.reg.scis2, "AN21");
    state->u.e2.fld.scis2.an22 = cm_object_get_child_by_name(state->u.e2.reg.scis2, "AN22");
    state->u.e2.fld.scis2.an23 = cm_object_get_child_by_name(state->u.e2.reg.scis2, "AN23");

    // SCIS1bitfields.
    state->u.e2.fld.scis1.an8 = cm_object_get_child_by_name(state->u.e2.reg.scis1, "AN8");
    state->u.e2.fld.scis1.an9 = cm_object_get_child_by_name(state->u.e2.reg.scis1, "AN9");
    state->u.e2.fld.scis1.an10 = cm_object_get_child_by_name(state->u.e2.reg.scis1, "AN10");
    state->u.e2.fld.scis1.an11 = cm_object_get_child_by_name(state->u.e2.reg.scis1, "AN11");
    state->u.e2.fld.scis1.an12 = cm_object_get_child_by_name(state->u.e2.reg.scis1, "AN12");
    state->u.e2.fld.scis1.an13 = cm_object_get_child_by_name(state->u.e2.reg.scis1, "AN13");
    state->u.e2.fld.scis1.an14 = cm_object_get_child_by_name(state->u.e2.reg.scis1, "AN14");
    state->u.e2.fld.scis1.an15 = cm_object_get_child_by_name(state->u.e2.reg.scis1, "AN15");

    // SCIS0bitfields.
    state->u.e2.fld.scis0.an0 = cm_object_get_child_by_name(state->u.e2.reg.scis0, "AN0");
    state->u.e2.fld.scis0.an1 = cm_object_get_child_by_name(state->u.e2.reg.scis0, "AN1");
    state->u.e2.fld.scis0.an2 = cm_object_get_child_by_name(state->u.e2.reg.scis0, "AN2");
    state->u.e2.fld.scis0.an3 = cm_object_get_child_by_name(state->u.e2.reg.scis0, "AN3");
    state->u.e2.fld.scis0.an4 = cm_object_get_child_by_name(state->u.e2.reg.scis0, "AN4");
    state->u.e2.fld.scis0.an5 = cm_object_get_child_by_name(state->u.e2.reg.scis0, "AN5");
    state->u.e2.fld.scis0.an6 = cm_object_get_child_by_name(state->u.e2.reg.scis0, "AN6");
    state->u.e2.fld.scis0.an7 = cm_object_get_child_by_name(state->u.e2.reg.scis0, "AN7");

    // PFNSbitfields.
    state->u.e2.fld.pfns.pfs = cm_object_get_child_by_name(state->u.e2.reg.pfns, "PFS");
    state->u.e2.fld.pfns.test = cm_object_get_child_by_name(state->u.e2.reg.pfns, "TEST");

    // PCCRbitfields.
    state->u.e2.fld.pccr.pstr = cm_object_get_child_by_name(state->u.e2.reg.pccr, "PSTR");
    state->u.e2.fld.pccr.phen = cm_object_get_child_by_name(state->u.e2.reg.pccr, "PHEN");
    state->u.e2.fld.pccr.peen = cm_object_get_child_by_name(state->u.e2.reg.pccr, "PEEN");
    state->u.e2.fld.pccr.esce = cm_object_get_child_by_name(state->u.e2.reg.pccr, "ESCE");
    state->u.e2.fld.pccr.pfclr = cm_object_get_child_by_name(state->u.e2.reg.pccr, "PFCLR");
    state->u.e2.fld.pccr.povr = cm_object_get_child_by_name(state->u.e2.reg.pccr, "POVR");
    state->u.e2.fld.pccr.pful = cm_object_get_child_by_name(state->u.e2.reg.pccr, "PFUL");
    state->u.e2.fld.pccr.pemp = cm_object_get_child_by_name(state->u.e2.reg.pccr, "PEMP");

    // PCFDbitfields.
    state->u.e2.fld.pcfd.pc = cm_object_get_child_by_name(state->u.e2.reg.pcfd, "PC");
    state->u.e2.fld.pcfd.rs = cm_object_get_child_by_name(state->u.e2.reg.pcfd, "RS");
    state->u.e2.fld.pcfd.invl = cm_object_get_child_by_name(state->u.e2.reg.pcfd, "INVL");
    state->u.e2.fld.pcfd.pd = cm_object_get_child_by_name(state->u.e2.reg.pcfd, "PD");

    // PCISbitfields.
    state->u.e2.fld.pcis.p1a = cm_object_get_child_by_name(state->u.e2.reg.pcis, "P1A");
    state->u.e2.fld.pcis.p2a = cm_object_get_child_by_name(state->u.e2.reg.pcis, "P2A");

    // CMPCRbitfields.
    state->u.e2.fld.cmpcr.cch = cm_object_get_child_by_name(state->u.e2.reg.cmpcr, "CCH");
    state->u.e2.fld.cmpcr.cmd0 = cm_object_get_child_by_name(state->u.e2.reg.cmpcr, "CMD0");
    state->u.e2.fld.cmpcr.cmd1 = cm_object_get_child_by_name(state->u.e2.reg.cmpcr, "CMD1");
    state->u.e2.fld.cmpcr.cmpen = cm_object_get_child_by_name(state->u.e2.reg.cmpcr, "CMPEN");

    // CMPDbitfields.
    state->u.e2.fld.cmpd.cmad = cm_object_get_child_by_name(state->u.e2.reg.cmpd, "CMAD");

    // ADSS3bitfields.
    state->u.e2.fld.adss3.ts24 = cm_object_get_child_by_name(state->u.e2.reg.adss3, "TS24");
    state->u.e2.fld.adss3.ts25 = cm_object_get_child_by_name(state->u.e2.reg.adss3, "TS25");
    state->u.e2.fld.adss3.ts26 = cm_object_get_child_by_name(state->u.e2.reg.adss3, "TS26");
    state->u.e2.fld.adss3.ts27 = cm_object_get_child_by_name(state->u.e2.reg.adss3, "TS27");
    state->u.e2.fld.adss3.ts28 = cm_object_get_child_by_name(state->u.e2.reg.adss3, "TS28");
    state->u.e2.fld.adss3.ts29 = cm_object_get_child_by_name(state->u.e2.reg.adss3, "TS29");
    state->u.e2.fld.adss3.ts30 = cm_object_get_child_by_name(state->u.e2.reg.adss3, "TS30");
    state->u.e2.fld.adss3.ts31 = cm_object_get_child_by_name(state->u.e2.reg.adss3, "TS31");

    // ADSS2bitfields.
    state->u.e2.fld.adss2.ts16 = cm_object_get_child_by_name(state->u.e2.reg.adss2, "TS16");
    state->u.e2.fld.adss2.ts17 = cm_object_get_child_by_name(state->u.e2.reg.adss2, "TS17");
    state->u.e2.fld.adss2.ts18 = cm_object_get_child_by_name(state->u.e2.reg.adss2, "TS18");
    state->u.e2.fld.adss2.ts19 = cm_object_get_child_by_name(state->u.e2.reg.adss2, "TS19");
    state->u.e2.fld.adss2.ts20 = cm_object_get_child_by_name(state->u.e2.reg.adss2, "TS20");
    state->u.e2.fld.adss2.ts21 = cm_object_get_child_by_name(state->u.e2.reg.adss2, "TS21");
    state->u.e2.fld.adss2.ts22 = cm_object_get_child_by_name(state->u.e2.reg.adss2, "TS22");
    state->u.e2.fld.adss2.ts23 = cm_object_get_child_by_name(state->u.e2.reg.adss2, "TS23");

    // ADSS1bitfields.
    state->u.e2.fld.adss1.ts8 = cm_object_get_child_by_name(state->u.e2.reg.adss1, "TS8");
    state->u.e2.fld.adss1.ts9 = cm_object_get_child_by_name(state->u.e2.reg.adss1, "TS9");
    state->u.e2.fld.adss1.ts10 = cm_object_get_child_by_name(state->u.e2.reg.adss1, "TS10");
    state->u.e2.fld.adss1.ts11 = cm_object_get_child_by_name(state->u.e2.reg.adss1, "TS11");
    state->u.e2.fld.adss1.ts12 = cm_object_get_child_by_name(state->u.e2.reg.adss1, "TS12");
    state->u.e2.fld.adss1.ts13 = cm_object_get_child_by_name(state->u.e2.reg.adss1, "TS13");
    state->u.e2.fld.adss1.ts14 = cm_object_get_child_by_name(state->u.e2.reg.adss1, "TS14");
    state->u.e2.fld.adss1.ts15 = cm_object_get_child_by_name(state->u.e2.reg.adss1, "TS15");

    // ADSS0bitfields.
    state->u.e2.fld.adss0.ts0 = cm_object_get_child_by_name(state->u.e2.reg.adss0, "TS0");
    state->u.e2.fld.adss0.ts1 = cm_object_get_child_by_name(state->u.e2.reg.adss0, "TS1");
    state->u.e2.fld.adss0.ts2 = cm_object_get_child_by_name(state->u.e2.reg.adss0, "TS2");
    state->u.e2.fld.adss0.ts3 = cm_object_get_child_by_name(state->u.e2.reg.adss0, "TS3");
    state->u.e2.fld.adss0.ts4 = cm_object_get_child_by_name(state->u.e2.reg.adss0, "TS4");
    state->u.e2.fld.adss0.ts5 = cm_object_get_child_by_name(state->u.e2.reg.adss0, "TS5");
    state->u.e2.fld.adss0.ts6 = cm_object_get_child_by_name(state->u.e2.reg.adss0, "TS6");
    state->u.e2.fld.adss0.ts7 = cm_object_get_child_by_name(state->u.e2.reg.adss0, "TS7");

    // ADST1bitfields.
    state->u.e2.fld.adst1.st1 = cm_object_get_child_by_name(state->u.e2.reg.adst1, "ST1");
    state->u.e2.fld.adst1.stx1 = cm_object_get_child_by_name(state->u.e2.reg.adst1, "STX1");

    // ADST0bitfields.
    state->u.e2.fld.adst0.st0 = cm_object_get_child_by_name(state->u.e2.reg.adst0, "ST0");
    state->u.e2.fld.adst0.stx0 = cm_object_get_child_by_name(state->u.e2.reg.adst0, "STX0");

    // ADCTbitfields.
    state->u.e2.fld.adct.ct = cm_object_get_child_by_name(state->u.e2.reg.adct, "CT");

    // PRTSLbitfields.
    state->u.e2.fld.prtsl.prtsl = cm_object_get_child_by_name(state->u.e2.reg.prtsl, "PRTSL");

    // SCTSLbitfields.
    state->u.e2.fld.sctsl.sctsl = cm_object_get_child_by_name(state->u.e2.reg.sctsl, "SCTSL");

    // ADCENbitfields.
    state->u.e2.fld.adcen.enbl = cm_object_get_child_by_name(state->u.e2.reg.adcen, "ENBL");
    state->u.e2.fld.adcen.ready = cm_object_get_child_by_name(state->u.e2.reg.adcen, "READY");
    state->u.e2.fld.adcen.enbltime = cm_object_get_child_by_name(state->u.e2.reg.adcen, "ENBLTIME");

    // WCMRCOTbitfields.
    state->u.e2.fld.wcmrcot.rcoof = cm_object_get_child_by_name(state->u.e2.reg.wcmrcot, "RCOOF");

    // WCMRCIFbitfields.
    state->u.e2.fld.wcmrcif.rcint = cm_object_get_child_by_name(state->u.e2.reg.wcmrcif, "RCINT");

    // WCMPCRbitfields.
    state->u.e2.fld.wcmpcr.rcoe = cm_object_get_child_by_name(state->u.e2.reg.wcmpcr, "RCOE");
    state->u.e2.fld.wcmpcr.rcoie = cm_object_get_child_by_name(state->u.e2.reg.wcmpcr, "RCOIE");
    state->u.e2.fld.wcmpcr.rcoirs = cm_object_get_child_by_name(state->u.e2.reg.wcmpcr, "RCOIRS");
    state->u.e2.fld.wcmpcr.rcocd = cm_object_get_child_by_name(state->u.e2.reg.wcmpcr, "RCOCD");

    // WCMPSRbitfields.
    state->u.e2.fld.wcmpsr.wcch = cm_object_get_child_by_name(state->u.e2.reg.wcmpsr, "WCCH");
    state->u.e2.fld.wcmpsr.wcmd = cm_object_get_child_by_name(state->u.e2.reg.wcmpsr, "WCMD");

    // WCMPDLbitfields.
    state->u.e2.fld.wcmpdl.cmld = cm_object_get_child_by_name(state->u.e2.reg.wcmpdl, "CMLD");

    // WCMPDHbitfields.
    state->u.e2.fld.wcmpdh.cmhd = cm_object_get_child_by_name(state->u.e2.reg.wcmpdh, "CMHD");
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// ----- Private --------------------------------------------------------------

#if 0
static peripheral_register_t fm4_adc0_xxx_pre_write_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    FM4ADC0State *state = FM4_ADC0_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);

    // TODO: Add code to adjust the value (like applying some masks,
    // for example prevent setting interrupts not enabled).
    // Also process cleared/set by write 1/0 bits.
    // The returned value will be stored in the register value.

    return full_value;
}

static void fm4_adc0_xxx_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    FM4ADC0State *state = FM4_ADC0_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);
    // The new register value is full_value, the old one is prev_value.

    // TODO: Add code to send the value to the consumer.
}

static peripheral_register_t fm4_adc0_xxx_pre_read_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size)
{
    FM4ADC0State *state = FM4_ADC0_STATE(periph);

    peripheral_register_t value = 0;

    // Add code to get the value from the producer, and return it.

    // This value, possibly masked, will be stored in the register
    // and returned when the register is read.
    return value;
}

static void fm4_adc0_xxx_post_read_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size)
{
    FM4ADC0State *state = FM4_ADC0_STATE(periph);

    peripheral_register_t value = peripheral_register_get_raw_value(reg);

    // TODO: add code to perform the post read actions, like clearing some bits.
}
#endif

/**
 * Callback function for sccr register
 * Gets called if s6e2cc starts conversation to get coordinates for lcd or joysticks
 * Writes coordinates in scfd register
 */
static void fm4_gpio_sccr_post_write_callback(Object *reg, Object *periph,
                                              uint32_t addr, uint32_t offset, unsigned size,
                                              peripheral_register_t value, peripheral_register_t full_value)
{

    FM4ADC0State *state = FM4_ADC0_STATE(periph);

    // define used registers
    Object *adsr = state->u.e2.reg.adsr;
    Object *scfd = state->u.e2.reg.scfd; //  32bits data

    // get lcd coordinates
    x_ = get_x_();
    y_ = get_y_();

    // get left joystick coordinates
    x_joystick_left = get_x_joystick_left();
    y_joystick_left = get_y_joystick_left();

    //get right joystick coordinates
    x_joystick_right = get_x_joystick_right();
    y_joystick_right = get_y_joystick_right();

    //  clear scfd memory
    peripheral_register_and_raw_value(scfd, 0);

    if (get_TOUCH_X_() == false && get_TOUCH_Y_() == true)
    {
        // write x coordinate in register scfd
        // [27:20] x coordinate
        // [19:19] Bit = 1 if no joystick is used
        peripheral_register_set_raw_value(adsr, 0 << 6); // //  FDAS  [6:6] FIFO data placement selection bit
        u_int32_t x_coordinate = 1 << 19;
        x_coordinate = x_coordinate ^ (x_ << 20);
        peripheral_register_set_raw_value(scfd, x_coordinate);
    }
    else if (get_TOUCH_X_() == true && get_TOUCH_Y_() == false)
    {
        // write y coordinate in register scfd
        // [27:20] y coordinate
        // [19:19] Bit = 1 if no joystick is used
        peripheral_register_set_raw_value(adsr, 1 << 6);
        u_int32_t y_coordinate = 1 << 19;
        y_coordinate = y_coordinate ^ (y_ << 20);
        peripheral_register_set_raw_value(scfd, y_coordinate);
    }
    else
    {
        peripheral_register_set_raw_value(adsr, 0 << 6);

        bool left_used = get_left_joystick_used();
        bool right_used = get_right_joystick_used();

        // [27:20] : x coordinate
        // [19:19] : Bit to decide if left or right joystick used (1 if left used)
        // [18:18] : Bit is 1 if no joystick is used -> idle case, position (190,190)
        // [7:0] : y coordinate
        if (left_used)
        {
            u_int32_t coordinates = 1 << 18;
            coordinates = coordinates ^ (x_joystick_left << 20);
            coordinates = coordinates ^ y_joystick_left;

            peripheral_register_set_raw_value(scfd, coordinates);
        }
        else if (right_used)
        {
            u_int32_t coordinates = x_joystick_right << 20;
            coordinates = coordinates ^ y_joystick_right;
            peripheral_register_set_raw_value(scfd, coordinates);
        }
        else
        {
            u_int32_t coordinates = 1 << 19;
            coordinates = coordinates ^ (190 << 20);
            coordinates = coordinates ^ 190;
            peripheral_register_set_raw_value(scfd, coordinates);
        }
    }
}

// ----------------------------------------------------------------------------

// TODO: remove this if the peripheral is always enabled.
static bool fm4_adc0_is_enabled(Object *obj)
{
    FM4ADC0State *state = FM4_ADC0_STATE(obj);

    if (register_bitfield_is_non_zero(state->enabling_bit))
    {
        return true; // Positive logic, bit == 1 means enabled.
    }

    // Not enabled
    return false;
}

static void fm4_adc0_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    FM4ADC0State *state = FM4_ADC0_STATE(obj);

    // TODO: remove this if the peripheral is always enabled.
    state->enabling_bit = NULL;

    // TODO: Add code to initialise all members.
}

static void fm4_adc0_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_FM4_ADC0))
    {
        return;
    }

    FM4MCUState *mcu = fm4_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    FM4ADC0State *state = FM4_ADC0_STATE(dev);

    // First thing first: get capabilities from MCU, needed everywhere.
    state->capabilities = mcu->capabilities;

    // Also keep a local pointer, to access them easier.
    const FM4Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    const char *periph_name = "ADC0";

    svd_set_peripheral_address_block(cm_state->svd_json, periph_name, obj);
    peripheral_create_memory_region(obj);
    cm_object_property_set_int(obj, 1, "register-size-bytes");

    cm_object_property_set_bool(obj, true, "is-little-endian");

    fm4s6e2cc_adc0_create_objects(obj, cm_state->svd_json, periph_name);

    peripheral_register_set_post_write(state->u.e2.reg.sccr, &fm4_gpio_sccr_post_write_callback);

    peripheral_prepare_registers(obj);
}

static void fm4_adc0_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset(); this will reset all children registers.
    cm_device_parent_reset(dev, TYPE_FM4_ADC0);
}

static void fm4_adc0_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = fm4_adc0_reset_callback;
    dc->realize = fm4_adc0_realize_callback;
}

static const TypeInfo fm4_adc0_type_info = {
    .name = TYPE_FM4_ADC0,
    .parent = TYPE_FM4_ADC0_PARENT,
    .instance_init = fm4_adc0_instance_init_callback,
    .instance_size = sizeof(FM4ADC0State),
    .class_init = fm4_adc0_class_init_callback,
    .class_size = sizeof(FM4ADC0Class)};

static void fm4_adc0_register_types(void)
{
    type_register_static(&fm4_adc0_type_info);
}

type_init(fm4_adc0_register_types);

// ----------------------------------------------------------------------------