unsigned int radio_rx(unsigned int rxWindowSize);
char* radio_rx_response(char* data);

unsigned int radio_tx(char* data);
char* radio_tx_response(char* data);

unsigned int radio_cw(unsigned int state);
unsigned int radio_cw_response(char* data);