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

#ifndef FM4_ADC0_H_
#define FM4_ADC0_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/fm4/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_FM4_ADC0 DEVICE_PATH_FM4"ADC0"


// ----------------------------------------------------------------------------

#define TYPE_FM4_ADC0 TYPE_FM4_PREFIX "adc0" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_FM4_ADC0_PARENT TYPE_PERIPHERAL
typedef PeripheralClass FM4ADC0ParentClass;
typedef PeripheralState FM4ADC0ParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define FM4_ADC0_GET_CLASS(obj) \
    OBJECT_GET_CLASS(FM4ADC0Class, (obj), TYPE_FM4_ADC0)
#define FM4_ADC0_CLASS(klass) \
    OBJECT_CLASS_CHECK(FM4ADC0Class, (klass), TYPE_FM4_ADC0)

// Note: the "port-index" property has type "int".
typedef enum {
    FM4_ADC0 = 0,
    FM4_ADC1,
    FM4_ADC2,
    FM4_ADC_UNDEFINED = 0xFF,
} ADC_index_t;

// ----------------------------------------------------------------------------

typedef struct {
    // private: 
    FM4ADC0ParentClass parent_class;
    // public: 

    // None, so far.
} FM4ADC0Class;





// ----------------------------------------------------------------------------
// Instance definitions.
#define FM4_ADC0_STATE(obj) \
    OBJECT_CHECK(FM4ADC0State, (obj), TYPE_FM4_ADC0)

