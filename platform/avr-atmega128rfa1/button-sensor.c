/* Dummy sensor routine */

#include "lib/sensors.h"
#include "dev/button-sensor.h"
#include "dev/rs232.h"

#define BUTTON_BIT 5
#define BUTTON_MASK (1<<BUTTON_BIT)

const struct sensors_sensor button_sensor;
static int status(int type);
struct sensors_sensor *sensors[1];
unsigned char sensors_flags[1];


static int configured = 0;

static int
value(int type)
{
	rs232_print(0, "button 1\n\r");
	return ((PINE&BUTTON_MASK)==0);
}

static int
configure(int type, int c)
{
	switch (type) {
	case SENSORS_ACTIVE:
		if (c) {
			if(!status(SENSORS_ACTIVE)) {
				DDRE &= ~(1<<BUTTON_BIT);
				PORTE |= (1<<BUTTON_BIT); // enable pullup resistor

				//EICRB |= (2<<ISC50); // For falling edge
				//EIMSK |= (1<<INT5); // Set int. This sets so contiki reboots on button press?

				configured = 1;
			}
		} else {
			//EIMSK &= ~(1<<INT5); // clear int
			configured = 0;
		}
		return 1;
	}
	return 0;
}

static int
status(int type)
{
	switch (type) {
	case SENSORS_ACTIVE:
	case SENSORS_READY:
		return configured;
	}
	return 0;
}

SENSORS_SENSOR(button_sensor, BUTTON_SENSOR,
	       value, configure, status);

