#include "rn2483_radio_set.h"

//Radio Set Commands
unsigned int radio_set_bt(char* gfBT)
{
	if(strcmp(gfBT,"none") | strcmp(gfBT,"1.0") | strcmp(gfBT,"0.5") | strcmp(gfBT,"0.3"))
	{
		char* command == "radio set bt ";

		char *result = malloc(strlen(command)+strlen(gfBT)+3);
    	strcpy(result, command);
    	strcat(result, gfBT);
    	strcat(result, "\r\n");

    	rs232_print(RS232_PORT_1, result);

    	return 1;
	}
	else
	{
		rs232_print(RS232_PORT_0, "ERROR: radio_set_bt: gfBT is not none, 1.0, 0.5, or 0.3.\r\n");
		return 0;
	}
}

unsigned int radio_set_bt_response(char* data)
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

unsigned int radio_set_mod(char* mode)
{
	if(strcmp(mode,"lora") | strcmp(mode,"fsk"))
	{
		char* command == "radio set mod ";

		char *result = malloc(strlen(command)+strlen(mode)+3);
    	strcpy(result, command);
    	strcat(result, mode);
    	strcat(result, "\r\n");

    	rs232_print(RS232_PORT_1, result);

    	return 1;
	}
	else
	{
		rs232_print(RS232_PORT_0, "ERROR: radio_set_mod: mode is not lora or fsk.\r\n");
		return 0;
	}
}

unsigned int radio_set_mod_response(char* data)
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

unsigned int radio_set_freq(unsigned long frequency)
{
	if((frequency >= 863000000 & frequency <= 870000000)|(frequency >= 433050000 & frequency <= 434790000))
	{
		char* command == "radio set freq ";

		//convert ulong to string
    	const int n = snprintf(NULL, 0, "%lu", frequency);
    	assert(n > 0);
    	char fre_str[n+1];
    	int c = snprintf(fre_str, n+1, "%lu", frequency);
   	 	assert(fre_str[n] == '\0');
    	assert(c == n);

    	char *result = malloc(strlen(command)+strlen(fre_str)+3);
    	strcpy(result, command);
    	strcat(result, fre_str);
    	strcat(result, "\r\n");

    	rs232_print(RS232_PORT_1, result);

    	return 1;
	}
	else
	{
		rs232_print(RS232_PORT_0, "ERROR: radio_set_freq: chosen frequency is not in the unlicenced bands.\r\n");
		return 0;
	}
}

unsigned int radio_set_freq_response(char* data)
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

unsigned int radio_set_pwr(int pwrout)
{
	if(pwrout >= -3 & pwrout <= 15)
	{
		char* command == "radio set pwr ";

		char* pwrout_str;
		sprintf(pwrout_str, "%d", pwrout);

		//copy all into one array
		char *result = malloc(strlen(command)+strlen(pwrout_str)+3);
    	strcpy(result, command);
    	strcat(result, pwrout_str);
    	strcat(result, "\r\n");

    	rs232_print(RS232_PORT_1, result);

    	return 1;
	}
	else
	{
		rs232_print(RS232_PORT_0, "ERROR: radio_set_pwr: pwrout is not between -3 and 15.\r\n");
		return 0;
	}
}

unsigned int radio_set_pwr_response(char* data)
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

unsigned int radio_set_sf(char* spreadingfactor)
{
	if(strcmp(spreadingfactor,"sf7") | strcmp(spreadingfactor,"sf8") | strcmp(spreadingfactor,"sf9")
	| strcmp(spreadingfactor,"sf10")| strcmp(spreadingfactor,"sf11")| strcmp(spreadingfactor,"sf12"))
	{
		char* command == "radio set sf ";

		char *result = malloc(strlen(command)+strlen(spreadingfactor)+3);
    	strcpy(result, command);
    	strcat(result, spreadingfactor);
    	strcat(result, "\r\n");

    	rs232_print(RS232_PORT_1, result);

    	return 1;
	}
	else
	{
		rs232_print(RS232_PORT_0, "ERROR: radio_set_sf: spreadfactor inputed incorrectly.\r\n");
		return 0;
	}
}

unsigned int radio_set_sf_response(char* data)
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

