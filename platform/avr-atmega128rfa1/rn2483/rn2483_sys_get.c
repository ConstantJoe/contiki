//System Get Commands

unsigned int sys_get_ver()
{
	rs232_print(RS232_PORT_1, "sys get ver\r\n");

	return 1;
}

char* sys_get_ver_response(char* data)
{
	// data is system data, in the format:
	// RN2483 X.Y.Z MMM DD YYYY HH:MM:SS
	// Date and time refer to the release of the firmware
	//TODO: put this into a nicer format
	return data;
}


unsigned int sys_get_nvm(unsigned int address)
{
	if(address >= 0x300 && address <= 0x3FF)
	{
		char* command = "sys get nvm ";

		char* add_str;
		sprintf(add_str, "%x", address);
		//address to char*

		//copy all into one array
		char *result = malloc(strlen(command)+strlen(add_str)+3);
    	strcpy(result, command);
    	strcat(result, add_str);
    	strcat(result, "\r\n");

    	rs232_print(RS232_PORT_1, result);

    	return 1;
	}
	else
	{
		rs232_print(RS232_PORT_0, "ERROR: sys_get_nvm: address not between 0x300 and 0x3FF.\r\n");
		return 0;
	}
}

unsigned int sys_get_nvm_response(char* data)
{
	if(strcmp(data,"invalid_param"))
	{
		return 0;
	}
	else
	{
		return (unsigned int)strtol(data, NULL, 16);
	}
}


unsigned int sys_get_vdd()
{
	rs232_print(RS232_PORT_1, "sys get vdd\r\n");

	return 1;
}

unsigned int sys_get_vdd_response(char* data)
{
	return (unsigned int *)strtoull(data, NULL, 0);
}





unsigned int sys_get_hweui()
{
	rs232_print(RS232_PORT_1, "sys get hweui\r\n");

	return 1;
}

unsigned int sys_get_hweui_response(char* data)
{
	return (unsigned int)strtol(data, NULL, 16);
}