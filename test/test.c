#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "test.h"

int main (int argc, char const *argv[])
{
	bool result = true;

	result = test_array() && result;

	if (result)
	{
		printf("=== Tests réussis! ===\n");
	}
	
	return EXIT_SUCCESS;
}