/*
 * Exercise-4: Write an alternate version of squeeze(s1,s2) that deletes each
 *             character in the string s1 that matches any character in the
 *             string s2.
 *
 * Here the examples of the inputs that are entered by the user and their
 * outputs.
 *
 * 1) Enter your strings:
 *    abc	d       e	f
 *    123\\\\	bcd
 *    string-1 after removing the matched characters with string-2: aef
 *
 * 2) Enter your strings:
 *    ab      cd	ef
 *    defnr2
 *    string-1 after removing the matched characters with string-2: ab	c
 *
 * 3) Enter your strings:
 *    rfid ^&*&* abcd
 *    ^&* a
 *    string-1 after removing the matched characters with string-2: rfidbcd
 *
 * 4) Enter your strings:
 *    ijk@ lmno
 *    @jl
 *    string-1 after removing the matched characters with string-2: ik mo
 */

#include <stdio.h>
#include "squeeze.h"

#define MAX 20

int main(void)
{
	char str1[MAX], str2[MAX];

	printf("Enter your strings:\n");
	fgets(str1, MAX, stdin);
	fgets(str2, MAX, stdin);

	squeeze(str1, str2);

	return 0;
}
