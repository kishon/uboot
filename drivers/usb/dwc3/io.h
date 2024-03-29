/**
 * io.h - DesignWare USB3 DRD IO Header
 *
 * Copyright (C) 2014 Texas Instruments Incorporated - http://www.ti.com
 *
 * Authors: Felipe Balbi <balbi@ti.com>,
 *	    Sebastian Andrzej Siewior <bigeasy@linutronix.de>
 *
 * Taken from Linux Kernel v3.16 (drivers/usb/dwc3/core.c) and ported
 * to uboot.
 *
 * commit 5945f7 : usb: dwc3: switch to GPL v2 only
 *
 * SPDX-License-Identifier:     GPL-2.0
 *
 */

#ifndef __DRIVERS_USB_DWC3_IO_H
#define __DRIVERS_USB_DWC3_IO_H

#include <asm/io.h>
#include "core.h"

static inline u32 dwc3_readl(void __iomem *base, u32 offset)
{
	u32 temp;
	/*
	 * We requested the mem region starting from the Globals address
	 * space, see dwc3_probe in core.c.
	 * However, the offsets are given starting from xHCI address space.
	 */
	temp = readl(base + (offset - DWC3_GLOBALS_REGS_START));
	return temp;
}

static inline void dwc3_writel(void __iomem *base, u32 offset, u32 value)
{
	/*
	 * We requested the mem region starting from the Globals address
	 * space, see dwc3_probe in core.c.
	 * However, the offsets are given starting from xHCI address space.
	 */
	writel(value, base + (offset - DWC3_GLOBALS_REGS_START));
}

#endif /* __DRIVERS_USB_DWC3_IO_H */
