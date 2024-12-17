/*
 * Exercise-5: Write the function any(s1,s2), which returns the first location
 *             in the string s1 where any character from the string s2 occurs,
 *             or -1 if s1 contains no characters from s2. (The standard
 *             library function strpbrk does the same job but returns a pointer
 *             to the location.)
 *
 * Here the examples of the inputs that are entered by the user and their
 * outputs.
 *
 * 1) Enter your strings:
 *    aijk    jklm	n
 *    edefgh	ijk
 *    Matched character at index: 4
 *
 * 2) Enter your strings:
 *    12345678		a
 *    abcdefg
 *    Matched character at index: 10
 *
 * 3) Enter your strings:
 *    Enter your strings:
 *    12abcdefhild
 *    	xyz54321
 *    Matched character at index: 1
 *
 * 4) Enter your strings:
 *    abcd xyz
 *    vwpqrstu
 *    Matched character at index: -1
 */

#include <stdio.h>
#include "any.h"

#define MAX 20

int main(void)
{

	/* char_location: Take the return value of any function. */
	char str1[MAX], str2[MAX];
	int char_location;

	printf("Enter your strings:\n");
	fgets(str1, MAX, stdin);
	fgets(str2, MAX, stdin);

	char_location = any(str1, str2);

	if (char_location == -1)
		printf("Character not found: %d\n", char_location);
	else
		printf("Matched character at index: %d\n", char_location);

	return 0;
}
