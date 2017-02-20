/*
	Name: Shaurya Gupta
	Roll No: 1601CS43
	Date: 14/02/2017
	Objective: Output all possible unique combinations of possible overs for a given number of total overs and bowlers
*/

#include <stdio.h>


int overs, maxOvers, bowlers; // global variables to make sure that recursive functions are neat with few arguments.

// returns minimum of two numbers
int min(int a, int b) {
	if(a < b)
		return a;
	return b;
}
// outputs elements of array on a line.
void print(int * array) {
	int i = 0;
	for(; i  < bowlers-1; i++) {
		printf("%d ", array[i]);
	}
	printf("%d\n", array[bowlers-1]);
}
// recursive function to get combinations.
// bowler is the current bowler index
// last is the number of overs for the last bowler
// oversLeft is the number of overs that can still be bowled
// output is the pointer to output array
void backtrack(int bowler, int last, int oversLeft, int * output) {
	// terminating condition
	if(bowler == bowlers) {
		if(oversLeft == 0) print(output); // print output only if 0 overs left.
		return;
	}
	
	int i; // loop variable for overs of current bowler
	for(i = min(min(maxOvers, oversLeft), last); i >= 0; i--) { // min condition makes sure that combinations are unique and satisfy constraints.
		output[bowler] = i; // add to output
		backtrack(bowler+1, i, oversLeft - i, output); // recursive call for next bowler
	}
}


int main(void) {
	// get input.
	printf("Total overs: ");
	scanf("%d%*c", &overs);
	printf("Maximum number of overs for one bowler: ");
	scanf("%d%*c", &maxOvers);
	printf("Number of bowlers: ");
	scanf("%d%*c", &bowlers);
	int output[bowlers+1]; // output array
	backtrack(0, overs, overs, output); // inital backtrack call
	return 0;
}