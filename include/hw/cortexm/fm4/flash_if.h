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

#ifndef FM4_FLASH_IF_H_
#define FM4_FLASH_IF_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/fm4/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_FM4_FLASH_IF DEVICE_PATH_FM4"FLASH_IF"


// ----------------------------------------------------------------------------

#define TYPE_FM4_FLASH_IF TYPE_FM4_PREFIX "flash_if" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_FM4_FLASH_IF_PARENT TYPE_PERIPHERAL
typedef PeripheralClass FM4FLASH_IFParentClass;
typedef PeripheralState FM4FLASH_IFParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define FM4_FLASH_IF_GET_CLASS(obj) \
    OBJECT_GET_CLASS(FM4FLASH_IFClass, (obj), TYPE_FM4_FLASH_IF)
#define FM4_FLASH_IF_CLASS(klass) \
    OBJECT_CLASS_CHECK(FM4FLASH_IFClass, (klass), TYPE_FM4_FLASH_IF)

typedef struct {
    // private: 
    FM4FLASH_IFParentClass parent_class;
    // public: 

    // None, so far.
} FM4FLASH_IFClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define FM4_FLASH_IF_STATE(obj) \
    OBJECT_CHECK(FM4FLASH_IFState, (obj), TYPE_FM4_FLASH_IF)

typedef struct {
    // private:
    FM4FLASH_IFParentState parent_obj;
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
        // E2FLASH_IF(Flash Memory) registers.
        struct { 
          Object *faszr; // 0x00(Flash Access Size Register) 
          Object *frwtr; // 0x04(Flash Read Wait Register) 
          Object *fstr; // 0x08(Flash Status Register) 
          Object *fsyndn; // 0x10(Flash Sync Down Register) 
          Object *fbfcr; // 0x14(Flash Buffer Control Register) 
          Object *ficr; // 0x20(Flash Interrupt Control Register) 
          Object *fisr; // 0x24(Flash Interrupt Status Register) 
          Object *ficlr; // 0x28(Flash Interrupt Clear Register) 
          Object *dfctrlr; // 0x30(Dual Flash mode Control Register) 
          Object *crtrmm; // 0x100(CR Trimming Data Mirror Register) 
          Object *fgpdm1; // 0x110(Flash General Purpose Data Mirror Register1) 
          Object *fgpdm2; // 0x114(Flash General Purpose Data Mirror Register2) 
          Object *fgpdm3; // 0x118(Flash General Purpose Data Mirror Register3) 
          Object *fgpdm4; // 0x11C(Flash General Purpose Data Mirror Register4) 
        } reg;

        struct { 

          // FASZR(Flash Access Size Register) bitfields.
          struct { 
            Object *asz; // [0:1] Access Size          
            } faszr; 

          // FRWTR(Flash Read Wait Register) bitfields.
          struct { 
            Object *rwt; // [0:1] Read Wait Cycle          
            } frwtr; 

          // FSTR(Flash Status Register) bitfields.
          struct { 
            Object *rdy; // [0:0] Flash Rdy            
            Object *hng; // [1:1] Flash Hang            
            Object *err; // [2:2] Flash ECC Error          
            } fstr; 

          // FSYNDN(Flash Sync Down Register) bitfields.
          struct { 
            Object *sd; // [0:2] Sync Down          
            } fsyndn; 

          // FBFCR(Flash Buffer Control Register) bitfields.
          struct { 
            Object *be; // [0:0] Buffer Enable            
            Object *bs; // [1:1] Buffer Status          
            } fbfcr; 

          // FICR(Flash Interrupt Control Register) bitfields.
          struct { 
            Object *rdyie; // [0:0] Flash RDY Interrupt Enable            
            Object *hangie; // [1:1] Flash HANG Interrupt Enable           
            Object *errie; // [2:2] Flash ECC Error Interrupt Enable          
            } ficr; 

          // FISR(Flash Interrupt Status Register) bitfields.
          struct { 
            Object *rdyif; // [0:0] Flash RDY Interrupt Flag            
            Object *hangif; // [1:1] Flash HANG Interrupt Flag            
            Object *errif; // [2:2] Flash ECC Error Interrupt Flag          
            } fisr; 

          // FICLR(Flash Interrupt Clear Register) bitfields.
          struct { 
            Object *rdyic; // [0:0] Flash RDY Interrupt Clear            
            Object *hangic; // [1:1] Flash HANG Interrupt Clear            
            Object *erric; // [2:2] Flash ECC Error Interrupt Clear          
            } ficlr; 

          // DFCTRLR(Dual Flash mode Control Register) bitfields.
          struct { 
            Object *dfe; // [0:0] Dual Flash mode Enable            
            Object *rme; // [1:1] Re-Map Enable            
            Object *wkey; // [16:31] Write Key          
            } dfctrlr; 

          // CRTRMM(CR Trimming Data Mirror Register) bitfields.
          struct { 
            Object *trmm; // [0:9] CR Trimming Data Mirror            
            Object *ttrmm; // [16:20] Temperature CR Trimming Data Mirror          
            } crtrmm; 

          // FGPDM1(Flash General Purpose Data Mirror Register1) bitfields.
          struct { 
            Object *gpd1; // [0:31] General Purpose Data1          
            } fgpdm1; 

          // FGPDM2(Flash General Purpose Data Mirror Register2) bitfields.
          struct { 
            Object *gpd2; // [0:31] General Purpose Data2          
            } fgpdm2; 

          // FGPDM3(Flash General Purpose Data Mirror Register3) bitfields.
          struct { 
            Object *gpd3; // [0:31] General Purpose Data3          
            } fgpdm3; 

          // FGPDM4(Flash General Purpose Data Mirror Register4) bitfields.
          struct { 
            Object *gpd4; // [0:31] General Purpose Data4          
            } fgpdm4; 
        } fld;
      } e2;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} FM4FLASH_IFState;

// ----------------------------------------------------------------------------

#endif /* FM4_FLASH_IF_H_ */