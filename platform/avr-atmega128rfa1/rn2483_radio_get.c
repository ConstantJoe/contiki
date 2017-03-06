#include "rn2483_radio_get.h"

//Radio Get Commands
unsigned int radio_get_bt()
{
	rs232_print(RS232_PORT_1, "radio get bt\r\n");

	return 1;
}

char* radio_get_bt_response(char* data)
{
	return data;
}

unsigned int radio_get_mod()
{
	rs232_print(RS232_PORT_1, "radio get mod\r\n");

	return 1;
}

char* radio_get_mod_response(char* data)
{
	return data;
}

unsigned int radio_get_freq()
{
	rs232_print(RS232_PORT_1, "radio get freq\r\n");

	return 1;
}

unsigned long radio_get_freq_response(char* data)
{
	return (unsigned long *)strtoull(data, NULL, 0);
}

unsigned int radio_get_pwr()
{
	rs232_print(RS232_PORT_1, "radio get pwr\r\n");

	return 1;
}

int radio_get_pwr_response(char* data)
{
	return (int *)strtol(data, NULL, 0);
}

unsigned int radio_get_sf()
{
	rs232_print(RS232_PORT_1, "radio get sf\r\n");

	return 1;
}

char* radio_get_sf_response(char* data)
{
	return data;
}

unsigned int radio_get_afcbw()
{
	rs232_print(RS232_PORT_1, "radio get afcbw\r\n");

	return 1;
}

char* radio_get_afcbw_response(char* data)
{
	return data;
}

unsigned int radio_get_rxbw()
{
	rs232_print(RS232_PORT_1, "radio get rxbw\r\n");

	return 1;
}

char* radio_get_rxbw_response(char* data)
{
	return data;
}

unsigned int radio_get_bitrate()
{
	rs232_print(RS232_PORT_1, "radio get bitrate\r\n");

	return 1;
}

unsigned int radio_get_bitrate_response(char* data)
{
	return (unsigned int *)strtoull(data, NULL, 0);
}

unsigned int radio_get_fdev()
{
	rs232_print(RS232_PORT_1, "radio get fdev\r\n");

	return 1;
}

unsigned int radio_get_fdev_response(char* data)
{
	return (unsigned int *)strtoull(data, NULL, 0);
}

unsigned int radio_get_prlen()
{
	rs232_print(RS232_PORT_1, "radio get prlen\r\n");

	return 1;
}

unsigned int radio_get_prlen_response(char* data)
{
	return (unsigned int *)strtoull(data, NULL, 0);
}

unsigned int radio_get_crc()
{
	rs232_print(RS232_PORT_1, "radio get crc\r\n");

	return 1;
}

unsigned int radio_get_crc_response(char* data)
{
	return (unsigned int *)strtoull(data, NULL, 0);
}

unsigned int radio_get_iqi()
{
	rs232_print(RS232_PORT_1, "radio get iqi\r\n");

	return 1;
}

unsigned int radio_get_iqi_response(char* data)
{
	return (unsigned int *)strtoull(data, NULL, 0);
}

unsigned int radio_get_cr()
{
	rs232_print(RS232_PORT_1, "radio get cr\r\n");

	return 1;
}

char* radio_get_cr_response(char* data)
{
	return data;
}

unsigned int radio_get_wdt()
{
	rs232_print(RS232_PORT_1, "radio get wdt\r\n");

	return 1;
}

unsigned long radio_get_wdt_response(char* data)
{
	return (unsigned long *)strtoull(data, NULL, 0);
}

unsigned int radio_get_bw()
{
	rs232_print(RS232_PORT_1, "radio get bw\r\n");

	return 1;
}

unsigned int radio_get_bw_response(char* data)
{
	return (unsigned int *)strtoull(data, NULL, 0);
}

unsigned int radio_get_snr()
{
	rs232_print(RS232_PORT_1, "radio get snr\r\n");

	return 1;
}

int radio_get_snr_response(char* data)
{
	return (int *)strtol(data, NULL, 0);
}