unsigned int radio_set_afcbw(char* autoFreqBand)
{
	if(strcmp(autoFreqBand,"250") | strcmp(autoFreqBand,"125") | strcmp(autoFreqBand,"62.5") | strcmp(autoFreqBand,"31.3") | 
		strcmp(autoFreqBand,"15.6") | strcmp(autoFreqBand,"7.8") | strcmp(autoFreqBand,"3.9") | strcmp(autoFreqBand,"200") | 
		strcmp(autoFreqBand,"100") | strcmp(autoFreqBand,"50") | strcmp(autoFreqBand,"25") | strcmp(autoFreqBand,"12.5") | 
		strcmp(autoFreqBand,"6.3") | strcmp(autoFreqBand,"3.1") | strcmp(autoFreqBand,"166.7") | strcmp(autoFreqBand,"83.3") | 
		strcmp(autoFreqBand,"41.7") | strcmp(autoFreqBand,"20.8") | strcmp(autoFreqBand,"10.4") | strcmp(autoFreqBand,"5.2") | 
		strcmp(autoFreqBand,"2.6"))
	{
		char* command == "radio set afcbw ";

		char *result = malloc(strlen(command)+strlen(autoFreqBand)+3);
    	strcpy(result, command);
    	strcat(result, autoFreqBand);
    	strcat(result, "\r\n");

    	rs232_print(RS232_PORT_1, result);

    	return 1;
	}
	else
	{
		rs232_print(RS232_PORT_0, "ERROR: radio_set_afcbw: autoFreqBand inputed incorrectly.\r\n");
		return 0;
	}
}

unsigned int radio_set_afcbw_response(char* data)
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

unsigned int radio_set_rxbw(char* rxbandwidth)
{
	if(strcmp(rxbandwidth,"250") | strcmp(rxbandwidth,"125") | strcmp(rxbandwidth,"62.5") | strcmp(rxbandwidth,"31.3") | 
		strcmp(rxbandwidth,"15.6") | strcmp(rxbandwidth,"7.8") | strcmp(rxbandwidth,"3.9") | strcmp(rxbandwidth,"200") | 
		strcmp(rxbandwidth,"100") | strcmp(rxbandwidth,"50") | strcmp(rxbandwidth,"25") | strcmp(rxbandwidth,"12.5") | 
		strcmp(rxbandwidth,"6.3") | strcmp(rxbandwidth,"3.1") | strcmp(rxbandwidth,"166.7") | strcmp(rxbandwidth,"83.3") | 
		strcmp(rxbandwidth,"41.7") | strcmp(rxbandwidth,"20.8") | strcmp(rxbandwidth,"10.4") | strcmp(rxbandwidth,"5.2") | 
		strcmp(rxbandwidth,"2.6"))
	{
		char* command == "radio set afcbw ";

		char *result = malloc(strlen(command)+strlen(rxbandwidth)+3);
    	strcpy(result, command);
    	strcat(result, rxbandwidth);
    	strcat(result, "\r\n");

    	rs232_print(RS232_PORT_1, result);

    	return 1;
	}
	else
	{
		rs232_print(RS232_PORT_0, "ERROR: radio_set_rxbw: rxbandwidth inputed incorrectly.\r\n");
		return 0;
	}	
}

unsigned int radio_set_rxbw_response(char* data)
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

unsigned int radio_set_bitrate(unsigned int fskBitRate)
{
	if(fskBitRate >= 0 & fskBitRate <= 65535)
	{
		char* command == "radio set bitrate ";

		char* fskBitRate_str;
		sprintf(fskBitRate_str, "%u", fskBitRate);

		//copy all into one array
		char *result = malloc(strlen(command)+strlen(fskBitRate_str)+3);
    	strcpy(result, command);
    	strcat(result, fskBitRate_str);
    	strcat(result, "\r\n");

    	rs232_print(RS232_PORT_1, result);

    	return 1;
	}
	else
	{
		rs232_print(RS232_PORT_0, "ERROR: radio_set_bitrate: bitrate chosen not between 0 and 65535.\r\n");
		return 0;
	}
}

unsigned int radio_set_bitrate_response(char* data)
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

unsigned int radio_set_fdev(unsigned int freqdev)
{
	if(freqdev >= 0 & freqdev <= 65535)
	{
		char* command == "radio set fdev ";

		char* freqdev_str;
		sprintf(freqdev_str, "%u", freqdev);

		//copy all into one array
		char *result = malloc(strlen(command)+strlen(freqdev_str)+3);
    	strcpy(result, command);
    	strcat(result, freqdev_str);
    	strcat(result, "\r\n");

    	rs232_print(RS232_PORT_1, result);

    	return 1;
	}
	else
	{
		rs232_print(RS232_PORT_0, "ERROR: radio_set_fdev: freqdev chosen not between 0 and 65535.\r\n");
		return 0;
	}
}

unsigned int radio_set_fdev_response(char* data)
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

unsigned int radio_set_prlen(unsigned int preamble)
{
	if(preamble >= 0 & preamble <= 65535)
	{
		char* command == "radio set afcbw ";

		char* preamble_str;
		sprintf(preamble_str, "%u", preamble);

		//copy all into one array
		char *result = malloc(strlen(command)+strlen(preamble_str)+3);
    	strcpy(result, command);
    	strcat(result, preamble_str);
    	strcat(result, "\r\n");

    	rs232_print(RS232_PORT_1, result);

    	return 1;
	}
	else
	{
		rs232_print(RS232_PORT_0, "ERROR: radio_set_prlen: preamble chosen not between 0 and 65535.\r\n");
		return 0;
	}
}

