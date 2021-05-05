/*
 * FM4 Cortex-M devices emulation.
 *
 * Copyright (c) 2014 Liviu Ionescu.
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

#ifndef FM4_MCUS_H_
#define FM4_MCUS_H_

#include "qemu/osdep.h"

#include <hw/cortexm/fm4/mcu.h>

/* ------------------------------------------------------------------------- */

// For compatibility with some development tools, it is
// strongly recommended to use the CMSIS names.
#define TYPE_FM4S6E2CC "FM4S6E2CC"


// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_FM4_DEVICE_PARENT TYPE_FM4_MCU
typedef FM4MCUClass FM4DeviceParentClass;
typedef FM4MCUState FM4DeviceParentState;

// ----------------------------------------------------------------------------

// Class definitions.
// Warning, this cast must not check the type!
#define FM4_DEVICE_GET_CLASS(obj) \
    ((FM4DeviceClass *)object_get_class(OBJECT(obj)))

// Structure to define the specifics of each MCU. Capabilities are
// split between core & fm4; they care processed by parent class
// constructors.
typedef struct {

    const char *name; // CMSIS device name

    const CortexMCapabilities cortexm;
    const FM4Capabilities *fm4;

} FM4PartInfo;

typedef struct {
    // private:
    FM4DeviceParentClass parent_class;
    // public:

    FM4PartInfo *part_info;
} FM4DeviceClass;

// ----------------------------------------------------------------------------

// Instance definitions.
typedef struct {
    // private:
    FM4DeviceParentState parent_class;
// public:

} FM4DeviceState;

// ----------------------------------------------------------------------------

#endif /* FM4_MCUS_H_ */
