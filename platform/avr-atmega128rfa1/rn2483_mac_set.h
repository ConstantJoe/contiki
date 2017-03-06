unsigned int mac_set_devaddr(unsigned long address);
unsigned int mac_set_devaddr_response(char* data);

unsigned int mac_set_deveui(char* deveui);
unsigned int mac_set_deveui_response(char* data);

unsigned int mac_set_appeui(char* appeui);
unsigned int mac_set_appeui_response(char* data);

unsigned int mac_set_nwkskey(char* nwksesskey);
unsigned int mac_set_nwkskey_response(char* data);

unsigned int mac_set_appskey(char* appSesskey);
unsigned int mac_set_appskey_response(char* data);

unsigned int mac_set_appkey(char* appkey);
unsigned int mac_set_appkey_response(char* appkey);

unsigned int mac_set_pwridx(unsigned int pwrIndex);
unsigned int mac_set_pwridx_response(char* data);

unsigned int mac_set_dr(unsigned int dataRate);
unsigned int mac_set_dr_response(char* data);

unsigned int mac_set_adr(unsigned int state);
unsigned int mac_set_adr_response(char* data);

unsigned int mac_set_bat(unsigned int level);
unsigned int mac_set_bat_response(char* data);

unsigned int mac_set_retx(unsigned int reTxNb);
unsigned int mac_set_retx_response(char* data);

unsigned int mac_set_linkchk(unsigned int linkCheck);
unsigned int mac_set_linkchk_response(char* data);

unsigned int mac_set_rxdelay1(unsigned int rxDelay);
unsigned int mac_set_rxdelay1_response(char* data);

unsigned int mac_set_ar(unsigned int state);
unsigned int mac_set_ar_response(char* data);

unsigned int mac_set_rx2(unsigned int dataRate, unsigned long frequency);
unsigned int mac_set_rx2_response(char* data);