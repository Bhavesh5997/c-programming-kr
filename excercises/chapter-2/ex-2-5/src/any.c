#include <stdio.h>
#include "any.h"

/*
 * When string 1 and string 2 have the same characters during comparison, then
 * this function return it's location from string 1, otherwise it return -1.
 */
int any(char s1[], char s2[])
{
	/*
	 * i, j: i for accessing str2 index in outler loop and j for accessing
	 *	 str1 in inner loop.
	 */
	int i, j;

	for (i = 0; s2[i] != '\n'; i++) {
		for (j = 0; s1[j] != '\n'; j++) {
			if (s2[i] == s1[j])
				return j;
		}
	}

	return -1;
}
