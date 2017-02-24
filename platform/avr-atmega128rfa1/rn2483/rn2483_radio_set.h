unsigned int radio_set_bt(char* gfBT);
unsigned int radio_set_bt_response(char* data);

unsigned int radio_set_mod(char* mode);
unsigned int radio_set_mod_response(char* data);

unsigned int radio_set_freq(unsigned long frequency);
unsigned int radio_set_freq_response(char* data);

unsigned int radio_set_pwr(int pwrout);
unsigned int radio_set_pwr_response(char* data);

unsigned int radio_set_sf(char* spreadingfactor);
unsigned int radio_set_sf_response(char* data);

unsigned int radio_set_afcbw(char* autoFreqBand);
unsigned int radio_set_afcbw_response(char* data);

unsigned int radio_set_rxbw(char* rxbandwidth);
unsigned int radio_set_rxbw_response(char* data);

unsigned int radio_set_bitrate(unsigned int fskBitRate);
unsigned int radio_set_bitrate_response(char* data);

unsigned int radio_set_fdev(unsigned int freqdev);
unsigned int radio_set_fdev_response(char* data);

unsigned int radio_set_prlen(unsigned int preamble);
unsigned int radio_set_prlen_response(char* data);

unsigned int radio_set_crc(unsigned int crcHeader);
unsigned int radio_set_crc_response(char* data);

unsigned int radio_set_iqi(unsigned int iqInvert);
unsigned int radio_set_iqi_response(char* data);

unsigned int radio_set_cr(char* codingRate);
unsigned int radio_set_cr_response(char* data);

unsigned int radio_set_wdt(unsigned long watchDog);
unsigned int radio_set_wdt_response(char* data);

unsigned int radio_set_sync(char* syncWord);
unsigned int radio_set_sync_response(char* data);

unsigned int radio_set_bw(unsigned int bandWidth);
unsigned int radio_set_bw_response(char* data);