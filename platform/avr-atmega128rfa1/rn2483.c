

unsigned int sys_sleep(unsigned long length)
{

	if(length > 100)
	{
		char* command = "sys sleep ";

		//TODO: generate len_str
		//see http://stackoverflow.com/questions/2709713/how-to-convert-unsigned-long-to-string

		char *result = malloc(strlen(command)+strlen(len_str)+1);
		strcpy(result, command);
		strcat(result, len_str);
		rs232_print(RS232_PORT_1, result);

		PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1)


		//TODO: if "ok", return 1. Else return 0.
	}
	else
	{

		//TODO: Print err message, and return 0.
	}
}

char* sys_reset()
{
	rs232_print(RS232_PORT_1, "sys reset\r\n");

	PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1)

	return (char *)data; //use of ev and data not as simple as this. But this is basically the idea.
}

void sys_eraseFW()
{
	rs232_print(RS232_PORT_1, "sys eraseFW\r\n");
}

void sys_factoryRESET()
{
	rs232_print(RS232_PORT_1, "sys factoryRESET\r\n");

	PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1)

	return (char *)data; //use of ev and data not as simple as this. But this is basically the idea.
}

//System Set Commands

/*Modify EEPROM at address to data. Both address and data must be inputted as hex values
	Can modify addresses from 300 to 3FF.
*/
int sys_set_nvm(unsigned int address, unsigned char data)
{
	if(address >= 0x300 && address <= 0x3FF)
	{
		if(data >= 0x00 && <= 0xFF)
		{
			char* command = "sys set nvm ";

			//TODO: address to char* (hex version)

			//TODO: data to char* (hex version)

			PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1)

			//if "ok", return 1.
			//else return 0
		}
		else
		{
			//print err message, return 0.
		}
	}
	else
	{
		//print err message, return 0.
	}
}

/*Modify unused pins on the module
Pinname can be GPIO0-GPIO14, UART_CTS, UART_RTS, TEST0, TEST1
Pinstate can be 0 or 1.
*/
int sys_set_pindig(char* pinname, int pinstate)
{
	if(pinname == "GPIO0" | pinname == "GPIO1" | pinname == "GPIO2" | pinname == "GPIO3" | pinname == "GPIO4" 
		| pinname == "GPIO5" | pinname == "GPIO6" | pinname == "GPIO7" | pinname == "GPIO8" | pinname == "GPIO9"
		| pinname == "GPIO10" | pinname == "GPIO11" | pinname == "GPIO12" | pinname == "GPIO13" | pinname == "GPIO14"
		| pinname == "UART_CTS" | pinname == "UART_RTS" | pinname == "TEST0" | pinname == "TEST1")
	{
		if(pinstate == 0 | pinstate == 1)
		{
			char* command = "sys set pindig ";

			//TODO: pinstate to char*

			PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

			//if "ok", return 1.
			//else return 0
		}
		else
		{
			//print err message, return 0.
		}
	}
	else
	{
		//print err message, return 0.
	}
}

//System Get Commands

char* sys_get_ver()
{
	rs232_print(RS232_PORT_1, "sys get ver\r\n");

	PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1)

	return (char *)data; 
}

unsigned char sys_get_nvm(int address)
{
	if(address >= 0x300 && address <= 0x3FF)
	{
		char* command = "sys get nvm ";

		//TODO: address to char*

		PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

		//TODO: data to unsigned int.

	}
	else
	{
		//print err message, return 0.
	}
}

unsigned int sys_get_vdd()
{
	rs232_print(RS232_PORT_1, "sys get vdd\r\n");

	PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

	//TODO: data to unsigned int
}

void sys_get_hweui()
{
	rs232_print(RS232_PORT_1, "sys get hweui\r\n");

	PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

	return (char *)data; 
}

//MAC Commands

/*band can be 868 or 433*/
int mac_reset(int band)
{
	if(band == 433 | band == 868)
	{
		char* command = "mac reset ";
		
		//TODO: int to char*

		PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

		//TODO: if "ok", return 1. Else return 0.
	}
	else
	{
		//print err message, return 0.
	}
}

