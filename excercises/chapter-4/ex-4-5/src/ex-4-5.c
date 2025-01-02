/*
 * Exercise-5: Add access to library functions like sin, exp, and pow using
 *	       <math.h>.
 */

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE	100	/* Maximum buffer size */
#define MAXVAL	100	/* maximum depth of val stack */
#define MAXOP	100	/* max size of operand or operator */
#define NUMBER	'0'	/* signal that a number was found */

int sp;			/* next free stack position */
double val[MAXVAL];	/* value stack */
char buf[BUFSIZE];	/* buffer for ungetch */
int bufp;		/* next free position in buf */

/* get a (possibly pushed−back) character */
int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push character back on input */
void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("Too many characters for buffer\n");
	else
		buf[bufp++] = c;
}

/* push: push f onto value stack */
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("Error: stack full\n");
}

/* pop: pop and return top value from stack */
double pop(void)
{
	if (sp > 0)
		return val[--sp];

	printf("Error: stack empty\n");

	return 0.0;
}

/* getop: get next character or numeric operand */
int getop(char s[])
{
	int i = 0, c;

	c = getch();
	s[0] = c;

	while (c == ' ' || c == '\t') {
		c = getch();
		s[0] = c;
	}

	s[1] = '\0';

	if (!isdigit(c) && c != '.' && c != '-')
		return c;

	if (c == '-') {
		c = getch();

		if (isdigit(c) || c == '.') {
			s[++i] = c;
		} else {
			if (c != EOF)
				ungetch(c);

			return '-';
		}
	}

	if (isdigit(c)) {
		while (isdigit(c)) {
			c = getch();
			s[++i] = c;
		}
	}

	if (c == '.') {
		c = getch();

		while (isdigit(c)) {
			s[++i] = c;
			c = getch();
		}

		s[++i] = c;
	}

	s[i] = '\0';

	if (c != EOF)
		ungetch(c);

	return NUMBER;
}

/* Print the top element of stack without using pop. */
void top(void)
{
	if (sp > 0)
		printf("Top element of stack: %g\n", val[sp - 1]);
	else
		printf("Error: stack empty\n");
}

/* Create and push duplicate of top element of stack. */
void duplicate(void)
{
	if (sp > 0)
		push(val[sp - 1]);
	else
		printf("Error: stack empty\n");
}

/* Swap the top two elements of stack. */
void swap(void)
{
	double first, second;

	if (sp > 0) {
		first = pop();
		second = pop();
		push(first);
		push(second);
	} else {
		printf("Error: stack empty\n");
	}
}

/* Use to clear the stack. */
void clear(void)
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
void display(void)
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
	double op1, op2, op3;
	char str[MAXOP];

	printf("First input your digits with spaces or tab\n");
	printf("+ -> addition\n");
	printf("- -> subtraction\n");
	printf("* -> multiplication\n");
	printf("/ -> division\n");
	printf("S -> sine function\n");
	printf("P -> power function\n");
	printf("e -> Exponential function\n");
	printf("p -> print the top element of stack\n");
	printf("d -> create and push duplicate of top element\n");
	printf("s -> swapping of top two elements\n");
	printf("c -> clearing the stack\n");
	printf("D -> display the stack elements\n");
	printf("q -> quit\n");

	type = getop(str);

	while (type != EOF) {
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
				printf("error: zero divisor\n");
			break;
		case 'S':
			op1 = pop();
			op2 = sin(op1);
			printf("Sine(%0.8g) = %0.8g\n", op1, op2);
			push(op2);
			break;
		case 'P':
			op1 = pop();
			op2 = pop();

			if ((op2 == 0 && op1 <= 0) || (op2 < 0)) {
				printf("Invalid input\n");
			} else {
				op3 = pow(op2, op1);
				printf("%0.8g^%0.8g = %0.8g", op2, op1, op3);
			}
			break;
		case 'e':
			op1 = pop();
			op2 = exp(op1);
			printf("exp(%0.8g) = %0.8g\n", op1, op2);
			push(op2);
			break;

		case '\n':
			break;
		case 'p':
			top();
			break;
		case 'd':
			duplicate();
			break;
		case 's':
			swap();
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
			printf("error: unknown command %s\n", str);
			break;
		}

		type = getop(str);
	}

	return 0;
}
