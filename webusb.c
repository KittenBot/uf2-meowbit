/*
 * Copyright (c) 2016, Devan Lai
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose with or without fee is hereby granted, provided
 * that the above copyright notice and this permission notice
 * appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR
 * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
 * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,
 * NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <libopencm3/usb/usbd.h>
#include "webusb.h"

// #include "usb_conf.h"
// #include "config.h"

const struct webusb_platform_descriptor webusb_platform = {
    .bLength = WEBUSB_PLATFORM_DESCRIPTOR_SIZE,
    .bDescriptorType = USB_DT_DEVICE_CAPABILITY,
    .bDevCapabilityType = USB_DC_PLATFORM,
    .bReserved = 0,
    .platformCapabilityUUID = WEBUSB_UUID,
    .bcdVersion = 0x0100,
    .bVendorCode = WEBUSB_VENDOR_CODE,
    .iLandingPage = 1
};
