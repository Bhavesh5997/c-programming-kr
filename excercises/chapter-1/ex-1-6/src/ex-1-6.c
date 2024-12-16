/* Exercise-6: Verify that the expression getchar() != EOF is 0 or 1. */

#include <stdio.h>

int main(void)
{
	int c;

	c = getchar() != EOF;

	printf("The value of getchar() != EOF is : %d\n", c);

	return 0;
}
