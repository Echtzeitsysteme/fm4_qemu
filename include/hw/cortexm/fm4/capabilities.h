/*
 * FM4 capabilities definitions.
 *
 * Copyright (c) 2015 Liviu Ionescu.
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

#ifndef FM4_CAPABILITIES_H_
#define FM4_CAPABILITIES_H_

#include <stdint.h>

/*
 * This file defines the members used in the structure used to describe
 * the capabilities of the FM4 MCUs.
 *
 * FM4 MCUs are grouped by families and sub-families.
 */

#define TYPE_FM4_PREFIX       "fm4:"
#define TYPE_FM4F1_PREFIX     "fm4f1:"
#define TYPE_FM4F1CL_PREFIX   "fm4f1cl:"

#define DEVICE_PATH_FM4 "/machine/mcu/fm4/"

/*
 * The family is the main differentiator for FM4 MCUs.
 */
typedef enum {
    FM4_FAMILY_UNKNOWN,
    FM4_FAMILY_F0,
    FM4_FAMILY_F1,
    FM4_FAMILY_F2,
    FM4_FAMILY_F3,
    FM4_FAMILY_F4,
    FM4_FAMILY_F7,
    FM4_FAMILY_H7,
    FM4_FAMILY_L0,
    FM4_FAMILY_L1,
    FM4_FAMILY_L4,
} fm4_family_t;

#define FM4_MAX_GPIO  (8)
#define FM4_MAX_USART (6)



typedef struct {

    fm4_family_t family;

    // Properties common to all families

    uint32_t hsi_freq_hz;
    uint32_t lsi_freq_hz;

    uint32_t eeprom_size_kb;
    uint32_t ccm_size_kb; // size of CCM area, in KB
    uint32_t back_sram_size_kb; // size of backup SRAM area, in KB

    // Bitband the 1 MB from 0x40000000-0x400FFFFF area to
    // 32 MB at 0x42000000-0x43FFFFFF.

    unsigned int has_periph_bitband :1;

#if 0
    // Peripherals common to all families.

    unsigned int has_rcc :1;
    unsigned int has_flash :1;
    unsigned int has_pwr :1;

    // System configuration; F4 specific.
    unsigned int has_syscfg :1;

    // Alternate function I/O; F1 specific
    unsigned int has_afio :1;

    // EXTI
    unsigned int has_exti :1;

#endif

    // GPIOs
    unsigned int has_gpio :1;
 
    unsigned char num_gpio; // Will be computed, no need to set it.

    // DMA
    unsigned int has_dma :1;
    unsigned int has_dma1 :1;
    unsigned int has_dma2 :1;

    // Advanced control timers
    unsigned int has_ac_tim1 :1;
    unsigned int has_ac_tim8 :1;
    // General-purpose timers
    unsigned int has_gp_tim2 :1;
    unsigned int has_gp_tim5 :1;
    // General-purpose timers
    unsigned int has_gp_tim3 :1;
    unsigned int has_gp_tim4 :1;
    // General-purpose timers
    unsigned int has_gp_tim9 :1;
    unsigned int has_gp_tim12 :1;
    // General-purpose timers
    unsigned int has_gp_tim10 :1;
    unsigned int has_gp_tim11 :1;
    unsigned int has_gp_tim13 :1;
    unsigned int has_gp_tim14 :1;
    unsigned int has_gp_tim15 :1;
    unsigned int has_gp_tim16 :1;
    unsigned int has_gp_tim17 :1;
    // Basic timers
    unsigned int has_bc_tim6 :1;
    unsigned int has_bc_tim7 :1;
    // Watchdogs
    unsigned int has_iwdg :1;
    unsigned int has_wwdg :1;

    // I2C
    unsigned int has_i2c :1;
    unsigned int has_i2c1 :1;
    unsigned int has_i2c2 :1;
    unsigned int has_i2c3 :1;

    // Universal synchronous/asynchronous
    unsigned int has_usart1 :1;
    unsigned int has_usart2 :1;
    unsigned int has_usart3 :1;
    unsigned int has_usart4 :1;
    unsigned int has_usart5 :1;
    unsigned int has_usart6 :1;
    unsigned int has_usart7 :1;
    unsigned int has_usart8 :1;
    // Universal asynchronous
    unsigned int has_uart4 :1;
    unsigned int has_uart5 :1;

 
   
   
    // Memory
    unsigned int has_fsmc :1;

    // SDIO
    unsigned int has_sdio :1;

    // Ethernet
    unsigned int has_eth :1;
    // CAN
    unsigned int has_bx_can1 :1;
    unsigned int has_bx_can2 :1;
    unsigned int has_can1 :1;
    unsigned int has_can2 :1;
    // ADC
    unsigned int has_adc :1;
    unsigned int has_adc1 :1;
    unsigned int has_adc2 :1;
    unsigned int has_adc3 :1;
    // DAC
    unsigned int has_dac :1; // num_dac
    unsigned int has_dac1 :1;
    unsigned int has_dac2 :1;
    // USB
    unsigned int has_usb_fs :1;
    unsigned int has_usb_otg_fs :1;
    unsigned int has_usb_otg_hs :1;

    // RTC
    unsigned int has_rtc :1;

    // CRC
    unsigned int has_crc :1;

    // Temperature sensor
    unsigned int has_ts :1;

    unsigned int has_comp :1; // num_comp

    unsigned int has_dcmi :1;
    unsigned int has_rng :1;
    unsigned int has_hdmi_cec :1;

    // Has TSC (touch sensing controller)
    unsigned int has_tsc :1;

    // Keep them together
    unsigned char num_exti;
    unsigned char num_dma1;
    unsigned char num_dma2;
    unsigned char num_dma;
    unsigned char num_comp;

    // Number of backup bytes
    uint32_t num_back_bytes;

    /*
     * Note: the family definitions are mutual exclusive, and could
     * be packed in a union, but this makes writing the definitions
     * more complicated and was discarded.
     * The memory penalty is not significant.
     */
   
// TODO: add other families that have sub-families.

} FM4Capabilities;

#endif /* FM4_CAPABILITIES_H_ */
