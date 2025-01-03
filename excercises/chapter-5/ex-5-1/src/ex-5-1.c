/*
 * Exercise-1: As written, getint treats a + or - not followed by a digit as a
 *	       valid representation of zero. Fix it to push such a character
 *	       back on the input.
 */

#include <ctype.h>
#include <stdio.h>

#define BUFSIZE	100	/* maximum buffer size */
#define SIZE	100	/* array maximum size */

char buf[BUFSIZE];	/* buffer for ungetch */
int bufp;		/* next free position in buf */

/* get a (possibly pushed-back) character */
static int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push character back on input */
static void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("Too many characters for buffer\n");
	else
		buf[bufp++] = c;
}

/* getint: get next integer from input into *pn */
static int getint(int *pn)
{
	int c, sign = 1;

	c = getch();

	/* skip white space */
	while (isspace(c))
		c = getch();

	/* it is not a number */
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		printf("Invalid input\n");
		ungetch(c);
		return -1;
	}

	while ((c == '+' || c == '-' || isspace(c)) && c != EOF
	       && !isalpha(c)) {
		sign = (c == '+') ? 1 : -1;
		c = getch();
	}

	if (!isdigit(c) && c != EOF) {
		printf("Invalid input\n");
		ungetch(c);
		return -1;
	}

	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');

	*pn *= sign;

	if (c != EOF)
		ungetch(c);

	return c;
}

int main(void)
{
	int n, array[SIZE];

	printf("Enter array elements:\n");

	/* assign integer to array index */
	for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
		printf("array[%d] = %d\n", n, array[n]);

	return 0;
}
