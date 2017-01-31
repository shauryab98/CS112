/*
	Name: Shaurya Gupta
	Roll No. : 1601CS43
	Date: 31/01/2017
	Objective: print all numbers in given range that are perfect squares.
*/
#include <stdio.h>
#include <math.h>

int main(void) {
	int start, end, rootStart, rootEnd; // start and end of range, their square roots.
	int i; // loop variable
	printf("Enter the range of numbers: ");
	scanf("%d%*c%d%*c", &start, &end); // get output
	while(1) { // infinite loop until atleast one perfect squrare is printed.
		rootStart = ceil(sqrt((double)start)); // sqrt of starting rounded up
		rootEnd = floor(sqrt((double)end)); // sqrt of ending rounded down
		if(rootStart <= rootEnd) { // in case there's atleast one perfect square
			if(rootStart == rootEnd) // case of single perfect square
				printf("The perfect square in the given range is: %d\n", rootStart*rootStart); 
			else { // case of multiple perfect squares
				printf("The perfect squares in the given range are: ");
				for(i = rootStart; i <= rootEnd - 1; i++) {
					printf("%d, ", i*i);
				}
				printf("and %d\n", rootEnd*rootEnd);
			}
			break; // we're done, exit infinite while loop
		} else {
			// retry
			printf("No perfect square exists. Please enter another range: ");
			scanf("%d%*c%d%*c", &start, &end); // get new range
		}
	}
}