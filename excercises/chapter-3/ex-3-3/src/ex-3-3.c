/*
 * Exercise-3: Write a function expand(s1,s2) that expands shorthand notations
 *	       like a-z in the string s1 into the equivalent complete list
 *	       abc...xyz in s2. Allow for letters of either case and digits,
 *	       and be prepared to handle cases like a-b-c and a-z0-9 and -a-z.
 *	       Arrange that a leading or trailing - is taken literally.
 *
 * Here the examples of the inputs that are entered by the user and their
 * outputs.
 *
 * 1)
 * Enter string s1:
 * a-z
 * String s2: abcdefghijklmnopqrstuvwxyz
 *
 * 2)
 * Enter string s1:
 * z-a
 * String s2: zyxwvutsrqponmlkjihgfedcba
 *
 * 3)
 * Enter string s1:
 * a-z0-9
 * String s2: abcdefghijklmnopqrstuvwxyz0123456789
 *
 * 4)
 * Enter string s1:
 * a-b-c
 * String s2: abc
 *
 * 5)
 * Enter string s1:
 * --a-z--
 *  String s2: --abcdefghijklmnopqrstuvwxyz--
 *
 * 6)
 * Enter string s1:
 * --z-a--
 *  String s2: --zyxwvutsrqponmlkjihgfedcba--
 *
 * 7)
 * Enter string s1:
 * abcd
 * String s2: abcd
 *
 * 8)
 * Enter string s1:
 * a--z
 * String s2: a--z
 *
 * 9)
 * Enter string s1:
 * ---z-a----
 *  String s2: ---zyxwvutsrqponmlkjihgfedcba----
 */

#include <stdio.h>
#include <stdlib.h>
#include "expand.h"

#define BUFSIZE 300

int main(void)
{
	int k;
	char str1[BUFSIZE], str2[BUFSIZE];

	printf("Enter string s1:\n");
	fgets(str1, BUFSIZE, stdin);

	k = expand(str1, str2);

	printf("String s2: ");
	for (int i = 0; i < k; i++)
		putchar(str2[i]);
	printf("\n");

	return 0;
}
