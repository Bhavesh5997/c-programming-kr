/*
 * Exercise-4: Write the function strend(s,t), which returns 1 if the string t
 *	      occurs at the end of the string s, and zero otherwise.
 */

#include <stdio.h>
#include <string.h>

#define BUFSIZE	100

/* Check the str2 occurs at the end of str1 or not */
static int strend(char *s, char *t)
{
	/*
	 * str1_len: str1 length
	 * str2_len: str2 length
	 */
	int str1_len, str2_len;

	str1_len = strlen(s) - 1;
	str2_len = strlen(t) - 1;

	/* Check one by one character from str1_len - str2_len */
	while (*t != '\n') {
		if (*(s + str1_len - str2_len) == *t++)
			s++;
		else
			return 0;
	}

	return 1;
}

int main(void)
{
	int result;
	char str1[BUFSIZE], str2[BUFSIZE];

	printf("Enter your string1:\n");
	fgets(str1, BUFSIZE, stdin);

	printf("Enter your string2:\n");
	fgets(str2, BUFSIZE, stdin);

	result = strend(str1, str2);

	if (result == 1)
		printf("str2 is occurs at the end of str1\n");
	else
		printf("str2 is not occur at the end of str1\n");

	return 0;
}
