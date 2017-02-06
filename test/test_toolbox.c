#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "test_toolbox.h"


bool test_equality_int (int expected, int value, char * msg)
{
	if (expected != value)
	{
		fprintf(stderr, "ERR: valeur attendue %d ; valeur calculee %d. %s\n", expected, value, msg);
		return false;
	}
	return true;
}

bool test_interval_int (int val_min, int val_max, int value, char * msg)
{
	if (value < val_min  || val_max < value)
	{
		fprintf(stderr, "ERR: interval attendue [%d,%d] ; valeur calculee %d. %s\n", val_min, val_max, value, msg);
		return false;
	}
	return true;
}

bool test_equality_bool (bool expected, bool value, char * msg)
{
	if (expected != value)
	{
		fprintf(stderr, "ERR: valeur attendue %d ; valeur calculee %d. %s\n", expected, value, msg);
		return false;
	}
	return true;
}
