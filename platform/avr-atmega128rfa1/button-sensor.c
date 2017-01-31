/* Dummy sensor routine */

//#include "lib/sensors.h"
#include "dev/button-sensor.h"
#include "dev/rs232.h"
#include <avr/interrupt.h> 

#define BUTTON_BIT 5
#define BUTTON_MASK (1<<BUTTON_BIT)

const struct sensors_sensor button_sensor;
static int status(int type);
struct sensors_sensor *sensors[1];
unsigned char sensors_flags[1];


static int configured = 0;

ISR(INT5_vect)
{
	rs232_print(0, "in isr \n\r");
  	if((EIFR & INTF5) ? 0 : 1) {
   	sensors_changed(&button_sensor);
  	}
}

static int
value(int type)
{
	rs232_print(0, "button 1\n\r");
	//return ((PINE&BUTTON_MASK)==0);
	return (PORTE & _BV(PE5) ? 0 : 1);
}

static int
configure(int type, int c)
{
	rs232_print(0, "button 2\n\r");
	switch (type) {
	case SENSORS_ACTIVE:
		if (c) {
			if(!status(SENSORS_ACTIVE)) {
				DDRE &= ~(1<<BUTTON_BIT);
				PORTE |= (1<<BUTTON_BIT); // enable pullup resistor

				EICRB |= (2<<ISC50); 
				EIMSK |= (1<<INT5); // Enable INT5 hardware interrupt

				configured = 1;
			}
		} else {
			EIMSK &= ~(1<<INT5); // clear int
			configured = 0;
		}
		return 1;
	}
	return 0;
}

static int
status(int type)
{
	rs232_print(0, "button 3\n\r");
	switch (type) {
	case SENSORS_ACTIVE:
	case SENSORS_READY:
		return configured;
	}
	return 0;
}

SENSORS_SENSOR(button_sensor, BUTTON_SENSOR,
	       value, configure, status);

