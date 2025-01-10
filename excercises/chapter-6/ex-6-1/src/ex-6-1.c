/*
 * Exercise 6-1: Our version of getword does not properly handle underscores,
 *	         string constants, comments, or preprocessor control lines.
 *	         Write a better version.
 */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAXWORD	100
#define BUFSIZE	100
#define NKEYS	((int)(sizeof(keytab) / sizeof(keytab[0])))

char buf[BUFSIZE];	/* buffer for ungetch */
int bufp;		/* next free position in buf */

struct key {
	char *word;
	int count;
} keytab[] = {
	{"auto", 0},
	{"break", 0},
	{"case", 0},
	{"char", 0},
	{"const", 0},
	{"continue", 0},
	{"default", 0},
	{"unsigned", 0},
	{"void", 0},
	{"volatile", 0},
	{"while", 0}
};

static int getch(void);
static void ungetch(int c);
static int getword(char *str, int n);
static int binsearch(char *str, struct key *ptr, int n);

int main(void)
{
	/*
	 * n: Store the return value of binsearch function.
	 * word: It's store the word which entered by the user.
	 * c: Store the return value of the getword function.
	 */
	int n;
	char word[MAXWORD], c;

	printf("Enter your words:\n");
	c = getword(word, MAXWORD);

	/* Increment the count if the word is keyword */
	while (c != EOF) {
		if (isalpha(word[0])) {
			n = binsearch(word, keytab, NKEYS);

			if (n >= 0)
				keytab[n].count++;
		}

		c = getword(word, MAXWORD);
	}

	printf("\nKeywords from entered words:\n");

	for (n = 0; n < NKEYS; n++)
		if (keytab[n].count > 0)
			printf("%4d %s\n", keytab[n].count, keytab[n].word);

	return 0;
}

/* get a (possibly pushed−back) character */
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

/* binsearch: find word in tab[0]...tab[n−1] */
static int binsearch(char *word, struct key tab[], int n)
{
	int cond, low, high, mid;

	low = 0;
	high = n - 1;

	while (low <= high) {
		mid = (low + high) / 2;
		cond = strcmp(word, tab[mid].word);
		if (cond < 0)
			high = mid - 1;
		else if (cond > 0)
			low = mid + 1;
		else
			return mid;
	}

	return -1;
}

/* getword: get next word or character from input */
static int getword(char *word, int lim)
{
	int c;
	char *w = word;

	c = getch();

	while (isspace(c))
		c = getch();

	if (c != EOF)
		*w++ = c;

	if (c == '/' || !isalpha(c)) {
		c = getch();
		if (c == '/') {
			while (c != '\n' && c != EOF)
				c = getch();
		} else if (c == '*') {
			c = getch();
			while (c != EOF) {
				if (c == '*') {
					c = getch();
					if (c == '/')
						break;
				}
				c = getch();
			}
		} else {
			while (c != '\n' && c != EOF)
				c = getch();
		}

		return c;
	}

	for ( ; --lim > 0; w++) {
		*w = getch();
		if (isspace(*w)) {
			ungetch(*w);
			break;
		}
	}

	*w = '\0';

	return word[0];
}
