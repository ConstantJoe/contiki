unsigned int mac_set_ch_freq(unsigned int channelID, unsigned long frequency);
unsigned int mac_set_ch_freq_response(char* data);

unsigned int mac_set_ch_dcycle(unsigned int channelID, unsigned int dutyCycle);
unsigned int mac_set_ch_dcycle_response(char* data);

unsigned int mac_set_ch_drrange(unsigned int channelID, unsigned int minRange, unsigned int maxRange);
unsigned int mac_set_ch_drrange_response(char* data);

unsigned int mac_set_ch_status(unsigned int channelID, unsigned int status);
unsigned int mac_set_ch_status_response(char* data);