static void lcd_mouse_motion_to_adc(int x, int y);
//FM4ADC0State *state;
typedef struct {
    // private:
    FM4ADC0ParentState parent_obj;
    // public:
    
    ADC_index_t port_index;
    const FM4Capabilities *capabilities;

    // TODO: remove this if the peripheral is always enabled.
    // Points to the bitfield that enables the peripheral.
    Object *enabling_bit;

    qemu_irq sccr_irq[8];
    
    union {
      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

      // DO NOT REMOVE FIELDS! Automatically generated!
      // Merge fields from different family members.
      struct {
        // E2ADC0(ADC0 Registers) registers.
        struct { 
          Object *adcr; // 0x1(A/D Control Register) 
          Object *adsr; // 0x0(A/D Status Register) 
          Object *sccr; // 0x9(Scan Conversion Control Register) 
          Object *sfns; // 0x8(Scan Conversion FIFO Stage Count Setup Register) 
          Object *scfd; // 0xC(Scan Conversion FIFO Data Register) 
          Object *scis3; // 0x11(Scan Conversion Input Selection Register 3) 
          Object *scis2; // 0x10(Scan Conversion Input Selection Register 2) 
          Object *scis1; // 0x15(Scan Conversion Input Selection Register 1) 
          Object *scis0; // 0x14(Scan Conversion Input Selection Register 0) 
          Object *pfns; // 0x18(Priority Conversion FIFO Stage Count Setup Register) 
          Object *pccr; // 0x19(Priority Conversion Control Register) 
          Object *pcfd; // 0x1C(Priority Conversion FIFO Data Register) 
          Object *pcis; // 0x20(Priority Conversion Input Selection Register) 
          Object *cmpcr; // 0x24(A/D Comparison Control Register) 
          Object *cmpd; // 0x26(A/D Comparison Value Setup Register) 
          Object *adss3; // 0x29(Sampling Time Selection Register 3) 
          Object *adss2; // 0x28(Sampling Time Selection Register 2) 
          Object *adss1; // 0x2D(Sampling Time Selection Register 1) 
          Object *adss0; // 0x2C(Sampling Time Selection Register 0) 
          Object *adst1; // 0x30(Sampling Time Setup Register 1) 
          Object *adst0; // 0x31(Sampling Time Setup Register 0) 
          Object *adct; // 0x34(Frequency Division Ratio Setup Register) 
          Object *prtsl; // 0x38(Priority Conversion Timer Trigger Selection Register) 
          Object *sctsl; // 0x39(Scan Conversion Timer Trigger Selection Register) 
          Object *adcen; // 0x3C(A/D Operation Enable Setup Register) 
          Object *wcmrcot; // 0x44(Range Comparison Threshold Excess Flag Register) 
          Object *wcmrcif; // 0x48(Range Comparison Flag Register) 
          Object *wcmpcr; // 0x4C(Range Comparison Control Register) 
          Object *wcmpsr; // 0x4D(Range Comparison Channel Select Register) 
          Object *wcmpdl; // 0x50(Lower Limit Threshold Setup Register) 
          Object *wcmpdh; // 0x52(Upper Limit Setup Register) 
        } reg;

        struct { 

          // ADCR(A/D Control Register) bitfields.
          struct { 
            Object *ovrie; // [0:0] FIFO overrun interrupt enable bit            
            Object *cmpie; // [1:1] Conversion result comparison interrupt enable bit            
            Object *pcie; // [2:2] Priority conversion interrupt enable bit            
            Object *scie; // [3:3] Scan conversion interrupt enable bit            
            Object *cmpif; // [5:5] Conversion result comparison interrupt request bit            
            Object *pcif; // [6:6] Priority conversion interrupt request bit            
            Object *scif; // [7:7] Scan conversion interrupt request bit          
            } adcr; 

          // ADSR(A/D Status Register) bitfields.
          struct { 
            Object *scs; // [0:0] Scan conversion status flag            
            Object *pcs; // [1:1] Priority conversion status flag            
            Object *pcns; // [2:2] Priority conversion pending flag            
            Object *fdas; // [6:6] FIFO data placement selection bit            
            Object *adstp; // [7:7] A/D conversion forced stop bit          
            } adsr; 

          // SCCR(Scan Conversion Control Register) bitfields.
          struct { 
            Object *sstr; // [0:0] Scan conversion start bit            
            Object *shen; // [1:1] Scan conversion timer start enable bit            
            Object *rpt; // [2:2] Scan conversion repeat bit            
            Object *sfclr; // [4:4] Scan conversion FIFO clear bit            
            Object *sovr; // [5:5] Scan conversion overrun flag            
            Object *sful; // [6:6] Scan conversion FIFO full bit            
            Object *semp; // [7:7] Scan conversion FIFO empty bit          
            } sccr; 

          // SFNS(Scan Conversion FIFO Stage Count Setup Register) bitfields.
          struct { 
            Object *sfs; // [0:3] Scan conversion FIFO stage count setting bit          
            } sfns; 

          // SCFD(Scan Conversion FIFO Data Register) bitfields.
          struct { 
            Object *sc; // [0:4] Conversion input channel bits            
            Object *rs; // [8:9] Scan conversion start factor            
            Object *invl; // [12:12] A/D conversion result disable bit            
            Object *sd; // [20:31] Scan conversion result          
            } scfd; 

          // SCIS3(Scan Conversion Input Selection Register 3) bitfields.
          struct { 
            Object *an24; // [0:0] Bit0 of SCIS3            
            Object *an25; // [1:1] Bit1 of SCIS3            
            Object *an26; // [2:2] Bit2 of SCIS3            
            Object *an27; // [3:3] Bit3 of SCIS3            
            Object *an28; // [4:4] Bit4 of SCIS3            
            Object *an29; // [5:5] Bit5 of SCIS3            
            Object *an30; // [6:6] Bit6 of SCIS3            
            Object *an31; // [7:7] Bit7 of SCIS3          
            } scis3; 

          // SCIS2(Scan Conversion Input Selection Register 2) bitfields.
          struct { 
            Object *an16; // [0:0] Bit0 of SCIS2            
            Object *an17; // [1:1] Bit1 of SCIS2            
            Object *an18; // [2:2] Bit2 of SCIS2            
            Object *an19; // [3:3] Bit3 of SCIS2            
            Object *an20; // [4:4] Bit4 of SCIS2            
            Object *an21; // [5:5] Bit5 of SCIS2            
            Object *an22; // [6:6] Bit6 of SCIS2            
            Object *an23; // [7:7] Bit7 of SCIS2          
            } scis2; 

          // SCIS1(Scan Conversion Input Selection Register 1) bitfields.
          struct { 
            Object *an8; // [0:0] Bit0 of SCIS1            
            Object *an9; // [1:1] Bit1 of SCIS1            
            Object *an10; // [2:2] Bit2 of SCIS1            
            Object *an11; // [3:3] Bit3 of SCIS1            
            Object *an12; // [4:4] Bit4 of SCIS1            
            Object *an13; // [5:5] Bit5 of SCIS1            
            Object *an14; // [6:6] Bit6 of SCIS1            
            Object *an15; // [7:7] Bit7 of SCIS1          
            } scis1; 

          // SCIS0(Scan Conversion Input Selection Register 0) bitfields.
          struct { 
            Object *an0; // [0:0] Bit0 of SCIS0            
            Object *an1; // [1:1] Bit1 of SCIS0            
            Object *an2; // [2:2] Bit2 of SCIS0            
            Object *an3; // [3:3] Bit3 of SCIS0            
            Object *an4; // [4:4] Bit4 of SCIS0            
            Object *an5; // [5:5] Bit5 of SCIS0            
            Object *an6; // [6:6] Bit6 of SCIS0            
            Object *an7; // [7:7] Bit7 of SCIS0          
            } scis0; 

          // PFNS(Priority Conversion FIFO Stage Count Setup Register) bitfields.
          struct { 
            Object *pfs; // [0:1] Priority conversion FIFO stage count setting bits            
            Object *test; // [4:5] Test bits          
            } pfns; 

          // PCCR(Priority Conversion Control Register) bitfields.
          struct { 
            Object *pstr; // [0:0] Priority conversion start bit            
            Object *phen; // [1:1] Priority conversion timer start enable bit           
            Object *peen; // [2:2] Priority conversion external start enable bit            
            Object *esce; // [3:3] External trigger analog input selection bit            
            Object *pfclr; // [4:4] Priority conversion FIFO clear bit            
            Object *povr; // [5:5] Priority conversion overrun flag            
            Object *pful; // [6:6] Priority conversion FIFO full bit            
            Object *pemp; // [7:7] Priority conversion FIFO empty bit          
            } pccr; 

          // PCFD(Priority Conversion FIFO Data Register) bitfields.
          struct { 
            Object *pc; // [0:4] Conversion input channel bits            
            Object *rs; // [8:10] Scan conversion start factor            
            Object *invl; // [12:12] A/D conversion result disable bit            
            Object *pd; // [20:31] Priority conversion result          
            } pcfd; 

          // PCIS(Priority Conversion Input Selection Register) bitfields.
          struct { 
            Object *p1a; // [0:2] Priority level 1 analog input selection            
            Object *p2a; // [3:7] Priority level 2 analog input selection          
            } pcis; 

          // CMPCR(A/D Comparison Control Register) bitfields.
          struct { 
            Object *cch; // [0:4] Comparison target analog input channel            
            Object *cmd0; // [5:5] Comparison mode 0            
            Object *cmd1; // [6:6] Comparison mode 1            
            Object *cmpen; // [7:7] Conversion result comparison function operation enable bit          
            } cmpcr; 

          // CMPD(A/D Comparison Value Setup Register) bitfields.
          struct { 
            Object *cmad; // [6:15] A/D conversion result value setting bits          
            } cmpd; 

          // ADSS3(Sampling Time Selection Register 3) bitfields.
          struct { 
            Object *ts24; // [0:0] Bit0 of ADSS3            
            Object *ts25; // [1:1] Bit1 of ADSS3            
            Object *ts26; // [2:2] Bit2 of ADSS3            
            Object *ts27; // [3:3] Bit3 of ADSS3            
            Object *ts28; // [4:4] Bit4 of ADSS3            
            Object *ts29; // [5:5] Bit5 of ADSS3            
            Object *ts30; // [6:6] Bit6 of ADSS3            
            Object *ts31; // [7:7] Bit7 of ADSS3         
           } adss3; 

          // ADSS2(Sampling Time Selection Register 2) bitfields.
          struct { 
            Object *ts16; // [0:0] Bit0 of ADSS2            
            Object *ts17; // [1:1] Bit1 of ADSS2            
            Object *ts18; // [2:2] Bit2 of ADSS2            
            Object *ts19; // [3:3] Bit3 of ADSS2            
            Object *ts20; // [4:4] Bit4 of ADSS2            
            Object *ts21; // [5:5] Bit5 of ADSS2            
            Object *ts22; // [6:6] Bit6 of ADSS2            
            Object *ts23; // [7:7] Bit7 of ADSS2          
            } adss2; 

          // ADSS1(Sampling Time Selection Register 1) bitfields.
          struct { 
            Object *ts8; // [0:0] Bit0 of ADSS1            
            Object *ts9; // [1:1] Bit1 of ADSS1            
            Object *ts10; // [2:2] Bit2 of ADSS1            
            Object *ts11; // [3:3] Bit3 of ADSS1            
            Object *ts12; // [4:4] Bit4 of ADSS1            
            Object *ts13; // [5:5] Bit5 of ADSS1            
            Object *ts14; // [6:6] Bit6 of ADSS1            
            Object *ts15; // [7:7] Bit7 of ADSS1          
            } adss1; 

          // ADSS0(Sampling Time Selection Register 0) bitfields.
          struct { 
            Object *ts0; // [0:0] Bit0 of ADSS0            
            Object *ts1; // [1:1] Bit1 of ADSS0            
            Object *ts2; // [2:2] Bit2 of ADSS0            
            Object *ts3; // [3:3] Bit3 of ADSS0            
            Object *ts4; // [4:4] Bit4 of ADSS0            
            Object *ts5; // [5:5] Bit5 of ADSS0            
            Object *ts6; // [6:6] Bit6 of ADSS0            
            Object *ts7; // [7:7] Bit7 of ADSS0         
           } adss0; 

          // ADST1(Sampling Time Setup Register 1) bitfields.
          struct { 
            Object *st1; // [0:4] Sampling time setting bits            
            Object *stx1; // [5:7] Sampling time N times setting bits          
            } adst1; 

          // ADST0(Sampling Time Setup Register 0) bitfields.
          struct { 
            Object *st0; // [0:4] Sampling time setting bits            
            Object *stx0; // [5:7] Sampling time N times setting bits          
            } adst0; 

          // ADCT(Frequency Division Ratio Setup Register) bitfields.
          struct { 
            Object *ct; // [0:7] Frequency division ratio setting bits          
            } adct; 

          // PRTSL(Priority Conversion Timer Trigger Selection Register) bitfields.
          struct { 
            Object *prtsl; // [0:3] Priority conversion timer trigger selection bit          
            } prtsl; 

          // SCTSL(Scan Conversion Timer Trigger Selection Register) bitfields.
          struct { 
            Object *sctsl; // [0:3] Scan conversion timer trigger selection bit          
            } sctsl; 

          // ADCEN(A/D Operation Enable Setup Register) bitfields.
          struct { 
            Object *enbl; // [0:0] A/D operation enable bit            
            Object *ready; // [1:1] A/D operation enable state bit            
            Object *enbltime; // [8:15] Operation enable state transition cycle selection bits          
            } adcen; 

          // WCMRCOT(Range Comparison Threshold Excess Flag Register) bitfields.
          struct { 
            Object *rcoof; // [0:0] Threshold excess flag bit          
            } wcmrcot; 

          // WCMRCIF(Range Comparison Flag Register) bitfields.
          struct { 
            Object *rcint; // [0:0] Range comparison interrupt factor flag          
            } wcmrcif; 

          // WCMPCR(Range Comparison Control Register) bitfields.
          struct { 
            Object *rcoe; // [2:2] Range comparison execution enable bit            
            Object *rcoie; // [3:3] Range comparison interrupt request enable bit            
            Object *rcoirs; // [4:4] Selection bit of within-range and out-of- range confirmation            
            Object *rcocd; // [5:7] Continuous detection specification count/state indication bits          
            } wcmpcr; 

          // WCMPSR(Range Comparison Channel Select Register) bitfields.
          struct { 
            Object *wcch; // [0:4] Comparison target analog input channel            
            Object *wcmd; // [5:5] Comparison mode select bit          
            } wcmpsr; 

          // WCMPDL(Lower Limit Threshold Setup Register) bitfields.
          struct { 
            Object *cmld; // [6:15] Lower limit threshold bits          
            } wcmpdl; 

          // WCMPDH(Upper Limit Setup Register) bitfields.
          struct { 
            Object *cmhd; // [6:15] Upper limit threshold bits          
            } wcmpdh; 
        } fld;
      } e2;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} FM4ADC0State;

// ----------------------------------------------------------------------------

#endif /* FM4_ADC0_H_ */
