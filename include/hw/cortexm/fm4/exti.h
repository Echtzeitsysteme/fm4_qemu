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

#ifndef FM4_EXTI_H_
#define FM4_EXTI_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/fm4/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_FM4_EXTI DEVICE_PATH_FM4 "EXTI"

#define FM4_IRQ_EXTI_IN     "exti-in"
#define FM4_IRQ_EXTI_OUT    "nvic-out"
// ----------------------------------------------------------------------------

#define TYPE_FM4_EXTI TYPE_FM4_PREFIX "exti" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_FM4_EXTI_PARENT TYPE_PERIPHERAL
typedef PeripheralClass FM4EXTIParentClass;
typedef PeripheralState FM4EXTIParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define FM4_EXTI_GET_CLASS(obj) \
    OBJECT_GET_CLASS(FM4EXTIClass, (obj), TYPE_FM4_EXTI)
#define FM4_EXTI_CLASS(klass) \
    OBJECT_CLASS_CHECK(FM4EXTIClass, (klass), TYPE_FM4_EXTI)

typedef struct {
    // private: 
    FM4EXTIParentClass parent_class;
    // public: 

    // None, so far.
} FM4EXTIClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define FM4_EXTI_STATE(obj) \
    OBJECT_CHECK(FM4EXTIState, (obj), TYPE_FM4_EXTI)

