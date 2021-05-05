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

#ifndef FM4_RTC_H_
#define FM4_RTC_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/fm4/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_FM4_RTC DEVICE_PATH_FM4"RTC"


// ----------------------------------------------------------------------------

#define TYPE_FM4_RTC TYPE_FM4_PREFIX "rtc" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_FM4_RTC_PARENT TYPE_PERIPHERAL
typedef PeripheralClass FM4RTCParentClass;
typedef PeripheralState FM4RTCParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define FM4_RTC_GET_CLASS(obj) \
    OBJECT_GET_CLASS(FM4RTCClass, (obj), TYPE_FM4_RTC)
#define FM4_RTC_CLASS(klass) \
    OBJECT_CLASS_CHECK(FM4RTCClass, (klass), TYPE_FM4_RTC)

typedef struct {
    // private: 
    FM4RTCParentClass parent_class;
    // public: 

    // None, so far.
} FM4RTCClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define FM4_RTC_STATE(obj) \
    OBJECT_CHECK(FM4RTCState, (obj), TYPE_FM4_RTC)

typedef struct {
    // private:
    FM4RTCParentState parent_obj;
    // public:

    const FM4Capabilities *capabilities;

    // TODO: remove this if the peripheral is always enabled.
    // Points to the bitfield that enables the peripheral.
    Object *enabling_bit;

    union {
      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

      // DO NOT REMOVE FIELDS! Automatically generated!
      // Merge fields from different family members.
      struct {
        // E2RTC(REAL-TIME CLOCK) registers.
        struct { 
          Object *wtcr10; // 0x100(Control Register 10) 
          Object *wtcr11; // 0x104(Control Register 11) 
          Object *wtcr12; // 0x108(Control Register 12) 
          Object *wtcr13; // 0x10C(Control Register 13) 
          Object *wtcr20; // 0x110(Control Register 20) 
          Object *wtcr21; // 0x114(Control Register 21) 
          Object *wtsr; // 0x11C(Second Register) 
          Object *wtmir; // 0x120(Minute Register) 
          Object *wthr; // 0x124(Hour register) 
          Object *wtdr; // 0x128(Day Register) 
          Object *wtdw; // 0x12C(Day of the Week Register) 
          Object *wtmor; // 0x130(Month Register) 
          Object *wtyr; // 0x134(Year Register) 
          Object *almir; // 0x138(Alarm Minute Register) 
          Object *alhr; // 0x13C(Alarm Hour Register) 
          Object *aldr; // 0x140(Alarm Date Register) 
          Object *almor; // 0x144(Alarm Month Register) 
          Object *alyr; // 0x148(Alarm Years Register) 
          Object *wttr0; // 0x14C(Timer Setting Register 0) 
          Object *wttr1; // 0x150(Timer Setting Register 1) 
          Object *wttr2; // 0x154(Timer Setting Register 2) 
          Object *wtcal0; // 0x158(Frequency Correction Value Setting Register 0) 
          Object *wtcal1; // 0x15C(Frequency Correction Value Setting Register 1) 
          Object *wtcalen; // 0x160(Frequency Correction Enable Register) 
          Object *wtdiv; // 0x164(Division Ratio Setting Register) 
          Object *wtdiven; // 0x168(Divider Output Enable Register) 
          Object *wtcalprd; // 0x16C(Frequency Correction Period Setting Register) 
          Object *wtcosel; // 0x170(RTCCO Output Selection Register) 
          Object *vb_clkdiv; // 0x174(VB_CLKDIV Register) 
          Object *wtosccnt; // 0x178(WTOSCCNT Register) 
          Object *ccs; // 0x17C(CCS Register) 
          Object *ccb; // 0x180(CCB Register) 
          Object *boost; // 0x188(BOOST Register) 
          Object *ewkup; // 0x18C(EWKUP Register) 
          Object *vdet; // 0x190(VDET Register) 
          Object *hibrst; // 0x198(HIBRST Register) 
          Object *vbpfr; // 0x19C(Port Function Set Register) 
          Object *vbpcr; // 0x1A0(Pull-up Set Register) 
          Object *vbddr; // 0x1A4(Port I/O Direction Set Register) 
          Object *vbdir; // 0x1A8(Port Input Data Register) 
          Object *vbdor; // 0x1AC(Port Output Data Register) 
          Object *vbpzr; // 0x1B0(Port Pseudo-Open Drain Set Register) 
          Object *breg00; // 0x200(Backup Register) 
          Object *breg01; // 0x201(Backup Register) 
          Object *breg02; // 0x202(Backup Register) 
          Object *breg03; // 0x203(Backup Register) 
          Object *breg04; // 0x204(Backup Register) 
          Object *breg05; // 0x205(Backup Register) 
          Object *breg06; // 0x206(Backup Register) 
          Object *breg07; // 0x207(Backup Register) 
          Object *breg08; // 0x208(Backup Register) 
          Object *breg09; // 0x209(Backup Register) 
          Object *breg0a; // 0x20A(Backup Register) 
          Object *breg0b; // 0x20B(Backup Register) 
          Object *breg0c; // 0x20C(Backup Register) 
          Object *breg0d; // 0x20D(Backup Register) 
          Object *breg0e; // 0x20E(Backup Register) 
          Object *breg0f; // 0x20F(Backup Register) 
          Object *breg10; // 0x210(Backup Register) 
          Object *breg11; // 0x211(Backup Register) 
          Object *breg12; // 0x212(Backup Register) 
          Object *breg13; // 0x213(Backup Register) 
          Object *breg14; // 0x214(Backup Register) 
          Object *breg15; // 0x215(Backup Register) 
          Object *breg16; // 0x216(Backup Register) 
          Object *breg17; // 0x217(Backup Register) 
          Object *breg18; // 0x218(Backup Register) 
          Object *breg19; // 0x219(Backup Register) 
          Object *breg1a; // 0x21A(Backup Register) 
          Object *breg1b; // 0x21B(Backup Register) 
          Object *breg1c; // 0x21C(Backup Register) 
          Object *breg1d; // 0x21D(Backup Register) 
          Object *breg1e; // 0x21E(Backup Register) 
          Object *breg1f; // 0x21F(Backup Register) 
          Object *breg20; // 0x220(Backup Register) 
          Object *breg21; // 0x221(Backup Register) 
          Object *breg22; // 0x222(Backup Register) 
          Object *breg23; // 0x223(Backup Register) 
          Object *breg24; // 0x224(Backup Register) 
          Object *breg25; // 0x225(Backup Register) 
          Object *breg26; // 0x226(Backup Register) 
          Object *breg27; // 0x227(Backup Register) 
          Object *breg28; // 0x228(Backup Register) 
          Object *breg29; // 0x229(Backup Register) 
          Object *breg2a; // 0x22A(Backup Register) 
          Object *breg2b; // 0x22B(Backup Register) 
          Object *breg2c; // 0x22C(Backup Register) 
          Object *breg2d; // 0x22D(Backup Register) 
          Object *breg2e; // 0x22E(Backup Register) 
          Object *breg2f; // 0x22F(Backup Register) 
          Object *breg30; // 0x230(Backup Register) 
          Object *breg31; // 0x231(Backup Register) 
          Object *breg32; // 0x232(Backup Register) 
          Object *breg33; // 0x233(Backup Register) 
          Object *breg34; // 0x234(Backup Register) 
          Object *breg35; // 0x235(Backup Register) 
          Object *breg36; // 0x236(Backup Register) 
          Object *breg37; // 0x237(Backup Register) 
          Object *breg38; // 0x238(Backup Register) 
          Object *breg39; // 0x239(Backup Register) 
          Object *breg3a; // 0x23A(Backup Register) 
          Object *breg3b; // 0x23B(Backup Register) 
          Object *breg3c; // 0x23C(Backup Register) 
          Object *breg3d; // 0x23D(Backup Register) 
          Object *breg3e; // 0x23E(Backup Register) 
          Object *breg3f; // 0x23F(Backup Register) 
          Object *breg40; // 0x240(Backup Register) 
          Object *breg41; // 0x241(Backup Register) 
          Object *breg42; // 0x242(Backup Register) 
          Object *breg43; // 0x243(Backup Register) 
          Object *breg44; // 0x244(Backup Register) 
          Object *breg45; // 0x245(Backup Register) 
          Object *breg46; // 0x246(Backup Register) 
          Object *breg47; // 0x247(Backup Register) 
          Object *breg48; // 0x248(Backup Register) 
          Object *breg49; // 0x249(Backup Register) 
          Object *breg4a; // 0x24A(Backup Register) 
          Object *breg4b; // 0x24B(Backup Register) 
          Object *breg4c; // 0x24C(Backup Register) 
          Object *breg4d; // 0x24D(Backup Register) 
          Object *breg4e; // 0x24E(Backup Register) 
          Object *breg4f; // 0x24F(Backup Register) 
          Object *breg50; // 0x250(Backup Register) 
          Object *breg51; // 0x251(Backup Register) 
          Object *breg52; // 0x252(Backup Register) 
          Object *breg53; // 0x253(Backup Register) 
          Object *breg54; // 0x254(Backup Register) 
          Object *breg55; // 0x255(Backup Register) 
          Object *breg56; // 0x256(Backup Register) 
          Object *breg57; // 0x257(Backup Register) 
          Object *breg58; // 0x258(Backup Register) 
          Object *breg59; // 0x259(Backup Register) 
          Object *breg5a; // 0x25A(Backup Register) 
          Object *breg5b; // 0x25B(Backup Register) 
          Object *breg5c; // 0x25C(Backup Register) 
          Object *breg5d; // 0x25D(Backup Register) 
          Object *breg5e; // 0x25E(Backup Register) 
          Object *breg5f; // 0x25F(Backup Register) 
          Object *breg60; // 0x260(Backup Register) 
          Object *breg61; // 0x261(Backup Register) 
          Object *breg62; // 0x262(Backup Register) 
          Object *breg63; // 0x263(Backup Register) 
          Object *breg64; // 0x264(Backup Register) 
          Object *breg65; // 0x265(Backup Register) 
          Object *breg66; // 0x266(Backup Register) 
          Object *breg67; // 0x267(Backup Register) 
          Object *breg68; // 0x268(Backup Register) 
          Object *breg69; // 0x269(Backup Register) 
          Object *breg6a; // 0x26A(Backup Register) 
          Object *breg6b; // 0x26B(Backup Register) 
          Object *breg6c; // 0x26C(Backup Register) 
          Object *breg6d; // 0x26D(Backup Register) 
          Object *breg6e; // 0x26E(Backup Register) 
          Object *breg6f; // 0x26F(Backup Register) 
          Object *breg70; // 0x270(Backup Register) 
          Object *breg71; // 0x271(Backup Register) 
          Object *breg72; // 0x272(Backup Register) 
          Object *breg73; // 0x273(Backup Register) 
          Object *breg74; // 0x274(Backup Register) 
          Object *breg75; // 0x275(Backup Register) 
          Object *breg76; // 0x276(Backup Register) 
          Object *breg77; // 0x277(Backup Register) 
          Object *breg78; // 0x278(Backup Register) 
          Object *breg79; // 0x279(Backup Register) 
          Object *breg7a; // 0x27A(Backup Register) 
          Object *breg7b; // 0x27B(Backup Register) 
          Object *breg7c; // 0x27C(Backup Register) 
          Object *breg7d; // 0x27D(Backup Register) 
          Object *breg7e; // 0x27E(Backup Register) 
          Object *breg7f; // 0x27F(Backup Register) 
        } reg;

        struct { 

          // WTCR10(Control Register 10) bitfields.
          struct { 
            Object *st; // [0:0] Start bit            
            Object *run; // [2:2] RTC count block operation bit            
            Object *srst; // [3:3] RTC reset bit            
            Object *scst; // [4:4] 1-second clock output stop bit            
            Object *scrst; // [5:5] Sub second generation/1-second generation counter reset bit            
            Object *busy; // [6:6] Busy bit            
            Object *trans; // [7:7] Transfer flag bit          
            } wtcr10; 

          // WTCR11(Control Register 11) bitfields.
          struct { 
            Object *mien; // [0:0] Alarm minute register enable bit            
            Object *hen; // [1:1] Alarm hour register enable bit            
            Object *den; // [2:2] Alarm day register enable bit            
            Object *moen; // [3:3] Alarm month register enable bit            
            Object *yen; // [4:4] Alarm year register enable bit          
            } wtcr11; 

          // WTCR12(Control Register 12) bitfields.
          struct { 
            Object *intssi; // [0:0] Every 0.5-second flag bit            
            Object *intsi; // [1:1] Every second flag bit            
            Object *intmi; // [2:2] Every minute flag bit            
            Object *inthi; // [3:3] Every hour flag bit            
            Object *inttmi; // [4:4] Timer underflow detection flag bit            
            Object *intali; // [5:5] Alarm coincidence flag bit            
            Object *interi; // [6:6] Time rewrite error interrupt flag bit            
            Object *intcri; // [7:7] Year/month/date/hour/minute/second/day of the week counter value read completion interrupt flag bit         
             } wtcr12; 

          // WTCR13(Control Register 13) bitfields.
          struct { 
            Object *intssie; // [0:0] Every 0.5-second interrupt enable bit            
            Object *intsie; // [1:1] Every second interrupt enable bit            
            Object *intmie; // [2:2] Every minute interrupt enable bit            
            Object *inthie; // [3:3] Every hour interrupt enable bit            
            Object *inttmie; // [4:4] Timer underflow interrupt enable bit            
            Object *intalie; // [5:5] Alarm coincidence interrupt enable bit            
            Object *interie; // [6:6] Time rewrite error interrupt enable bit            
            Object *intcrie; // [7:7] Year/month/date/hour/minute/second/day of the week counter value read completion interrupt enable bit          
            } wtcr13; 

          // WTCR20(Control Register 20) bitfields.
          struct { 
            Object *cread; // [0:0] RTC setting recall control bit            
            Object *cwrite; // [1:1] RTC setting save control bit            
            Object *bread; // [2:2] Back up register recall control bit            
            Object *bwrite; // [3:3] Back up register save control bit            
            Object *pread; // [4:4] VBAT PORT recall control bit            
            Object *pwrite; // [5:5] VBAT PORT save control bit          
            } wtcr20; 

          // WTCR21(Control Register 21) bitfields.
          struct { 
            Object *tmst; // [0:0] Timer counter start bit            
            Object *tmen; // [1:1] Timer counter control bit           
             Object *tmrun; // [2:2] Timer counter operation bit         
              } wtcr21; 

          // WTSR(Second Register) bitfields.
          struct { 
            Object *s; // [0:3] 1st digit of the second information            
            Object *ts; // [4:6] 2nd digit of the second information          
            } wtsr; 

          // WTMIR(Minute Register) bitfields.
          struct { 
            Object *mi; // [0:3] 1st digit of the minute information            
            Object *tmi; // [4:6] 2nd digit of the minute information          
            } wtmir; 

          // WTHR(Hour register) bitfields.
          struct { 
            Object *h; // [0:3] 1st digit of the hour information            
            Object *th; // [4:5] 2nd digit of the hour information          
            } wthr; 

          // WTDR(Day Register) bitfields.
          struct { 
            Object *d; // [0:3] 1st digit of the day information            
            Object *td; // [4:5] 2nd digit of the day information          
            } wtdr; 

          // WTDW(Day of the Week Register) bitfields.
          struct { 
            Object *dw; // [0:2] Day of the week information          
            } wtdw; 

          // WTMOR(Month Register) bitfields.
          struct { 
            Object *mo; // [0:3] 1st digit of the month information            
            Object *tmo0; // [4:4] 2nd digit of the month information          
            } wtmor; 

          // WTYR(Year Register) bitfields.
          struct { 
            Object *y; // [0:3] 1st digit of the year information           
             Object *ty; // [4:7] 2nd digit of the year information          
             } wtyr; 

          // ALMIR(Alarm Minute Register) bitfields.
          struct { 
            Object *ami; // [0:3] 1st digit of the alarm-set minute information           
             Object *tami; // [4:6] 2nd digit of the alarm-set minute information          
             } almir; 

          // ALHR(Alarm Hour Register) bitfields.
          struct { 
            Object *ah; // [0:3] 1st digit of the alarm-set hour information            
            Object *tah; // [4:5] 2nd digit of the alarm-set hour information          
            } alhr; 

          // ALDR(Alarm Date Register) bitfields.
          struct { 
            Object *ad; // [0:3] 1st digit of the alarm-set date information          
              Object *tad; // [4:5] 2nd digit of the alarm-set date information          
              } aldr; 

          // ALMOR(Alarm Month Register) bitfields.
          struct { 
            Object *amo; // [0:3] 1st digit of the alarm-set month information            
            Object *tamo0; // [4:4] 2nd digit of the alarm-set month information          
            } almor; 

          // ALYR(Alarm Years Register) bitfields.
          struct { 
            Object *ay; // [0:3] 1st digit of the alarm-set year information           
             Object *tay; // [4:7] 2nd digit of the alarm-set year information          
             } alyr; 

          // WTTR0(Timer Setting Register 0) bitfields.
          struct { 
            Object *tm; // [0:7] Timer Setting Register          
            } wttr0; 

          // WTTR1(Timer Setting Register 1) bitfields.
          struct { 
            Object *tm; // [0:7] Timer Setting Register          
            } wttr1; 

          // WTTR2(Timer Setting Register 2) bitfields.
          struct { 
            Object *tm; // [0:1] Timer Setting Register         
             } wttr2; 

          // WTCAL0(Frequency Correction Value Setting Register 0) bitfields.
          struct { 
            Object *wtcal0; // [0:7] Frequency correction value setting bits 0         
             } wtcal0; 

          // WTCAL1(Frequency Correction Value Setting Register 1) bitfields.
          struct { 
            Object *wtcal1; // [0:1] Frequency correction value setting bits 1          
            } wtcal1; 

          // WTCALEN(Frequency Correction Enable Register) bitfields.
          struct { 
            Object *wtcalen; // [0:0] Frequency correction enable bit         
             } wtcalen; 

          // WTDIV(Division Ratio Setting Register) bitfields.
          struct { 
            Object *wtdiv; // [0:3] Division ration setting bits          
            } wtdiv; 

          // WTDIVEN(Divider Output Enable Register) bitfields.
          struct { 
            Object *wtdiven; // [0:0] Divider enable bit            
            Object *wtdivrdy; // [1:1] Divider state bit         
             } wtdiven; 

          // WTCALPRD(Frequency Correction Period Setting Register) bitfields.
          struct { 
            Object *wtcalprd; // [0:5] Frequency correction value setting bits          
            } wtcalprd; 

          // WTCOSEL(RTCCO Output Selection Register) bitfields.
          struct { 
            Object *wtcosel; // [0:0] RTCCO output selection bit          
            } wtcosel; 

          // VB_CLKDIV(VB_CLKDIV Register) bitfields.
          struct { 
            Object *div; // [0:7] Transfer clock set bits         
             } vb_clkdiv; 

          // WTOSCCNT(WTOSCCNT Register) bitfields.
          struct { 
            Object *soscex; // [0:0] Oscillation enable bit            
            Object *soscntl; // [1:1] Cooperative operation control bit          
            } wtosccnt; 

          // CCS(CCS Register) bitfields.
          struct { 
            Object *ccs; // [0:7] Oscillation sustain current set bits          
            } ccs; 

          // CCB(CCB Register) bitfields.
          struct { 
            Object *ccb; // [0:7] Oscillation boost current set bits          
            } ccb; 

          // BOOST(BOOST Register) bitfields.
          struct { 
            Object *boost; // [0:1] Oscillation boost time set bits          
            } boost; 

          // EWKUP(EWKUP Register) bitfields.
          struct { 
            Object *wup0; // [0:0] Wakeup request bit          
            } ewkup; 

          // VDET(VDET Register) bitfields.
          struct { 
            Object *pon; // [7:7] Power-on bit          
            } vdet; 

          // HIBRST(HIBRST Register) bitfields.
          struct { 
            Object *hibrst; // [0:0] Hibernation start bit          
            } hibrst; 

          // VBPFR(Port Function Set Register) bitfields.
          struct { 
            Object *vpfr0; // [0:0] Port function of P48/VREGCTL pin set bit           
             Object *vpfr1; // [1:1] Port function of P49/VWAKEUP pin set bit           
              Object *vpfr2; // [2:2] Port function of P47/X1A pin set bit            
              Object *vpfr3; // [3:3] Port function of P46/X0A pin set bit            
              Object *spsr; // [4:5] Oscillation pin function set bits          
              } vbpfr; 

          // VBPCR(Pull-up Set Register) bitfields.
          struct { 
            Object *vpcr0; // [0:0] P48/VREGCTL pin pull-up set bit            
            Object *vpcr1; // [1:1] P49/VWAKEUP pin pull-up set bit            
            Object *vpcr2; // [2:2] P47/X1A pin pull-up set bit            
            Object *vpcr3; // [3:3] P46/X0A pin pull-up set bit          
            } vbpcr; 

          // VBDDR(Port I/O Direction Set Register) bitfields.
          struct { 
            Object *vddr0; // [0:0] Port direction of P48/VREGCTL pin set bit            
            Object *vddr1; // [1:1] Port direction of P49/VWAKEUP pin set bit            
            Object *vddr2; // [2:2] Port direction of P47/X1A pin set bit            
            Object *vddr3; // [3:3] Port direction of P46/X0A pin set bit          
            } vbddr; 

          // VBDIR(Port Input Data Register) bitfields.
          struct { 
            Object *vdir0; // [0:0] Port input data of P48/VREGCTL pin bit            
            Object *vdir1; // [1:1] Port input data of P49/VWAKEUP pin bit            
            Object *vdir2; // [2:2] Port input data of P47/X1A pin bit            
            Object *vdir3; // [3:3] Port input data of P46/X0A pin bit          
            } vbdir; 

          // VBDOR(Port Output Data Register) bitfields.
          struct { 
            Object *vdor0; // [0:0] Port output data of P48/VREGCTL pin bit            
            Object *vdor1; // [1:1] Port output data of P49/VWAKEUP pin bit            
            Object *vdor2; // [2:2] Port output data of P47/X1A pin bit            
            Object *vdor3; // [3:3] Port output data of P46/X0A pin bit          
            } vbdor; 

          // VBPZR(Port Pseudo-Open Drain Set Register) bitfields.
          struct { 
            Object *vpzr0; // [0:0] P48/VREGCTL pin pseudo-open drain set bit            
            Object *vpzr1; // [1:1] P49/VWAKEUP pin pseudo-open drain set bit          
            } vbpzr; 

          // BREG00(Backup Register) bitfields.
          struct { 
          } breg00; 

          // BREG01(Backup Register) bitfields.
          struct { 
          } breg01; 

          // BREG02(Backup Register) bitfields.
          struct { 
          } breg02; 

          // BREG03(Backup Register) bitfields.
          struct { 
          } breg03; 

          // BREG04(Backup Register) bitfields.
          struct { 
          } breg04; 

          // BREG05(Backup Register) bitfields.
          struct { 
          } breg05; 

          // BREG06(Backup Register) bitfields.
          struct { 
          } breg06; 

          // BREG07(Backup Register) bitfields.
          struct { 
          } breg07; 

          // BREG08(Backup Register) bitfields.
          struct { 
          } breg08; 

          // BREG09(Backup Register) bitfields.
          struct { 
          } breg09; 

          // BREG0A(Backup Register) bitfields.
          struct { 
          } breg0a; 

          // BREG0B(Backup Register) bitfields.
          struct { 
          } breg0b; 

          // BREG0C(Backup Register) bitfields.
          struct { 
          } breg0c; 

          // BREG0D(Backup Register) bitfields.
          struct { 
          } breg0d; 

          // BREG0E(Backup Register) bitfields.
          struct { 
          } breg0e; 

          // BREG0F(Backup Register) bitfields.
          struct { 
          } breg0f; 

          // BREG10(Backup Register) bitfields.
          struct { 
          } breg10; 

          // BREG11(Backup Register) bitfields.
          struct { 
          } breg11; 

          // BREG12(Backup Register) bitfields.
          struct { 
          } breg12; 

          // BREG13(Backup Register) bitfields.
          struct { 
          } breg13; 

          // BREG14(Backup Register) bitfields.
          struct { 
          } breg14; 

          // BREG15(Backup Register) bitfields.
          struct { 
          } breg15; 

          // BREG16(Backup Register) bitfields.
          struct { 
          } breg16; 

          // BREG17(Backup Register) bitfields.
          struct { 
          } breg17; 

          // BREG18(Backup Register) bitfields.
          struct { 
          } breg18; 

          // BREG19(Backup Register) bitfields.
          struct { 
          } breg19; 

          // BREG1A(Backup Register) bitfields.
          struct { 
          } breg1a; 

          // BREG1B(Backup Register) bitfields.
          struct { 
          } breg1b; 

          // BREG1C(Backup Register) bitfields.
          struct { 
          } breg1c; 

          // BREG1D(Backup Register) bitfields.
          struct { 
          } breg1d; 

          // BREG1E(Backup Register) bitfields.
          struct { 
          } breg1e; 

          // BREG1F(Backup Register) bitfields.
          struct { 
          } breg1f; 

          // BREG20(Backup Register) bitfields.
          struct { 
          } breg20; 

          // BREG21(Backup Register) bitfields.
          struct { 
          } breg21; 

          // BREG22(Backup Register) bitfields.
          struct { 
          } breg22; 

          // BREG23(Backup Register) bitfields.
          struct { 
          } breg23; 

          // BREG24(Backup Register) bitfields.
          struct { 
          } breg24; 

          // BREG25(Backup Register) bitfields.
          struct { 
          } breg25; 

          // BREG26(Backup Register) bitfields.
          struct { 
          } breg26; 

          // BREG27(Backup Register) bitfields.
          struct { 
          } breg27; 

          // BREG28(Backup Register) bitfields.
          struct { 
          } breg28; 

          // BREG29(Backup Register) bitfields.
          struct { 
          } breg29; 

          // BREG2A(Backup Register) bitfields.
          struct { 
          } breg2a; 

          // BREG2B(Backup Register) bitfields.
          struct { 
          } breg2b; 

          // BREG2C(Backup Register) bitfields.
          struct { 
          } breg2c; 

          // BREG2D(Backup Register) bitfields.
          struct { 
          } breg2d; 

          // BREG2E(Backup Register) bitfields.
          struct { 
          } breg2e; 

          // BREG2F(Backup Register) bitfields.
          struct { 
          } breg2f; 

          // BREG30(Backup Register) bitfields.
          struct { 
          } breg30; 

          // BREG31(Backup Register) bitfields.
          struct { 
          } breg31; 

          // BREG32(Backup Register) bitfields.
          struct { 
          } breg32; 

          // BREG33(Backup Register) bitfields.
          struct { 
          } breg33; 

          // BREG34(Backup Register) bitfields.
          struct { 
          } breg34; 

          // BREG35(Backup Register) bitfields.
          struct { 
          } breg35; 

          // BREG36(Backup Register) bitfields.
          struct { 
          } breg36; 

          // BREG37(Backup Register) bitfields.
          struct { 
          } breg37; 

          // BREG38(Backup Register) bitfields.
          struct { 
          } breg38; 

          // BREG39(Backup Register) bitfields.
          struct { 
          } breg39; 

          // BREG3A(Backup Register) bitfields.
          struct { 
          } breg3a; 

          // BREG3B(Backup Register) bitfields.
          struct { 
          } breg3b; 

          // BREG3C(Backup Register) bitfields.
          struct { 
          } breg3c; 

          // BREG3D(Backup Register) bitfields.
          struct { 
          } breg3d; 

          // BREG3E(Backup Register) bitfields.
          struct { 
          } breg3e; 

          // BREG3F(Backup Register) bitfields.
          struct { 
          } breg3f; 

          // BREG40(Backup Register) bitfields.
          struct { 
          } breg40; 

          // BREG41(Backup Register) bitfields.
          struct { 
          } breg41; 

          // BREG42(Backup Register) bitfields.
          struct { 
          } breg42; 

          // BREG43(Backup Register) bitfields.
          struct { 
          } breg43; 

          // BREG44(Backup Register) bitfields.
          struct { 
          } breg44; 

          // BREG45(Backup Register) bitfields.
          struct { 
          } breg45; 

          // BREG46(Backup Register) bitfields.
          struct { 
          } breg46; 

          // BREG47(Backup Register) bitfields.
          struct { 
          } breg47; 

          // BREG48(Backup Register) bitfields.
          struct { 
          } breg48; 

          // BREG49(Backup Register) bitfields.
          struct { 
          } breg49; 

          // BREG4A(Backup Register) bitfields.
          struct { 
          } breg4a; 

          // BREG4B(Backup Register) bitfields.
          struct { 
          } breg4b; 

          // BREG4C(Backup Register) bitfields.
          struct { 
          } breg4c; 

          // BREG4D(Backup Register) bitfields.
          struct { 
          } breg4d; 

          // BREG4E(Backup Register) bitfields.
          struct { 
          } breg4e; 

          // BREG4F(Backup Register) bitfields.
          struct { 
          } breg4f; 

          // BREG50(Backup Register) bitfields.
          struct { 
          } breg50; 

          // BREG51(Backup Register) bitfields.
          struct { 
          } breg51; 

          // BREG52(Backup Register) bitfields.
          struct { 
          } breg52; 

          // BREG53(Backup Register) bitfields.
          struct { 
          } breg53; 

          // BREG54(Backup Register) bitfields.
          struct { 
          } breg54; 

          // BREG55(Backup Register) bitfields.
          struct { 
          } breg55; 

          // BREG56(Backup Register) bitfields.
          struct { 
          } breg56; 

          // BREG57(Backup Register) bitfields.
          struct { 
          } breg57; 

          // BREG58(Backup Register) bitfields.
          struct { 
          } breg58; 

          // BREG59(Backup Register) bitfields.
          struct { 
          } breg59; 

          // BREG5A(Backup Register) bitfields.
          struct { 
          } breg5a; 

          // BREG5B(Backup Register) bitfields.
          struct { 
          } breg5b; 

          // BREG5C(Backup Register) bitfields.
          struct { 
          } breg5c; 

          // BREG5D(Backup Register) bitfields.
          struct { 
          } breg5d; 

          // BREG5E(Backup Register) bitfields.
          struct { 
          } breg5e; 

          // BREG5F(Backup Register) bitfields.
          struct { 
          } breg5f; 

          // BREG60(Backup Register) bitfields.
          struct { 
          } breg60; 

          // BREG61(Backup Register) bitfields.
          struct { 
          } breg61; 

          // BREG62(Backup Register) bitfields.
          struct { 
          } breg62; 

          // BREG63(Backup Register) bitfields.
          struct { 
          } breg63; 

          // BREG64(Backup Register) bitfields.
          struct { 
          } breg64; 

          // BREG65(Backup Register) bitfields.
          struct { 
          } breg65; 

          // BREG66(Backup Register) bitfields.
          struct { 
          } breg66; 

          // BREG67(Backup Register) bitfields.
          struct { 
          } breg67; 

          // BREG68(Backup Register) bitfields.
          struct { 
          } breg68; 

          // BREG69(Backup Register) bitfields.
          struct { 
          } breg69; 

          // BREG6A(Backup Register) bitfields.
          struct { 
          } breg6a; 

          // BREG6B(Backup Register) bitfields.
          struct { 
          } breg6b; 

          // BREG6C(Backup Register) bitfields.
          struct { 
          } breg6c; 

          // BREG6D(Backup Register) bitfields.
          struct { 
          } breg6d; 

          // BREG6E(Backup Register) bitfields.
          struct { 
          } breg6e; 

          // BREG6F(Backup Register) bitfields.
          struct { 
          } breg6f; 

          // BREG70(Backup Register) bitfields.
          struct { 
          } breg70; 

          // BREG71(Backup Register) bitfields.
          struct { 
          } breg71; 

          // BREG72(Backup Register) bitfields.
          struct { 
          } breg72; 

          // BREG73(Backup Register) bitfields.
          struct { 
          } breg73; 

          // BREG74(Backup Register) bitfields.
          struct { 
          } breg74; 

          // BREG75(Backup Register) bitfields.
          struct { 
          } breg75; 

          // BREG76(Backup Register) bitfields.
          struct { 
          } breg76; 

          // BREG77(Backup Register) bitfields.
          struct { 
          } breg77; 

          // BREG78(Backup Register) bitfields.
          struct { 
          } breg78; 

          // BREG79(Backup Register) bitfields.
          struct { 
          } breg79; 

          // BREG7A(Backup Register) bitfields.
          struct { 
          } breg7a; 

          // BREG7B(Backup Register) bitfields.
          struct { 
          } breg7b; 

          // BREG7C(Backup Register) bitfields.
          struct { 
          } breg7c; 

          // BREG7D(Backup Register) bitfields.
          struct { 
          } breg7d; 

          // BREG7E(Backup Register) bitfields.
          struct { 
          } breg7e; 

          // BREG7F(Backup Register) bitfields.
          struct { 
          } breg7f; 
        } fld;
      } e2;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} FM4RTCState;

// ----------------------------------------------------------------------------

#endif /* FM4_RTC_H_ */
