/*
 * Initially this function doesn't handle maximum negative number conversion
 * into string, so here it's data type change from int to long long, which can
 * handle maximum negative integer number and it's also machine independent. It
 * have same size on 32 bit and 64 bit machine, which is 8 byte.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "itoa.h"

void itoa(int n, char s[])
{
	/* i: Used to access the string index.
	 * str_len: It stores the string s length.
	 * sign: it's stores the number, if it's negative then first convert it
	 *	 into positive and atlast string last index assign to '-'
	 * char_temp: Temporary variable for string s, Use during reverse
	 *	      operation of string.
	 */
	int i, str_len, sign;
	char char_temp;

	sign = n;

	/* It's convert digit into character. */
	do
		s[i++] = abs(n % 10) + '0';
	while (abs((n /= 10)) > 0);

	if (sign < 0)
		s[i++] = '-';

	s[i] = '\0';
	str_len = strlen(s);

	/* Reverse the string. */
	for (i = 0; i < str_len / 2; i++) {
		char_temp = s[i];
		s[i] = s[str_len - i - 1];
		s[str_len - i - 1] = char_temp;
	}
}
