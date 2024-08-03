#include <stdio.h>
#include "lists.h"

void premain(void) __attribute__((constructor));

/**
 * premain - prints amessage before the main function
 * This function uses the constructor attribute to run before main
 */
	void premain(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
