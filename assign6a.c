/*
	Name: Shaurya Gupta
	Roll No: 1601CS43
	Date: 14/02/2017
	Objective: prints all unique permutations of given letters.
*/

#include <stdio.h>
#include <stdlib.h>


int started = 0; // bool type integer to make sure that comma is not printed before first permutation.

// this function returns 1 if the str is unique. Else 0.
// str is string to check, index is array of lexicographic index of each letter, size is number of letters.
int check(char * str, int * index, int size) {
	int i, j;
	for(i = 0; i < size; i++) {
		for(j = 0; j < i; j++) {
			if(str[i] == str[j] && index[i] < index[j]) // if same letters but wrong lexicographic order, duplicate
				return 0;
		}
	}
	return 1; // not duplicate
}
// Using backtracking, this function generates permutations and outputs them
// input is sequence to permute, output is array to print
// len is current length of output, maxlen is number of letters
// done array stores whether each letter has been used or not, index stores the initial lexicographic order of each letter in output
void recurse(char* input, char* output, int len, int maxlen, int* done, int* index) {
	// terminating case
	if(len == maxlen) {
		if(check(output, index, maxlen)) { // check if unique output
			if(started) printf(",");
			printf("%s", output); // print permutation
			started = 1; // we have started printing.
		}
		return;
	}
	int i; // loop variable
	for(i = 0; i < maxlen; i++) {
		if(!done[i]) { // if ith letter is not in current output
			done[i] = 1; // we're using this letter now
			index[len] = i; // store index of character at position len in the output
			output[len] = input[i]; // add to current output
			recurse(input, output, len+1, maxlen, done, index); // recursive call
			done[i] = 0; // not using ith character now.
		}
	}
}
// comparator function used for sorting letters.
int cmpfunc (const void * a, const void * b)
{
   return ( (*(char*)a) - (*(char*)b) );
}

int main(void) {
	// get input
	int num;
	printf("Number of letters: ");
	scanf("%d%*c", &num);
	char letters[num], output[num+1]; // letters contains the input letters, output is sequence of output letters.
	int done[num]; // stores whether ith letter has been used in output
	int outputIndex[num+1]; // corresponding to output char array, this array contains original index of each letter used. 
	printf("Enter the letters: ");		
	int i; // loop variable
	// get letters, set done to 0.
	for(i = 0; i < num; i++) {
		scanf("%c%*c", letters+i);
		done[i] = 0;
	}		
	qsort(letters, num, sizeof(char), cmpfunc); // sort the letters
	output[num] = '\0'; // string ends with null character
	printf("The possible words are: ");	
	recurse(letters, output, 0, num, done, outputIndex); // base call
	printf("\n");
	return 0;
}