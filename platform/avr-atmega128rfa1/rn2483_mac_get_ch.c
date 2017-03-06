#include "rn2483.h"

//MAC Get Channel Commands
unsigned int mac_get_ch_freq(unsigned int channelID)
{
	if((channelID >= 0) & (channelID <= 15))
	{
		char* command = "mac get ch freq ";

		char* channelID_str = malloc(nDigits(channelID));
		sprintf(channelID_str, "%u", channelID);

		//copy all into one array
		char *result = malloc(strlen(command)+strlen(channelID_str)+3);
    	strcpy(result, command);
    	strcat(result, channelID_str);
    	strcat(result, "\r\n");

    	rs232_print(RS232_PORT_1, result);

    	return 1;
	}
	else
	{
		rs232_print(RS232_PORT_0, "ERROR: mac_get_ch_freq: channelID not between 0 and 15.\r\n");
		return 0;
	}
}

char* mac_get_ch_freq_response(char* data)
{
	//TODO: have to return an unsigned long
	return data;
}

unsigned int mac_get_ch_dcycle(unsigned int channelID)
{
	if((channelID >= 0) & (channelID <= 15))
	{
		char* command = "mac get ch dcycle ";

		char* channelID_str = malloc(nDigits(channelID));
		sprintf(channelID_str, "%u", channelID);

		//copy all into one array
		char *result = malloc(strlen(command)+strlen(channelID_str)+3);
    	strcpy(result, command);
    	strcat(result, channelID_str);
    	strcat(result, "\r\n");

    	rs232_print(RS232_PORT_1, result);

    	return 1;
	}
	else
	{
		rs232_print(RS232_PORT_0, "ERROR: mac_get_ch_dcycle: channelID not between 0 and 15.\r\n");
		return 0;
	}
}

unsigned int mac_get_ch_dcycle_response(char* data)
{
	return (unsigned int *)strtoull(data, NULL, 0);
}

unsigned int mac_get_ch_drrange(unsigned int channelID)
{
	if((channelID >= 0) & (channelID <= 15))
	{
		char* command = "mac get ch drrange ";

		char* channelID_str = malloc(nDigits(channelID));
		sprintf(channelID_str, "%u", channelID);

		//copy all into one array
		char *result = malloc(strlen(command)+strlen(channelID_str)+3);
    	strcpy(result, command);
    	strcat(result, channelID_str);
    	strcat(result, "\r\n");

    	rs232_print(RS232_PORT_1, result);

    	return 1;
	}
	else
	{
		rs232_print(RS232_PORT_0, "ERROR: mac_get_ch_drrange: channelID not between 0 and 15.\r\n");
		return 0;
	}
}

char* mac_get_ch_drrange_response(char* data)
{
	//TODO: complex, returns min and max range
	return data;
}

unsigned int mac_get_ch_status(unsigned int channelID)
{
	if((channelID >= 0) & (channelID <= 15))
	{
		char* command = "mac get ch status ";

		char* channelID_str = malloc(nDigits(channelID));
		sprintf(channelID_str, "%u", channelID);

		//copy all into one array
		char *result = malloc(strlen(command)+strlen(channelID_str)+3);
    	strcpy(result, command);
    	strcat(result, channelID_str);
    	strcat(result, "\r\n");

    	rs232_print(RS232_PORT_1, result);

    	return 1;
	}
	else
	{
		rs232_print(RS232_PORT_0, "ERROR: mac_get_ch_status: channelID not between 0 and 15.\r\n");
		return 0;
	}
}

unsigned int mac_get_ch_status_response(char* data)
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