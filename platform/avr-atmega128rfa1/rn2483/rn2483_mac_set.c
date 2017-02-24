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

unsigned int mac_set_nwkskey_response(char* data)
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

unsigned int mac_set_appskey_response(char* data)
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
			rs232_print(RS232_PORT_0, "ERROR: mac_set_rx2: frequency is not in the two unlicensed bands.\r\n");		
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