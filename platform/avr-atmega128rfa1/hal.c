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

#include "dev/rs232.h"
//#include "serial.h"
// -----------------------------------------------------------------------------
// I/O
#if defined RFA1
	#define DDR 			DDRB
	#define PORT 			PORTB	
	#define PIN_DIO0		PB7	
	#define PIN_DIO1		PB6	
	#define PIN_SPI_MOSI            PB2			
	#define PIN_SPI_MISO            PB3			
	#define PIN_SPI_CLK             PB1			
	#define PIN_SPI_CS              PB0
	#define PIN_SPI_RX_SWITCH	PB4 	
	#define PIN_SPI_TX_SWITCH 	PB5		 
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

// -----------------------------------------------------------------------------
// I/O

void hal_io_init ()
{
	rs232_print(RS232_PORT_0, "In hal io init\r\n");
	//set input and output pins
	DDR &= ~(1<<PIN_DIO0);
	DDR &= ~(1<<PIN_DIO1);
	
	rs232_print(RS232_PORT_0, "In hal ddr\r\n");
	//enable Pin Change interrupts on PB7 and PB6.
	//if this doesn't work: old rising edge --> falling edge was 1 -> 0. 
	PCMSK0 |= (1 << PCINT7);
	PCMSK0 |= (1 << PCINT6); 
	PCICR  |= (1 << PCIE0); 
	rs232_print(RS232_PORT_0, "In hal ints\r\n");
}

// val ==1  => tx 1, rx 0 ; val == 0 => tx 0, rx 1
void hal_pin_rxtx (u1_t val)
{
	//test: seeing if it works without this
	/*if(val) {
		PORT |=  (1<<PIN_SPI_TX_SWITCH);
		PORT &= ~(1<<PIN_SPI_RX_SWITCH);
	}
	else {
		PORT &= ~(1<<PIN_SPI_TX_SWITCH);
		PORT |=  (1<<PIN_SPI_RX_SWITCH);
	}*/
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
	//Not needed (hopefully!)
}

extern void radio_irq_handler(u1_t dio);

// handle data from DIO0 and DIO1 via a hardware interrupt
// the Pin Change Interrupt PCI0 will trigger if any enabled PCINT7:0 pin toggles
// so inside the interrupt we figure out which pin made it fire
ISR(PCINT0_vect)
{
	u1_t changed_bits;

	changed_bits = PINB ^ port_b_old;
    port_b_old = PINB;

    if(changed_bits & (1 << PIN_DIO0)){
		radio_irq_handler(0);	
	}

	if(changed_bits & (1 << PIN_DIO1)){
		radio_irq_handler(1);
	}
}

/*void spix_chipsel(unsigned char sel)
{
	if(sel) {
		PORT &= ~(1<<0); // Drop CE to enable slave - mode 0
	}
	else {
		PORT |= (1<<0); // raise to disable SPI slave - mode 0
	}
}*/


void hal_spi_init ()
{
	rs232_print(RS232_PORT_0, "In hal spi init\r\n");
	//serial_puts((char *) "in hal spi init\r\n");
	uint t = 1 << PB2;
	rs232_print(RS232_PORT_0, "make t\r\n");	

	DDRB |= t;
	rs232_print(RS232_PORT_0, "use t\r\n");
	//DDRB |= (1 << PB2); //problem is here?
	//DDR |=  (1 << PIN_SPI_MOSI);
	rs232_print(RS232_PORT_0, "In hal init\r\n");
	DDR |=  (1 << PIN_SPI_CLK);
	rs232_print(RS232_PORT_0, "In hal init\r\n");
	DDR |=  (1 << PIN_SPI_CS);
	rs232_print(RS232_PORT_0, "In hal init\r\n");
	DDR &= ~(1 << PIN_SPI_MISO);
	rs232_print(RS232_PORT_0, "ddr sets okay\r\n");

	PORTB = 1; // CE high=deselect only
	rs232_print(RS232_PORT_0, "portb set okay\r\n");

	SPCR  = (1<<SPE) | (1<<MSTR) | (1<<SPR0); // SPI Control Register, clk/16=500kHz
	SPSR |= (1<<SPIF); // Clear int flag
	rs232_print(RS232_PORT_0, "spi reg set okay\r\n");

	//spix_chipsel(0);
}

// perform SPI transaction with radio
u1_t hal_spi (u1_t out)
{
	//serial_puts((char *) "in hal spi\r\n");
	/* For every byte sent, one is received */
	//spix_chipsel(1);


	//serial_puts((char *) "init slave spi\r\n");
	SPDR = out; // init slave spi
	//serial_puts((char *) "wait for tx done\r\n");
	while (!(SPSR && (1<<SPIF))); // wait for tx done
	//serial_puts((char *) "tx done\r\n");
	u1_t in = SPDR;
	//serial_puts((char *) "read SPDR\r\n");
	//sprintf(dest, "%d", in);
	//serial_puts((char *) dest);
	//serial_puts((char *) "\r\n");
	SPSR |= (1<<SPIF); // Clear int flag

	//serial_puts((char *) "undo chipsel\r\n");
	//spix_chipsel(0);

	return in;
}


