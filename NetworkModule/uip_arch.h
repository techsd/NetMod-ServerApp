/**
 * Architecture specific uIP functions
 *
 * The functions in the architecture specific module implement the IP
 * check sum and 32-bit additions.
 *
 * The IP checksum calculation is the most computationally expensive
 * operation in the TCP/IP stack and it therefore pays off to
 * implement this in efficient assembler. The purpose of the uip-arch
 * module is to let the checksum functions to be implemented in
 * architecture specific assembler.
 */

/**
 * Declarations of architecture specific functions.
 * \author Adam Dunkels <adam@dunkels.com>
 */

/*
 * Copyright (c) 2001, Adam Dunkels.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote
 *    products derived from this software without specific prior
 *    written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * This file is part of the uIP TCP/IP stack.
 *
 * $Id: uip_arch.h,v 1.1 2007/01/04 11:06:41 adamdunkels Exp $
 *
 */
 
/* Modifications 2020-2022 Michael Nielson
 * Adapted for STM8S005 processor, ENC28J60 Ethernet Controller,
 * Web_Relay_Con V2.0 HW-584, and compilation with Cosmic tool set.
 * Author: Michael Nielson
 * Email: nielsonm.projects@gmail.com
 *
 * This declaration applies to modifications made by Michael Nielson
 * and in no way changes the Adam Dunkels declaration above.
 
 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful, but
 WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 General Public License for more details.

 See GNU General Public License at <http://www.gnu.org/licenses/>.
 
 Copyright 2022 Michael Nielson
*/



#ifndef __UIP_ARCH_H__
#define __UIP_ARCH_H__

#include "uip.h"

/**
 * Carry out a 32-bit addition.
 *
 * Because not all architectures for which uIP is intended has native
 * 32-bit arithmetic, uIP uses an external C function for doing the
 * required 32-bit additions in the TCP protocol processing. This
 * function should add the two arguments and place the result in the
 * global variable uip_acc32.
 *
 * The 32-bit integer pointed to by the op32 parameter and the
 * result in the uip_acc32 variable are in network byte order (big
 * endian).
 *
 * op32 - A pointer to a 4-byte array representing a 32-bit
 * integer in network byte order (big endian).
 *
 * op16 - A 16-bit integer in host byte order.
 */
void uip_add32(uint8_t *op32, uint16_t op16);

/**
 * Calculate the Internet checksum over a buffer.
 *
 * The Internet checksum is the one's complement of the one's
 * complement sum of all 16-bit words in the buffer.
 *
 * See RFC1071.
 *
 * This function is not called in the current version of uIP,
 * but future versions might make use of it.
 *
 * buf - A pointer to the buffer over which the checksum is to be computed.
 * len - The length of the buffer over which the checksum is to be computed.
 * return - The Internet checksum of the buffer.
 */
uint16_t uip_chksum(uint16_t *buf, uint16_t len);

/**
 * Calculate the IP header checksum of the packet header in uip_buf.
 *
 * The IP header checksum is the Internet checksum of the 20 bytes of
 * the IP header.
 *
 * return - The IP header checksum of the IP header in the uip_buf
 * buffer.
 */
uint16_t uip_ipchksum(void);

/**
 * Calculate the TCP checksum of the packet in uip_buf and uip_appdata.
 *
 * The TCP checksum is the Internet checksum of data contents of the
 * TCP segment, and a pseudo-header as defined in RFC793.
 *
 * The uip_appdata pointer that points to the packet data may
 * point anywhere in memory, so it is not possible to simply calculate
 * the Internet checksum of the contents of the uip_buf buffer.
 *
 * return - The TCP checksum of the TCP segment in uip_buf and pointed
 * to by uip_appdata.
 */
uint16_t uip_tcpchksum(void);

#endif /* __UIP_ARCH_H__ */