void mac_tx(char* type, unsigned int portno, char* data)
{
	if(type == "cnf" | "uncnf")
	{
		if(portno >= 1 && <= 223)
		{
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

int mac_save()
{
	rs232_print(RS232_PORT_1, "mac save\r\n");

	PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

	// if data is ok, return 1. Else return 0.
}

void mac_forceENABLE()
{
	rs232_print(RS232_PORT_1, "mac forceENABLE\r\n");

	PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

	// if data is ok, return 1. Else return 0.
}

unsigned int mac_pause()
{
	rs232_print(RS232_PORT_1, "mac pause\r\n");

	PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

	// convert data to unsigned int, return it.
}

int mac_resume()
{
	rs232_print(RS232_PORT_1, "mac resume\r\n");

	PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

	// if data is ok, return 1. Else return 0.
}

//MAC Set Commands

int mac_set_devaddr(unsigned int address)
{
	char* command == "mac set devaddr ";
	//TODO: convert unsigned int to char*

	PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

	// if data is ok, return 1. Else return 0.
}

int mac_set_deveui(char* deveui)
{
	//TODO: check if string is in hex format, correct length

	char* command == "mac set deveui ";

	//TODO: concat char*s, send off

	PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

	// if data is ok, return 1. Else return 0.
}

int mac_set_appeui(char* appeui)
{
	//TODO: check if string is in hex format, correct length

	char* command == "mac set appeui ";

	//TODO: concat char*s, send off

	PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

	// if data is ok, return 1. Else return 0.
}

int mac_set_nwkskey(char* nwksesskey)
{
	//TODO: check if string is in hex format, correct length

	char* command == "mac set nwkskey ";

	//TODO: concat char*s, send off

	PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

	// if data is ok, return 1. Else return 0.
}

int mac_set_appskey(char* appSesskey)
{
	//TODO: check if string is in hex format, correct length

	char* command == "mac set appskey ";

	//TODO: concat char*s, send off

	PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

	// if data is ok, return 1. Else return 0.
}

int mac_set_appkey(char* appkey)
{
	//TODO: check if string is in hex format, correct length

	char* command == "mac set appkey ";

	//TODO: concat char*s, send off

	PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

	// if data is ok, return 1. Else return 0.
}

void mac_set_pwridx(int pwrIndex)
{
	//TODO: check if string is in hex format, correct length

	if(pwrIndex >=0 && pwrIndex <= 5)
	{
		char* command == "mac set pwridx ";

		//TODO: convert int to char*

		PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

		// if data is ok, return 1. Else return 0.
	}
	else
	{

	}
}

int mac_set_dr(unsigned int dataRate)
{
	if(dataRate >= 0 && dataRate <= 7)
	{
		char* command == "mac set dr ";

		//TODO: convert int to char*

		PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

		// if data is ok, return 1. Else return 0.			
	}
	else
	{
		//err message, return 0.
	}
}

int mac_set_adr(int state)
{
	if(state == 1 | state == 0)
	{
		char* command == "mac set adr ";

		//TODO: convert int to char*

		PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

		// if data is ok, return 1. Else return 0.
	}
	else
	{
		//err message, return 0
	}
}

int mac_set_bat(unsigned int level)
{
	if(level >= 0 && level <= 255)
	{
		char* command == "mac set bat ";

		//TODO: convert int to char*

		PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

		// if data is ok, return 1. Else return 0.
	}
	else
	{
		//err message, return 0
	}
}

int mac_set_retx(unsigned int reTxNb)
{
	if(reTxNb >= 0 && reTxNb <= 255)
	{
		char* command == "mac set retx ";

		//TODO: convert int to char*

		PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

		// if data is ok, return 1. Else return 0.
	}
	else
	{
		//err message, return 0
	}
}

int mac_set_linkchk(unsigned int linkCheck)
{
	if(linkCheck >= 0 && linkCheck <= 65535)
	{
		char* command == "mac set linkchk ";

		//TODO: convert int to char*

		PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

		// if data is ok, return 1. Else return 0.
	}
	else
	{
		//err message, return 0
	}
}

int mac_set_rxdelay1(unsigned int rxDelay)
{
	if(rxDelay >= 0 & rxDelay <= 65535)
	{
		char* command == "mac set rxdelay1 ";

		//TODO: convert int to char*

		PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

		// if data is ok, return 1. Else return 0.
	}
	else
	{
		//err message, return 0
	}
}

int mac_set_ar(unsigned int state)
{
	if(state == 0 | state == 1)
	{
		char* command == "mac set ar ";

		//TODO: convert int to char*

		PROCESS_WAIT_EVENT_UNTIL(ev == serial_line_event_message_1);

		// if data is ok, return 1. Else return 0.
	}
	else
	{
		//err message, return 0
	}
}

int mac_set_rx2(unsigned int dataRate, unsigned long frequency)
{
	if(dataRate >= 0 & dataRate <= 7)
	{
		if((frequency >= 863000000 & frequency <= 870000000)|(frequency >= 433050000 & frequency <= 434790000))
		{
			char* command == "mac set rx2 ";

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