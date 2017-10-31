/*******************************************************************************
 * Copyright (c) 2014-2015 IBM Corporation.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *    IBM Zurich Research Lab - initial API, implementation and documentation
 *
 *	
 *	  
 *
 *******************************************************************************/

#include "lmic.h"

#include <avr/io.h>
#include <avr/interrupt.h>

#include <stdio.h>
#include <string.h>

#include "sys/clock.h"

// -----------------------------------------------------------------------------
// I/O
#if defined RFA1
	#define DDR 					DDRB
	#define PORT 					PORTB	
	#define PIN_DIO0				PB7	
	#define PIN_DIO1				PB6	
	#define PIN_SPI_MOSI            PB2			
	#define PIN_SPI_MISO            PB3			
	#define PIN_SPI_CLK             PB1			
	#define PIN_SPI_CS              PB0
	#define PIN_SPI_RX_SWITCH		PB4 	
	#define PIN_SPI_TX_SWITCH 		PB5		 
#else
#error Missing board!
#endif

// HAL state
static struct
{
    //int irqlevel;
    u4_t ticks;
} HAL;

volatile u1_t port_b_old = 0xFF;     // default is high 

char dest[20];

// val ==1  => tx 1, rx 0 ; val == 0 => tx 0, rx 1
void hal_pin_rxtx (u1_t val)
{
	//not needed
}

// set radio NSS pin to given value
void hal_pin_nss (u1_t val)
{
	if(val) {
		PORT |=  (1<<PIN_SPI_CS); // SPI Disable
	}
	else {
		PORT &= ~(1<<PIN_SPI_CS); //  SPI Enable (Active Low)
	}
}

// set radio RST pin to given value (or keep floating!)
void hal_pin_rst (u1_t val)
{
	//not needed
}

extern void radio_irq_handler(u1_t dio);

// handle data from DIO0 and DIO1 via a hardware interrupt
// the Pin Change Interrupt PCI0 will trigger if any enabled PCINT7:0 pin toggles
// so inside the interrupt we figure out which pin made it fire
volatile uint8_t portbhistory = 0xFF;     // default is high because the pull-up

ISR(PCINT0_vect)
{	
	uint8_t changedbits;

    changedbits = PINB ^ portbhistory;
    portbhistory = PINB;

    //routine doesn't care which pin it came from
    if(changedbits & (1 << PINB6) | changedbits & (1 << PINB7))
    {
        /* PCINT0 changed */
    	radio_irq_handler(1);
    }
}



// perform SPI transaction with radio
u1_t hal_spi (u1_t out)
{
	SPDR = out; // init slave spi
	while (!(SPSR && (1<<SPIF))); // wait for tx done
	u1_t in = SPDR;

	SPSR |= (1<<SPIF); // Clear int flag

	return in;
}


u4_t hal_ticks ()
{
	//return 32-bit system time in ticks
	return clock_time();
}


void hal_waitUntil (u4_t time)
{	
	u4_t ctime = hal_ticks();

    u4_t t;
    if(ctime > time){
       t = 0;
    } else{
       t = time - ctime;
    }

    hal_wait(t);
}

void hal_wait (u4_t time){
	clock_wait(time);
}  

// -----------------------------------------------------------------------------
// IRQ

void hal_disableIRQs ()
{
	cli(); // turns off handling of interrupts in avr 
}

void hal_enableIRQs ()
{
	sei(); // turns on handling of interrupts in avr
}

void hal_sleep ()
{
	//The below commands causes the device to enter Energy Mode 2 on the Cortex-M3, which disables high frequency clocks.
	//Ideally this should put the device into sleep mode until an interrupt occurs.
	//But its not necessary for full execution
	//Just going to leave out an avr version for now
	//EMU_EnterEM2(false); 
}

// -----------------------------------------------------------------------------

void lmic_hal_init ()
{
	hal_disableIRQs();
    memset(&HAL, 0x00, sizeof(HAL));
   
    //set DIO input pins
	DDRB &= ~(1<<PB7);
	DDRB &= ~(1<<PB6);
 
 	//enable Pin Change interrupts on PB7 and PB6.
	PCMSK0 |= (1 << PCINT7);
	PCMSK0 |= (1 << PCINT6); 
	PCICR  |= (1 << PCIE0); 

	//set MISO, MOSI, NSS, CLK
	DDRB |=  (1 << PB2);
	DDRB |=  (1 << PB1);
	DDRB |=  (1 << PB0);
	DDRB &= ~(1 << PB3);
	
	PORTB = 1; // CE high=deselect only
	
	//SPCR  = (1<<SPE) | (1<<MSTR) | (1<<SPR0); // SPI Control Register, clk/16=500kHz
	SPCR  = (1<<SPE) | (1<<MSTR) | (1<<SPR0) | (1<<SPR1); //slow down  clock rate further
	SPSR |= (1<<SPIF); // Clear int flag

	hal_enableIRQs();
}

void hal_failed ()
{
	// HALT...
    hal_disableIRQs();
    hal_sleep();
}
