/*
 * This function after the conversion of digit into string set it according to
 * fieldwidth, which entered by user.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "itoa.h"

void itoa(int n, char s[], int field_width)
{
	/*
	 * i: Used to access string s index.
	 * str_len: It store the string s length.
	 * sign: Store the number, used during checking the number sign.
	 * char_temp: Temporary variable for string s, Use during reverse
	 *	      operation of string.
	 */
	int i = 0, sign, str_len;
	char char_temp;

	sign = n;

	/*
	 * Convert digit into character one by one and assign to string
	 * index and fit it according to fieldwidth.
	 */
	do {
		s[i++] = abs(n % 10) + '0';
		n = abs(n / 10);

	} while (n > 0);

	if (sign < 0)
		s[i++] = '-';

	field_width = field_width - i;

	/* Set the string according to fieldwidth */
	while (field_width-- > 0)
		s[i++] = ' ';

	s[i] = '\0';
	str_len = strlen(s);

	/* It simply reverse the string. */
	for (i = 0; i < str_len / 2; i++) {
		char_temp = s[i];
		s[i] = s[str_len - i - 1];
		s[str_len - i - 1] = char_temp;
	}
}
