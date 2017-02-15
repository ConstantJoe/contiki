

unsigned int sys_sleep(unsigned long length)
{

  if(length > 100)
  {
    char* command = "sys sleep ";

    //convert ulong to string
    const int n = snprintf(NULL, 0, "%lu", length);
    assert(n > 0);
    char len_str[n+1];
    int c = snprintf(len_str, n+1, "%lu", length);
    assert(len_str[n] == '\0');
    assert(c == n);

    char *result = malloc(strlen(command)+strlen(len_str)+3);
    strcpy(result, command);
    strcat(result, len_str);
    strcat(result, "\r\n");

    rs232_print(RS232_PORT_1, result);

    return 1;
  }
  else
  {
    rs232_print(RS232_PORT_0, "ERROR: sleep length not long enough.");
    return 0;
  }
}

unsigned int sys_sleep_response(char* data)
{
	if(strcmp(data,"ok"))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

unsigned int sys_reset()
{
	rs232_print(RS232_PORT_1, "sys reset\r\n");

	return 1;
}

char* sys_reset_response(char* data)
{
	// data is system data, in the format:
	// RN2483 X.Y.Z MMM DD YYYY HH:MM:SS
	// Date and time refer to the release of the firmware
	//TODO: put this into a nicer format
	return data;
}

/*NOTE: this method gives no response.*/
unsigned int sys_eraseFW()
{
	rs232_print(RS232_PORT_1, "sys eraseFW\r\n");

	return 1;
}


unsigned int sys_factoryRESET()
{
	rs232_print(RS232_PORT_1, "sys factoryRESET\r\n");

	return 1;
}

char* sys_factoryRESET_response(char* data)
{
	// data is system data, in the format:
	// RN2483 X.Y.Z MMM DD YYYY HH:MM:SS
	// Date and time refer to the release of the firmware
	//TODO: put this into a nicer format
	return data;
}



















//System Set Commands

/*Modify EEPROM at address to data. Both address and data must be inputted as hex values
	Can modify addresses from 300 to 3FF.
*/
unsigned int sys_set_nvm(unsigned int address, unsigned int data)
{
	if(address >= 0x300 && address <= 0x3FF)
	{
		if(data >= 0x00 && <= 0xFF)
		{
			char* command = "sys set nvm ";

			//address to char* (hex version)
			char* add_str;
			sprintf(add_str, "%x", address);

			//data to char* (hex version)
			char* data_str;
			sprintf(data_str, "%x", data);

			//copy all into one array
			char *result = malloc(strlen(command)+strlen(add_str)+strlen(data_str)+4);
    		strcpy(result, command);
    		strcat(result, add_str);
    		strcat(result, " ");
    		strcat(result, data_str);
    		strcat(result, "\r\n");

    		rs232_print(RS232_PORT_1, result);

    		return 1;
		}
		else
		{
			rs232_print(RS232_PORT_0, "ERROR: sys_set_nvm: data not between 0x00 and 0xFF\r\n");
			return 0;
		}
	}
	else
	{
		rs232_print(RS232_PORT_0, "ERROR: sys_set_nvm: address not between 0x300 and 0x3FF\r\n");
		return 0;
	}
}

unsigned int sys_set_nvm_response(char* data)
{
	if(strcmp(data,"ok"))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*Modify unused pins on the module
Pinname can be GPIO0-GPIO14, UART_CTS, UART_RTS, TEST0, TEST1
Pinstate can be 0 or 1.
*/
unsigned int sys_set_pindig(char* pinname, unsigned int pinstate)
{
	if( strcmp(pinname,"GPIO0")    | strcmp(pinname,"GPIO1")    | strcmp(pinname,"GPIO2")  | strcmp(pinname,"GPIO3")  | strcmp(pinname,"GPIO4") | 
		strcmp(pinname,"GPIO5")    | strcmp(pinname,"GPIO6")    | strcmp(pinname,"GPIO7")  | strcmp(pinname,"GPIO8")  | strcmp(pinname,"GPIO9") | 
		strcmp(pinname,"GPIO10")   | strcmp(pinname,"GPIO11")   | strcmp(pinname,"GPIO12") | strcmp(pinname,"GPIO13") | strcmp(pinname,"GPIO14") | 
		strcmp(pinname,"UART_CTS") | strcmp(pinname,"UART_RTS") | strcmp(pinname,"TEST0")  | strcmp(pinname,"TEST1"))
	{
		if(pinstate == 0 | pinstate == 1)
		{
			char* command = "sys set pindig ";

			//pinstate to char*
			char* pinstate_str;
			sprintf(pinstate_str, "%u", address);

			//copy all into one array
			char *result = malloc(strlen(command)+strlen(pinname)+strlen(pinstate_str)+4);
    		strcpy(result, command);
    		strcat(result, pinname);
    		strcat(result, " ");
    		strcat(result, pinstate_str);
    		strcat(result, "\r\n");

    		rs232_print(RS232_PORT_1, result);

    		return 1;
		}
		else
		{
			rs232_print(RS232_PORT_0, "ERROR: sys_set_pindig: pinstate is not 0 or 1\r\n");
			return 0;
		}
	}
	else
	{
		rs232_print(RS232_PORT_0, "ERROR: sys_set_pindig: pinname not correct\r\n");
		return 0;
	}
}

unsigned int sys_set_pindig_response(char* data)
{
	if(strcmp(data,"ok"))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}





















//System Get Commands

unsigned int sys_get_ver()
{
	rs232_print(RS232_PORT_1, "sys get ver\r\n");

	return 1;
}

char* sys_get_ver_response(char* data)
{
	// data is system data, in the format:
	// RN2483 X.Y.Z MMM DD YYYY HH:MM:SS
	// Date and time refer to the release of the firmware
	//TODO: put this into a nicer format
	return data;
}


unsigned int sys_get_nvm(unsigned int address)
{
	if(address >= 0x300 && address <= 0x3FF)
	{
		char* command = "sys get nvm ";

		char* add_str;
		sprintf(add_str, "%x", address);
		//address to char*

		//copy all into one array
		char *result = malloc(strlen(command)+strlen(add_str)+3);
    	strcpy(result, command);
    	strcat(result, add_str);
    	strcat(result, "\r\n");

    	rs232_print(RS232_PORT_1, result);

    	return 1;
	}
	else
	{
		rs232_print(RS232_PORT_0, "ERROR: sys_get_nvm: address not between 0x300 and 0x3FF.\r\n");
		return 0;
	}
}

unsigned int sys_get_nvm_response(char* data)
{
	if(strcmp(data,"invalid_param"))
	{
		return 0;
	}
	else
	{
		return (unsigned int)strtol(data, NULL, 16);
	}
}


unsigned int sys_get_vdd()
{
	rs232_print(RS232_PORT_1, "sys get vdd\r\n");

	return 1;
}

unsigned int sys_get_vdd_response(char* data)
{
	return (unsigned int *)strtoull(data, NULL, 0);
}





unsigned int sys_get_hweui()
{
	rs232_print(RS232_PORT_1, "sys get hweui\r\n");

	return 1;
}

unsigned int sys_get_hweui_response(char* data)
{
	return (unsigned int)strtol(data, NULL, 16);
}























//MAC Commands

/*band can be 868 or 433*/
unsigned int mac_reset(unsigned int band)
{
	if(band == 433 | band == 868)
	{
		char* command = "mac reset ";
		
		//int to char*
		char* band_str;
		sprintf(band_str, "%u", band);

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
		rs232_print(RS232_PORT_0, "ERROR: mac_reset: band chosen is not 433 or 868.\r\n");
		return 0;
	}
}

unsigned int mac_reset_response(char* data)
{
	if(strcmp(data,"ok"))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}




void mac_tx(char* type, unsigned int portno, char* data)
{
	if(strcmp(type,"cnf") | strcmp(type,"uncnf"))
	{
		if(portno >= 1 && <= 223)
		{
			//TODO: check if data is in hex form.

			char* command == "mac tx ";

			//TODO: unsigned int to char

			PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

			//TODO: response is complex; there's two parts
		}
		else
		{
			//print err message, return "0"
		}
	}
	else
	{
		//print err message, return "0"
	}
}

void mac_join(char* mode)
{
	if(mode == "otaa" | mode == "abp")
	{
		char* command == "mac join ";

		//TODO: concat strings

		PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

		//TODO: response is complex
	}
	else
	{
		//print err message, return "0"
	}
}

unsigned int mac_save()
{
	rs232_print(RS232_PORT_1, "mac save\r\n");

	return 1;
}

unsigned int mac_save_response(char* data)
{
	if(strcmp(data,"ok"))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}



unsigned int mac_forceENABLE()
{
	rs232_print(RS232_PORT_1, "mac forceENABLE\r\n");

	return 1;
}

unsigned int mac_forceENABLE_response(char* data)
{
	if(strcmp(data,"ok"))
	{
		return 1;
	}
	else
	{
		return 0;
	}	
}





unsigned int mac_pause()
{
	rs232_print(RS232_PORT_1, "mac pause\r\n");

	return 1;
}

unsigned long mac_pause_response(char* data)
{
	return (unsigned long)strtoul(data, NULL, 0);
}

unsigned int mac_resume()
{
	rs232_print(RS232_PORT_1, "mac resume\r\n");

	return 1;
}

unsigned int mac_resume_response()
{
	if(strcmp(data,"ok"))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

















//MAC Set Commands

unsigned int mac_set_devaddr(unsigned long address)
{
	char* command == "mac set devaddr ";

	//address to char*
	char* add_str;
	sprintf(add_str, "%x", address);
		
	//copy all into one array
	char *result = malloc(strlen(command)+strlen(add_str)+3);
    strcpy(result, command);
    strcat(result, add_str);
    strcat(result, "\r\n");

   	rs232_print(RS232_PORT_1, result);

    return 1;
}

unsigned int mac_set_devaddr_response(char* data)
{
	if(strcmp(data,"ok"))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


unsigned int mac_set_deveui(char* deveui)
{
	//TODO: complex, check if string is in hex format, correct length

	char* command == "mac set deveui ";

	//TODO: concat char*s, send off

	PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

	// if data is ok, return 1. Else return 0.
}

unsigned int mac_set_deveui_response(char* data)
{
	if(strcmp(data,"ok"))
	{
		return 1;
	}
	else
	{
		return 0;
	}	
}


unsigned int mac_set_appeui(char* appeui)
{
	//TODO: complex, check if string is in hex format, correct length

	char* command == "mac set appeui ";

	//TODO: concat char*s, send off

	PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

	// if data is ok, return 1. Else return 0.
}

unsigned int mac_set_appeui_response(char* data)
{
	if(strcmp(data,"ok"))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}



unsigned int mac_set_nwkskey(char* nwksesskey)
{
	//TODO: complex, check if string is in hex format, correct length

	char* command == "mac set nwkskey ";

	//TODO: concat char*s, send off

	PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

	// if data is ok, return 1. Else return 0.
}

unsigned int mac_set_nwkskey(char* data)
{
	if(strcmp(data,"ok"))
	{
		return 1;
	}
	else
	{
		return 0;
	}	
}


unsigned int mac_set_appskey(char* appSesskey)
{
	//TODO: complex, check if string is in hex format, correct length

	char* command == "mac set appskey ";

	//TODO: concat char*s, send off

	PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

	// if data is ok, return 1. Else return 0.
}

unsigned int mac_set_appskey(char* data)
{
	if(strcmp(data,"ok"))
	{
		return 1;
	}
	else
	{
		return 0;
	}	
}



unsigned int mac_set_appkey(char* appkey)
{
	//TODO: complex, check if string is in hex format, correct length

	char* command == "mac set appkey ";

	//TODO: concat char*s, send off

	PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

	// if data is ok, return 1. Else return 0.
}

unsigned int mac_set_appkey_response(char* appkey)
{
	if(strcmp(data,"ok"))
	{
		return 1;
	}
	else
	{
		return 0;
	}	
}

unsigned int mac_set_pwridx(unsigned int pwrIndex)
{
	if(pwrIndex >= 0 && pwrIndex <= 5)
	{
		char* command == "mac set pwridx ";

		//int to char*
		char* pwrIndex_str;
		sprintf(pwrIndex_str, "%u", pwrIndex);

		//copy all into one array
		char *result = malloc(strlen(command)+strlen(pwrIndex_str)+3);
    	strcpy(result, command);
    	strcat(result, pwrIndex_str);
    	strcat(result, "\r\n");

    	rs232_print(RS232_PORT_1, result);

    	return 1;
	}
	else
	{
		rs232_print(RS232_PORT_0, "ERROR: mac_set_pwridx: pwrIndex not between 0 and 5.\r\n");		
		return 0;
	}
}

unsigned int mac_set_pwridx_response(char* data)
{
	if(strcmp(data,"ok"))
	{
		return 1;
	}
	else
	{
		return 0;
	}		
}


unsigned int mac_set_dr(unsigned int dataRate)
{
	if(dataRate >= 0 && dataRate <= 7)
	{
		char* command == "mac set dr ";

		//int to char*
		char* dataRate_str;
		sprintf(dataRate_str, "%u", dataRate);

		//copy all into one array
		char *result = malloc(strlen(command)+strlen(dataRate_str)+3);
    	strcpy(result, command);
    	strcat(result, dataRate_str);
    	strcat(result, "\r\n");

    	rs232_print(RS232_PORT_1, result);

    	return 1;
	}
	else
	{
		rs232_print(RS232_PORT_0, "ERROR: mac_set_dr: dataRate not between 0 and 7.\r\n");		
		return 0;		
	}
}

unsigned int mac_set_dr_response(char* data)
{
	if(strcmp(data,"ok"))
	{
		return 1;
	}
	else
	{
		return 0;
	}	
}



unsigned int mac_set_adr(unsigned int state)
{
	if(state == 1 | state == 0)
	{
		char* command == "mac set adr ";

		//int to char*
		char* state_str;
		if(state)
		{
			state_str = "on";
		}
		else
		{
			state_str = "off";
		}

		//copy all into one array
		char *result = malloc(strlen(command)+strlen(state_str)+3);
    	strcpy(result, command);
    	strcat(result, state_str);
    	strcat(result, "\r\n");

    	rs232_print(RS232_PORT_1, result);

    	return 1;
	}
	else
	{
		rs232_print(RS232_PORT_0, "ERROR: mac_set_dr: state is not 0 or 1.\r\n");		
		return 0;
	}
}

unsigned int mac_set_adr_response(char* data)
{
	if(strcmp(data,"ok"))
	{
		return 1;
	}
	else
	{
		return 0;
	}		
}



unsigned int mac_set_bat(unsigned int level)
{
	if(level >= 0 && level <= 255)
	{
		char* command == "mac set bat ";

		//int to char*
		char* level_str;
		sprintf(level_str, "%u", level);

		//copy all into one array
		char *result = malloc(strlen(command)+strlen(level_str)+3);
    	strcpy(result, command);
    	strcat(result, level_str);
    	strcat(result, "\r\n");

    	rs232_print(RS232_PORT_1, result);

    	return 1;
	}
	else
	{
		rs232_print(RS232_PORT_0, "ERROR: mac_set_bat: state is not between 0 and 255.\r\n");		
		return 0;
	}
}

unsigned int mac_set_bat_response(char* data)
{
	if(strcmp(data,"ok"))
	{
		return 1;
	}
	else
	{
		return 0;
	}		
}





unsigned int mac_set_retx(unsigned int reTxNb)
{
	if(reTxNb >= 0 && reTxNb <= 255)
	{
		char* command == "mac set retx ";

		//int to char*
		char* reTxNb_str;
		sprintf(reTxNb_str, "%u", reTxNb);

		//copy all into one array
		char *result = malloc(strlen(command)+strlen(reTxNb_str)+3);
    	strcpy(result, command);
    	strcat(result, reTxNb_str);
    	strcat(result, "\r\n");

    	rs232_print(RS232_PORT_1, result);

    	return 1;
	}
	else
	{
		rs232_print(RS232_PORT_0, "ERROR: mac_set_retx: reTxNb is not between 0 and 255.\r\n");		
		return 0;
	}
}

unsigned int mac_set_retx_response(char* data)
{
	if(strcmp(data,"ok"))
	{
		return 1;
	}
	else
	{
		return 0;
	}	
}

unsigned int mac_set_linkchk(unsigned int linkCheck)
{
	if(linkCheck >= 0 && linkCheck <= 65535)
	{
		char* command == "mac set linkchk ";

		//int to char*
		char* linkCheck_str;
		sprintf(linkCheck_str, "%u", linkCheck);

		//copy all into one array
		char *result = malloc(strlen(command)+strlen(linkCheck_str)+3);
    	strcpy(result, command);
    	strcat(result, linkCheck_str);
    	strcat(result, "\r\n");

    	rs232_print(RS232_PORT_1, result);

    	return 1;
	}
	else
	{
		rs232_print(RS232_PORT_0, "ERROR: mac_set_linkchk: linkCheck is not between 0 and 65535.\r\n");		
		return 0;
	}
}

unsigned int mac_set_linkchk_response(char* data)
{
	if(strcmp(data,"ok"))
	{
		return 1;
	}
	else
	{
		return 0;
	}		
}

unsigned int mac_set_rxdelay1(unsigned int rxDelay)
{
	if(rxDelay >= 0 & rxDelay <= 65535)
	{
		char* command == "mac set rxdelay1 ";

		//int to char*
		char* rxDelay_str;
		sprintf(rxDelay_str, "%u", rxDelay);

		//copy all into one array
		char *result = malloc(strlen(command)+strlen(rxDelay_str)+3);
    	strcpy(result, command);
    	strcat(result, rxDelay_str);
    	strcat(result, "\r\n");

    	rs232_print(RS232_PORT_1, result);

    	return 1;
	}
	else
	{
		rs232_print(RS232_PORT_0, "ERROR: mac_set_rxdelay1: rxDelay is not between 0 and 65535.\r\n");		
		return 0;
	}
}

unsigned int mac_set_rxdelay1_response(char* data)
{
	if(strcmp(data,"ok"))
	{
		return 1;
	}
	else
	{
		return 0;
	}		
}



unsigned int mac_set_ar(unsigned int state)
{
	if(state == 0 | state == 1)
	{
		char* command == "mac set ar ";

		//int to char*
		char* state_str;
		if(state)
		{
			state_str = "on";
		}
		else
		{
			state_str = "off";
		}

		//copy all into one array
		char *result = malloc(strlen(command)+strlen(state_str)+3);
    	strcpy(result, command);
    	strcat(result, state_str);
    	strcat(result, "\r\n");

    	rs232_print(RS232_PORT_1, result);

    	return 1;
	}
	else
	{
		rs232_print(RS232_PORT_0, "ERROR: mac_set_ar: state is not 0 and 1.\r\n");		
		return 0;
	}
}

unsigned int mac_set_ar_response(char* data)
{
	if(strcmp(data,"ok"))
	{
		return 1;
	}
	else
	{
		return 0;
	}		
}

unsigned int mac_set_rx2(unsigned int dataRate, unsigned long frequency)
{
	if(dataRate >= 0 & dataRate <= 7)
	{
		if((frequency >= 863000000 & frequency <= 870000000)|(frequency >= 433050000 & frequency <= 434790000))
		{
			char* command == "mac set rx2 ";


			//int to char*
			char* dataRate_str;
			sprintf(dataRate_str, "%u", dataRate);


    		//convert ulong to string
    		const int n = snprintf(NULL, 0, "%lu", frequency);
    		assert(n > 0);
    		char fre_str[n+1];
    		int c = snprintf(fre_str, n+1, "%lu", frequency);
    		assert(fre_str[n] == '\0');
    		assert(c == n);



    		char *result = malloc(strlen(command)+strlen(len_str)+4);
    		strcpy(result, command);
    		strcat(result, dataRate_str);
    		strcat(result, " ");
    		strcat(result, fre_str);
    		strcat(result, "\r\n");

    		rs232_print(RS232_PORT_1, result);

    		return 1;
		}
		else
		{
			rs232_print(RS232_PORT_0, "ERROR: mac_set_rx2: frequency is in the two unlicensed bands.\r\n");		
			return 0;
		}
	}	
	else
	{
		rs232_print(RS232_PORT_0, "ERROR: mac_set_rx2: dataRate is not between 0 and 7.\r\n");		
		return 0;
	}
}

unsigned int mac_set_rx2_response(char* data)
{
	if(strcmp(data,"ok"))
	{
		return 1;
	}
	else
	{
		return 0;
	}		
}


















//MAC Set Channel Commands

int mac_set_ch_freq(unsigned int channelID, unsigned long frequency)
{
	if(channelID >= 3 & channelID <= 15)
	{
		if((frequency >= 863000000 & frequency <= 870000000)|(frequency >= 433050000 & frequency <= 434790000))
		{
			char* command == "mac set ch freq ";

			//TODO: convert int to char*

			PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

			// if data is ok, return 1. Else return 0.
		}
		else
		{
			//err message, return 0
		}
	}
	else
	{
		//err message, return 0
	}
}

int mac_set_ch_dcycle(unsigned int channelID, unsigned int dutyCycle)
{
	if(channelID >= 0 & channelID <= 15)
	{
		if(dutyCycle >= 0 & dutyCycle <= 65535)
		{
			char* command == "mac set ch dcycle ";

			//TODO: convert int to char*

			PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

			// if data is ok, return 1. Else return 0.
		}
		else
		{
			//err message, return 0
		}
	}
	else
	{
		//err message, return 0
	}
}

unsigned int mac_set_ch_drrange(unsigned int channelID, unsigned int minRange, unsigned int maxRange)
{
	if(channelID >= 0 & channelID <= 15)
	{
		if(minRange >= 0 & minRange <= 7)
		{
			if(maxRange >= 0 & maxRange <= 7)
			{
				if(minRange <= maxRange)
				{
					char* command == "mac set ch drrange ";

					//TODO: convert int to char*

					PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

					// if data is ok, return 1. Else return 0.
				}
				else
				{
					//err message, return 0
				}
			}
			else
			{
				//err message, return 0
			}
		}
		else
		{
			//err message, return 0
		}
	}
	else
	{
		//err message, return 0
	}
}

unsigned int mac_set_ch_status(unsigned int channelID, unsigned int status)
{
	if(channelID >= 0 & channelID <= 15)
	{
		if(status == 0 | channelID == 1)
		{
			char* command == "mac set ch status ";

			//TODO: convert int to char*

			PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

			// if data is ok, return 1. Else return 0.
		}
		else
		{

		}
	}
	else
	{

	}
}

//MAC Get Commands
char* mac_get_devaddr()
{
	rs232_print(RS232_PORT_1, "mac get devaddr\r\n");

	PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

	//return data
}

char* mac_get_deveui()
{
	rs232_print(RS232_PORT_1, "mac get deveui\r\n");

	PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

	//return data
}

char* mac_get_appeui()
{
	rs232_print(RS232_PORT_1, "mac get appeui\r\n");

	PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

	//return data
}

unsigned int mac_get_dr()
{
	rs232_print(RS232_PORT_1, "mac get dr\r\n");

	PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

	//return data
}

unsigned int mac_get_band()
{
	rs232_print(RS232_PORT_1, "mac get band\r\n");

	PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

	//return data
}

unsigned int mac_get_pwridx()
{
	rs232_print(RS232_PORT_1, "mac get pwridx\r\n");

	PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

	//return data
}

unsigned int mac_get_adr()
{
	rs232_print(RS232_PORT_1, "mac get adr\r\n");

	PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

	//convert data to 1 or 0, return it
}

unsigned int mac_get_retx()
{
	rs232_print(RS232_PORT_1, "mac get retx\r\n");

	PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

	//return data
}

unsigned int mac_get_rxdelay1()
{
	rs232_print(RS232_PORT_1, "mac get rxdelay1\r\n");

	PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

	//return data
}

unsigned int mac_get_rxdelay2()
{
	rs232_print(RS232_PORT_1, "mac get rxdelay2\r\n");

	PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

	//return data
}

unsigned int mac_get_ar()
{
	rs232_print(RS232_PORT_1, "mac get ar\r\n");

	PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

	//convert data to 1 or 0, return it
}

char* mac_get_rx2(unsigned int freqBand)
{
	if(freqBand == 868 | freqBand == 433)
	{
		char* command == "mac get rx2 ";

		//TODO: convert int to char*

		PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

		// if data is ok, return it. Else return "0".
	}
	else
	{
		//err message, return "0"
	}
	
}

unsigned int mac_get_dcycleps()
{
	rs232_print(RS232_PORT_1, "mac get dcycleps\r\n");

	PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

	//return data
}

unsigned int mac_get_mrgn()
{
	rs232_print(RS232_PORT_1, "mac get mrgn\r\n");

	PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

	//return data
}

unsigned int mac_get_gwnb()
{
	rs232_print(RS232_PORT_1, "mac get gwnb\r\n");

	PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

	//return data
}

char* mac_get_status()
{
	rs232_print(RS232_PORT_1, "mac get status\r\n");

	PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

	//return data
}

//MAC Get Channel Commands
char* mac_get_ch_freq(unsigned int channelID)
{
	if(channelID >= 0 & channelID <= 15)
	{
		char* command == "mac get ch freq ";

		//TODO: convert int to char*

		PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

		// if data is ok, return it. Else return "0".
	}
	else
	{
		//err message, return 0	
	}
}

unsigned int mac_get_ch_dcycle(unsigned int channelID)
{
	if(channelID >= 0 & channelID <= 15)
	{
		char* command == "mac get ch dcycle ";

		//TODO: convert int to char*

		PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

		// if data is ok, return it. Else return "0".
	}
	else
	{
		//err message, return 0	
	}
}

char* mac_get_ch_drrange(unsigned int channelID)
{
	if(channelID >= 0 & channelID <= 15)
	{
		char* command == "mac get ch drrange ";

		//TODO: convert int to char*

		PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

		// if data is ok, return it. Else return "0".
	}
	else
	{
		//err message, return 0	
	}
}

unsigned int mac_get_ch_status(unsigned int channelID)
{
	if(channelID >= 0 & channelID <= 15)
	{
		char* command == "mac get ch status ";

		//TODO: convert int to char*

		PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

		// if data is ok, return it. Else return "0".
	}
	else
	{
		//err message, return 0	
	}
}

//Radio Commands
void radio_rx(unsigned int rxWindowSize)
{
	if(rxWindowSize >= 0 & rxWindowSize <= 65535)
	{
		char* command == "radio rx ";

		//TODO: convert int to char*

		PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

		// note: complex, multiple responses
	}
	else
	{
		//err message, return 0
	}
}

char* radio_tx(unsigned int data)
{
	if(data >= 0 & data <= 255)
	{
		char* command == "radio tx ";

		//TODO: convert int to char*

		PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

		// note: complex, multiple responses
	}
	else
	{
		//err message, return 0
	}
}

unsigned int radio_cw(unsigned int state)
{
	if(state == 0 | state == 1)
	{
		char* command == "radio cw ";

		//TODO: convert int to char*

		PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

		// return 1 or 0
	}
	else
	{
		//err message, return 0
	}
}

//Radio Set Commands
unsigned int radio_set_bt(char* gfBT)
{
	if(gfBT == "none" | gfBT == "1.0" | gfBT == "0.5" | gfBT == "0.3")
	{
		char* command == "radio set bt ";

		

		PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

		// return 1 or 0
	}
	else
	{
		//err message, return 0
	}
}

void radio_set_mod(char* mode)
{
	if(mode == "lora" | mode == "fsk")
	{
		char* command == "radio set mod ";

		

		PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

		// return 1 or 0
	}
	else
	{
		//err message, return 0
	}
}

unsigned int radio_set_freq(unsigned long frequency)
{
	if((frequency >= 863000000 & frequency <= 870000000)|(frequency >= 433050000 & frequency <= 434790000))
	{
		char* command == "radio set freq ";

		

		PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

		// return 1 or 0
	}
	else
	{
		//err message, return 0
	}
}

void radio_set_pwr(int pwrout)
{
	if(pwrout >= -3 & pwrout <= 15)
	{
		char* command == "radio set pwr ";

		

		PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

		// return 1 or 0
	}
	else
	{
		//err message, return 0
	}
}

void radio_set_sf(char* spreadingfactor)
{
	if(spreadingfactor == "sf7" | spreadingfactor == "sf8" | spreadingfactor == "sf9" 
		| spreadingfactor == "sf10" | spreadingfactor == "sf11" | spreadingfactor == "sf12")
	{
		char* command == "radio set sf ";

		

		PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

		// return 1 or 0
	}
	else
	{
		//err message, return 0
	}
}

void radio_set_afcbw(char* autoFreqBand)
{
	if(autoFreqBand == "250" | autoFreqBand == "125" | autoFreqBand == "62.5" | autoFreqBand == "31.3" | 
		autoFreqBand == "15.6" | autoFreqBand == "7.8" | autoFreqBand == "3.9" | autoFreqBand == "200" | 
		autoFreqBand == "100" | autoFreqBand == "50" | autoFreqBand == "25" | autoFreqBand == "12.5" | 
		autoFreqBand == "6.3" | autoFreqBand == "3.1" | autoFreqBand == "166.7" | autoFreqBand == "83.3" | 
		autoFreqBand == "41.7" | autoFreqBand == "20.8" | autoFreqBand == "10.4" | autoFreqBand == "5.2" | 
		autoFreqBand == "2.6")
	{
		char* command == "radio set afcbw ";

		

		PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

		// return 1 or 0
	}
	else
	{
		//err message, return 0
	}
}

void radio_rxbw(char* rxbandwidth)
{
	if(rxbandwidth == "250" | rxbandwidth == "125" | rxbandwidth == "62.5" | rxbandwidth == "31.3" | 
		rxbandwidth == "15.6" | rxbandwidth == "7.8" | rxbandwidth == "3.9" | rxbandwidth == "200" | 
		rxbandwidth == "100" | rxbandwidth == "50" | rxbandwidth == "25" | rxbandwidth == "12.5" | 
		rxbandwidth == "6.3" | rxbandwidth == "3.1" | rxbandwidth == "166.7" | rxbandwidth == "83.3" | 
		rxbandwidth == "41.7" | rxbandwidth == "20.8" | rxbandwidth == "10.4" | rxbandwidth == "5.2" | 
		rxbandwidth == "2.6")
	{
		char* command == "radio set afcbw ";

		

		PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

		// return 1 or 0
	}
	else
	{
		//err message, return 0
	}	
}

unsigned int radio_set_bitrate(unsigned int fskBitRate)
{
	if(fskBitRate >= 0 & fskBitRate <= 65535)
	{
		char* command == "radio set afcbw ";

		

		PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

		// return 1 or 0
	}
	else
	{
		//err message, return 0
	}
}

unsigned int radio_set_fdev(unsigned int freqdev)
{
	if(freqdev >= 0 & freqdev <= 65535)
	{
		char* command == "radio set fdev ";

		

		PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

		// return 1 or 0
	}
	else
	{
		//err message, return 0
	}
}

unsigned int radio_set_prlen(unsigned int preamble)
{
	if(preamble >= 0 & preamble <= 65535)
	{
		char* command == "radio set afcbw ";

		

		PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

		// return 1 or 0
	}
	else
	{
		//err message, return 0
	}
}

unsigned int radio_set_crc(unsigned int crcHeader)
{
	if(crcHeader == 0 | crcHeader == 1)
	{
		char* command == "radio set crc ";

		

		PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

		// return 1 or 0
	}
	else
	{
		//err message, return 0
	}
}

unsigned int radio_set_iqi(unsigned int iqInvert)
{
	if(iqInvert == 0 | iqInvert == 1)
	{
		char* command == "radio set iqi ";

		

		PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

		// return 1 or 0
	}
	else
	{
		//err message, return 0
	}
}

unsigned int radio_set_cr(char* codingRate)
{
	if(codingRate == "4/5" | codingRate == "4/6" | codingRate == "4/7" | codingRate == "4/8")
	{
		char* command == "radio set cr ";

		

		PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

		// return 1 or 0
	}
	else
	{
		//err message, return 0
	}
}

unsigned int radio_set_wdt(unsigned long watchDog)
{
	if(watchDog >= 0 & watchDog <= 4294967295)
	{
		char* command == "radio set wdt ";

		

		PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

		// return 1 or 0
	}
	else
	{
		//err message, return 0
	}
}

unsigned int radio_set_sync(char* syncWord)
{
	//TODO: test syncWord is in hex format

	char* command == "radio set cr ";

		

	PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

	// return 1 or 0
}

unsigned int radio_set_bw(unsigned int bandWidth)
{
	if(bandWidth == 125 | bandWidth == 250 | bandWidth == 500)
	{
		char* command == "radio set bw ";

		PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

		// return 1 or 0
	}
	else
	{
		//err message, return 0
	}
}

//Radio Get Commands
char* radio_get_bt()
{
	rs232_print(RS232_PORT_1, "radio get bt\r\n");

	PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

	// return data
}

char* radio_get_mod()
{
	rs232_print(RS232_PORT_1, "radio get mod\r\n");

	PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

	// return data
}

unsigned long radio_get_freq()
{
	rs232_print(RS232_PORT_1, "radio get freq\r\n");

	PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

	// convert data, return it
}

int radio_get_pwr()
{
	rs232_print(RS232_PORT_1, "radio get pwr\r\n");

	PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

	// return data
}

char* radio_get_sf()
{
	rs232_print(RS232_PORT_1, "radio get sf\r\n");

	PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

	// return data
}

char* radio_get_afcbw()
{
	rs232_print(RS232_PORT_1, "radio get afcbw\r\n");

	PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

	// return data
}

char* radio_get_rxbw()
{
	rs232_print(RS232_PORT_1, "radio get rxbw\r\n");

	PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

	// return data
}

unsigned int radio_get_bitrate()
{
	rs232_print(RS232_PORT_1, "radio get bitrate\r\n");

	PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

	// return data
}

unsigned int radio_get_fdev()
{
	rs232_print(RS232_PORT_1, "radio get fdev\r\n");

	PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

	// return data
}

unsigned int radio_get_prlen()
{
	rs232_print(RS232_PORT_1, "radio get prlen\r\n");

	PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

	// return data
}

unsigned int radio_get_crc()
{
	rs232_print(RS232_PORT_1, "radio get crc\r\n");

	PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

	// return data
}

unsigned int radio_get_iqi()
{
	rs232_print(RS232_PORT_1, "radio get iqi\r\n");

	PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

	// return data
}

char* radio_get_cr()
{
	rs232_print(RS232_PORT_1, "radio get cr\r\n");

	PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

	// return data
}

unsigned long radio_get_wdt()
{
	rs232_print(RS232_PORT_1, "radio get wdt\r\n");

	PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

	// return data
}

unsigned int radio_get_bw()
{
	rs232_print(RS232_PORT_1, "radio get bw\r\n");

	PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

	// return data
}

int radio_get_snr()
{
	rs232_print(RS232_PORT_1, "radio get snr\r\n");

	PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

	// return data
}

/*---------------------------------------------------------------------------*/
PROCESS_THREAD(rn2483_handler, ev, data)
{
  	PROCESS_BEGIN();

  	while(1) 
  	{
  		 //Process wait until polled
  		PROCESS_YIELD();
  	  	
  	  	//call function mentioned in data

  	  	//process wait until ev=serial_process_1
  		PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

  	  	//process_poll/post(rn2483_controller)    
  	}

  	PROCESS_END();
}

/*---------------------------------------------------------------------------*/

PROCESS_THREAD(rn2483_handler, ev, data)
{
	PROCESS_BEGIN();


	PROCESS_END();
}