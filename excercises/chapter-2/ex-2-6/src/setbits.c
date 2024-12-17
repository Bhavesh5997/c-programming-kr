#include <stdio.h>
#include "setbits.h"

/* This function replaces rightmost n bits of y in x from position p. */
unsigned int setbits(unsigned int x, unsigned int p, unsigned int n, unsigned int y)
{
	unsigned int mask = 0;

	/* Create mask for acessing rightmost n bits of y. */
	for (unsigned int i = 0; i < n; i++)
		mask |= (1 << i) | 1;

	y = mask & y;
	y = y << (p + 1 - n);

	/* Clear n bits of x from position p. */
	for (unsigned int i = p; n; i--, n--)
		x &= ~(1 << i);

	x |= y;

	return x;
}
