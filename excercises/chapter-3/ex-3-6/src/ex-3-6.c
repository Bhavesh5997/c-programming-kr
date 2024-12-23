/*
 * Exercise-6: Write a version of itoa that accepts three arguments instead of
 *	       two. The third argument is a minimum field width; the converted
 *	       number must be padded with blanks on the left if necessary to
 *	       make it wide enough.
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
	int num, field_width;
	char str[BUFSIZE];

	printf("Enter your digit: ");
	scanf("%d", &num);
	printf("Enter your field width: ");
	scanf("%d", &field_width);

	itoa(num, str, field_width);
	printf("Number %d in string format with fieldwidth %d: %s\n",
	       num, field_width, str);

	return 0;
}
