/*
 * Exercise−5: Write the function itob(n,s,b) that converts the integer n
 *	       into a base b character representation in the string s. In
 *	       particular, itob(n,s,16) formats s as a hexadecimal integer in
 *	       s.
 *
 * Here the examples of the inputs that are entered by the user and their
 * outputs.
 *
 * 1)
 * Enter your number: 2147483647
 * Enter your base: 2
 * Number 2147483647 with base 2 String s: 1111111111111111111111111111111
 *
 * 2)
 * Enter your number: 12345
 * Enter your base: 3
 * Number 12345 with base 3 String s: 121221020
 *
 * 3)
 * Enter your number: 1234567
 * Enter your base: 4
 * Number 1234567 with base 4 String s: 10231122013
 *
 * 4)
 * Enter your number: 123456
 * Enter your base: 16
 * Number 123456 with base 16 String s: 1E240
 */

#include <stdio.h>
#include "itob.h"

#define BUFSIZE 100

int main(void)
{
	char str[BUFSIZE];
	unsigned int num, base;

	printf("Enter your number: ");
	scanf("%d", &num);
	printf("Enter your base: ");
	scanf("%d", &base);

	if (base < 2 || base > 36) {
		printf("Invalid base\n");
		return -1;
	}

	itob(num, str, base);
	printf("Number %d with base %d String s: %s\n", num, base, str);

	return 0;
}
