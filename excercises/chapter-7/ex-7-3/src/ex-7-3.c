/*
 * Exercise 7-3: Revise minprintf to handle more of the other facilities of
 *	         printf.
 */

#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE	100

/* minprintf: minimal printf with variable argument list */
static void minprintf(char *fmt, ...)
{
	va_list ap;
	char *p, *sval, cval, str[BUFSIZE];
	int width = 0, i = 0, ival;
	double dval;

	va_start(ap, fmt);

	for (p = fmt; *p; p++) {
		if (*p != '%') {
			putchar(*p);
			continue;
		}

		/* get the field width in string form */
		while (isdigit(*++p) || *p == '-')
			str[i++] = *p;

		str[i] = '\0';

		if (i > 0)
			width = atoi(str);

		/*
		 * print the value according to format specifier and field
		 * width
		 */
		switch (*p) {
		case 'c':
			cval = va_arg(ap, int);

			if (width != 0)
				printf("%*c", width, cval);
			else
				printf("%c", cval);
			break;
		case 'd':
			ival = va_arg(ap, int);

			if (width != 0)
				printf("%*d", width, ival);
			else
				printf("%d", ival);
			break;
		case 'f':
			dval = va_arg(ap, double);

			if (width != 0)
				printf("%*f", width, dval);
			else
				printf("%f", dval);
			break;
		case 's':
			sval = va_arg(ap, char*);

			if (width != 0)
				printf("%*s", width, sval);
			else
				printf("%s", sval);
			break;
		case 'o':
			ival = va_arg(ap, int);

			if (width != 0)
				printf("%*o", width, ival);
			else
				printf("%o", ival);
			break;
		case 'x':
			ival = va_arg(ap, int);

			if (width != 0)
				printf("%*x", width, ival);
			else
				printf("%x", ival);
			break;
		case 'X':
			ival = va_arg(ap, int);

			if (width != 0)
				printf("%*X", width, ival);
			else
				printf("%X", ival);
			break;
		default:
			putchar(*p);
		}
	}

	va_end(ap);
}

int main(void)
{
	char ch = 'a';
	char str[] = "hello world";
	float fnum = 7.2;
	int inum = 15;

	minprintf("character type value = %c\n", ch);
	minprintf("string = %s\n", str);
	minprintf("float number = %f\n", fnum);
	minprintf("integer number = %d\n", inum);
	minprintf("integer number with fieldwidth 5 = %5d\n", inum);
	minprintf("integer number in hex form with %%x format specifier = %x"
		  "\n", inum);
	minprintf("integer number in hex form %%X specifier = %X\n", inum);
	minprintf("integer number in octal form = %o\n", inum);

	return 0;
}
