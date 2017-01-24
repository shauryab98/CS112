/* 
	Name: Shaurya Gupta
	Roll No: 1601cs43
	Date: 24/01/2017
	Objective: takes a two digit number, a display character and then prints out the two digit number using a 7 segement 5 character display using the display character.
*/

#include <stdio.h>

int main(void) {
	int i; // loop variable
	char display, roll[2]; // roll is the roll number as chars, display is the display character.
	// take input
	printf("Enter last two digits of your Roll.No: ");
	scanf("%c%c%*c", &roll[0], &roll[1]);
	printf("\n");
	printf("Enter the character for display: ");
	scanf("%c", &display);
	printf("\n");
	// each number has four types of lines: "*****", "*    ", "    *", "*   *" where * is the display character
	char types[4][6] = {{display, display, display, display, display, '\0'}, {display, ' ', ' ', ' ',' ', '\0'}, {' ', ' ', ' ',' ', display,'\0'}, {display, ' ', ' ', ' ',display, '\0'}};
	int digits[10][7] = {{0,3,3,3,3,3,0}, {2,2,2,2,2,2,2}, {0,2,2,0,1,1,0}, {0,2,2,0,2,2,0}, {3,3,3,0,2,2,2}, {0,1,1,0,2,2,0}, {0,1,1,0,3,3,0}, {0,2,2,2,2,2,2}, {0,3,3,0,3,3,0}, {0,3,3,0,2,2,0}}; // digits[i] stores the ith digit as a series of types perviously mentioned.
	for(i = 0; i < 2; i++) { // print each digit
		int currDigit = roll[i] - '0';
		int j; // loop varialbe
		for(j = 0; j < 7; j++) {
			printf("%s\n", types[digits[currDigit][j]]); // print each of the 7 segements
		}
		printf("\n");
	}
}
