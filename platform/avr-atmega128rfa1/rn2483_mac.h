unsigned int mac_reset(unsigned int band);
unsigned int mac_reset_response(char* data);

void mac_tx(char* type, unsigned int portno, char* data);

void mac_join(char* mode);

unsigned int mac_save();
unsigned int mac_save_response(char* data);

unsigned int mac_forceENABLE();
unsigned int mac_forceENABLE_response(char* data);

unsigned int mac_pause();
unsigned long mac_pause_response(char* data);

unsigned int mac_resume();
unsigned int mac_resume_response(char* data);


