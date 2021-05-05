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

#ifndef FM4_GPIO_H_
#define FM4_GPIO_H_

#include "qemu/osdep.h"
#include <hw/cortexm/fm4/capabilities.h>
#include <hw/cortexm/peripheral.h>
#include "exec/address-spaces.h"
//#include <hw/cortexm/gpio-lcd.h>
//#include <hw/cortexm/fm4/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_FM4_GPIO DEVICE_PATH_FM4 "GPIO"

// ----------------------------------------------------------------------------

// Note: the "port-index" property has type "int".
typedef enum {
    // TODO: keep this list in ascending order.
    FM4_PORT_GPIO = 0,
    FM4_PORT_GPIO_UNDEFINED = 0xFF,
} fm4_gpio_index_t;

// ----------------------------------------------------------------------------
#define FM4_GPIO_PIN_COUNT    (16)
#define FM4_ADC0_COUNT    (32)

#define FM4_IRQ_GPIO_IDR_IN         "idr-in"
#define FM4_IRQ_GPIO_ODR_OUT        "odr-out"
#define FM4_IRQ_GPIO_EXTI_OUT       "exti-out"

#define TYPE_FM4_GPIO TYPE_FM4_PREFIX "gpio" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_FM4_GPIO_PARENT TYPE_PERIPHERAL
typedef PeripheralClass FM4GPIOParentClass;
typedef PeripheralState FM4GPIOParentState;

static bool TOUCH_XP_;
static bool TOUCH_YP_;
static int count = 0;  // the counter for trasfering 32 bits
static int x, y;
static int unit8_of_unit32 = 0;
static uint16_t  t_x_start, t_y_start, t_x_end, t_y_end;   //unit32
static uint32_t t;
static bool flag_state = false;
static uint8_t pixel_state;
static uint16_t color_;
bool get_TOUCH_X_();
bool get_TOUCH_Y_();
static bool pixel_or_rec = false;
// ----------------------------------------------------------------------------

// Class definitions.
#define FM4_GPIO_GET_CLASS(obj) \
    OBJECT_GET_CLASS(FM4GPIOClass, (obj), TYPE_FM4_GPIO)
#define FM4_GPIO_CLASS(klass) \
    OBJECT_CLASS_CHECK(FM4GPIOClass, (klass), TYPE_FM4_GPIO)

typedef struct {
    // private: 
    FM4GPIOParentClass parent_class;
    // public: 

    // None, so far.
} FM4GPIOClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define FM4_GPIO_STATE(obj) \
    OBJECT_CHECK(FM4GPIOState, (obj), TYPE_FM4_GPIO)

