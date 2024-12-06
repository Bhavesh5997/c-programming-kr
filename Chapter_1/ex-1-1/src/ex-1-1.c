/*
 * Exercise-1: Run the "hello world" program on your system. Experiment with
 *             leaving out parts of the program, to see what error messages you
 *             get.
 *
 * 1) By removing the int keyword before the main function, it will take
 *    default as int, by using void main() there is no need to write
 *    return 0 at the end, if there is a return 0 statement in the block of
 *    this function then it is to give a warning message to write int instead
 *    of void.
 *
 * 2) By removing the standard library, the program runs fine, but there is a
 *    warning message to include the library.
 *
 * 3) By removing the semicolon at the end of the printf function and return 0
 *    there are errors in the program.
 */

#include <stdio.h>

int main(void)
{
	printf("hello world\n");

	return 0;
}
