/*
 * Exercise-11: How would you test the word count program? What kinds of input
 *              are most likely to uncover bugs if there are any?
 *
 * Here the examples of the inputs that are entered by the user and their
 * outputs.
 *
 * 1) input -> a,b,c,d e:f:g:h:i hello j@k l>m n<o p.q.r.s t<u
 *    output -> number of words:22
 *
 * 2) input -> a,b,c,d 1234 p>q hello m<t
 *    output -> 9
 *
 * 3) input -> hello#hii a,b,c,d
 *             e,f,g,h @@@@ i j k
 *             abcd
 *    output -> 14
 */

#include <stdio.h>

#define IN 1
#define OUT 0

int main(void)
{
	/*
	 * c: It stores the user input.
	 * state: Indicate whether the word is continue or not.
	 * nw: Store the word count.
	 * state_change: Check if the word is any special character or
	 *               digit.
	 */

	int c, state, nw, state_change;

	nw = 0;
	state_change = 0;
	state = OUT;

	printf("Enter your input from which you want to find the number of"
	       "words:\n");

	/*
	 * Here entered characters are compared with alphabets. If it is
	 * matches, then nw is incremented by 1; otherwise, it is not.
	 */

	while ((c = getchar()) != EOF) {
		switch (c) {
		case 'A' ... 'Z':
		case 'a' ... 'z':
			state_change = 0;
			break;
		default:
			state_change = 1;
			break;
		}
		if (state_change) {
			state = OUT;
		} else if (state == OUT) {
			state = IN;
			++nw;
		}
	}

	printf("\nnumber of words: %d\n", nw);

	return 0;
}
