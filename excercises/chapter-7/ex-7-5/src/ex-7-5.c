/*
 * Exercise 7-5: Rewrite the postfix calculator of Chapter 4 to use scanf
 *	         and/or sscanf to do the input and number conversion.
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE	100	/* Maximum buffer size */
#define NUMBER	'0'	/* signal that a number was found */
#define MAXVAL	100	/* maximum depth of val stack */
#define MAXOP	100	/* max size of operand or operator */
#define NUMBER	'0'	/* signal that a number was found */

int sp;			/* next free stack position */
double val[MAXVAL];	/* value stack */
char buf[BUFSIZE];	/* buffer for ungetch */
int bufp;		/* next free position in buf */

/* push: push f onto value stack */
static void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't %s %g\n", __func__, f);
}

/* pop: pop and return top value from stack */
static double pop(void)
{
	if (sp > 0)
		return val[--sp];

	printf("error: stack empty\n");

	return 0.0;
}

/* getop: get next character or numeric operand */
static int getop(char s[])
{
	static char c;
	int i = 0;

	if (c == '\n')
		c = '\0';

	scanf("%c", &c);
	s[0] = c;

	while (c == ' ' || c == '\t') {
		scanf("%c", &c);
		s[0] = c;
	}

	s[1] = '\0';

	if (!isdigit(c) && c != '.')
		return c;

	if (c == '-') {
		scanf("%c", &c);

		if (isdigit(c) || c == '.')
			s[++i] = c;
		else
			return '-';
	}

	while (isdigit(c)) {
		scanf("%c", &c);
		s[++i] = c;
	}

	if (c == '.') {
		scanf("%c", &c);

		while (isdigit(c)) {
			s[++i] = c;
			scanf("%c", &c);
		}

		i++;
	}

	s[i] = '\0';

	return NUMBER;
}

/* Print the top element of stack without using pop. */
static void top(void)
{
	if (sp > 0)
		printf("Top element of stack: %g\n", val[sp - 1]);
	else
		printf("Error: stack empty\n");
}

/* Use to clear the stack. */
static void clear(void)
{
	if (sp == 0) {
		printf("Now stack is empty\n");
		return;
	}

	while (sp > 0)
		pop();

	printf("Now stack is empty\n");
}

/* Display the stack. */
static void display(void)
{
	if (sp == 0) {
		printf("Error: stack empty\n");
		return;
	}

	for (int i = sp - 1; i >= 0; i--)
		printf("val[%d] = %g\n", i, val[i]);
}

int main(void)
{
	int type;
	double op2;
	char str[MAXOP];

	printf("First input your digits with spaces or tab\n");
	printf("+ -> addition\n");
	printf("- -> subtraction\n");
	printf("* -> multiplication\n");
	printf("/ -> division\n");
	printf("p -> print the top element of stack\n");
	printf("c -> clearing the stack\n");
	printf("D -> display the stack elements\n");
	printf("q -> quit\n");

	type = getop(str);

	while (type != '\0') {
		switch (type) {
		case NUMBER:
			push(atof(str));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("Error: zero divisor\n");
			break;
		case '\n':
			break;
		case 'p':
			top();
			break;
		case 'c':
			clear();
			break;
		case 'D':
			display();
			break;
		case 'q':
			return 0;
		default:
			printf("Error: unknown command %s\n", str);
			break;
		}

		type = getop(str);
	}

	return 0;
}
