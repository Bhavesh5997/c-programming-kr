/*
 * This function simply expand the shorthand notation like a-z into
 * abc ... xyz, 0-9 into 0123 ... 789, a-z0-9 into abc ... xyz0123 ... 789.
 * It's also handle cases like -a-z and a-b-c also.
 */

#include <stdio.h>
#include <ctype.h>
#include "expand.h"

int expand(char s1[], char s2[])
{
	/* ch: Temporary variable it's store before '-' character from str1 */
	char ch;
	int j = 0;

	/* Expand the str1 into str2 if expandable. */
	for (int i = 0; s1[i] != '\n'; i++) {
		if (s1[i] == '-' && i > 0 && s1[i + 1] != '\n' &&
		    ((s1[i - 1] >= '0' && s1[i + 1] <= '9') ||
		    (s1[i - 1] >= 'A' && s1[i + 1] <= 'Z') ||
		    (s1[i - 1] >= 'a' && s1[i + 1] <= 'z')) &&
		    (s1[i + 1] != '-')) {
			if (s1[i - 1] < s1[i + 1]) {
				ch = s1[i - 1] + 1;

				/* Expand str1 into str2 in forward direction */
				while (ch < s1[i + 1])
					s2[j++] = ch++;
			} else {
				ch = s1[i - 1] - 1;

				/* Expand str1 into str2 in reverse direction */
				while ((ch > s1[i + 1]) && (isdigit(ch) || isalpha(ch)))
					s2[j++] = ch--;
			}
		} else {
			s2[j++] = s1[i];
		}
	}

	return j;
}
