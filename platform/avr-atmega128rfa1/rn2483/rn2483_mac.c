
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

unsigned int mac_resume_response(char* data)
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