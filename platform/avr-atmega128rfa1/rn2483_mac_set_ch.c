#include "rn2483_mac_set_ch.h"

//MAC Set Channel Commands

unsigned int mac_set_ch_freq(unsigned int channelID, unsigned long frequency)
{
	if(channelID >= 3 & channelID <= 15)
	{
		if((frequency >= 863000000 & frequency <= 870000000)|(frequency >= 433050000 & frequency <= 434790000))
		{
			char* command == "mac set ch freq ";

			//int to char*
			char* channelID_str;
			sprintf(channelID_str, "%u", channelID);


    		//convert ulong to string
    		const int n = snprintf(NULL, 0, "%lu", frequency);
    		assert(n > 0);
    		char fre_str[n+1];
    		int c = snprintf(fre_str, n+1, "%lu", frequency);
    		assert(fre_str[n] == '\0');
    		assert(c == n);



    		char *result = malloc(strlen(command)+strlen(len_str)+4);
    		strcpy(result, command);
    		strcat(result, channelID_str);
    		strcat(result, " ");
    		strcat(result, fre_str);
    		strcat(result, "\r\n");

    		rs232_print(RS232_PORT_1, result);

    		return 1;
		}
		else
		{
			rs232_print(RS232_PORT_0, "ERROR: mac_set_ch_freq: frequency is not in the two unlicensed bands.\r\n");		
			return 0;
		}
	}
	else
	{
		rs232_print(RS232_PORT_0, "ERROR: mac_set_ch_freq: ChannelID is not between 3 and 15.\r\n");		
		return 0;
	}
}

unsigned int mac_set_ch_freq_response(char* data)
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



unsigned int mac_set_ch_dcycle(unsigned int channelID, unsigned int dutyCycle)
{
	if(channelID >= 0 & channelID <= 15)
	{
		if(dutyCycle >= 0 & dutyCycle <= 65535)
		{
			char* command == "mac set ch dcycle ";

			//int to char*
			char* channelID_str;
			sprintf(channelID_str, "%u", channelID);

			char* dutyCycle_str;
			sprintf(dutyCycle_str, "%u", dutyCycle);

    		char *result = malloc(strlen(command)+strlen(len_str)+4);
    		strcpy(result, command);
    		strcat(result, channelID_str);
    		strcat(result, " ");
    		strcat(result, dutyCycle_str);
    		strcat(result, "\r\n");

    		rs232_print(RS232_PORT_1, result);

    		return 1;
		}
		else
		{
			rs232_print(RS232_PORT_0, "ERROR: mac_set_ch_dcycle: dutyCycle is not between 0 and 65535.\r\n");		
			return 0;
		}
	}
	else
	{
		rs232_print(RS232_PORT_0, "ERROR: mac_set_ch_dcycle: ChannelID is not between 0 and 15.\r\n");		
		return 0;
	}
}

unsigned int mac_set_ch_dcycle_response(char* data)
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

					//int to char*
					char* channelID_str;
					sprintf(channelID_str, "%u", channelID);

					char* minRange_str;
					sprintf(minRange_str, "%u", minRange);

					char* maxRange_str;
					sprintf(maxRange_str, "%u", maxRange);

    				char *result = malloc(strlen(command)+strlen(len_str)+5);
    				strcpy(result, command);
    				strcat(result, channelID_str);
    				strcat(result, " ");
    				strcat(result, minRange_str);
    				strcat(result, " ");
    				strcat(result, maxRange_str);
    				strcat(result, "\r\n");

    				rs232_print(RS232_PORT_1, result);

    				return 1;
				}
				else
				{
					rs232_print(RS232_PORT_0, "ERROR: mac_set_ch_dcycle: minRange is greater than maxRange.\r\n");		
					return 0;
				}
			}
			else
			{
				rs232_print(RS232_PORT_0, "ERROR: mac_set_ch_drrange: maxRange is not between 0 and 7.\r\n");		
				return 0;
			}
		}
		else
		{
			rs232_print(RS232_PORT_0, "ERROR: mac_set_ch_drrange: minRange is not between 0 and 7.\r\n");		
			return 0;
		}
	}
	else
	{
		rs232_print(RS232_PORT_0, "ERROR: mac_set_ch_drrange: ChannelID is not between 0 and 15.\r\n");		
		return 0;
	}
}

unsigned int mac_set_ch_drrange_response(char* data)
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

unsigned int mac_set_ch_status(unsigned int channelID, unsigned int status)
{
	if(channelID >= 0 & channelID <= 15)
	{
		if(status == 0 | status == 1)
		{
			char* command == "mac set ch status ";

			char* channelID_str;
			sprintf(channelID_str, "%u", channelID);

			char* status_str;
			if(status)
			{
				status_str = "on";
			}
			else
			{
				status_str = "off";
			}

    		char *result = malloc(strlen(command)+strlen(channelID_str)+strlen(status_str)+4);
    		strcpy(result, command);
    		strcat(result, channelID_str);
    		strcat(result, " ");
    		strcat(result, status_str);
    		strcat(result, "\r\n");

    		rs232_print(RS232_PORT_1, result);
		}
		else
		{
			rs232_print(RS232_PORT_0, "ERROR: mac_set_ch_status: status is not 0 or 1.\r\n");		
			return 0;
		}
	}
	else
	{
		rs232_print(RS232_PORT_0, "ERROR: mac_set_ch_status: ChannelID is not between 0 and 15.\r\n");		
		return 0;
	}
}

unsigned int mac_set_ch_status_response(char* data)
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