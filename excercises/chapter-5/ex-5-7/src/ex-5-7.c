/*
 * Exercise-7: Rewrite readlines to store lines in an array supplied by main,
 *	       rather than calling alloc to maintain storage. How much faster
 *	       is the program?
 */

#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAXLINES	5000	/* max #lines to be sorted */
#define MAXLEN		1000	/* max length of any input line */

char *lineptr[MAXLINES];	/* pointers to text lines */

static int my_getline(char *ptr, int lim);
static int readlines(char *lineptr[], int nlines, char lines[][MAXLEN]);
static void writelines(char *lineptr[], int nlines);
static void qsort(char *lineptr[], int left, int right);
static void swap(char *v[], int i, int j);

int main(void)
{
	int nlines;
	clock_t t;
	float time;
	char lines[MAXLINES][MAXLEN];	/* 2d character array for storing lines */

	/* input lines to read */
	printf("Enter your input lines:\n");

	t = clock();
	nlines = readlines(lineptr, MAXLINES, lines);
	t = clock() - t;
	time = ((float)t)/CLOCKS_PER_SEC;

	printf("Runtime of readline with 2d array: %f Seconds\n", time);

	/* Sorting of the lines */
	if (nlines > 0) {
		qsort(lineptr, 0, nlines - 1);
		printf("\nEntered lines after soting:\n");
		writelines(lineptr, nlines);

		return 0;
	} else if (nlines == 0) {
		printf("No lines are entered\n");
	} else {
		printf("error: input too big to sort\n");
	}

	return 1;
}

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
static int readlines(char *lineptr[], int maxlines, char lines[][MAXLEN])
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
static void writelines(char *lineptr[], int nlines)
{
	for (int i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}

/* qsort: sort v[left]...v[right] into increasing order */
static void qsort(char *v[], int left, int right)
{
	int i, last;

	/* do nothing if array contains only one element */
	if (left >= right)
		return;

	/* fewer than two elements */
	swap(v, left, (left + right) / 2);
	last = left;

	for (i = left + 1; i <= right; i++)
		if (strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);

	swap(v, left, last);
	qsort(v, left, last - 1);
	qsort(v, last + 1, right);
}

/* swap: interchange v[i] and v[j] */
static void swap(char *v[], int i, int j)
{
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
