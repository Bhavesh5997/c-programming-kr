/*
 * Here are the two versions of the binsearch function. Both are used to find
 * the target index from the sorted array by comparing its middle index.
 */

#include <stdio.h>
#include "binsearch.h"

int binsearch_original(int x, int v[], int n)
{
	/*
	 * low: It store the 0th index of array.
	 * high: It store the (n-1)th index of array.
	 * mid: It store the middle index of array.
	 */
	int low, high, mid;

	low = 0;
	high = n - 1;

	/* Find the target index by comparing with middle index of array. */
	while (low <= high) {
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else
			return mid;
	}

	return -1;
}

int binsearch_modified(int x, int v[], int n)
{
	/*
	 * low: It store the 0th index of array.
	 * high: It store the (n-1)th index of array.
	 * mid: It store the middle index of array.
	 */
	int low, high, mid;

	low = 0;
	high = n - 1;
	mid = (high + low) / 2;

	/* Find the target index by comparing with middle index of array. */
	while (low <= high && v[mid] != x) {
		if (v[mid] > x)
			high = mid - 1;
		else
			low = mid + 1;

		mid = (high + low) / 2;
	}

	if (v[mid] == x)
		return mid;
	else
		return -1;
}
