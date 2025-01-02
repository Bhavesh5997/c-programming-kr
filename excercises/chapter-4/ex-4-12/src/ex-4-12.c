/*
 * Exercise-12: Adapt the ideas of printd to write a recursive version of itoa;
 *	        that is, convert an integer into a string by calling a
 *	        recursive routine.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 100

/* Convert digits into characters using recursive function. */
void itoa(int n, char s[])
{
	static int i;
	int sign = n;

	/* It's convert digit into character. */
	if (n != 0) {
		s[i++] = abs(n % 10) + '0';
		itoa(abs(n /= 10),  s);
	}

	if (sign < 0)
		s[i++] = '-';

	s[i] = '\0';
}

int main(void)
{
	int str_len, num, i = 0;
	char str[BUFSIZE], ch;

	printf("Enter your number: ");
	scanf("%d", &num);

	if (num != 0) {
		itoa(num, str);
	} else {
		str[i++] = '0';
		str[i] = '\0';
	}

	str_len = strlen(str);

	for (int j = 0; j < str_len/2; j++) {
		ch = str[j];
		str[j] = str[str_len - j - 1];
		str[str_len - j - 1] = ch;
	}

	printf("String s: %s\n", str);

	return 0;
}
