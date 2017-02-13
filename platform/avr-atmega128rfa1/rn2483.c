

int sys_sleep(unsigned long length)
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

void mac_set_dr(int dataRate)
{
	
}

void mac_set_adr(char* state)
{

}

void mac_set_bat(int level)
{

}

void mac_set_retx(int reTxNb)
{

}

void mac_set_linkchk(int linkCheck)
{

}

void mac_set_rxdelay1(int rxDelay)
{

}

void mac_set_ar(int state)
{

}

void mac_set_rx2(int dataRate, long frequency)
{

}

void mac_set_ch_freq(int channelID, long frequency)
{

}

void mac_set_ch_dcycle(int channelID, int dutyCycle)
{

}

void mac_set_ch_drrange(int channelID, int minRange, int maxRange)
{

}

void mac_set_ch_status(int channelID, int status)
{

}

//MAC Get Commands
void mac_get_devaddr()
{
	rs232_print(RS232_PORT_1, "mac get devaddr\r\n");
}

void mac_get_deveui()
{
	rs232_print(RS232_PORT_1, "mac get deveui\r\n");
}

void mac_get_appeui()
{
	rs232_print(RS232_PORT_1, "mac get appeui\r\n");
}

void mac_get_dr()
{
	rs232_print(RS232_PORT_1, "mac get dr\r\n");
}

void mac_get_band()
{
	rs232_print(RS232_PORT_1, "mac get band\r\n");
}

void mac_get_pwridx()
{
	rs232_print(RS232_PORT_1, "mac get pwridx\r\n");
}

void mac_get_adr()
{
	rs232_print(RS232_PORT_1, "mac get adr\r\n");
}

void mac_get_retx()
{
	rs232_print(RS232_PORT_1, "mac get retx\r\n");
}

void mac_get_rxdelay1()
{
	rs232_print(RS232_PORT_1, "mac get rxdelay1\r\n");
}

void mac_get_rxdelay2()
{
	rs232_print(RS232_PORT_1, "mac get rxdelay2\r\n");
}

void mac_get_ar()
{
	rs232_print(RS232_PORT_1, "mac get ar\r\n");
}

void mac_get_rx2()
{
	rs232_print(RS232_PORT_1, "mac get rx2\r\n");
}

void mac_get_dcycleps()
{
	rs232_print(RS232_PORT_1, "mac get dcycleps\r\n");
}

void mac_get_mrgn()
{
	rs232_print(RS232_PORT_1, "mac get mrgn\r\n");
}

void mac_get_gwnb()
{
	rs232_print(RS232_PORT_1, "mac get gwnb\r\n");
}

void mac_get_status()
{
	rs232_print(RS232_PORT_1, "mac get status\r\n");
}

//MAC Get Channel Commands
void mac_get_ch_freq(int channelID)
{

}

void mac_get_ch_dcycle(int channelID)
{

}

void mac_get_ch_drrange(int channelID)
{

}

void mac_get_ch_status(int channelID)
{

}

//Radio Commands
void radio_rx(int rxWindowSize)
{

}

void radio_tx(int data)
{

}

void radio_cw(int state)
{

}

//Radio Set Commands
void radio_set_bt(char* gfBT)
{

}

void radio_set_mod(char* mode)
{

}

void radio_set_freq(long frequency)
{

}

void radio_set_pwr(int pwrout)
{

}

void radio_set_sf(char* spreadingfactor)
{

}

void radio_set_afcbw(char* autoFreqBand)
{

}

void radio_rxbw(char* rxbandwidth)
{

}

void radio_set_bitrate(int fskBitRate)
{

}

void radio_set_fdev(int freqdev)
{

}

void radio_set_prlen(int preamble)
{

}

void radio_set_crc(int crcHeader)
{

}

void radio_set_iqi(int iqInvert)
{

}

void radio_set_cr(char* codingRate)
{

}

void radio_set_wdt(long watchDog)
{

}

void radio_set_sync(int syncWord)
{

}

void radio_set_bw(int bandWidth)
{

}

//Radio Get Commands
void radio_get_bt()
{
	rs232_print(RS232_PORT_1, "radio get bt\r\n");
}

void radio_get_mod()
{
	rs232_print(RS232_PORT_1, "radio get mod\r\n");
}

void radio_get_freq()
{
	rs232_print(RS232_PORT_1, "radio get freq\r\n");
}

void radio_get_pwr()
{
	rs232_print(RS232_PORT_1, "radio get pwr\r\n");
}

void radio_get_sf()
{
	rs232_print(RS232_PORT_1, "radio get sf\r\n");
}

void radio_get_afcbw()
{
	rs232_print(RS232_PORT_1, "radio get afcbw\r\n");
}

void radio_get_rxbw()
{
	rs232_print(RS232_PORT_1, "radio get rxbw\r\n");
}

void radio_get_bitrate()
{
	rs232_print(RS232_PORT_1, "radio get bitrate\r\n");
}

void radio_get_fdev()
{
	rs232_print(RS232_PORT_1, "radio get fdev\r\n");
}

void radio_get_prlen()
{
	rs232_print(RS232_PORT_1, "radio get prlen\r\n");
}

void radio_get_crc()
{
	rs232_print(RS232_PORT_1, "radio get crc\r\n");
}

void radio_get_iqi()
{
	rs232_print(RS232_PORT_1, "radio get iqi\r\n");
}

void radio_get_cr()
{
	rs232_print(RS232_PORT_1, "radio get cr\r\n");
}

void radio_get_wdt()
{
	rs232_print(RS232_PORT_1, "radio get wdt\r\n");
}

void radio_get_bw()
{
	rs232_print(RS232_PORT_1, "radio get bw\r\n");
}

void radio_get_snr()
{
	rs232_print(RS232_PORT_1, "radio get snr\r\n");
}