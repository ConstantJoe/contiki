#include "dev/button-sensor.h"

#define BUTTON_BIT 5

const struct sensors_sensor button_sensor;
static int status(int type);


const struct sensors_sensor *sensors[] = {
	&button_sensor,
	0
};
unsigned char sensors_flags[(sizeof(sensors) / sizeof(struct sensors_sensor *))];


static int configured = 0;

ISR(INT5_vect)
{
  	if((EIFR & INTF5) ? 0 : 1) {
   	sensors_changed(&button_sensor);
  	}
}

static int
value(int type)
{
	return (PORTE & _BV(PE5) ? 0 : 1);
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
	switch (type) {
	case SENSORS_ACTIVE:
	case SENSORS_READY:
		return configured;
	}
	return 0;
}

SENSORS_SENSOR(button_sensor, BUTTON_SENSOR,
	       value, configure, status);

