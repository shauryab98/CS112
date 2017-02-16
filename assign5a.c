/*
    Name: Shaurya Gupta
    Roll No.: 1601CS43
    Date: 7/01/2017
    Objective: Determines how many students can see the stage and whether all elements in an array are unique.
*/

#include <stdio.h>

int main(void) {
    printf("Enter the number of students participated: ");
    int numStud; // number of students
    scanf("%d%*c", &numStud); // get input
    int canSee = 0, currMaxHeight = 0, height;
    // canSee is number of students who can see the stage, currMaxHeight is the max height at a given stage in the loop, height is curr height.
    printf("Enter their heights: ");
    int i; // loop variable
    for(i = 0; i < numStud; i++) {
        scanf("%d%*c", &height);
        if(height >= currMaxHeight) {
            canSee++;
            currMaxHeight = height;
        }
    }
    printf("No. of students can see the stage: %d\n", canSee); // output
    printf("Enter the color of robes denoted by integers: "); // get robe colors
    int boysParty = 0, robes[numStud]; // boysParty  -> 0 signifies false and 1 signifies true. robes are colors
    for(i = 0; i < numStud; i++) {
        scanf("%d", robes+i);
        int j;
        for(j = 0; j < i; j++) {
            if(robes[j] == robes[i]) {
                boysParty = 1; // if any equal color robes, boys party
            }
        }
    }
    if(boysParty) printf("It is a BOYS party.\n"); // boys party
    else printf("It is a GIRLS party.\n"); // girls party
}