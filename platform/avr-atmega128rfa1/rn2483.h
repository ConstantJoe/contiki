#include "dev/rs232.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rn2483_sys.h"
#include "rn2483_sys_set.h"
#include "rn2483_sys_get.h"
#include "rn2483_mac.h"
#include "rn2483_mac_set.h"
#include "rn2483_mac_get.h"
#include "rn2483_radio.h"
#include "rn2483_radio_set.h"
#include "rn2483_radio_get.h"

//TODO: for all files: Magic numbers everywhere! Create some definitions here.

int nDigits(int i)
{
  if (i < 0) i = -i;
  if (i <         10) return 1;
  if (i <        100) return 2;
  if (i <       1000) return 3;
  if (i <      10000) return 4;
  if (i <     100000) return 5;
  if (i <    1000000) return 6;      
  if (i <   10000000) return 7;
  if (i <  100000000) return 8;
  if (i < 1000000000) return 9;
  return 10;
}

unsigned int hexFormCheck(char a)
{
	//if the ascii value of the char a indicates that its either a digit or one of A-F
	if((a >= 48 && a <= 57) | (a >= 65 && a <= 70))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

unsigned int hexFormArrayCheck(char* data)
{
	int i;
	for(i = 0; i < sizeof(data) / sizeof(char); i++)
	{
  		if(!hexFormCheck(data[i]))
  		{
  			return 0;
  		}
	}
	return 1;
}

