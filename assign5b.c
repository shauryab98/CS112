/*
    Name: Shaurya Gupta
    Roll No.: 1601CS43
    Date: 7/01/2017
    Objective: Displays sorted seating arrangment, searches for a given id, counts and outputs females/males, also red/blue. Also checks whether new element can be added to an array and then adds it and sorts it.
*/

#include <stdio.h>

// This function sorts list of given size. Implementation is selection sort.
void sort(int * list, int size) {
    int i, j;
    for(i = 0; i < size; i++) {
        int maxIndex = i;
        for(j = i+1; j < size; j++) {
            if(list[j] > list[maxIndex]) {
                maxIndex = j;
            }
        }
        int tmp = list[i];
        list[i] = list[maxIndex];
        list[maxIndex] = tmp;
    }
}
// THis prints out elements of given list comma separated. If rem is 4, then 5 elements on a line. If 5, then all elements on single line.
void output(int *list, int size, int rem) {
    if(size) {
    	int i = 0;
    	for(i = 0; i < size - 1; i++) {
	        printf("%d", list[i]);
        	if(i%5 == rem) printf("\n");
        	else printf(", ");
    	}
	    printf("%d\n", list[i]);
    } else printf("There are no such guests. \n");
}

int main(void) {
    int n, id[17], i; // n is number of people, id[] is the array of unique ids. i is loop variable.
    char c; // character to check when input of unique ids has ended.
    do {
        scanf("%d%c", id + n, &c);
        n++;
    } while (c != '\n'); // get input while newline character not found.
    
    sort(id, n); // sort largest to smallest.
    printf("The seating arrangement is:\n" );
    output(id, n, 4); // 4 parameter signifies that we need only 5 numbers on each line.
    
    printf("Enter the id to be searched: ");
    int new_id, found = 0; // found -> 0 means not found, 1 means found
    scanf("%d%*c", &new_id); // get id to be searched.
    for(i = 0; i < n; i++) {
        if(id[i] == new_id) {
            found = 1; // we've found it!
            printf("The guest with id %d is present in the party and is seated at position %d.\n", new_id, (n%5) + 1);
            break;
        }
    }
    if(!found) printf("The guest with id %d is not present in the party.\n", new_id); // not found.
    
    int males = 0, females = 0, fem[17], male[17], red = 0, blue = 0, redGuests[17], blueGuests[17];
    // male, fem arrays store the ids. redGuest, blueGuest store the index of red and blue elements respectively.
	// this loop counts females and males, red and blues, then stores them in arrays.
    for(i = 0; i < n; i++) {
        if(id[i] > 0) {
            fem[females] = id[i];
            females++;
        }
        else {
            male[males] = id[i];
            males++;
        }
        if(id[i] % 2 == 0) {
            redGuests[red] = i+1;
            red++;
        }
        else {
            blueGuests[blue] = i+1;
            blue++;
        }
    }
    // print males and females related output
    printf("There are %d males and %d females.\n", males, females);
    printf("The male guest id's are: ");
    output(male, males, 5); // 5 signifies that all integers should be printed on the same line;
    printf("The female guest id's are: ");
    output(fem, females, 5); // 5 signifies that all integers should be printed on the same line;
    // print red and  blue related information.
    printf("There are %d guests in red and %d guests in blue dress respectively.\n", red, blue);
    printf("The seating positions of the guests in red dress are: ");
    output(redGuests, red, 5);
    printf("The seating positions of the guests in blue dress are: ");
    output(blueGuests, blue, 5);
    printf("Enter the unique id of the new guest: ");
    scanf("%d*c", &new_id);
    if(n < 15) { // if guest capacity isn't filled.
    	printf("The new seating arrangement is: ");
        id[n] = new_id;
        n++;
        sort(id, n);
        output(id, n, 4);
    } else printf("No more guests are allowed.\n");
}