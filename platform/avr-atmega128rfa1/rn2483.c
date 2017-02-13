

void sys_sleep(int length)
{
	rs232_print(RS232_PORT_1, "tester");
}

void sys_reset()
{
	rs232_print(RS232_PORT_1, "sys reset\r\n");
}

void sys_eraseFW()
{
	rs232_print(RS232_PORT_1, "sys eraseFW\r\n");
}

void sys_factoryRESET()
{
	rs232_print(RS232_PORT_1, "sys factoryRESET\r\n");
}

/*Modify EEPROM at address to data. Both address and data must be inputted as hex values
	Can modify addresses from 300 to 3FF.
*/
void sys_set_nvm(int address, int data)
{

}

/*Modify unused pins on the module
Pinname can be GPIO0-GPIO4, UART_CTS, UART_RTS, TEST0, TEST1
Pinstate can be 0 or 1.
*/
void sys_set_pindig(char* pinname, int pinstate)
{

}

void sys_get_ver()
{
	rs232_print(RS232_PORT_1, "sys get ver\r\n");
}

void sys_get_nvm(int address)
{

}

void sys_get_vdd()
{
	rs232_print(RS232_PORT_1, "sys get vdd\r\n");
}

void sys_get_hweui()
{
	rs232_print(RS232_PORT_1, "sys get hweui\r\n");
}

/*band can be 868 or 433*/
void mac_reset(int band)
{

}

void mac_tx(char* type, int portno, char* data)
{

}

void mac_join(char* mode)
{

}

void mac_save()
{
	rs232_print(RS232_PORT_1, "mac save\r\n");
}

void mac_forceENABLE()
{
	rs232_print(RS232_PORT_1, "mac forceENABLE\r\n");
}

void mac_pause()
{
	rs232_print(RS232_PORT_1, "mac pause\r\n");
}

void mac_resume()
{
	rs232_print(RS232_PORT_1, "mac resume\r\n");
}


void mac_set_devaddr(int address)
{

}

void mac_set_deveui(char* deveui)
{

}

void mac_set_appeui(char* appeui)
{

}

void mac_set_nwkskey(char* nwksesskey)
{

}

void mac_set_appskey(char* appSesskey)
{

}

void mac_set_appkey(char* appkey)
{

}

void mac_set_pwridx(int pwrIndex)
{

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