/*
 * Exercise-3: Write a pointer version of the function strcat that we showed in
 *	       Chapter 2 strcat(s,t) copies the string t to the end of s.
 */

#include <stdio.h>
#include <string.h>

#define BUFSIZE	100

/* Concate the two string */
static void my_strcat(char *s, char *t)
{
	int str1_len;

	str1_len = strlen(s);

	/* Assign str2 characters to str1 from str1_len - 1 */
	while (*t != '\n') {
		*(s + str1_len - 1) = *t++;
		s++;
	}

	*(s + str1_len - 1) = '\0';
}

int main(void)
{
	char str1[BUFSIZE], str2[BUFSIZE];

	printf("Enter your string1: ");
	fgets(str1, BUFSIZE, stdin);
	printf("Enter your string2: ");
	fgets(str2, BUFSIZE, stdin);

	my_strcat(str1, str2);

	printf("string1 after concat with string2: ");

	for (int i = 0; *(str1 + i) != '\0'; i++)
		putchar(*(str1 + i));

	printf("\n");

	return 0;
}
