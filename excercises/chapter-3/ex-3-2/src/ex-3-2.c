/*
 * Exercise-2: Write a function escape(s,t) that converts characters like
 *	       newline and tab into visible escape sequences like \n and \t as
 *	       it copies the string t to s. Use a switch. Write a function for
 *	       the other direction as well, converting escape sequences into
 *	       the real characters.
 *
 * Here the examples of the inputs that are entered by the user and their
 * outputs.
 *
 * 1)
 * Enter string1:
 * abs	ijk
 * lmop
 * wxyz
 *
 * String2 after return from the escape function:
 * abs\tijk\t\nlmop\nwxyz\n
 *
 * String2 after return from the unescape function:
 * abs	ijk
 * lmop
 * wxyz
 *
 */

#include <stdio.h>
#include "escape.h"

#define BUFSIZE 30

int main(void)
{
	char str1[BUFSIZE], str2[BUFSIZE];
	int i = 0, j = 0;

	printf("Enter string1:\n");

	while ((str1[i] = getchar()) != EOF)
		i++;

	escape(str2, str1);

	printf("\nString2 after return from the escape function:\n");

	while (str2[j] != EOF) {
		putchar(str2[j]);
		j++;
	}
	printf("\n");

	j = 0;

	unescape(str2);

	printf("\nString2 after return from the unescape function:\n");

	while (str2[j] != '\0')
		putchar(str2[j++]);
	printf("\n");

	return 0;
}