typedef struct {
    // private:
    FM4GPIOParentState parent_obj;
    // public:

    const FM4Capabilities *capabilities;

    // TODO: remove this if the peripheral is always enabled.
    // Points to the bitfield that enables the peripheral.
    Object *enabling_bit;

    // Remove it if there is only one port
    fm4_gpio_index_t port_index;



     // IRQs used to communicate with the machine implementation, for
    // cases like blinking a LED.
    // There is one IRQ for each pin.  Note that for pins configured
    // as inputs, the output IRQ state has no meaning.  Perhaps
    // the output should be updated to match the input in this case...
    qemu_irq odr_irq[FM4_GPIO_PIN_COUNT];

    qemu_irq odr_irq_lcd[FM4_GPIO_PIN_COUNT];


    
    // IRQs used to communicate with EXTI.
    qemu_irq exti_irq[FM4_GPIO_PIN_COUNT];

    // Cached direction mask. 1 = output pin.
    // No more than 16 bits/port.
    uint16_t dir_mask;
    uint16_t dir_mask1;


    union {
      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

      // DO NOT REMOVE FIELDS! Automatically generated!
      // Merge fields from different family members.
      struct {
        // E2GPIO(0) registers.
        struct { 
          Object *pfr0; // 0x0(Port Function Setting Register 0) 
          Object *pfr1; // 0x4(Port Function Setting Register 1) 
          Object *pfr2; // 0x8(Port Function Setting Register 2) 
          Object *pfr3; // 0xC(Port Function Setting Register 3) 
          Object *pfr4; // 0x10(Port Function Setting Register 4) 
          Object *pfr5; // 0x14(Port Function Setting Register 5) 
          Object *pfr6; // 0x18(Port Function Setting Register 6) 
          Object *pfr7; // 0x1C(Port Function Setting Register 7) 
          Object *pfr8; // 0x20(Port Function Setting Register 8) 
          Object *pfr9; // 0x24(32) 
          Object *pfra; // 0x28(32) 
          Object *pfrb; // 0x2C(32) 
          Object *pfrc; // 0x30(32) 
          Object *pfrd; // 0x34(32) 
          Object *pfre; // 0x38(Port Function Setting Register E) 
          Object *pfrf; // 0x3C(32) 
          Object *pcr0; // 0x100(Pull-up Setting Register 0) 
          Object *pcr1; // 0x104(Pull-up Setting Register 1) 
          Object *pcr2; // 0x108(Pull-up Setting Register 2) 
          Object *pcr3; // 0x10C(Pull-up Setting Register 3) 
          Object *pcr4; // 0x110(Pull-up Setting Register 4) 
          Object *pcr5; // 0x114(Pull-up Setting Register 5) 
          Object *pcr6; // 0x118(Pull-up Setting Register 6) 
          Object *pcr7; // 0x11C(Pull-up Setting Register 7) 
          Object *pcr8; // 0x120(Pull-up Setting Register 8) 
          Object *pcr9; // 0x124(Pull-up Setting Register 9) 
          Object *pcra; // 0x128(Pull-up Setting Register A) 
          Object *pcrb; // 0x12C(Pull-up Setting Register B) 
          Object *pcrc; // 0x130(Pull-up Setting Register C) 
          Object *pcrd; // 0x134(Pull-up Setting Register D) 
          Object *pcre; // 0x138(Pull-up Setting Register E) 
          Object *pcrf; // 0x13C(Pull-up Setting Register F) 
          Object *ddr0; // 0x200(Port input/output Direction Setting Register 0) 
          Object *ddr1; // 0x204(Port input/output Direction Setting Register 1) 
          Object *ddr2; // 0x208(Port input/output Direction Setting Register 2) 
          Object *ddr3; // 0x20C(Port input/output Direction Setting Register 3) 
          Object *ddr4; // 0x210(Port input/output Direction Setting Register 4) 
          Object *ddr5; // 0x214(Port input/output Direction Setting Register 5) 
          Object *ddr6; // 0x218(Port input/output Direction Setting Register 6) 
          Object *ddr7; // 0x21C(Port input/output Direction Setting Register 7) 
          Object *ddr8; // 0x220(Port input/output Direction Setting Register 8) 
          Object *ddr9; // 0x224(Port input/output Direction Setting Register 9) 
          Object *ddra; // 0x228(Port input/output Direction Setting Register A) 
          Object *ddrb; // 0x22C(Port input/output Direction Setting Register B) 
          Object *ddrc; // 0x230(Port input/output Direction Setting Register C) 
          Object *ddrd; // 0x234(Port input/output Direction Setting Register D) 
          Object *ddre; // 0x238(Port input/output Direction Setting Register E) 
          Object *ddrf; // 0x23C(Port input/output Direction Setting Register F) 
          Object *pdir0; // 0x300(Port Input Data Register 0) 
          Object *pdir1; // 0x304(Port Input Data Register 1) 
          Object *pdir2; // 0x308(Port Input Data Register 2) 
          Object *pdir3; // 0x30C(Port Input Data Register 3) 
          Object *pdir4; // 0x310(Port Input Data Register 4) 
          Object *pdir5; // 0x314(Port Input Data Register 5) 
          Object *pdir6; // 0x318(Port Input Data Register 6) 
          Object *pdir7; // 0x31C(Port Input Data Register 7) 
          Object *pdir8; // 0x320(Port Input Data Register 8) 
          Object *pdir9; // 0x324(Port Input Data Register 9) 
          Object *pdira; // 0x328(Port Input Data Register A) 
          Object *pdirb; // 0x32C(Port Input Data Register B) 
          Object *pdirc; // 0x330(Port Input Data Register C) 
          Object *pdird; // 0x334(Port Input Data Register D) 
          Object *pdire; // 0x338(Port Input Data Register E) 
          Object *pdirf; // 0x33C(Port Input Data Register F) 
          Object *pdor0; // 0x400(Port Output Data Register 0) 
          Object *pdor1; // 0x404(Port Output Data Register 1) 
          Object *pdor2; // 0x408(Port Output Data Register 2) 
          Object *pdor3; // 0x40C(Port Output Data Register 3) 
          Object *pdor4; // 0x410(Port Output Data Register 4) 
          Object *pdor5; // 0x414(Port Output Data Register 5) 
          Object *pdor6; // 0x418(Port Output Data Register 6) 
          Object *pdor7; // 0x41C(Port Output Data Register 7) 
          Object *pdor8; // 0x420(Port Output Data Register 8) 
          Object *pdor9; // 0x424(Port Output Data Register 9) 
          Object *pdora; // 0x428(Port Output Data Register A) 
          Object *pdorb; // 0x42C(Port Output Data Register B) 
          Object *pdorc; // 0x430(Port Output Data Register C) 
          Object *pdord; // 0x434(Port Output Data Register D) 
          Object *pdore; // 0x438(Port Output Data Register E) 
          Object *pdorf; // 0x43C(Port Output Data Register F) 
          Object *ade; // 0x500(Analog Input Setting Register) 
          Object *spsr; // 0x580(Special Port Setting Register) 
          Object *epfr00; // 0x600(Extended Pin Function Setting Register 00) 
          Object *epfr01; // 0x604(Extended Pin Function Setting Register 01) 
          Object *epfr02; // 0x608(Extended Pin Function Setting Register 02) 
          Object *epfr03; // 0x60C(Extended Pin Function Setting Register 03) 
          Object *epfr04; // 0x610(Extended Pin Function Setting Register 04) 
          Object *epfr05; // 0x614(Extended Pin Function Setting Register 05) 
          Object *epfr06; // 0x618(Extended Pin Function Setting Register 06) 
          Object *epfr07; // 0x61C(Extended Pin Function Setting Register 07) 
          Object *epfr08; // 0x620(Extended Pin Function Setting Register 08) 
          Object *epfr09; // 0x624(Extended Pin Function Setting Register 09) 
          Object *epfr10; // 0x628(Extended Pin Function Setting Register 10) 
          Object *epfr11; // 0x62C(Extended Pin Function Setting Register 11) 
          Object *epfr12; // 0x630(Extended Pin Function Setting Register 12) 
          Object *epfr13; // 0x634(Extended Pin Function Setting Register 13) 
          Object *epfr14; // 0x638(Extended Pin Function Setting Register 14) 
          Object *epfr15; // 0x63C(Extended Pin Function Setting Register 15) 
          Object *epfr16; // 0x640(Extended Pin Function Setting Register 16) 
          Object *epfr17; // 0x644(Extended Pin Function Setting Register 17) 
          Object *epfr18; // 0x648(Extended Pin Function Setting Register 18) 
          Object *epfr19; // 0x64C(Extended Pin Function Setting Register 19) 
          Object *epfr20; // 0x650(Extended Pin Function Setting Register 20) 
          Object *epfr21; // 0x654(Extended Pin Function Setting Register 21) 
          Object *epfr22; // 0x658(Extended Pin Function Setting Register 22) 
          Object *epfr23; // 0x65C(Extended Pin Function Setting Register 23) 
          Object *epfr24; // 0x660(Extended Pin Function Setting Register 24) 
          Object *epfr25; // 0x664(Extended Pin Function Setting Register 25) 
          Object *epfr26; // 0x668(Extended Pin Function Setting Register 26) 
          Object *pzr0; // 0x700(Port Pseudo Open Drain Setting Register 0) 
          Object *pzr1; // 0x704(Port Pseudo Open Drain Setting Register 1) 
          Object *pzr2; // 0x708(Port Pseudo Open Drain Setting Register 2) 
          Object *pzr3; // 0x70C(Port Pseudo Open Drain Setting Register 3) 
          Object *pzr4; // 0x710(Port Pseudo Open Drain Setting Register 4) 
          Object *pzr5; // 0x714(Port Pseudo Open Drain Setting Register 5) 
          Object *pzr6; // 0x718(Port Pseudo Open Drain Setting Register 6) 
          Object *pzr7; // 0x71C(Port Pseudo Open Drain Setting Register 7) 
          Object *pzr8; // 0x720(Port Pseudo Open Drain Setting Register 8) 
          Object *pzr9; // 0x724(Port Pseudo Open Drain Setting Register 9) 
          Object *pzra; // 0x728(Port Pseudo Open Drain Setting Register A) 
          Object *pzrb; // 0x72C(Port Pseudo Open Drain Setting Register B) 
          Object *pzrc; // 0x730(Port Pseudo Open Drain Setting Register C) 
          Object *pzrd; // 0x734(Port Pseudo Open Drain Setting Register D) 
          Object *pzre; // 0x738(Port Pseudo Open Drain Setting Register E) 
          Object *pzrf; // 0x73C(Port Pseudo Open Drain Setting Register F) 
          Object *pdsr0; // 0x740(/dr) 
          Object *pdsr1; // 0x744(/dr) 
          Object *pdsr2; // 0x748(/dr) 
          Object *pdsr3; // 0x74C(/dr) 
          Object *pdsr4; // 0x750(/dr) 
          Object *pdsr5; // 0x754(/dr) 
          Object *pdsr6; // 0x758(/dr) 
          Object *pdsr7; // 0x75C(/dr) 
          Object *pdsr8; // 0x760(/dr) 
          Object *pdsr9; // 0x764(/dr) 
          Object *pdsra; // 0x768(/dr) 
          Object *pdsrb; // 0x76C(/dr) 
          Object *pdsrc; // 0x770(/dr) 
          Object *pdsrd; // 0x774(/dr) 
          Object *pdsre; // 0x778(/dr) 
          Object *pdsrf; // 0x77C(/dr) 
        } reg;

        struct { 

          // PFR0(Port Function Setting Register 0) bitfields.
          struct { 
            Object *p00; // [0:0] Bit0 of PFR0 
            Object *p01; // [1:1] Bit1 of PFR0            
            Object *p02; // [2:2] Bit2 of PFR0            
            Object *p03; // [3:3] Bit3 of PFR0            
            Object *p04; // [4:4] Bit4 of PFR0            
            Object *p08; // [8:8] Bit8 of PFR0            
            Object *p09; // [9:9] Bit9 of PFR0            
            Object *p0a; // [10:10] Bit10 of PFR0          
          } pfr0; 
           
          // PFR1(Port Function Setting Register 1) bitfields.
          struct { 
            Object *p10; // [0:0] Bit0 of PFR1            
            Object *p11; // [1:1] Bit1 of PFR1            
            Object *p12; // [2:2] Bit2 of PFR1            
            Object *p13; // [3:3] Bit3 of PFR1            
            Object *p14; // [4:4] Bit4 of PFR1            
            Object *p15; // [5:5] Bit5 of PFR1            
            Object *p16; // [6:6] Bit6 of PFR1            
            Object *p17; // [7:7] Bit7 of PFR1            
            Object *p18; // [8:8] Bit8 of PFR1            
            Object *p19; // [9:9] Bit9 of PFR1            
            Object *p1a; // [10:10] Bit10 of PFR1            
            Object *p1b; // [11:11] Bit11 of PFR1            
            Object *p1c; // [12:12] Bit12 of PFR1            
            Object *p1d; // [13:13] Bit13 of PFR1            
            Object *p1e; // [14:14] Bit14 of PFR1            
            Object *p1f; // [15:15] Bit15 of PFR1          
          } pfr1; 

          // PFR2(Port Function Setting Register 2) bitfields.
          struct { 
            Object *p20; // [0:0] Bit0 of PFR2            
            Object *p21; // [1:1] Bit1 of PFR2            
            Object *p22; // [2:2] Bit2 of PFR2            
            Object *p23; // [3:3] Bit3 of PFR2            
            Object *p24; // [4:4] Bit4 of PFR2            
            Object *p25; // [5:5] Bit5 of PFR2            
            Object *p26; // [6:6] Bit6 of PFR2            
            Object *p27; // [7:7] Bit7 of PFR2            
            Object *p28; // [8:8] Bit8 of PFR2            
            Object *p29; // [9:9] Bit9 of PFR2            
            Object *p2a; // [10:10] Bit10 of PFR2          
          } pfr2; 

          // PFR3(Port Function Setting Register 3) bitfields.
          struct { 
            Object *p30; // [0:0] Bit0 of PFR3            
            Object *p31; // [1:1] Bit1 of PFR3            
            Object *p32; // [2:2] Bit2 of PFR3            
            Object *p33; // [3:3] Bit3 of PFR3            
            Object *p34; // [4:4] Bit4 of PFR3            
            Object *p35; // [5:5] Bit5 of PFR3            
            Object *p36; // [6:6] Bit6 of PFR3            
            Object *p37; // [7:7] Bit7 of PFR3            
            Object *p38; // [8:8] Bit8 of PFR3            
            Object *p39; // [9:9] Bit9 of PFR3            
            Object *p3a; // [10:10] Bit10 of PFR3            
            Object *p3b; // [11:11] Bit11 of PFR3            
            Object *p3c; // [12:12] Bit12 of PFR3            
            Object *p3d; // [13:13] Bit13 of PFR3            
            Object *p3e; // [14:14] Bit14 of PFR3          
          } pfr3; 

          // PFR4(Port Function Setting Register 4) bitfields.
          struct { 
            Object *p40; // [0:0] Bit0 of PFR4            
            Object *p41; // [1:1] Bit1 of PFR4            
            Object *p42; // [2:2] Bit2 of PFR4            
            Object *p43; // [3:3] Bit3 of PFR4            
            Object *p44; // [4:4] Bit4 of PFR4            
            Object *p45; // [5:5] Bit5 of PFR4            
            Object *p46; // [6:6] Bit6 of PFR4            
            Object *p47; // [7:7] Bit7 of PFR4            
            Object *p48; // [8:8] Bit8 of PFR4            
            Object *p49; // [9:9] Bit9 of PFR4            
            Object *p4a; // [10:10] Bit10 of PFR4            
            Object *p4b; // [11:11] Bit11 of PFR4            
            Object *p4c; // [12:12] Bit12 of PFR4            
            Object *p4d; // [13:13] Bit13 of PFR4            
            Object *p4e; // [14:14] Bit14 of PFR4          
          } pfr4; 

          // PFR5(Port Function Setting Register 5) bitfields.
          struct { 
            Object *p50; // [0:0] Bit0 of PFR5            
            Object *p51; // [1:1] Bit1 of PFR5            
            Object *p52; // [2:2] Bit2 of PFR5            
            Object *p53; // [3:3] Bit3 of PFR5            
            Object *p54; // [4:4] Bit4 of PFR5            
            Object *p55; // [5:5] Bit5 of PFR5            
            Object *p56; // [6:6] Bit6 of PFR5            
            Object *p57; // [7:7] Bit7 of PFR5            
            Object *p58; // [8:8] Bit8 of PFR5            
            Object *p59; // [9:9] Bit9 of PFR5            
            Object *p5a; // [10:10] Bit10 of PFR5            
            Object *p5b; // [11:11] Bit11 of PFR5            
            Object *p5c; // [12:12] Bit12 of PFR5            
            Object *p5d; // [13:13] Bit13 of PFR5            
            Object *p5e; // [14:14] Bit14 of PFR5            
            Object *p5f; // [15:15] Bit15 of PFR5          
          } pfr5; 

          // PFR6(Port Function Setting Register 6) bitfields.
          struct { 
            Object *p60; // [0:0] Bit0 of PFR6            
            Object *p61; // [1:1] Bit1 of PFR6            
            Object *p62; // [2:2] Bit2 of PFR6            
            Object *p63; // [3:3] Bit3 of PFR6            
            Object *p64; // [4:4] Bit4 of PFR6            
            Object *p65; // [5:5] Bit5 of PFR6            
            Object *p66; // [6:6] Bit6 of PFR6            
            Object *p67; // [7:7] Bit7 of PFR6           
            Object *p68; // [8:8] Bit8 of PFR6            
            Object *p69; // [9:9] Bit9 of PFR6            
            Object *p6a; // [10:10] Bit10 of PFR6            
            Object *p6b; // [11:11] Bit11 of PFR6            
            Object *p6c; // [12:12] Bit12 of PFR6            
            Object *p6d; // [13:13] Bit13 of PFR6            
            Object *p6e; // [14:14] Bit14 of PFR6          
          } pfr6; 

          // PFR7(Port Function Setting Register 7) bitfields.
          struct { 
            Object *p70; // [0:0] Bit0 of PFR7            
            Object *p71; // [1:1] Bit1 of PFR7            
            Object *p72; // [2:2] Bit2 of PFR7            
            Object *p73; // [3:3] Bit3 of PFR7           
            Object *p74; // [4:4] Bit4 of PFR7           
            Object *p75; // [5:5] Bit5 of PFR7           
            Object *p76; // [6:6] Bit6 of PFR7          
            Object *p77; // [7:7] Bit7 of PFR7        
            Object *p78; // [8:8] Bit8 of PFR7      
            Object *p79; // [9:9] Bit9 of PFR7       
            Object *p7a; // [10:10] Bit10 of PFR7    
            Object *p7b; // [11:11] Bit11 of PFR7
            Object *p7c; // [12:12] Bit12 of PFR7          
            Object *p7d; // [13:13] Bit13 of PFR7          
            Object *p7e; // [14:14] Bit14 of PFR7         
            } pfr7; 

          // PFR8(Port Function Setting Register 8) bitfields.
          struct { 
            Object *p80; // [0:0] Bit0 of PFR8            
            Object *p81; // [1:1] Bit1 of PFR8            
            Object *p82; // [2:2] Bit2 of PFR8            
            Object *p83; // [3:3] Bit3 of PFR8          
          } pfr8; 

          // PFR9(32) bitfields.
          struct { 
            Object *p90; // [0:0] Bit0 of PFR9            
            Object *p91; // [1:1] Bit1 of PFR9            
            Object *p92; // [2:2] Bit2 of PFR9           
            Object *p93; // [3:3] Bit3 of PFR9          
            Object *p94; // [4:4] Bit4 of PFR9         
            Object *p95; // [5:5] Bit5 of PFR9      
            Object *p96; // [6:6] Bit6 of PFR9  
            Object *p97; // [7:7] Bit7 of PFR9       
          } pfr9; 

          // PFRA(32) bitfields.
          struct { 
            Object *pa0; // [0:0] Bit0 of PFRA            
            Object *pa1; // [1:1] Bit1 of PFRA            
            Object *pa2; // [2:2] Bit2 of PFRA            
            Object *pa3; // [3:3] Bit3 of PFRA            
            Object *pa4; // [4:4] Bit4 of PFRA            
            Object *pa5; // [5:5] Bit5 of PFRA            
            Object *pa6; // [6:6] Bit6 of PFRA            
            Object *pa7; // [7:7] Bit7 of PFRA            
            Object *pa8; // [8:8] Bit8 of PFRA            
            Object *pa9; // [9:9] Bit9 of PFRA            
            Object *paa; // [10:10] Bit10 of PFRA           
            Object *pab; // [11:11] Bit11 of PFRA            
            Object *pac; // [12:12] Bit12 of PFRA            
            Object *pad; // [13:13] Bit13 of PFRA            
            Object *pae; // [14:14] Bit14 of PFRA            
            Object *paf; // [15:15] Bit15 of PFRA          
          } pfra; 

          // PFRB(32) bitfields.
          struct { 
            Object *pb0; // [0:0] Bit0 of PFRB            
            Object *pb1; // [1:1] Bit1 of PFRB            
            Object *pb2; // [2:2] Bit2 of PFRB            
            Object *pb3; // [3:3] Bit3 of PFRB            
            Object *pb4; // [4:4] Bit4 of PFRB            
            Object *pb5; // [5:5] Bit5 of PFRB            
            Object *pb6; // [6:6] Bit6 of PFRB            
            Object *pb7; // [7:7] Bit7 of PFRB            
            Object *pb8; // [8:8] Bit8 of PFRB            
            Object *pb9; // [9:9] Bit9 of PFRB            
            Object *pba; // [10:10] Bit10 of PFRB            
            Object *pbb; // [11:11] Bit11 of PFRB            
            Object *pbc; // [12:12] Bit12 of PFRB            
            Object *pbd; // [13:13] Bit13 of PFRB            
            Object *pbe; // [14:14] Bit14 of PFRB            
            Object *pbf; // [15:15] Bit15 of PFRB          
          } pfrb; 

          // PFRC(32) bitfields.
          struct { 
            Object *pc0; // [0:0] Bit0 of PFRC            
            Object *pc1; // [1:1] Bit1 of PFRC            
            Object *pc2; // [2:2] Bit2 of PFRC            
            Object *pc3; // [3:3] Bit3 of PFRC            
            Object *pc4; // [4:4] Bit4 of PFRC            
            Object *pc5; // [5:5] Bit5 of PFRC           
            Object *pc6; // [6:6] Bit6 of PFRC            
            Object *pc7; // [7:7] Bit7 of PFRC            
            Object *pc8; // [8:8] Bit8 of PFRC            
            Object *pc9; // [9:9] Bit9 of PFRC            
            Object *pca; // [10:10] Bit10 of PFRC            
            Object *pcb; // [11:11] Bit11 of PFRC            
            Object *pcc; // [12:12] Bit12 of PFRC            
            Object *pcd; // [13:13] Bit13 of PFRC            
            Object *pce; // [14:14] Bit14 of PFRC            
            Object *pcf; // [15:15] Bit15 of PFRC          
          } pfrc; 

          // PFRD(32) bitfields.
          struct { 
            Object *pd0; // [0:0] Bit0 of PFRD            
            Object *pd1; // [1:1] Bit1 of PFRD            
            Object *pd2; // [2:2] Bit2 of PFRD          
          } pfrd; 

          // PFRE(Port Function Setting Register E) bitfields.
          struct { 
            Object *pe0; // [0:0] Bit0 of PFRE            
            Object *pe2; // [2:2] Bit2 of PFRE            
            Object *pe3; // [3:3] Bit3 of PFRE          
          } pfre; 

          // PFRF(32) bitfields.
          struct { 
            Object *pf0; // [0:0] Bit0 of PFRF            
            Object *pf1; // [1:1] Bit1 of PFRF           
            Object *pf2; // [2:2] Bit2 of PFRF            
            Object *pf3; // [3:3] Bit3 of PFRF            
            Object *pf4; // [4:4] Bit4 of PFRF            
            Object *pf5; // [5:5] Bit5 of PFRF            
            Object *pf6; // [6:6] Bit6 of PFRF            
            Object *pf7; // [7:7] Bit7 of PFRF            
            Object *pf8; // [8:8] Bit8 of PFRF            
            Object *pf9; // [9:9] Bit9 of PFRF            
            Object *pfa; // [10:10] Bit10 of PFRF            
            Object *pfb; // [11:11] Bit11 of PFRF           
            Object *pfc; // [12:12] Bit12 of PFRF         
           } pfrf; 

          // PCR0(Pull-up Setting Register 0) bitfields.
          struct { 
          } pcr0; 

          // PCR1(Pull-up Setting Register 1) bitfields.
          struct { 
          } pcr1; 

          // PCR2(Pull-up Setting Register 2) bitfields.
          struct { 
          } pcr2; 

          // PCR3(Pull-up Setting Register 3) bitfields.
          struct { 
          } pcr3; 

          // PCR4(Pull-up Setting Register 4) bitfields.
          struct { 
          } pcr4; 

          // PCR5(Pull-up Setting Register 5) bitfields.
          struct { 
          } pcr5; 

          // PCR6(Pull-up Setting Register 6) bitfields.
          struct { 
          } pcr6; 

          // PCR7(Pull-up Setting Register 7) bitfields.
          struct { 
          } pcr7; 

          // PCR8(Pull-up Setting Register 8) bitfields.
          struct { 
          } pcr8; 

          // PCR9(Pull-up Setting Register 9) bitfields.
          struct { 
          } pcr9; 

          // PCRA(Pull-up Setting Register A) bitfields.
          struct { 
          } pcra; 

          // PCRB(Pull-up Setting Register B) bitfields.
          struct { 
          } pcrb; 

          // PCRC(Pull-up Setting Register C) bitfields.
          struct { 
          } pcrc; 

          // PCRD(Pull-up Setting Register D) bitfields.
          struct { 
          } pcrd; 

          // PCRE(Pull-up Setting Register E) bitfields.
          struct { 
          } pcre; 

          // PCRF(Pull-up Setting Register F) bitfields.
          struct { 
          } pcrf; 

          // DDR0(Port input/output Direction Setting Register 0) bitfields.
          struct { 
            Object *p00; // [0:0] Bit0 of DDR0            
            Object *p01; // [1:1] Bit1 of DDR0            
            Object *p02; // [2:2] Bit2 of DDR0            
            Object *p03; // [3:3] Bit3 of DDR0            
            Object *p04; // [4:4] Bit4 of DDR0            
            Object *p05; // [5:5] Bit5 of DDR0            
            Object *p06; // [6:6] Bit6 of DDR0           
            Object *p07; // [7:7] Bit7 of DDR0            
            Object *p08; // [8:8] Bit8 of DDR0            
            Object *p09; // [9:9] Bit9 of DDR0            
            Object *p0a; // [10:10] Bit10 of DDR0            
            Object *p0b; // [11:11] Bit11 of DDR0           
            Object *p0c; // [12:12] Bit12 of DDR0            
            Object *p0d; // [13:13] Bit13 of DDR0            
            Object *p0e; // [14:14] Bit14 of DDR0          
            } ddr0; 

          // DDR1(Port input/output Direction Setting Register 1) bitfields.
          struct { 
          } ddr1; 

          // DDR2(Port input/output Direction Setting Register 2) bitfields.
          struct { 
          } ddr2; 

          // DDR3(Port input/output Direction Setting Register 3) bitfields.
          struct { 
          } ddr3; 

          // DDR4(Port input/output Direction Setting Register 4) bitfields.
          struct { 
          } ddr4; 

          // DDR5(Port input/output Direction Setting Register 5) bitfields.
          struct { 
          } ddr5; 

          // DDR6(Port input/output Direction Setting Register 6) bitfields.
          struct { 
          } ddr6; 

          // DDR7(Port input/output Direction Setting Register 7) bitfields.
          struct { 
          } ddr7; 

          // DDR8(Port input/output Direction Setting Register 8) bitfields.
          struct { 
          } ddr8; 

          // DDR9(Port input/output Direction Setting Register 9) bitfields.
          struct { 
          } ddr9; 

          // DDRA(Port input/output Direction Setting Register A) bitfields.
          struct { 
          } ddra; 

          // DDRB(Port input/output Direction Setting Register B) bitfields.
          struct { 
          } ddrb; 

          // DDRC(Port input/output Direction Setting Register C) bitfields.
          struct { 
          } ddrc; 

          // DDRD(Port input/output Direction Setting Register D) bitfields.
          struct { 
          } ddrd; 

          // DDRE(Port input/output Direction Setting Register E) bitfields.
          struct { 
          } ddre; 

          // DDRF(Port input/output Direction Setting Register F) bitfields.
          struct { 
          } ddrf; 

          // PDIR0(Port Input Data Register 0) bitfields.
          struct { 
            Object *p00; // [0:0] Bit0 of DDR0            
            Object *p01; // [1:1] Bit1 of DDR0            
            Object *p02; // [2:2] Bit2 of DDR0            
            Object *p03; // [3:3] Bit3 of DDR0            
            Object *p04; // [4:4] Bit4 of DDR0            
            Object *p05; // [5:5] Bit5 of DDR0            
            Object *p06; // [6:6] Bit6 of DDR0           
            Object *p07; // [7:7] Bit7 of DDR0            
            Object *p08; // [8:8] Bit8 of DDR0            
            Object *p09; // [9:9] Bit9 of DDR0            
            Object *p0a; // [10:10] Bit10 of DDR0            
            Object *p0b; // [11:11] Bit11 of DDR0           
            Object *p0c; // [12:12] Bit12 of DDR0            
            Object *p0d; // [13:13] Bit13 of DDR0            
            Object *p0e; // [14:14] Bit14 of DDR0   
          } pdir0; 

          // PDIR1(Port Input Data Register 1) bitfields.
          struct { 
            Object *p10; // [0:0] Bit0 of DDR0            
            Object *p11; // [1:1] Bit1 of DDR0            
            Object *p12; // [2:2] Bit2 of DDR0            
            Object *p13; // [3:3] Bit3 of DDR0            
            Object *p14; // [4:4] Bit4 of DDR0            
            Object *p15; // [5:5] Bit5 of DDR0            
            Object *p16; // [6:6] Bit6 of DDR0           
            Object *p17; // [7:7] Bit7 of DDR0            
            Object *p18; // [8:8] Bit8 of DDR0            
            Object *p19; // [9:9] Bit9 of DDR0            
            Object *p1a; // [10:10] Bit10 of DDR0            
            Object *p1b; // [11:11] Bit11 of DDR0           
            Object *p1c; // [12:12] Bit12 of DDR0            
            Object *p1d; // [13:13] Bit13 of DDR0            
            Object *p1e; // [14:14] Bit14 of DDR0   
          } pdir1; 

          // PDIR2(Port Input Data Register 2) bitfields.
          struct { 
          } pdir2; 

          // PDIR3(Port Input Data Register 3) bitfields.
          struct { 
          } pdir3; 

          // PDIR4(Port Input Data Register 4) bitfields.
          struct { 
          } pdir4; 

          // PDIR5(Port Input Data Register 5) bitfields.
          struct { 
          } pdir5; 

          // PDIR6(Port Input Data Register 6) bitfields.
          struct { 
          } pdir6; 

          // PDIR7(Port Input Data Register 7) bitfields.
          struct { 
          } pdir7; 

          // PDIR8(Port Input Data Register 8) bitfields.
          struct { 
          } pdir8; 

          // PDIR9(Port Input Data Register 9) bitfields.
          struct { 
          } pdir9; 

          // PDIRA(Port Input Data Register A) bitfields.
          struct { 
          } pdira; 

          // PDIRB(Port Input Data Register B) bitfields.
          struct { 
          } pdirb; 

          // PDIRC(Port Input Data Register C) bitfields.
          struct { 
          } pdirc; 

          // PDIRD(Port Input Data Register D) bitfields.
          struct { 
          } pdird; 

          // PDIRE(Port Input Data Register E) bitfields.
          struct { 
          } pdire; 

          // PDIRF(Port Input Data Register F) bitfields.
          struct { 
          } pdirf; 

          // PDOR0(Port Output Data Register 0) bitfields.
          struct { 
            Object *p00;          
            Object *p01;        
            Object *p02; 
            Object *p03;     
            Object *p04;   
            Object *p05;          
            Object *p06;     
            Object *p07;      
            Object *p08;       
            Object *p09;     
            Object *p0a;       
          } pdor0; 

          // PDOR1(Port Output Data Register 1) bitfields.
          struct { 
            Object *p10;       
            Object *p11;            
            Object *p12;        
            Object *p13;        
            Object *p14;            
            Object *p15; 
            Object *p16;      
            Object *p17; 
            Object *p18; 
            Object *p19;            
            Object *p1a; 
            Object *p1b;           
            Object *p1c;    
            Object *p1d;             
            Object *p1e; 
            Object *p1f; 
          } pdor1; 

          // PDOR2(Port Output Data Register 2) bitfields.
          struct { 
            Object *p20;        
            Object *p21;     
            Object *p22;            
            Object *p23;          
            Object *p24;           
            Object *p25;       
            Object *p26;            
            Object *p27;       
            Object *p28;       
            Object *p29;  
            Object *p2a; 
          } pdor2; 

          // PDOR3(Port Output Data Register 3) bitfields.
          struct { 
          } pdor3; 

          // PDOR4(Port Output Data Register 4) bitfields.
          struct { 
          } pdor4; 

          // PDOR5(Port Output Data Register 5) bitfields.
          struct { 
          } pdor5; 

          // PDOR6(Port Output Data Register 6) bitfields.
          struct { 
          } pdor6; 

          // PDOR7(Port Output Data Register 7) bitfields.
          struct { 
          } pdor7; 

          // PDOR8(Port Output Data Register 8) bitfields.
          struct { 
          } pdor8; 

          // PDOR9(Port Output Data Register 9) bitfields.
          struct { 
          } pdor9; 

          // PDORA(Port Output Data Register A) bitfields.
          struct { 
          } pdora; 

          // PDORB(Port Output Data Register B) bitfields.
          struct { 
          } pdorb; 

          // PDORC(Port Output Data Register C) bitfields.
          struct { 
          } pdorc; 

          // PDORD(Port Output Data Register D) bitfields.
          struct { 
          } pdord; 

          // PDORE(Port Output Data Register E) bitfields.
          struct { 
          } pdore; 

          // PDORF(Port Output Data Register F) bitfields.
          struct { 
          } pdorf; 

          // ADE(Analog Input Setting Register) bitfields.
          struct { 
            Object *an00; // [0:0] Bit0 of ADE            
            Object *an01; // [1:1] Bit1 of ADE            
            Object *an02; // [2:2] Bit2 of ADE           
            Object *an03; // [3:3] Bit3 of ADE            
            Object *an04; // [4:4] Bit4 of ADE            
            Object *an05; // [5:5] Bit5 of ADE            
            Object *an06; // [6:6] Bit6 of ADE            
            Object *an07; // [7:7] Bit7 of ADE            
            Object *an08; // [8:8] Bit8 of ADE            
            Object *an09; // [9:9] Bit9 of ADE            
            Object *an10; // [10:10] Bit10 of ADE           
            Object *an11; // [11:11] Bit11 of ADE            
            Object *an12; // [12:12] Bit12 of ADE            
            Object *an13; // [13:13] Bit13 of ADE            
            Object *an14; // [14:14] Bit14 of ADE            
            Object *an15; // [15:15] Bit15 of ADE            
            Object *an16; // [16:16] Bit16 of ADE            
            Object *an17; // [17:17] Bit17 of ADE            
            Object *an18; // [18:18] Bit18 of ADE            
            Object *an19; // [19:19] Bit19 of ADE            
            Object *an20; // [20:20] Bit20 of ADE            
            Object *an21; // [21:21] Bit21 of ADE            
            Object *an22; // [22:22] Bit22 of ADE           
            Object *an23; // [23:23] Bit23 of ADE            
            Object *an24; // [24:24] Bit24 of ADE            
            Object *an25; // [25:25] Bit25 of ADE            
            Object *an26; // [26:26] Bit26 of ADE            
            Object *an27; // [27:27] Bit27 of ADE            
            Object *an28; // [28:28] Bit28 of ADE            
            Object *an29; // [29:29] Bit29 of ADE            
            Object *an30; // [30:30] Bit30 of ADE            
            Object *an31; // [31:31] Bit31 of ADE          
          } ade; 

          // SPSR(Special Port Setting Register) bitfields.
          struct { 
            Object *mainxc; // [2:3] Main Clock (Oscillation) Pin Setting bits            
            Object *usb0c; // [4:4] USB (ch.0) Pin Setting bit            
            Object *usb1c; // [5:5] USB (ch.1) Pin Setting bit          
          } spsr; 

          // EPFR00(Extended Pin Function Setting Register 00) bitfields.
          struct { 
            Object *nmis; // [0:0] NMIX Function Select bit            
            Object *croute; // [1:2] Internal high-speed CR Oscillation Output Function Select bit            
            Object *rtccoe; // [4:5] RTC clock output select bit            
            Object *suboute; // [6:7] Sub clock divide output function select bit            
            Object *usbp0e; // [9:9] USB ch.0 Function Select bit 1            
            Object *usbp1e; // [13:13] USB ch.1 Function Select bit 1            
            Object *jtagen0b; // [16:16] JTAG Function Select bit 0           
            Object *jtagen1s; // [17:17] JTAG Function Select bit 1           
            Object *trc0e; // [24:24] TRACED Function Select bit 0            
            Object *trc1e; // [25:25] TRACED Function Select bit 1            
            Object *trc2e; // [26:26] TRACED Function Select bit 2            
            Object *trc3e; // [27:27] TRACED Function Select bit 3          
          } epfr00; 

          // EPFR01(Extended Pin Function Setting Register 01) bitfields.
          struct { 
            Object *rto00e; // [0:1] RTO00 Output Select bits           
            Object *rto01e; // [2:3] RTO01 Output Select bits            
            Object *rto02e; // [4:5] RTO02 Output Select bits            
            Object *rto03e; // [6:7] RTO03 Output Select bits            
            Object *rto04e; // [8:9] RTO04 Output Select bits            
            Object *rto05e; // [10:11] RTO05 Output Select bits            
            Object *dtti0c; // [12:12] DTTIX0 Function Select bit           
            Object *dtti0s; // [16:17] DTTIX0 Input Select bits            
            Object *frck0s; // [18:19] FRCK0 Input Select bits            
            Object *ic00s; // [20:22] IC00 Input Select bits            
            Object *ic01s; // [23:25] IC01 Input Select bits            
            Object *ic02s; // [26:28] IC02 Input Select bits            
            Object *ic03s; // [29:31] IC03 Input Select bits          
          } epfr01; 

          // EPFR02(Extended Pin Function Setting Register 02) bitfields.
          struct { 
            Object *rto10e; // [0:1] RTO10 Output Select bits            
            Object *rto11e; // [2:3] RTO11 Output Select bits            
            Object *rto12e; // [4:5] RTO12 Output Select bits            
            Object *rto13e; // [6:7] RTO13 Output Select bits            
            Object *rto14e; // [8:9] RTO14 Output Select bits            
            Object *rto15e; // [10:11] RTO15 Output Select bits            
            Object *dtti1c; // [12:12] DTTIX1 Function Select bit           
            Object *dtti1s; // [16:17] DTTIX1 Input Select bits            
            Object *frck1s; // [18:19] FRCK1 Input Select bits            
            Object *ic10s; // [20:22] IC13 Input Select bits            
            Object *ic11s; // [23:25] IC13 Input Select bits            
            Object *ic12s; // [26:28] IC13 Input Select bits            
            Object *ic13s; // [29:31] IC13 Input Select bits          
          } epfr02; 

          // EPFR03(Extended Pin Function Setting Register 03) bitfields.
          struct { 
            Object *rto20e; // [0:1] RTO20 Output Select bits            
            Object *rto21e; // [2:3] RTO21 Output Select bits            
            Object *rto22e; // [4:5] RTO22 Output Select bits            
            Object *rto23e; // [6:7] RTO23 Output Select bits            
            Object *rto24e; // [8:9] RTO24 Output Select bits            
            Object *rto25e; // [10:11] RTO25 Output Select bits            
            Object *dtti2c; // [12:12] DTTIX2 Function Select bit            
            Object *dtti2s; // [16:17] DTTIX2 Input Select bits            
            Object *frck2s; // [18:19] FRCK2 Input Select bits            
            Object *ic20s; // [20:22] IC23 Input Select bits            
            Object *ic21s; // [23:25] IC23 Input Select bits            
            Object *ic22s; // [26:28] IC23 Input Select bits            
            Object *ic23s; // [29:31] IC23 Input Select bits          
          } epfr03; 

          // EPFR04(Extended Pin Function Setting Register 04) bitfields.
          struct { 
            Object *tioa0e; // [2:3] TIOA0 Output Select bits            
            Object *tiob0s; // [4:6] TIOB0 Input Select bits            
            Object *tioa1s; // [8:9] TIOA1 Input Select bits            
            Object *tioa1e; // [10:11] TIOA1 Output Select bits            
            Object *tiob1s; // [12:13] TIOB1 Input Select bits            
            Object *tioa2e; // [18:19] TIOA2 Output Select bits            
            Object *tiob2s; // [20:21] TIOB2 Input Select bits           
            Object *tioa3s; // [24:25] TIOA3 Input Select bits            
            Object *tioa3e; // [26:27] TIOA3 Output Select bits            
            Object *tiob3s; // [28:29] TIOB3 Input Select bits          
          } epfr04; 

          // EPFR05(Extended Pin Function Setting Register 05) bitfields.
          struct { 
            Object *tioa4e; // [2:3] TIOA4 Output Select bits            
            Object *tiob4s; // [4:5] TIOB4 Input Select bits            
            Object *tioa5s; // [8:9] TIOA5 Input Select bits            
            Object *tioa5e; // [10:11] TIOA5 Output Select bits            
            Object *tiob5s; // [12:13] TIOB5 Input Select bits            
            Object *tioa6e; // [18:19] TIOA6 Output Select bits            
            Object *tiob6s; // [20:21] TIOB6 Input Select bits           
            Object *tioa7s; // [24:25] TIOA7 Input Select bits            
            Object *tioa7e; // [26:27] TIOA7 Output Select bits           
            Object *tiob7s; // [28:29] TIOB7 Input Select bits          
          } epfr05; 

          // EPFR06(Extended Pin Function Setting Register 06) bitfields.
          struct { 
            Object *eint00s; // [0:1] External Interrupt 00 Input Select bits            
            Object *eint01s; // [2:3] External Interrupt 01 Input Select bits            
            Object *eint02s; // [4:5] External Interrupt 02 Input Select bits            
            Object *eint03s; // [6:7] External Interrupt 03 Input Select bits           
            Object *eint04s; // [8:9] External Interrupt 04 Input Select bits            
            Object *eint05s; // [10:11] External Interrupt 05 Input Select bits            
            Object *eint06s; // [12:13] External Interrupt 06 Input Select bits            
            Object *eint07s; // [14:15] External Interrupt 07 Input Select bits            
            Object *eint08s; // [16:17] External Interrupt 08 Input Select bits            
            Object *eint09s; // [18:19] External Interrupt 09 Input Select bits            
            Object *eint10s; // [20:21] External Interrupt 10 Input Select bits            
            Object *eint11s; // [22:23] External Interrupt 11 Input Select bits            
            Object *eint12s; // [24:25] External Interrupt 12 Input Select bits            
            Object *eint13s; // [26:27] External Interrupt 13 Input Select bits            
            Object *eint14s; // [28:29] External Interrupt 14 Input Select bits            
            Object *eint15s; // [30:31] External Interrupt 15 Input Select bits          
          } epfr06; 

          // EPFR07(Extended Pin Function Setting Register 07) bitfields.
          struct { 
            Object *sin0s; // [4:5] SIN0 Input Select bits            
            Object *sot0b; // [6:7] SOT0 Input/Output Select bits            
            Object *sck0b; // [8:9] SCK0 Input/Output Select bits            
            Object *sin1s; // [10:11] SIN1 Input Select bits            
            Object *sot1b; // [12:13] SOT1 Input/Output Select bits            
            Object *sck1b; // [14:15] SCK1 Input/Output Select bits            
            Object *sin2s; // [16:17] SIN2 Input Select bits            
            Object *sot2b; // [18:19] SOT2 Input/Output Select bits            
            Object *sck2b; // [20:21] SCK2 Input/Output Select bits            
            Object *sin3s; // [22:23] SIN3 Input Select bits            
            Object *sot3b; // [24:25] SOT3 Input/Output Select bits            
            Object *sck3b; // [26:27] SCK3 Input/Output Select bits          
          } epfr07; 

          // EPFR08(Extended Pin Function Setting Register 08) bitfields.
          struct { 
            Object *rts4e; // [0:1] RTS4 Input/Output Select bits            
            Object *cts4s; // [2:3] CTS4 Input/Output Select bits            
            Object *sin4s; // [4:5] SIN4 Input Select bits            
            Object *sot4b; // [6:7] SOT4 Input/Output Select bits            
            Object *sck4b; // [8:9] SCK4 Input/Output Select bits            
            Object *sin5s; // [10:11] SIN5 Input Select bits            
            Object *sot5b; // [12:13] SOT5 Input/Output Select bits           
            Object *sck5b; // [14:15] SCK5 Input/Output Select bits            
            Object *sin6s; // [16:17] SIN6 Input Select bits            
            Object *sot6b; // [18:19] SOT6 Input/Output Select bits            
            Object *sck6b; // [20:21] SCK6 Input/Output Select bits            
            Object *sin7s; // [22:23] SIN7 Input Select bits            
            Object *sot7b; // [24:25] SOT7 Input/Output Select bits            
            Object *sck7b; // [26:27] SCK7 Input/Output Select bits            
            Object *rts5e; // [28:29] RTS5 Input/Output Select bits            
            Object *cts5s; // [30:31] CTS5 Input/Output Select bits          
          } epfr08; 

          // EPFR09(Extended Pin Function Setting Register 09) bitfields.
          struct { 
            Object *qain0s; // [0:1] QAIN0S Input Select bits$            
            Object *qbin0s; // [2:3] QBIN0S Input Select bits            
            Object *qzin0s; // [4:5] QZIN0S Input Select bits            
            Object *qain1s; // [6:7] QAIN1S Input Select bits            
            Object *qbin1s; // [8:9] QBIN1S Input Select bits            
            Object *qzin1s; // [10:11] QZIN1S Input Select bits            
            Object *adtrg0s; // [12:15] ADTRG0 Input Select bits            
            Object *adtrg1s; // [16:19] ADTRG1 Input Select bits            
            Object *adtrg2s; // [20:23] ADTRG2 Input Select bits            
            Object *crx0s; // [24:25] CRX0S Input Select bits            
            Object *ctx0e; // [26:27] CTX0E Output Select bits            
            Object *crx1s; // [28:29] CRX1S Input Select bits            
            Object *ctx1e; // [30:31] CTX1E Output Select bits          
          } epfr09; 

          // EPFR10(Extended Pin Function Setting Register 10) bitfields.
          struct { 
            Object *uedefb; // [0:0] UEDEFB Input/Output Select bit            
            Object *uedthb; // [1:1] UEDTHB Input/Output Select bit            
            Object *ueclke; // [2:2] UECLKE Output Select bit            
            Object *uewexe; // [3:3] UEWEXE Output Select bit            
            Object *uedqme; // [4:4] UEDQME Output Select bit            
            Object *ueoexe; // [5:5] UEOEXE Output Select bit            
            Object *ueflse; // [6:6] UEFLSE Output Select bit            
            Object *uecs1e; // [7:7] UECS1E Output Select bit            
            Object *uecs2e; // [8:8] UECS2E Output Select bit            
            Object *uecs3e; // [9:9] UECS3E Output Select bit            
            Object *uecs4e; // [10:10] UECS4E Output Select bit            
            Object *uecs5e; // [11:11] UECS5E Output Select bit            
            Object *uecs6e; // [12:12] UECS6E Output Select bit            
            Object *uecs7e; // [13:13] UECS7E Output Select bit            
            Object *ueaooe; // [14:14] UEAOOE Output Select bit            
            Object *uea08e; // [15:15] UEA08E Output Select bit            
            Object *uea09e; // [16:16] UEA09E Output Select bit            
            Object *uea10e; // [17:17] UEA10E Output Select bit            
            Object *uea11e; // [18:18] UEA11E Output Select bit            
            Object *uea12e; // [19:19] UEA12E Output Select bit           
            Object *uea13e; // [20:20] UEA13E Output Select bit            
            Object *uea14e; // [21:21] UEA14E Output Select bit            
            Object *uea15e; // [22:22] UEA15E Output Select bit            
            Object *uea16e; // [23:23] UEA16E Output Select bit           
            Object *uea17e; // [24:24] UEA17E Output Select bit            
            Object *uea18e; // [25:25] UEA18E Output Select bit            
            Object *uea19e; // [26:26] UEA19E Output Select bit            
            Object *uea20e; // [27:27] UEA20E Output Select bit            
            Object *uea21e; // [28:28] UEA21E Output Select bit            
            Object *uea22e; // [29:29] UEA22E Output Select bit            
            Object *uea23e; // [30:30] UEA23E Output Select bit            
            Object *uea24e; // [31:31] UEA24E Output Select bit          
            } epfr10; 

          // EPFR11(Extended Pin Function Setting Register 11) bitfields.
          struct { 
            Object *uealee; // [0:0] UEALEE Output Select bit            
            Object *uecs0e; // [1:1] UEA00E Output Select bit            
            Object *uea01e; // [2:2] UEA01E Output Select bit           
            Object *uea02e; // [3:3] UEA02E Output Select bit           
            Object *uea03e; // [4:4] UEA03E Output Select bit            
            Object *uea04e; // [5:5] UEA04E Output Select bit            
            Object *uea05e; // [6:6] UEA05E Output Select bit            
            Object *uea06e; // [7:7] UEA06E Output Select bit            
            Object *uea07e; // [8:8] UEA07E Output Select bit            
            Object *ued00b; // [9:9] UED00B Input/Output Select bit            
            Object *ued01b; // [10:10] UED01B Input/Output Select bit            
            Object *ued02b; // [11:11] UED02B Input/Output Select bit            
            Object *ued03b; // [12:12] UED03B Input/Output Select bit           
            Object *ued04b; // [13:13] UED04B Input/Output Select bit            
            Object *ued05b; // [14:14] UED05B Input/Output Select bit            
            Object *ued06b; // [15:15] UED06B Input/Output Select bit           
            Object *ued07b; // [16:16] UED07B Input/Output Select bit            
            Object *ued08b; // [17:17] UED08B Input/Output Select bit            
            Object *ued09b; // [18:18] UED09B Input/Output Select bit            
            Object *ued10b; // [19:19] UED10B Input/Output Select bit            
            Object *ued11b; // [20:20] UED11B Input/Output Select bit            
            Object *ued12b; // [21:21] UED12B Input/Output Select bit            
            Object *ued13b; // [22:22] UED13B Input/Output Select bit            
            Object *ued14b; // [23:23] UED14B Input/Output Select bit            
            Object *ued15b; // [24:24] UED15B Input/Output Select bit            
            Object *uerlc; // [25:25] UERLC relocation select bit          
          } epfr11; 

          // EPFR12(Extended Pin Function Setting Register 12) bitfields.
          struct { 
            Object *tioa8e; // [2:3] TIOA8 Output Select bits            
            Object *tiob8s; // [4:5] TIOB8 Input Select bits            
            Object *tioa9s; // [8:9] TIOA9 Input Select bits            
            Object *tioa9e; // [10:11] TIOA9 Output Select bits            
            Object *tiob9s; // [12:13] TIOB9 Input Select bits            
            Object *tioa10e; // [18:19] TIOA10 Output Select bits            
            Object *tiob10s; // [20:21] TIOB10 Input Select bits            
            Object *tioa11s; // [24:25] TIOA11 Input Select bits            
            Object *tioa11e; // [26:27] TIOA11 Output Select bits           
            Object *tiob11s; // [28:29] TIOB11 Input Select bits          
          } epfr12; 

          // EPFR13(Extended Pin Function Setting Register 13) bitfields.
          struct { 
            Object *tioa12e; // [2:3] TIOA12 Output Select bits            
            Object *tiob12s; // [4:5] TIOB12 Input Select bits            
            Object *tioa13s; // [8:9] TIOA13 Input Select bits            
            Object *tioa13e; // [10:11] TIOA13 Output Select bits            
            Object *tiob13s; // [12:13] TIOB13 Input Select bits            
            Object *tioa14e; // [18:19] TIOA14 Output Select bits            
            Object *tiob14s; // [20:21] TIOB14 Input Select bits            
            Object *tioa15s; // [24:25] TIOA15 Input Select bits            
            Object *tioa15e; // [26:27] TIOA15 Output Select bits            
            Object *tiob15s; // [28:29] TIOB15 Input Select bits          
          } epfr13; 

          // EPFR14(Extended Pin Function Setting Register 14) bitfields.
          struct { 
            Object *qain2s; // [0:1] QDU-ch.2 AIN Input Pin bits            
            Object *qbin2s; // [2:3] QDU-ch.2 BIN Input Pin bits            
            Object *qzin2s; // [4:5] QDU-ch.2 ZIN Input Pin bits            
            Object *e_td0e; // [18:18] E_TX00, E_TX01 Output Select bit            
            Object *e_td1e; // [19:19] E_TX02_TX10, E_TX03_TX11 Output Select bit            
            Object *e_te0e; // [20:20] E_TXEN0 Output Select bit            
            Object *e_te1e; // [21:21] E_TXER0_TXEN1 Output Select bit            
            Object *e_mc0e; // [22:22] E_MDC0 Output Select bit            
            Object *e_mc1b; // [23:23] E_MDC1 I/O Select bit            
            Object *e_md0b; // [24:24] E_MDO0 I/O Select bit            
            Object *e_md1b; // [25:25] E_MDO1 I/O Select bit            
            Object *e_cke; // [26:26] E_COUT Output Select bit            
            Object *e_pse; // [27:27] PPS0_PPS1 Output Select bit for Ethernet-MAC            
            Object *e_splc; // [28:29] Input cutoff Select bit in Standby of input Pin for Ethernet-MAC          
          } epfr14; 

          // EPFR15(Extended Pin Function Setting Register 15) bitfields.
          struct { 
            Object *eint16s; // [0:1] External Interrupt 16 Input Select bits            
            Object *eint17s; // [2:3] External Interrupt 17 Input Select bits            
            Object *eint18s; // [4:5] External Interrupt 18 Input Select bits            
            Object *eint19s; // [6:7] External Interrupt 19 Input Select bits            
            Object *eint20s; // [8:9] External Interrupt 20 Input Select bits            
            Object *eint21s; // [10:11] External Interrupt 21 Input Select bits            
            Object *eint22s; // [12:13] External Interrupt 22 Input Select bits            
            Object *eint23s; // [14:15] External Interrupt 23 Input Select bits            
            Object *eint24s; // [16:17] External Interrupt 24 Input Select bits            
            Object *eint25s; // [18:19] External Interrupt 25 Input Select bits            
            Object *eint26s; // [20:21] External Interrupt 26 Input Select bits            
            Object *eint27s; // [22:23] External Interrupt 27 Input Select bits            
            Object *eint28s; // [24:25] External Interrupt 28 Input Select bits            
            Object *eint29s; // [26:27] External Interrupt 29 Input Select bits            
            Object *eint30s; // [28:29] External Interrupt 30 Input Select bits            
            Object *eint31s; // [30:31] External Interrupt 31 Input Select bits          
          } epfr15; 

          // EPFR16(Extended Pin Function Setting Register 16) bitfields.
          struct { 
            Object *scs6b; // [0:1] SCS6 Select bits            
            Object *scs7b; // [2:3] SCS7 Input/Output Select bits            
            Object *sin8s; // [4:5] SIN8 Input Select bits            
            Object *sot8b; // [6:7] SOT8 Input/Output Select bits            
            Object *sck8b; // [8:9] SCK8 Input/Output Select bits            
            Object *sin9s; // [10:11] SIN9 Input Select bits            
            Object *sot9b; // [12:13] SOT9 Input/Output Select bits           
            Object *sck9b; // [14:15] SCK9 Input/Output Select bits            
            Object *sin10s; // [16:17] SIN10 Input Select bits            
            Object *sot10b; // [18:19] SOT10 Input/Output Select bits            
            Object *sck10b; // [20:21] SCK10 Input/Output Select bits            
            Object *sin11s; // [22:23] SIN11 Input Select bits            
            Object *sot11b; // [24:25] SOT11 Input/Output Select bits            
            Object *sck11b; // [26:27] SCK11 Input/Output Select bits           
            Object *sfmpac; // [28:28] MFS ch.A I2C FastMode+ Select bit            
            Object *sfmpbc; // [29:29] MFS ch.B I2C FastMode+ Select bit          
          } epfr16; 

          // EPFR17(Extended Pin Function Setting Register 17) bitfields.
          struct { 
            Object *sin12s; // [4:5] SIN12 Input Select bits            
            Object *sot12b; // [6:7] SOT12 Input/Output Select bits            
            Object *sck12b; // [8:9] SCK12 Input/Output Select bits           
            Object *sin13s; // [10:11] SIN13 Input Select bits            
            Object *sot13b; // [12:13] SOT13 Input/Output Select bits            
            Object *sck13b; // [14:15] SCK13 Input/Output Select bits            
            Object *sin14s; // [16:17] SIN14 Input Select bits            
            Object *sot14b; // [18:19] SOT14 Input/Output Select bits            
            Object *sck14b; // [20:21] SCK14 Input/Output Select bits            
            Object *sin15s; // [22:23] SIN15 Input Select bits            
            Object *sot15b; // [24:25] SOT15 Input/Output Select bits            
            Object *sck15b; // [26:27] SCK15 Input/Output Select bits          
          } epfr17; 

          // EPFR18(Extended Pin Function Setting Register 18) bitfields.
          struct { 
            Object *cecr0b; // [0:1] CEC0 Input/Output Select bit            
            Object *cecr1b; // [2:3] CEC1 Input/Output Select bit            
            Object *qain3s; // [4:5] QDU-ch3 AIN input select bits            
            Object *qbin3s; // [6:7] QDU-ch3 BIN input select bits            
            Object *qzin3s; // [8:9] QDU-ch3 ZIN input select bits            
            Object *sdclke; // [14:15] S_CLK output select bits            
            Object *sdcmdb; // [16:17] S_CMD input/output select bits            
            Object *sddata0b; // [18:19] S_CD input select bits           
            Object *sddata1b; // [20:21] S_CD input select bits           
            Object *sddata2b; // [22:23] S_CD input select bits            
            Object *sddata3b; // [24:25] S_CD input select bits            
            Object *sdcds; // [26:27] S_CD input select bits            
            Object *sdwps; // [28:29] S_WP input select bits          
          } epfr18; 

          // EPFR19(Extended Pin Function Setting Register 19) bitfields.
          struct { 
          } epfr19; 

          // EPFR20(Extended Pin Function Setting Register 20) bitfields.
          struct { 
            Object *uesmcke; // [0:0] UESMCKE output select bit            
            Object *uesmcee; // [1:1] UESMCEE output select bit            
            Object *uerase; // [2:2] UERASE output select bit            
            Object *uecase; // [3:3] UECASE output select bit            
            Object *uedwexe; // [4:4] UEDWEXE output select bit            
            Object *uecsxe; // [5:5] UECSXE output select bit           
            Object *uedqm2e; // [6:6] UEDQM2E output select bit            
            Object *uedqm3e; // [7:7] UEDQM3E output select bit            
            Object *uedthhb; // [8:8] UEDTHHB input/output select bit            
            Object *ued16b; // [9:9] UED16B input/output select bit           
            Object *ued17b; // [10:10] UED17B input/output select bit            
            Object *ued18b; // [11:11] UED18B input/output select bit            
            Object *ued19b; // [12:12] UED19B input/output select bit            
            Object *ued20b; // [13:13] UED20B input/output select bit            
            Object *ued21b; // [14:14] UED21B input/output select bit            
            Object *ued22b; // [15:15] UED22B input/output select bit            
            Object *ued23b; // [16:16] UED23B input/output select bit            
            Object *ued24b; // [17:17] UED24B input/output select bit            
            Object *ued25b; // [18:18] UED25B input/output select bit            
            Object *ued26b; // [19:19] UED26B input/output select bit            
            Object *ued27b; // [20:20] UED27B input/output select bit            
            Object *ued28b; // [21:21] UED28B input/output select bit            
            Object *ued29b; // [22:22] UED29B input/output select bit            
            Object *ued30b; // [23:23] UED30B input/output select bit            
            Object *ued31b; // [24:24] UED31B input/output select bit          
          } epfr20; 

          // EPFR21(Extended Pin Function Setting Register 21) bitfields.
          struct { 
          } epfr21; 

          // EPFR22(Extended Pin Function Setting Register 22) bitfields.
          struct { 
          } epfr22; 

          // EPFR23(Extended Pin Function Setting Register 23) bitfields.
          struct { 
            Object *scs60e; // [0:1] SCS60 Input Select bits            
            Object *scs61e; // [2:3] SCS61 Input Select bits            
            Object *scs62e; // [4:5] SCS62 Input Select bits            
            Object *scs63e; // [6:7] SCS63 Input Select bits            
            Object *scs70e; // [8:9] SCS70 Input Select bits            
            Object *scs71e; // [10:11] SCS71 Input Select bits            
            Object *scs72e; // [12:13] SCS72 Input Select bits            
            Object *scs73e; // [14:15] SCS73 Input Select bits          
          } epfr23; 

          // EPFR24(Extended Pin Function Setting Register 24) bitfields.
          struct { 
            Object *i2sm4_mclk0s; // [0:1] I2SMCLK0 Input Select bits            
            Object *i2sm4_mclk0e; // [2:3] I2SMCLK0 Output Select bits            
            Object *i2sm4_sck0b; // [4:5] I2SCK0 Input/Output Select bits            
            Object *i2sm4_ws0b; // [6:7] I2SWS0 Input/Output Select bits            
            Object *i2sm4_sdi0s; // [8:9] I2SDI0 Input Select bits            
            Object *i2sm4_sdo0e; // [10:11] I2SDO0 Output Select bits          
          } epfr24; 

          // EPFR25(Extended Pin Function Setting Register 25) bitfields.
          struct { 
            Object *mcrx2s; // [0:1] RX2 Input Select bits            
            Object *mctx2e; // [2:3] TX2 Output Select bits          
          } epfr25; 

          // EPFR26(Extended Pin Function Setting Register 26) bitfields.
          struct { 
            Object *q_scke; // [0:1] Q_SCK Input Select bits            
            Object *q_cs0e; // [2:3] Q_CS0 Input Select bits            
            Object *q_cs1e; // [4:5] Q_CS1 Input Select bits            
            Object *q_cs2e; // [6:7] Q_CS2 Input Select bits            
            Object *q_cs3e; // [8:9] Q_CS3 Input Select bits            
            Object *q_io0b; // [10:11] Q_IO0 Input Select bits         
            Object *q_io1b; // [12:13] Q_IO1 Input Select bits            
            Object *q_io2b; // [14:15] Q_IO2 Input Select bits            
            Object *q_io3b; // [16:17] Q_IO3 Input Select bits          
          } epfr26; 

          // PZR0(Port Pseudo Open Drain Setting Register 0) bitfields.
          struct { 
          } pzr0; 

          // PZR1(Port Pseudo Open Drain Setting Register 1) bitfields.
          struct { 
          } pzr1; 

          // PZR2(Port Pseudo Open Drain Setting Register 2) bitfields.
          struct { 
          } pzr2; 

          // PZR3(Port Pseudo Open Drain Setting Register 3) bitfields.
          struct { 
          } pzr3; 

          // PZR4(Port Pseudo Open Drain Setting Register 4) bitfields.
          struct { 
          } pzr4; 

          // PZR5(Port Pseudo Open Drain Setting Register 5) bitfields.
          struct { 
          } pzr5; 

          // PZR6(Port Pseudo Open Drain Setting Register 6) bitfields.
          struct { 
          } pzr6; 

          // PZR7(Port Pseudo Open Drain Setting Register 7) bitfields.
          struct { 
          } pzr7; 

          // PZR8(Port Pseudo Open Drain Setting Register 8) bitfields.
          struct { 
          } pzr8; 

          // PZR9(Port Pseudo Open Drain Setting Register 9) bitfields.
          struct { 
          } pzr9; 

          // PZRA(Port Pseudo Open Drain Setting Register A) bitfields.
          struct { 
          } pzra; 

          // PZRB(Port Pseudo Open Drain Setting Register B) bitfields.
          struct { 
          } pzrb; 

          // PZRC(Port Pseudo Open Drain Setting Register C) bitfields.
          struct { 
          } pzrc; 

          // PZRD(Port Pseudo Open Drain Setting Register D) bitfields.
          struct { 
          } pzrd; 

          // PZRE(Port Pseudo Open Drain Setting Register E) bitfields.
          struct { 
          } pzre; 

          // PZRF(Port Pseudo Open Drain Setting Register F) bitfields.
          struct { 
          } pzrf; 

          // PDSR0(/dr) bitfields.
          struct { 
          } pdsr0; 

          // PDSR1(/dr) bitfields.
          struct { 
          } pdsr1; 

          // PDSR2(/dr) bitfields.
          struct { 
          } pdsr2; 

          // PDSR3(/dr) bitfields.
          struct { 
          } pdsr3; 

          // PDSR4(/dr) bitfields.
          struct { 
          } pdsr4; 

          // PDSR5(/dr) bitfields.
          struct { 
          } pdsr5; 

          // PDSR6(/dr) bitfields.
          struct { 
          } pdsr6; 

          // PDSR7(/dr) bitfields.
          struct { 
          } pdsr7; 

          // PDSR8(/dr) bitfields.
          struct { 
          } pdsr8; 

          // PDSR9(/dr) bitfields.
          struct { 
          } pdsr9; 

          // PDSRA(/dr) bitfields.
          struct { 
          } pdsra; 

          // PDSRB(/dr) bitfields.
          struct { 
          } pdsrb; 

          // PDSRC(/dr) bitfields.
          struct { 
          } pdsrc; 

          // PDSRD(/dr) bitfields.
          struct { 
          } pdsrd; 

          // PDSRE(/dr) bitfields.
          struct { 
          } pdsre; 

          // PDSRF(/dr) bitfields.
          struct { 
          } pdsrf; 
        } fld;
      } e2;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} FM4GPIOState;

// ----------------------------------------------------------------------------

#endif /* FM4_GPIO_H_ */