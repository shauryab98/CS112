/* 
	Name: Shaurya Gupta
	Roll No: 1601cs43
	Date: 24/01/2017
	Objective: takes number of months and then returns number of ways of building ships.
*/

#include <stdio.h>

int main(void) {
	int month, i; // i is loop variable
	printf("Enter the month after which the area is to be closed: ");
	scanf("%d", &month); // take input
	int memo[month+1]; // this is a memoization/dp table
	memo[0] = 0; memo[1] = 1; memo[2] = 2; // base cases
	printf("\n");
	for(i = 3; i <= month; i++) {
		memo[i] = memo[i-1] + memo[i-2]; // recurrence relation
	}
	printf("There are %d choices of plan.\n", memo[month]); // give output
}
