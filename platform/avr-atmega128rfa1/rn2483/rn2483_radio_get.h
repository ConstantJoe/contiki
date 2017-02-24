unsigned int radio_get_bt();
char* radio_get_bt_response(char* data);

unsigned int radio_get_mod();
char* radio_get_mod_response(char* data);

unsigned int radio_get_freq();
unsigned long radio_get_freq_response(char* data);

unsigned int radio_get_pwr();
int radio_get_pwr_response(char* data);

unsigned int radio_get_sf();
char* radio_get_sf_response(char* data);

unsigned int radio_get_afcbw();
char* radio_get_afcbw_response(char* data);

unsigned int radio_get_rxbw();
char* radio_get_rxbw_response(char* data);

unsigned int radio_get_bitrate();
unsigned int radio_get_bitrate_response(char* data);

unsigned int radio_get_fdev();
unsigned int radio_get_fdev_response(char* data);

unsigned int radio_get_prlen();
unsigned int radio_get_prlen_response(char* data);

unsigned int radio_get_crc();
unsigned int radio_get_crc_response(char* data);

unsigned int radio_get_iqi();
unsigned int radio_get_iqi_response(char* data);

unsigned int radio_get_cr();
char* radio_get_cr_response(char* data);

unsigned int radio_get_wdt();
unsigned long radio_get_wdt_response(char* data);

unsigned int radio_get_bw();
unsigned int radio_get_bw_response(char* data);

unsigned int radio_get_snr();
int radio_get_snr_response(char* data);