unsigned int sys_sleep(unsigned long length);
unsigned int sys_sleep_response(char* data);

unsigned int sys_reset();
char* sys_reset_response(char* data);

unsigned int sys_eraseFW();

unsigned int sys_factoryRESET();
char* sys_factoryRESET_response(char* data);