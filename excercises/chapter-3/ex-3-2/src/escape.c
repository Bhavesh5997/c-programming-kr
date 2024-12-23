/*
 * This function replace actual newline by \n and tab by \t and when user enter
 * \n and \t manually then this escape characters are replace with actual
 * newline and tab in the string s, which is copied from string t.
 */

#include <stdio.h>
#include "escape.h"

void escape(char s[], char t[])
{
	/*
	 * i: Use to access the string t index.
	 * j: Use to access the string s index.
	 */
	int i = 0, j = 0;

	/*
	 * When string t index have '\n' or '\t', then string s assign that
	 * index by '\' and next index by 'n', otherwise string t characters
	 * are assign to string s.
	 */
	while (t[i] != EOF) {
		switch (t[i]) {
		case '\n':
			s[j] = '\\';
			s[j + 1] = 'n';
			j++;
			break;
		case '\t':
			s[j] = '\\';
			s[j + 1] = 't';
			j++;
			break;
		default:
			s[j] = t[i];
		}
		i++;
		j++;
	}

	s[j] = EOF;
}

void unescape(char s[])
{
	/*
	 * i: Use to access the string t index.
	 * j: Use to access the string s index.
	 */
	int i = 0, j = 0;

	/*
	 * When string s index have '\' and next index 'n' or 't', then
	 * string s assign that index by '\n' or '\t'.
	 */
	while (s[i] != EOF) {
		switch (s[i]) {
		case '\\':
			if (s[i + 1] == 'n') {
				s[j] = '\n';
				i += 2;
			} else if (s[i + 1] == 't') {
				s[j] = '\t';
				i += 2;
			} else {
				s[j] = s[i];
			}
			break;
		default:
			s[j] = s[i];
			i++;
		}
		j++;
	}

	s[j] = '\0';
}
