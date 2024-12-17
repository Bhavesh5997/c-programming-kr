/*
 * Exercise-6: Write a function setbits(x,p,n,y) that returns x with the n bits
 *             that begin at position p set to the rightmost n bits of y,
 *             leaving the other bits unchanged.
 *
 * Here the examples of the inputs that are entered by the user and their
 * outputs.
 *
 * 1) Enter input x: 12
 *    Enter position p: 4
 *    Enter number of bits n: 2
 *    Enter input y: 3
 *    Modified x: 28
 *
 * 2) Enter input x: 23
 *    Enter position p: 7
 *    Enter number of bits n: 6
 *    Enter input y: 99
 *    Modified x: 143
 *
 * 3) Enter input x: 10
 *    Enter position p: 3
 *    Enter number of bits n: 1
 *    Enter input y: 0
 *    Modified x: 2
 *
 * 4) Enter input x: 7
 *    Enter position p: 3
 *    Enter number of bits n: 1
 *    Enter input y: 1
 *    Modified x: 15
 */

#include <stdio.h>
#include "setbits.h"

int main(void)
{
	unsigned int x, y, p, n;

	printf("Enter input x: ");
	scanf("%u", &x);
	printf("Enter position p: ");
	scanf("%u", &p);
	printf("Enter number of bits n: ");
	scanf("%u", &n);
	printf("Enter input y: ");
	scanf("%u", &y);

	x = setbits(x, p, n, y);

	printf("Modified x: %u\n", x);

	return 0;
}
