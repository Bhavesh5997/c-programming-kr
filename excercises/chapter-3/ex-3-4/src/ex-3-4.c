/*
 * Exercise-4: In a two's complement number representation, our version of
 *	       itoa does not handle the largest negative number, that is, the
 *	       value of n equal to −(2^wordsize−1). Explain why not. Modify it
 *	       to print that value correctly, regardless of the machine on
 *	       which it runs.
 *
 * Here the examples of the inputs that are entered by the user and their
 * outputs.
 *
 * 1)
 * Enter your number: -2147483648
 * Number -2147483648 in string format: -2147483648
 *
 * 2)
 * Enter your number: 2147483647
 * Number 2147483647 in string format: 2147483647
 *
 * 3)
 * Enter your number: -2147483647
 * Number -2147483647 in string format: -2147483647
 *
 * 4)
 * Enter your number: 2147483645
 * Number 2147483645 in string format: 2147483645
 */

#include <stdio.h>
#include "itoa.h"

#define BUFSIZE 100

int main(void)
{
	int num;
	char str[BUFSIZE];

	printf("Enter your number: ");
	scanf("%d", &num);

	itoa(num, str);
	printf("Number %d in string format: %s\n", num, str);

	return 0;
}