typedef struct {
    // private:
    FM4EXTIParentState parent_obj;
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
        // E2EXTI(External Interrupt and NMI Control) registers.
        struct { 
          Object *enir; // 0x0(Enable Interrupt Request Register) 
          Object *eirr; // 0x4(External Interrupt Request Register) 
          Object *eicl; // 0x8(External Interrupt Clear Register) 
          Object *elvr; // 0xC(External Interrupt Level Register) 
          Object *elvr1; // 0x10(External Interrupt Level Register 1) 
          Object *nmirr; // 0x14(Non Maskable Interrupt Request Register) 
          Object *nmicl; // 0x18(Non Maskable Interrupt Clear Register) 
        } reg;

        struct { 

          // ENIR(Enable Interrupt Request Register) bitfields.
          struct { 
            Object *en0; // [0:0] Bit0 of ENIR            
            Object *en1; // [1:1] Bit1 of ENIR            
            Object *en2; // [2:2] Bit2 of ENIR            
            Object *en3; // [3:3] Bit3 of ENIR            
            Object *en4; // [4:4] Bit4 of ENIR            
            Object *en5; // [5:5] Bit5 of ENIR            
            Object *en6; // [6:6] Bit6 of ENIR            
            Object *en7; // [7:7] Bit7 of ENIR            
            Object *en8; // [8:8] Bit8 of ENIR            
            Object *en9; // [9:9] Bit9 of ENIR            
            Object *en10; // [10:10] Bit10 of ENIR            
            Object *en11; // [11:11] Bit11 of ENIR            
            Object *en12; // [12:12] Bit12 of ENIR            
            Object *en13; // [13:13] Bit13 of ENIR            
            Object *en14; // [14:14] Bit14 of ENIR            
            Object *en15; // [15:15] Bit15 of ENIR            
            Object *en16; // [16:16] Bit16 of ENIR            
            Object *en17; // [17:17] Bit17 of ENIR            
            Object *en18; // [18:18] Bit18 of ENIR            
            Object *en19; // [19:19] Bit19 of ENIR            
            Object *en20; // [20:20] Bit20 of ENIR            
            Object *en21; // [21:21] Bit21 of ENIR            
            Object *en22; // [22:22] Bit22 of ENIR            
            Object *en23; // [23:23] Bit23 of ENIR            
            Object *en24; // [24:24] Bit24 of ENIR            
            Object *en25; // [25:25] Bit25 of ENIR            
            Object *en26; // [26:26] Bit26 of ENIR           
            Object *en27; // [27:27] Bit27 of ENIR           
            Object *en28; // [28:28] Bit28 of ENIR            
            Object *en29; // [29:29] Bit29 of ENIR            
            Object *en30; // [30:30] Bit30 of ENIR            
            Object *en31; // [31:31] Bit31 of ENIR          
          } enir; 

          // EIRR(External Interrupt Request Register) bitfields.
          struct { 
            Object *er0; // [0:0] Bit0 of EIRR            
            Object *er1; // [1:1] Bit1 of EIRR            
            Object *er2; // [2:2] Bit2 of EIRR           
            Object *er3; // [3:3] Bit3 of EIRR            
            Object *er4; // [4:4] Bit4 of EIRR            
            Object *er5; // [5:5] Bit5 of EIRR            
            Object *er6; // [6:6] Bit6 of EIRR            
            Object *er7; // [7:7] Bit7 of EIRR            
            Object *er8; // [8:8] Bit8 of EIRR            
            Object *er9; // [9:9] Bit9 of EIRR            
            Object *er10; // [10:10] Bit10 of EIRR           
            Object *er11; // [11:11] Bit11 of EIRR            
            Object *er12; // [12:12] Bit12 of EIRR            
            Object *er13; // [13:13] Bit13 of EIRR            
            Object *er14; // [14:14] Bit14 of EIRR            
            Object *er15; // [15:15] Bit15 of EIRR            
            Object *er16; // [16:16] Bit16 of EIRR            
            Object *er17; // [17:17] Bit17 of EIRR            
            Object *er18; // [18:18] Bit18 of EIRR            
            Object *er19; // [19:19] Bit19 of EIRR            
            Object *er20; // [20:20] Bit20 of EIRR            
            Object *er21; // [21:21] Bit21 of EIRR            
            Object *er22; // [22:22] Bit22 of EIRR            
            Object *er23; // [23:23] Bit23 of EIRR            
            Object *er24; // [24:24] Bit24 of EIRR            
            Object *er25; // [25:25] Bit25 of EIRR            
            Object *er26; // [26:26] Bit26 of EIRR            
            Object *er27; // [27:27] Bit27 of EIRR            
            Object *er28; // [28:28] Bit28 of EIRR            
            Object *er29; // [29:29] Bit29 of EIRR            
            Object *er30; // [30:30] Bit30 of EIRR            
            Object *er31; // [31:31] Bit31 of EIRR          
          } eirr; 

          // EICL(External Interrupt Clear Register) bitfields.
          struct { 
            Object *ecl0; // [0:0] Bit0 of EICL            
            Object *ecl1; // [1:1] Bit1 of EICL            
            Object *ecl2; // [2:2] Bit2 of EICL            
            Object *ecl3; // [3:3] Bit3 of EICL            
            Object *ecl4; // [4:4] Bit4 of EICL            
            Object *ecl5; // [5:5] Bit5 of EICL            
            Object *ecl6; // [6:6] Bit6 of EICL            
            Object *ecl7; // [7:7] Bit7 of EICL            
            Object *ecl8; // [8:8] Bit8 of EICL            
            Object *ecl9; // [9:9] Bit9 of EICL            
            Object *ecl10; // [10:10] Bit10 of EICL            
            Object *ecl11; // [11:11] Bit11 of EICL            
            Object *ecl12; // [12:12] Bit12 of EICL            
            Object *ecl13; // [13:13] Bit13 of EICL            
            Object *ecl14; // [14:14] Bit14 of EICL            
            Object *ecl15; // [15:15] Bit15 of EICL            
            Object *ecl16; // [16:16] Bit16 of EICL            
            Object *ecl17; // [17:17] Bit17 of EICL            
            Object *ecl18; // [18:18] Bit18 of EICL            
            Object *ecl19; // [19:19] Bit19 of EICL            
            Object *ecl20; // [20:20] Bit20 of EICL            
            Object *ecl21; // [21:21] Bit21 of EICL            
            Object *ecl22; // [22:22] Bit22 of EICL            
            Object *ecl23; // [23:23] Bit23 of EICL            
            Object *ecl24; // [24:24] Bit24 of EICL            
            Object *ecl25; // [25:25] Bit25 of EICL            
            Object *ecl26; // [26:26] Bit26 of EICL            
            Object *ecl27; // [27:27] Bit27 of EICL           
            Object *ecl28; // [28:28] Bit28 of EICL           
            Object *ecl29; // [29:29] Bit29 of EICL            
            Object *ecl30; // [30:30] Bit30 of EICL            
            Object *ecl31; // [31:31] Bit31 of EICL          
          } eicl; 

          // ELVR(External Interrupt Level Register) bitfields.
          struct { 
            Object *la0; // [0:0] Bit0 of ELVR            
            Object *lb0; // [1:1] Bit1 of ELVR            
            Object *la1; // [2:2] Bit2 of ELVR            
            Object *lb1; // [3:3] Bit3 of ELVR            
            Object *la2; // [4:4] Bit4 of ELVR            
            Object *lb2; // [5:5] Bit5 of ELVR            
            Object *la3; // [6:6] Bit6 of ELVR            
            Object *lb3; // [7:7] Bit7 of ELVR            
            Object *la4; // [8:8] Bit8 of ELVR           
            Object *lb4; // [9:9] Bit9 of ELVR            
            Object *la5; // [10:10] Bit10 of ELVR            
            Object *lb5; // [11:11] Bit11 of ELVR            
            Object *la6; // [12:12] Bit12 of ELVR            
            Object *lb6; // [13:13] Bit13 of ELVR            
            Object *la7; // [14:14] Bit14 of ELVR            
            Object *lb7; // [15:15] Bit15 of ELVR            
            Object *la8; // [16:16] Bit16 of ELVR            
            Object *lb8; // [17:17] Bit17 of ELVR            
            Object *la9; // [18:18] Bit18 of ELVR            
            Object *lb9; // [19:19] Bit19 of ELVR            
            Object *la10; // [20:20] Bit20 of ELVR           
            Object *lb10; // [21:21] Bit21 of ELVR            
            Object *la11; // [22:22] Bit22 of ELVR            
            Object *lb11; // [23:23] Bit23 of ELVR            
            Object *la12; // [24:24] Bit24 of ELVR            
            Object *lb12; // [25:25] Bit25 of ELVR            
            Object *la13; // [26:26] Bit26 of ELVR            
            Object *lb13; // [27:27] Bit27 of ELVR            
            Object *la14; // [28:28] Bit28 of ELVR            
            Object *lb14; // [29:29] Bit29 of ELVR            
            Object *la15; // [30:30] Bit30 of ELVR            
            Object *lb15; // [31:31] Bit31 of ELVR          
          } elvr; 

          // ELVR1(External Interrupt Level Register 1) bitfields.
          struct { 
            Object *la16; // [0:0] Bit0 of ELVR1            
            Object *lb16; // [1:1] Bit1 of ELVR1            
            Object *la17; // [2:2] Bit2 of ELVR1            
            Object *lb17; // [3:3] Bit3 of ELVR1            
            Object *la18; // [4:4] Bit4 of ELVR1            
            Object *lb18; // [5:5] Bit5 of ELVR1            
            Object *la19; // [6:6] Bit6 of ELVR1            
            Object *lb19; // [7:7] Bit7 of ELVR1            
            Object *la20; // [8:8] Bit8 of ELVR1            
            Object *lb20; // [9:9] Bit9 of ELVR1            
            Object *la21; // [10:10] Bit10 of ELVR1            
            Object *lb21; // [11:11] Bit11 of ELVR1            
            Object *la22; // [12:12] Bit12 of ELVR1            
            Object *lb22; // [13:13] Bit13 of ELVR1            
            Object *la23; // [14:14] Bit14 of ELVR1            
            Object *lb23; // [15:15] Bit15 of ELVR1            
            Object *la24; // [16:16] Bit16 of ELVR1            
            Object *lb24; // [17:17] Bit17 of ELVR1            
            Object *la25; // [18:18] Bit18 of ELVR1            
            Object *lb25; // [19:19] Bit19 of ELVR1            
            Object *la26; // [20:20] Bit20 of ELVR1            
            Object *lb26; // [21:21] Bit21 of ELVR1            
            Object *la27; // [22:22] Bit22 of ELVR1            
            Object *lb27; // [23:23] Bit23 of ELVR1            
            Object *la28; // [24:24] Bit24 of ELVR1            
            Object *lb28; // [25:25] Bit25 of ELVR1            
            Object *la29; // [26:26] Bit26 of ELVR1            
            Object *lb29; // [27:27] Bit27 of ELVR1            
            Object *la30; // [28:28] Bit28 of ELVR1            
            Object *lb30; // [29:29] Bit29 of ELVR1            
            Object *la31; // [30:30] Bit30 of ELVR1            
            Object *lb31; // [31:31] Bit31 of ELVR1          
          } elvr1; 

          // NMIRR(Non Maskable Interrupt Request Register) bitfields.
          struct { 
            Object *nr; // [0:0] NMI interrupt request detection bit          
          } nmirr; 

          // NMICL(Non Maskable Interrupt Clear Register) bitfields.
          struct { 
            Object *ncl; // [0:0] NMI interrupt cause clear bit          
          } nmicl; 
        } fld;
      } e2;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} FM4EXTIState;

// ----------------------------------------------------------------------------

#endif /* FM4_EXTI_H_ */