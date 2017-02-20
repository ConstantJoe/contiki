//Radio Commands
unsigned int radio_rx(unsigned int rxWindowSize)
{
	if(rxWindowSize >= 0 & rxWindowSize <= 65535)
	{
		char* command == "radio rx ";

		char* rxWindowSize_str;
		sprintf(rxWindowSize_str, "%u", rxWindowSize);

		//copy all into one array
		char *result = malloc(strlen(command)+strlen(rxWindowSize_str)+3);
    	strcpy(result, command);
    	strcat(result, rxWindowSize_str);
    	strcat(result, "\r\n");

    	rs232_print(RS232_PORT_1, result);

    	return 1;
	}
	else
	{
		rs232_print(RS232_PORT_0, "ERROR: radio_rx: rxWindowSize not between 0 and 65535.\r\n");
		return 0;
	}
}

char* radio_rx_response(char* data)
{
	//TODO: complex, one initial response and then another response.
	return data;
}

unsigned int radio_tx(char* data)
{
	if(/*length of data is between 0 and 255 bytes*/)
	{

		//TODO: above if statement, and check for FSK modulation
		char* command == "radio tx ";

		//copy all into one array
		char *result = malloc(strlen(command)+strlen(data)+3);
    	strcpy(result, command);
    	strcat(result, data);
    	strcat(result, "\r\n");

    	rs232_print(RS232_PORT_1, result);

    	return 1;
	}
	else
	{
		rs232_print(RS232_PORT_0, "ERROR: radio_tx: data payload is not between 0 and 255 bytes.\r\n");
		return 0;
	}
}

char* radio_tx_response(char* data)
{
	//TODO: complex, one initial response and then another response.
	return data;
}

unsigned int radio_cw(unsigned int state)
{
	if(state == 0 | state == 1)
	{
		char* command == "radio cw ";

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
		rs232_print(RS232_PORT_0, "ERROR: radio_cw: state not 0 or 1.\r\n");
		return 0;
	}
}

unsigned int radio_cw_response(char* data)
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