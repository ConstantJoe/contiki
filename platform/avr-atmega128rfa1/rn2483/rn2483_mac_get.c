//MAC Get Commands
unsigned int mac_get_devaddr()
{
	rs232_print(RS232_PORT_1, "mac get devaddr\r\n");

	return 1;
}

char* mac_get_devaddr_response(char* data)
{
	return data;
}

unsigned int mac_get_deveui()
{
	rs232_print(RS232_PORT_1, "mac get deveui\r\n");

	return 1;
}

char* mac_get_deveui_response(char* data)
{
	return data;
}

unsigned int mac_get_appeui()
{
	rs232_print(RS232_PORT_1, "mac get appeui\r\n");

	return 1;
}

char* mac_get_appeui_response(char* data)
{
	return data;
}

unsigned int mac_get_dr()
{
	rs232_print(RS232_PORT_1, "mac get dr\r\n");

	return 1;
}

unsigned int mac_get_dr_response(char* data)
{
	return (unsigned int *)strtoull(data, NULL, 0);
}

unsigned int mac_get_band()
{
	rs232_print(RS232_PORT_1, "mac get band\r\n");

	return 1;
}

unsigned int mac_get_band_response(char* data)
{
	return (unsigned int *)strtoull(data, NULL, 0);	
} 

unsigned int mac_get_pwridx()
{
	rs232_print(RS232_PORT_1, "mac get pwridx\r\n");

	return 1;
}

unsigned int mac_get_pwridx_response(char* data)
{
	return (unsigned int *)strtoull(data, NULL, 0);		
}

unsigned int mac_get_adr()
{
	rs232_print(RS232_PORT_1, "mac get adr\r\n");

	return 1;
}

unsigned int mac_get_adr_response(char* data)
{
	if(strcmp(data,"on"))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

unsigned int mac_get_retx()
{
	rs232_print(RS232_PORT_1, "mac get retx\r\n");

	return 1;
}

unsigned int mac_get_retx_response(char* data)
{
	return (unsigned int *)strtoull(data, NULL, 0);
}

unsigned int mac_get_rxdelay1()
{
	rs232_print(RS232_PORT_1, "mac get rxdelay1\r\n");

	return 1;
}

unsigned int mac_get_rxdelay1_response(char* data)
{
	return (unsigned int *)strtoull(data, NULL, 0);
}

unsigned int mac_get_rxdelay2()
{
	rs232_print(RS232_PORT_1, "mac get rxdelay2\r\n");

	return 1;
}

unsigned int mac_get_rxdelay2_response(char* data)
{
	return (unsigned int *)strtoull(data, NULL, 0);
}

unsigned int mac_get_ar()
{
	rs232_print(RS232_PORT_1, "mac get ar\r\n");

	return 1;
}

unsigned int mac_get_ar_response(char* data)
{
	if(strcmp(data,"on"))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

unsigned int mac_get_rx2(unsigned int freqBand)
{
	if(freqBand == 868 | freqBand == 433)
	{
		char* command == "mac get rx2 ";

		char* band_str;
		sprintf(band_str, "%u", freqBand);

		//copy all into one array
		char *result = malloc(strlen(command)+strlen(band_str)+3);
    	strcpy(result, command);
    	strcat(result, band_str);
    	strcat(result, "\r\n");

    	rs232_print(RS232_PORT_1, result);

    	return 1;
	}
	else
	{
		rs232_print(RS232_PORT_0, "ERROR: mac_get_rx2: freqBand chosen not 433 or 868.\r\n");
		return 0;
	}
}

char* mac_get_rx2_response(char* data)
{
	//TODO: two return values, more complex
	return data;
}


unsigned int mac_get_dcycleps()
{
	rs232_print(RS232_PORT_1, "mac get dcycleps\r\n");

	return 1;
}

unsigned int mac_get_dcycleps_response(char* data)
{
	return (unsigned int *)strtoull(data, NULL, 0);	
}

unsigned int mac_get_mrgn()
{
	rs232_print(RS232_PORT_1, "mac get mrgn\r\n");

	return 1;
}

unsigned int mac_get_mrgn_response(char* data)
{
	return (unsigned int *)strtoull(data, NULL, 0);
}

unsigned int mac_get_gwnb()
{
	rs232_print(RS232_PORT_1, "mac get gwnb\r\n");

	return 1;
}

unsigned int mac_get_gwnb_response(char* data)
{
	return (unsigned int *)strtoull(data, NULL, 0);
}

unsigned int mac_get_status()
{
	rs232_print(RS232_PORT_1, "mac get status\r\n");

	return 1;
}

char* mac_get_status_response(char* data)
{
	//TODO: bit mask is complex

	return data;
}