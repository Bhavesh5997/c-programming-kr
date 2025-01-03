/*
 * Exercise-13: Write the program tail, which prints the last n lines of its
 *	        input. By default, n is set to 10, let us say, but it can be
 *	        changed by an optional argument so that tail -n
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES	5000	/* max #lines to be sorted */
#define MAXLEN		1000	/* max length of any input line */

char *lineptr[MAXLINES];	/* pointers to text lines */
char lines[MAXLINES][MAXLEN];	/* 2d charcter array for storing lines */

/* take the input lines */
static int my_getline(char *s, int lim)
{
	int c, i;

	i = 0;
	c = getchar();

	/* get characters and assign to str */
	while (--lim > 0 && c != EOF && c != '\n') {
		s[i++] = c;
		c = getchar();
	}

	if (c == '\n')
		s[i++] = c;

	s[i] = '\0';

	return i;
}

/* readlines: read input lines */
static int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char line[MAXLEN];

	nlines = 0;
	len = my_getline(line, MAXLEN);

	while (len > 0) {
		if (nlines >= maxlines)
			return -1;

		line[len - 1] = '\0';	/* delete newline */
		strcpy(lines[nlines], line);
		lineptr[nlines] = lines[nlines];
		nlines++;

		len = my_getline(line, MAXLEN);
	}

	return nlines;
}

/* writelines: write output lines */
static void writelines(char *lineptr[], int nlines, int n)
{
	int i;

	i = (n <= nlines ? (nlines - n) : 0);

	printf("\nOutput:\n");

	while (i < nlines)
		printf("%s\n", lineptr[i++]);
}

int main(int argc, char *argv[])
{
	int n, nlines;

	/* Check the digit after "-n" argument */
	switch (argc - 1) {
	case 0:
		n = 10;
		break;
	case 2:
		if (strcmp(argv[1], "-n") == 0 && isdigit(argv[2][0])) {
			n = atoi(argv[2]);
		} else {
			printf("Usage: ./<path>/binary_file -n <no. of lines>"
			       "\n");
			return -1;
		}
		break;
	default:
		printf("Usage: ./<path>/binary_file -n <no. of lines>"
		       "\n");
		return -1;
	}

	printf("Enter your input lines:\n");

	nlines = readlines(lineptr, MAXLINES);

	if (nlines > 0)
		writelines(lineptr, nlines, n);
	else if (nlines == 0)
		printf("No lines are entered\n");
	else
		printf("error: input too big to sort\n");

	return 0;
}
