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

#ifndef FM4_CRG_H_
#define FM4_CRG_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/fm4/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_FM4_CRG DEVICE_PATH_FM4"CRG"

#define FM4_CRG_SIZEOF_ENABLING_BITFIELD (sizeof(DEVICE_PATH_FM4_CRG)+32)

// ----------------------------------------------------------------------------

#define TYPE_FM4_CRG TYPE_FM4_PREFIX "crg" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_FM4_CRG_PARENT TYPE_PERIPHERAL
typedef PeripheralClass FM4CRGParentClass;
typedef PeripheralState FM4CRGParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define FM4_CRG_GET_CLASS(obj) \
    OBJECT_GET_CLASS(FM4CRGClass, (obj), TYPE_FM4_CRG)
#define FM4_CRG_CLASS(klass) \
    OBJECT_CLASS_CHECK(FM4CRGClass, (klass), TYPE_FM4_CRG)

typedef struct {
    // private: 
    FM4CRGParentClass parent_class;
    // public: 

    // None, so far.
} FM4CRGClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define FM4_CRG_STATE(obj) \
    OBJECT_CHECK(FM4CRGState, (obj), TYPE_FM4_CRG)

typedef struct {
    // private:
    FM4CRGParentState parent_obj;
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
        // E2CRG(Clock Unit Registers) registers.
        struct { 
          Object *scm_ctl; // 0x0(System Clock Mode Control Register) 
          Object *scm_str; // 0x4(System Clock Mode Status Register) 
          Object *stb_ctl; // 0x8(Standby Mode Control Register) 
          Object *rst_str; // 0xC(Reset Cause Register) 
          Object *bsc_psr; // 0x10(Base Clock Prescaler Register) 
          Object *apbc0_psr; // 0x14(APB0 Prescaler Register) 
          Object *apbc1_psr; // 0x18(APB1 Prescaler Register) 
          Object *apbc2_psr; // 0x1C(APB2 Prescaler Register) 
          Object *swc_psr; // 0x20(Software Watchdog Clock Prescaler Register) 
          Object *ttc_psr; // 0x28(Trace Clock Prescaler Register) 
          Object *csw_tmr; // 0x30(Clock Stabilization Wait Time Register) 
          Object *psw_tmr; // 0x34(PLL Clock Stabilization Wait Time Setup Register) 
          Object *pll_ctl1; // 0x38(PLL Control Register 1) 
          Object *pll_ctl2; // 0x3C(PLL Control Register 2) 
          Object *csv_ctl; // 0x40(CSV control register) 
          Object *csv_str; // 0x44(CSV status register) 
          Object *fcswh_ctl; // 0x48(Frequency detection window setting register) 
          Object *fcswl_ctl; // 0x4C(Frequency detection window setting register) 
          Object *fcswd_ctl; // 0x50(Frequency detection counter register) 
          Object *dbwdt_ctl; // 0x54(Debug Break Watchdog Timer Control Register) 
          Object *int_enr; // 0x60(Interrupt Enable Register) 
          Object *int_str; // 0x64(Interrupt Status Register) 
          Object *int_clr; // 0x68(Interrupt Clear Register) 
        } reg;

        struct { 

          // SCM_CTL(System Clock Mode Control Register) bitfields.
          struct { 
            Object *mosce; // [1:1] Main clock oscillation enable bit            
            Object *sosce; // [3:3] Sub clock oscillation enable bit            
            Object *plle; // [4:4] PLL oscillation enable bit            
            Object *rcs; // [5:7] Master clock switch control bits          
            } scm_ctl; 

          // SCM_STR(System Clock Mode Status Register) bitfields.
          struct { 
            Object *mordy; // [1:1] Main clock oscillation stable bit            
            Object *sordy; // [3:3] Sub clock oscillation stable bit            
            Object *plrdy; // [4:4] PLL oscillation stable bit            
            Object *rcm; // [5:7] Master clock selection bits          
            } scm_str; 

          // STB_CTL(Standby Mode Control Register) bitfields.
          struct { 
            Object *stm; // [0:1] Standby mode selection bit            
            Object *dstm; // [2:2] Deep standby mode select bit            
            Object *spl; // [4:4] Standby pin level setting bit            
            Object *key; // [16:31] Standby mode control write control bit          
            } stb_ctl; 

          // RST_STR(Reset Cause Register) bitfields.
          struct { 
            Object *ponr; // [0:0] Power-on reset/low-voltage detection reset flag            
            Object *initx; // [1:1] INITX pin input reset flag            
            Object *swdt; // [4:4] Software watchdog reset flag            
            Object *hwdt; // [5:5] Hardware watchdog reset flag            
            Object *csvr; // [6:6] Clock failure detection reset flag            
            Object *fcsr; // [7:7] Flag for anomalous frequency detection reset            
            Object *srst; // [8:8] Software reset flag          
            } rst_str; 

          // BSC_PSR(Base Clock Prescaler Register) bitfields.
          struct { 
            Object *bsr; // [0:2] Base clock frequency division ratio setting bit          
            } bsc_psr; 

          // APBC0_PSR(APB0 Prescaler Register) bitfields.
          struct { 
            Object *apbc0; // [0:1] APB0 bus clock frequency division ratio setting bit          
            } apbc0_psr; 

          // APBC1_PSR(APB1 Prescaler Register) bitfields.
          struct { 
            Object *apbc1; // [0:1] APB1 bus clock frequency division ratio setting bit            
            Object *apbc1rst; // [4:4] APB1 bus reset control bit            
            Object *apbc1en; // [7:7] APB1 clock enable bit          
            } apbc1_psr; 

          // APBC2_PSR(APB2 Prescaler Register) bitfields.
          struct { 
            Object *apbc2; // [0:1] APB2 bus clock frequency division ratio setting bit            
            Object *apbc2rst; // [4:4] APB2 bus reset control bit            
            Object *apbc2en; // [7:7] APB2 clock enable bit          
            } apbc2_psr; 

          // SWC_PSR(Software Watchdog Clock Prescaler Register) bitfields.
          struct { 
            Object *swds; // [0:1] Software watchdog clock frequency division ratio setting bit          
            } swc_psr; 

          // TTC_PSR(Trace Clock Prescaler Register) bitfields.
          struct { 
            Object *ttc; // [0:1] Trace clock frequency division ratio setting bit         
             } ttc_psr; 

          // CSW_TMR(Clock Stabilization Wait Time Register) bitfields.
          struct { 
            Object *mowt; // [0:3] Main clock stabilization wait time setup bit            
            Object *sowt; // [4:7] Sub clock stabilization wait time setup bit          
            } csw_tmr; 

          // PSW_TMR(PLL Clock Stabilization Wait Time Setup Register) bitfields.
          struct { 
            Object *powt; // [0:2] PLL clock stabilization wait time setup bit            
            Object *pinc; // [4:4] PLL input clock select bit          
            } psw_tmr; 

          // PLL_CTL1(PLL Control Register 1) bitfields.
          struct { 
            Object *pllm; // [0:3] PLL VCO clock frequency division ratio setting bit            
            Object *pllk; // [4:7] PLL input clock frequency division ratio setting bit          
            } pll_ctl1; 

          // PLL_CTL2(PLL Control Register 2) bitfields.
          struct { 
            Object *plln; // [0:5] PLL feedback frequency division ratio setting bit          
            } pll_ctl2; 

          // CSV_CTL(CSV control register) bitfields.
          struct { 
            Object *mcsve; // [0:0] Main CSV function enable bit            
            Object *scsve; // [1:1] Sub CSV function enable bit            
            Object *fcsde; // [8:8] FCS function enable bit            
            Object *fcsre; // [9:9] FCS reset output enable bit            
            Object *fcd; // [12:14] FCS count cycle setting bits          
            } csv_ctl; 

          // CSV_STR(CSV status register) bitfields.
          struct { 
            Object *mcmf; // [0:0] Main clock failure detection flag            
            Object *scmf; // [1:1] Sub clock failure detection flag          
            } csv_str; 

          // FCSWH_CTL(Frequency detection window setting register) bitfields.
          struct { 
            Object *fwh; // [0:15] Frequency detection window setting bits (Upper)          
            } fcswh_ctl; 

          // FCSWL_CTL(Frequency detection window setting register) bitfields.
          struct { 
            Object *fwl; // [0:15] Frequency detection window setting bits (Lower)          
            } fcswl_ctl; 

          // FCSWD_CTL(Frequency detection counter register) bitfields.
          struct { 
            Object *fwd; // [0:15] Frequency detection count data          
            } fcswd_ctl; 

          // DBWDT_CTL(Debug Break Watchdog Timer Control Register) bitfields.
          struct { 
            Object *dpswbe; // [5:5] SW-WDG debug mode break bit            
            Object *dphwbe; // [7:7] HW-WDG debug mode break bit          
            } dbwdt_ctl; 

          // INT_ENR(Interrupt Enable Register) bitfields.
          struct { 
            Object *mcse; // [0:0] Main oscillation stabilization completion interrupt enable bit            
            Object *scse; // [1:1] Sub oscillation stabilization completion interrupt enable bit            
            Object *pcse; // [2:2] PLL oscillation stabilization completion interrupt enable bit            
            Object *fcse; // [5:5] Anomalous frequency detection interrupt enable bit          
            } int_enr; 

          // INT_STR(Interrupt Status Register) bitfields.
          struct { 
            Object *mcsi; // [0:0] Main oscillation stabilization completion interrupt status bit            
            Object *scsi; // [1:1] Sub oscillation stabilization completion interrupt status bit            
            Object *pcsi; // [2:2] PLL oscillation stabilization completion interrupt status bit            
            Object *fcsi; // [5:5] Anomalous frequency detection interrupt status bit          
            } int_str; 

          // INT_CLR(Interrupt Clear Register) bitfields.
          struct { 
            Object *mcsc; // [0:0] Main oscillation stabilization completion interrupt cause clear bit            
            Object *scsc; // [1:1] Sub oscillation stabilization completion interrupt cause clear bit            
            Object *pcsc; // [2:2] PLL oscillation stabilization completion interrupt cause clear bit            
            Object *fcsc; // [5:5] Anomalous frequency detection interrupt cause clear bit          
            } int_clr; 
        } fld;
      } e2;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} FM4CRGState;

// ----------------------------------------------------------------------------

#endif /* FM4_CRG_H_ */