// -----------------------------------------------------------------------------
// TIME
//static uint8_t       rtcInitialized = 0;    /**< 1 if rtc is initialized */
//static uint32_t      rtcFreq;               /**< RTC Frequence. 32.768 kHz */

/***************************************************************************//**
 * @brief RTC Interrupt Handler, invoke callback function if defined.
 ******************************************************************************/
/*void RTC_IRQHandler(void)
{
	if (RTC_IntGet() & RTC_IF_OF)
	{
		HAL.ticks ++;
	}

    if(RTC_IntGet() & RTC_IF_COMP0) // expired
    {
        // do nothing, only wake up cpu
    }
	RTC_IntClear(_RTC_IF_MASK); // clear IRQ flags
}*/


/*static void hal_time_init ()
{
	//using external clock instead

	RTC_Init_TypeDef init;

	rtcInitialized = 1;

	// Ensure LE modules are accessible 
	CMU_ClockEnable(cmuClock_CORELE, true);

	// Enable LFACLK in CMU (will also enable oscillator if not enabled) 
	CMU_ClockSelectSet(cmuClock_LFA, cmuSelect_LFXO);

	// Use the prescaler to reduce power consumption. 
	CMU_ClockDivSet(cmuClock_RTC, cmuClkDiv_1);

	rtcFreq = CMU_ClockFreqGet(cmuClock_RTC);

	// Enable clock to RTC module 
	CMU_ClockEnable(cmuClock_RTC, true);

	init.enable   = false;
	init.debugRun = false;
	init.comp0Top = false;
	//init.comp0Top = true; // Count to max before wrapping 
	RTC_Init(&init);

	// Disable interrupt generation from RTC0 
	RTC_IntDisable(_RTC_IF_MASK);

	// Enable interrupts 
	NVIC_ClearPendingIRQ(RTC_IRQn);
	NVIC_EnableIRQ(RTC_IRQn);

	// Enable RTC 
	RTC_Enable(true);

	RTC_IntEnable(RTC_IF_OF);	//Enable interrupt on overflow
}*/

u4_t hal_ticks ()
{
	//return 32-bit system time in ticks
	//return (u4_t) hw_timer_now(); // TODO: avr only has 16 and 8 bit timers - what to do about this?
	return clock_time();
}

// return modified delta ticks from now to specified ticktime (0 for past, FFFF for far future)
static u2_t deltaticks (u4_t time)
{
	rs232_print(RS232_PORT_0, "in delta ticks\r\n");
    u4_t t = hal_ticks();
    
    char buf[20];
    sprintf(buf, "%u", t);

    char buf2[20];
    sprintf(buf2, "%u", time);

    rs232_print(RS232_PORT_0, "t: ");
 	rs232_print(RS232_PORT_0, (char *) buf);
 	rs232_print(RS232_PORT_0, "\r\n ");
 	rs232_print(RS232_PORT_0, "time: ");
 	rs232_print(RS232_PORT_0, (char * ) buf2);
 	rs232_print(RS232_PORT_0, "\r\n");   

    
    s4_t d = time - t;
    if( d<=0 ) return 0;    // in the past
    if( (d>>16)!=0 ) return 0xFFFF; // far ahead
    return (u2_t)d;
}

void hal_waitUntil (u4_t time)
{
	rs232_print(RS232_PORT_0, "In wait until\r\n");
    while( deltaticks(time) != 0 ); // busy wait until timestamp (in ticks) is reached
}

// check and rewind for target time
u1_t hal_checkTimer (u4_t time)
{
    u2_t dt;
	
	//TODO: problem is here.

	//RTC_IntClear(RTC_IF_COMP0);		//clear any pending interrupts TODO: update this


    if((dt = deltaticks(time)) < 5) // event is now (a few ticks ahead)
    {
    	//RTC_IntDisable(RTC_IF_COMP0);	// disable IE
        return 1;
    }
    else // rewind timer (fully or to exact time))
    {
    	//RTC_CompareSet(0, RTC_CounterGet() + dt);   // set comparator
    	//RTC_IntEnable(RTC_IF_COMP0);  // enable IE
        return 0;
    }
}
  


// -----------------------------------------------------------------------------
// IRQ

void hal_disableIRQs ()
{
	//__disable_interrupt();
	cli(); // turns off handling of interrupts in avr
}

void hal_enableIRQs ()
{
	//__enable_interrupt();
	sei(); // turns on handling of interrupts in avr
	rs232_print(RS232_PORT_0, "test test test\r\n");
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
   
	DDR &= ~(1<<PB7);
	DDR &= ~(1<<PB6);
 
	PCMSK0 |= (1 << PCINT7);
	PCMSK0 |= (1 << PCINT6); 
	PCICR  |= (1 << PCIE0); 

	DDRB |=  (1 << PB2);
	DDRB |=  (1 << PB1);
	DDRB |=  (1 << PB0);
	DDRB &= ~(1 << PB3);
	
	PORTB = 1; // CE high=deselect only
	
	SPCR  = (1<<SPE) | (1<<MSTR) | (1<<SPR0); // SPI Control Register, clk/16=500kHz
	SPSR |= (1<<SPIF); // Clear int flag
}

void hal_failed ()
{
	//debug_led(1);
	// HALT...
    hal_disableIRQs();
    hal_sleep();
    //while(1);
}

