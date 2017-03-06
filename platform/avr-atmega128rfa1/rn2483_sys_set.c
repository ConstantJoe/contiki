#include "rn2483_sys_set.h"

//System Set Commands

/*Modify EEPROM at address to data. Both address and data must be inputted as hex values
	Can modify addresses from 300 to 3FF.
*/
unsigned int sys_set_nvm(unsigned int address, unsigned int data)
{
	if(address >= 0x300 && address <= 0x3FF)
	{
		if(data >= 0x00 && <= 0xFF)
		{
			char* command = "sys set nvm ";

			//address to char* (hex version)
			char* add_str;
			sprintf(add_str, "%x", address);

			//data to char* (hex version)
			char* data_str;
			sprintf(data_str, "%x", data);

			//copy all into one array
			char *result = malloc(strlen(command)+strlen(add_str)+strlen(data_str)+4);
    		strcpy(result, command);
    		strcat(result, add_str);
    		strcat(result, " ");
    		strcat(result, data_str);
    		strcat(result, "\r\n");

    		rs232_print(RS232_PORT_1, result);

    		return 1;
		}
		else
		{
			rs232_print(RS232_PORT_0, "ERROR: sys_set_nvm: data not between 0x00 and 0xFF\r\n");
			return 0;
		}
	}
	else
	{
		rs232_print(RS232_PORT_0, "ERROR: sys_set_nvm: address not between 0x300 and 0x3FF\r\n");
		return 0;
	}
}

unsigned int sys_set_nvm_response(char* data)
{
	if(strcmp(data,"ok"))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*Modify unused pins on the module
Pinname can be GPIO0-GPIO14, UART_CTS, UART_RTS, TEST0, TEST1
Pinstate can be 0 or 1.
*/
unsigned int sys_set_pindig(char* pinname, unsigned int pinstate)
{
	if( strcmp(pinname,"GPIO0")    | strcmp(pinname,"GPIO1")    | strcmp(pinname,"GPIO2")  | strcmp(pinname,"GPIO3")  | strcmp(pinname,"GPIO4") | 
		strcmp(pinname,"GPIO5")    | strcmp(pinname,"GPIO6")    | strcmp(pinname,"GPIO7")  | strcmp(pinname,"GPIO8")  | strcmp(pinname,"GPIO9") | 
		strcmp(pinname,"GPIO10")   | strcmp(pinname,"GPIO11")   | strcmp(pinname,"GPIO12") | strcmp(pinname,"GPIO13") | strcmp(pinname,"GPIO14") | 
		strcmp(pinname,"UART_CTS") | strcmp(pinname,"UART_RTS") | strcmp(pinname,"TEST0")  | strcmp(pinname,"TEST1"))
	{
		if(pinstate == 0 | pinstate == 1)
		{
			char* command = "sys set pindig ";

			//pinstate to char*
			char* pinstate_str;
			sprintf(pinstate_str, "%u", address);

			//copy all into one array
			char *result = malloc(strlen(command)+strlen(pinname)+strlen(pinstate_str)+4);
    		strcpy(result, command);
    		strcat(result, pinname);
    		strcat(result, " ");
    		strcat(result, pinstate_str);
    		strcat(result, "\r\n");

    		rs232_print(RS232_PORT_1, result);

    		return 1;
		}
		else
		{
			rs232_print(RS232_PORT_0, "ERROR: sys_set_pindig: pinstate is not 0 or 1\r\n");
			return 0;
		}
	}
	else
	{
		rs232_print(RS232_PORT_0, "ERROR: sys_set_pindig: pinname not correct\r\n");
		return 0;
	}
}

unsigned int sys_set_pindig_response(char* data)
{
	if(strcmp(data,"ok"))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}