/*
 * Copyright (c) 2006, Technical University of Munich
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
 * 3. Neither the name of the Institute nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * This file is part of the Contiki operating system.
 *
 * @(#)$$
 */

/**
 * \file
 *         AVR specific definitions for the rs232 port.
 *
 * \author
 *         Simon Barner <barner@in.tum.de
 */

#ifndef __RS232_ATMEGA128RFA1__
#define __RS232_ATMEGA128RFA1__
/******************************************************************************/
/***   Includes                                                               */
/******************************************************************************/
#include <avr/io.h>

/******************************************************************************/
/***   RS232 ports                                                            */
/******************************************************************************/
#define RS232_PORT_0 0
#define RS232_PORT_1 1

/******************************************************************************/
/***   Baud rates                                                             */
/******************************************************************************/
#if (F_CPU == 16000000UL)
/* Single speed operation (U2X = 0)*/
#define USART_BAUD_2400 416
#define USART_BAUD_4800 207
#define USART_BAUD_9600 103
#define USART_BAUD_14400 68
#define USART_BAUD_19200 51
#define USART_BAUD_28800 34
#define USART_BAUD_38400 25
#define USART_BAUD_57600 16
#define USART_BAUD_76800 12
#define USART_BAUD_115200 8
#define USART_BAUD_230400 3
#define USART_BAUD_250000 3
#define USART_BAUD_500000 1
#define USART_BAUD_1000000 0
#elif (F_CPU == 8000000UL)
/* Single speed operation (U2X = 0)*/
#define USART_BAUD_2400 207
#define USART_BAUD_4800 103
#define USART_BAUD_9600 51
#define USART_BAUD_14400 34
#define USART_BAUD_19200 25
#define USART_BAUD_28800 16
#define USART_BAUD_38400 12
#define USART_BAUD_57600 8
#define USART_BAUD_76800 6
#define USART_BAUD_115200 3
#define USART_BAUD_230400 1
#define USART_BAUD_250000 1
#define USART_BAUD_500000 0
#else
#error "Please define the baud rates for your CPU clock (see ATmega128RFA1 datasheet) \
or set the rate in contiki-conf.h"
#endif


/******************************************************************************/
/***   Interrupt settings                                                     */
/******************************************************************************/
#define USART_INTERRUPT_RX_COMPLETE_0 _BV (RXCIE0)
#define USART_INTERRUPT_TX_COMPLETE_0 _BV (TXCIE0)
#define USART_INTERRUPT_DATA_REG_EMPTY_0 _BV (UDRIE0)

#define USART_INTERRUPT_RX_COMPLETE_1 _BV (RXCIE1)
#define USART_INTERRUPT_TX_COMPLETE_1 _BV (TXCIE1)
#define USART_INTERRUPT_DATA_REG_EMPTY_1 _BV (UDRIE1)

/******************************************************************************/
/***   Receiver / transmitter                                                 */
/******************************************************************************/
#define USART_RECEIVER_ENABLE_0 _BV (RXEN0)
#define USART_TRANSMITTER_ENABLE_0 _BV (TXEN0)

#define USART_RECEIVER_ENABLE_1 _BV (RXEN1)
#define USART_TRANSMITTER_ENABLE_1 _BV (TXEN1)

/******************************************************************************/
/***   Mode select                                                            */
/******************************************************************************/
#define USART_MODE_ASYNC_0 0x00
#define USART_MODE_SYNC_0 _BV (UMSEL00)

#define USART_MODE_ASYNC_1 0x00
#define USART_MODE_SYNC_1 _BV (UMSEL10)

/******************************************************************************/
/***   Parity                                                                 */
/******************************************************************************/
#define USART_PARITY_NONE_0 0x00
#define USART_PARITY_EVEN_0 _BV (UPM01)
#define USART_PARITY_ODD_0  _BV (UPM01) | _BV (UPM00)

#define USART_PARITY_NONE_1 0x00
#define USART_PARITY_EVEN_1 _BV (UPM11)
#define USART_PARITY_ODD_1  _BV (UPM11) | _BV (UPM10)

/******************************************************************************/
/***   Stop bits                                                              */
/******************************************************************************/
#define USART_STOP_BITS_1 0x00
#define USART_STOP_BITS_2_1 _BV (USBS0)
#define USART_STOP_BITS_2_2 _BV (USBS1)

/******************************************************************************/
/***   Character size                                                         */
/******************************************************************************/
#define USART_DATA_BITS_5_0 0x00
#define USART_DATA_BITS_6_0 _BV (UCSZ00)
#define USART_DATA_BITS_7_0 _BV (UCSZ01)
#define USART_DATA_BITS_8_0 _BV (UCSZ01) | _BV (UCSZ00)
// #define USART_DATA_BITS_9 (needs also UCSZ2 bit in UCSRnB)


#define USART_DATA_BITS_5_1 0x00
#define USART_DATA_BITS_6_1 _BV (UCSZ10)
#define USART_DATA_BITS_7_1 _BV (UCSZ11)
#define USART_DATA_BITS_8_1 _BV (UCSZ11) | _BV (UCSZ10)

/******************************************************************************/
/***   Clock polarity                                                         */
/******************************************************************************/
#define USART_RISING_XCKN_EDGE_0 0x00
#define USART_FALLING_XCKN_EDGE_0 _BV (UCPOL0)

#define USART_RISING_XCKN_EDGE_1 0x00
#define USART_FALLING_XCKN_EDGE_1 _BV (UCPOL1)

#endif /* #ifndef __RS232_ATMEGA128RFA1__ */
