unsigned int sys_sleep(unsigned long length)
{

  if(length > 100)
  {
    char* command = "sys sleep ";

    //convert ulong to string
    const int n = snprintf(NULL, 0, "%lu", length);
    assert(n > 0);
    char len_str[n+1];
    int c = snprintf(len_str, n+1, "%lu", length);
    assert(len_str[n] == '\0');
    assert(c == n);

    char *result = malloc(strlen(command)+strlen(len_str)+3);
    strcpy(result, command);
    strcat(result, len_str);
    strcat(result, "\r\n");

    rs232_print(RS232_PORT_1, result);

    return 1;
  }
  else
  {
    rs232_print(RS232_PORT_0, "ERROR: sleep length not long enough.");
    return 0;
  }
}

unsigned int sys_sleep_response(char* data)
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

unsigned int sys_reset()
{
	rs232_print(RS232_PORT_1, "sys reset\r\n");

	return 1;
}

char* sys_reset_response(char* data)
{
	// data is system data, in the format:
	// RN2483 X.Y.Z MMM DD YYYY HH:MM:SS
	// Date and time refer to the release of the firmware
	//TODO: put this into a nicer format
	return data;
}

/*NOTE: this method gives no response.*/
unsigned int sys_eraseFW()
{
	rs232_print(RS232_PORT_1, "sys eraseFW\r\n");

	return 1;
}


unsigned int sys_factoryRESET()
{
	rs232_print(RS232_PORT_1, "sys factoryRESET\r\n");

	return 1;
}

char* sys_factoryRESET_response(char* data)
{
	// data is system data, in the format:
	// RN2483 X.Y.Z MMM DD YYYY HH:MM:SS
	// Date and time refer to the release of the firmware
	//TODO: put this into a nicer format
	return data;
}
