/*
	Name: Shaurya Gupta
	Roll No: 1601CS43
	Date: 7/03/2017
	Objective: Takes strings and stores them in dynamically allocated array, then sorts and prints it back out.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// comparator function for qsort
int compFunc (const void*, const void*);

int main(v0id) {
	char buffer[35]; // buffer to store names
	int numNames, i; // number of names and loop variable
	scanf("%d", &numNames);
	char **names = (char**)malloc(numNames * sizeof(char*)); // allocate array containing pointers to char*
	while(getchar() != '\n') {} // remove newline
	// get string in buffer and store in dynamically allocated space for string
	for(i=0; i < numNames;i++) {
		scanf("%s", buffer);
		names[i] = (char*) malloc(sizeof(char)*(1+strlen(buffer)));
		strcpy(names[i], buffer);
	}
	// sort the names
	qsort(names, numNames, sizeof(char*), compFunc);
	// print each name
	for(i = 0; i < numNames; i++)
		printf("%s\n", names[i]);
	// free each string
	for(i = 0; i < numNames; i++)
		free(names[i]);
	// free the initially allocated char** array
	free(names);
	return 0;	
}

int compFunc (const void *a, const void *b) {
	return (strcmp(*(char**)a, *(char**)b));
}
