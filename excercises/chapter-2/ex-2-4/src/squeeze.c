#include <stdio.h>
#include <string.h>
#include "squeeze.h"

/* This function remove matched charcters from str 1, which are in str 2. */
void squeeze(char s1[], char s2[])
{
	/*
	 * i, j, k: i for accessing str2 index in outer loop, j for accessing
	 *	    str1 index in inner loop and k for define new index for
	 *	    str1.
	 * str1_len: store the str1 length.
	 */
	int i, j, k, str1_len;

	str1_len = strlen(s1);

	for (i = 0; s2[i] != '\n'; i++) {
		for (j = 0, k = 0; j <= str1_len; j++) {
			if (s1[j] != s2[i]) {
				s1[k] = s1[j];
				k++;
			}
		}
	}

	printf("string-1 after removing the matched characters with "
	       "string-2: %s", s1);
}