unsigned int radio_set_prlen_response(char* data)
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

unsigned int radio_set_crc(unsigned int crcHeader)
{
	if(crcHeader == 0 | crcHeader == 1)
	{
		char* command == "radio set crc ";

		char* crcHeader_str;
		if(crcHeader)
		{
			crcHeader_str = "on";
		}
		else
		{
			crcHeader_str = "off";
		}
		

		//copy all into one array
		char *result = malloc(strlen(command)+strlen(crcHeader_str)+3);
    	strcpy(result, command);
    	strcat(result, crcHeader_str);
    	strcat(result, "\r\n");

    	rs232_print(RS232_PORT_1, result);

    	return 1;
	}
	else
	{
		rs232_print(RS232_PORT_0, "ERROR: radio_set_crc: crcHeader chosen not 0 or 1.\r\n");
		return 0;
	}
}

unsigned int radio_set_crc_response(char* data)
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

unsigned int radio_set_iqi(unsigned int iqInvert)
{
	if(iqInvert == 0 | iqInvert == 1)
	{
		char* command == "radio set iqi ";

		char* iqInvert_str;
		if(iqInvert)
		{
			iqInvert_str = "on";
		}
		else
		{
			iqInvert_str = "off";
		}
		

		//copy all into one array
		char *result = malloc(strlen(command)+strlen(iqInvert_str)+3);
    	strcpy(result, command);
    	strcat(result, iqInvert_str);
    	strcat(result, "\r\n");

    	rs232_print(RS232_PORT_1, result);

    	return 1;
	}
	else
	{
		rs232_print(RS232_PORT_0, "ERROR: radio_set_iqi: iqInvert chosen not 0 or 1.\r\n");
		return 0;
	}
}

unsigned int radio_set_iqi_response(char* data)
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

unsigned int radio_set_cr(char* codingRate)
{
	if(strcmp(codingRate,"4/5") | strcmp(codingRate,"4/6") | strcmp(codingRate,"4/7") | strcmp(codingRate,"4/8"))
	{
		char* command == "radio set cr ";

		//copy all into one array
		char *result = malloc(strlen(command)+strlen(codingRate)+3);
    	strcpy(result, command);
    	strcat(result, codingRate);
    	strcat(result, "\r\n");

    	rs232_print(RS232_PORT_1, result);

    	return 1;
	}
	else
	{
		rs232_print(RS232_PORT_0, "ERROR: radio_set_cr: coding rate chosen not in correct format.\r\n");
		return 0;
	}
}

unsigned int radio_set_cr_response(char* data)
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

unsigned int radio_set_wdt(unsigned long watchDog)
{
	if(watchDog >= 0 & watchDog <= 4294967295)
	{
    	//convert ulong to string
    	const int n = snprintf(NULL, 0, "%lu", watchDog);
    	assert(n > 0);
    	char len_str[n+1];
    	int c = snprintf(len_str, n+1, "%lu", watchDog);
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
		rs232_print(RS232_PORT_0, "ERROR: radio_set_wdt: watchDog timeout length not between 0 and 4294967295.\r\n");
		return 0;
	}
}

unsigned int radio_set_wdt_response(char* data)
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

unsigned int radio_set_sync(char* syncWord)
{
	//TODO: test syncWord is in hex format

	char* command == "radio set cr ";

	char *result = malloc(strlen(command)+strlen(syncWord)+3);
    strcpy(result, command);
    strcat(result, syncWord);
    strcat(result, "\r\n");

    rs232_print(RS232_PORT_1, result);

    return 1;
}

unsigned int radio_set_sync_response(char* data)
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

unsigned int radio_set_bw(unsigned int bandWidth)
{
	if(bandWidth == 125 | bandWidth == 250 | bandWidth == 500)
	{
		char* command == "radio set bw ";

		char* bandWidth_str;
		sprintf(bandWidth_str, "%u", bandWidth);

		//copy all into one array
		char *result = malloc(strlen(command)+strlen(bandWidth_str)+3);
    	strcpy(result, command);
    	strcat(result, bandWidth_str);
    	strcat(result, "\r\n");

    	rs232_print(RS232_PORT_1, result);

    	return 1;
	}
	else
	{
		rs232_print(RS232_PORT_0, "ERROR: radio_set_bw: bandwith chosen not 125, 250, or 500.\r\n");
		return 0;
	}
}

unsigned int radio_set_bw_response(char* data)
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