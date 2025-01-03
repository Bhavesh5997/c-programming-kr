/*
 * Exercise-10: Write the program expr, which evaluates a reverse Polish
 *	        expression from the command line, where each operator or
 *	        operand is a separate argument. For example,
 *
 *	        Example:
 *	        expr 2 3 4 + *
 *	        evaluates 2 * (3 + 4).
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 100	/* Maximum buffer size */

int sp;			/* Act as the stack pointer for push and pop operation */
float val[BUFSIZE];	/* Storing the pushed value */

/* push the value on stack */
static void push(float f)
{
	if (sp < BUFSIZE)
		val[sp++] = f;
	else
		printf("error: stack full, can't %s %g\n", __func__, f);
}

/* pop: pop and return top value from stack */
static float pop(void)
{
	if (sp > 0)
		return val[--sp];

	printf("error: stack empty\n");

	return 0.0;
}

int main(int argc, char *argv[])
{
	float op1, op2, op3;
	int i;

	/* Check the arguments are operands or operator and perform operation */
	for (i = 1; i < argc; i++) {
		if (argv[i][0] == ' ' || argv[i][0] == '\t') {
			continue;
		} else if (isdigit(argv[i][0]) ||
			   ((argv[i][0] == '-' || argv[i][0] == '+') &&
			    isdigit(argv[i][1]))) {
			push(atof(argv[i]));
		} else {
			if (sp >= 2) {
				switch (argv[i][0]) {
				case '+':
					op2 = pop();
					op1 = pop();
					op3 = op1 + op2;
					push(op3);
					break;
				case '-':
					op2 = pop();
					op1 = pop();
					op3 = op1 - op2;
					push(op3);
					break;
				case '*':
					op2 = pop();
					op1 = pop();
					op3 = op1 * op2;
					push(op3);
					break;
				case '/':
					op2 = pop();
					op1 = pop();

					if (op2 != 0) {
						op3 = op1 / op2;
						push(op3);
					} else {
						printf("Error\n");
					}
					break;
				default:
					printf("Invalid\n");
					return -1;
				}

			} else {
				printf("Provide command line as per below "
				       "example\nexample: ./<path>/binary_file"
				       " 2 3 4 + *\n");
				return -1;
			}
		}
	}

	if (argv[i - 1][0] != '+' && argv[i - 1][0] != '-' &&
	    argv[i - 1][0] != '*' && argv[i - 1][0] != '/') {
		printf("Provide command line as per below "
		       "example\nexample: ./<path>/binary_file"
		       " 2 3 4 + *\n");
		return -1;
	}

	printf("Result: %.2f\n", op3);

	return 0;
}
