/*
 * This function convert decimal digit into hexadecimal or binary base on base
 * and then convert into string.
 */

#include <stdio.h>
#include <string.h>
#include "itob.h"

void itob(unsigned int n, char s[], unsigned int b)
{
	/*
	 * str_len: It stores the string s length.
	 * i: Used to access the string s index.
	 * char_temp: Temporary variable, which is use during reverse operation
	 *	      of string.
	 */
	int str_len, i = 0;
	char char_temp;

	/*
	 * Convert digit into character based on base b and assign to string
	 * index.
	 */
	do {
		if (n % b >= 10 && b > 10)
			s[i++] = n % b + '7';
		else
			s[i++] = n % b + '0';
		n = n / b;
	} while (n > 0);

	s[i] = '\0';

	str_len = strlen(s);

	/* Reverse the string. */
	for (i = 0; i < str_len / 2; i++) {
		char_temp = s[i];
		s[i] = s[str_len - i - 1];
		s[str_len - i - 1] = char_temp;
	}
}
