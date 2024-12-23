/*
 * Exercise-1: Our binary search makes two tests inside the loop, when one
 *	       would suffice (at the price of more tests outside.) Write a
 *	       version with only one test inside the loop and measure the
 *	       difference in run−time.
 *
 * Here the examples of the inputs that are entered by the user and their
 * outputs.
 *
 * 1)
 * Enter number of elements for array: 6
 * Enter your 1D array:
 * 3
 * 4
 * 6
 * 1
 * 3
 * 2
 * Entered array after sorting:
 * 1 2 3 3 4 6
 * Enter your target: 200
 * Target not found in binary_original: -1
 * Target not found in binary_modified: -1
 * Run time difference between binsearch_original and binsearch_modified:
 * 0.000002 Seconds
 *
 * 2)
 * Enter number of elements for array: 7
 * Enter your 1D array:
 * 11
 * 21
 * 22
 * 12
 * 13
 * 56
 * 58
 * Entered array after sorting:
 * 11 12 13 21 22 56 58
 * Enter your target: 11
 * target index = 0
 * target index2 = 0
 * Run time difference between binsearch_original and binsearch_modified:
 * 0.000002 Seconds
 */

#include <stdio.h>
#include <time.h>
#include "binsearch.h"

#define MAXSIZE 100

int main(void)
{
	/*
	 * arr: Array with maximum 100 int elements
	 * n: It stores the number of elements of array.
	 * target: It stores the input from the user.
	 * target_index, target_index2: target_index and target_index2 are
	 *	                        stores the return values of
	 *	                        binsearch_original and
	 *	                        binsearch_modified respectively.
	 * temp: Temporary variable for store array element, during sorting
	 *	 of array.
	 * t1, t2: Stores the cpu cycles for binsearch_original and
	 *	   binsearch_modified.
	 * time1, time2: stores the time for binsearch_original and
	 *	         binsearch_modified respectively.
	 * time_diff: It stores the runtime difference of binsearch_modified
	 *	      and binsearch_original.
	 */
	int arr[MAXSIZE], n, target, target_index, target_index2, temp;
	clock_t t1, t2;
	float time1, time2, time_diff;

	printf("Enter number of elements for array: ");
	scanf("%d", &n);

	if (n <= 0 || n > MAXSIZE) {
		printf("Invalid input\n");
		return -1;
	}

	printf("Enter your 1D array:\n");
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	printf("Entered array after sorting:\n");

	/* Sorting of the array in ascending order. */
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] > arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);

	printf("\nEnter your target: ");
	scanf("%d", &target);

	t1 = clock();
	target_index = binsearch_original(target, arr, n);
	t1 = clock() - t1;
	time1 = ((float)t1)/CLOCKS_PER_SEC;
	t2 = clock();
	target_index2 = binsearch_modified(target, arr, n);
	t2 = clock() - t2;
	time2 = ((float)t2)/CLOCKS_PER_SEC;

	if (target_index == -1 && target_index2 == -1) {
		printf("Target not found in binsearch_original: %d\n",
		       target_index);
		printf("Target not found in binsearch_modified: %d\n",
		       target_index2);
	} else {
		printf("target using binsearch_original at array index = %d\n",
		       target_index);
		printf("target in binsearch_modified at array index = %d\n",
		       target_index2);
	}

	time_diff = time1 - time2;

	printf("Run time difference between binsearch_original and "
	       "binsearch_modified: %f Seconds\n", time_diff);

	return 0;
}
