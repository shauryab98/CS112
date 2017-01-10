/*
	Name: Shaurya Gupta
	Roll No: 1601cs43
	Date: 10/01/2017
	Objective: Encrypts first input and decrypts second input according to defined encyrption scheme.
*/
#include <stdio.h>

int main(void) {
	char input[4], tmp;
	int i;
	// encryption
	printf("Enter the four digit number to be encrypted: ");
	for(i = 0; i < 4; i++) {
		scanf("%c", &input[i]);
		input[i] = (char)(((input[i] - '0') + 7) % 10 + '0');	
	}
	scanf("%c", &tmp); // ignore newline character
	// swap
	tmp = input[0];
	input[0] = input[2];
	input[2] = tmp;
	tmp = input[1];
	input[1] = input[3];
	input[3] = tmp;
	// give output
	printf("The encrypted number: ");
	for(i = 0; i < 4; i++)
		printf("%c", input[i]);
	printf("\n");
	// decryption
	printf("Enter the four digit number to be decrypted: ");
	for(i = 0; i < 4; i++) {
		scanf("%c", &input[i]);
		input[i] = (char)(((input[i] - '0') + 3) % 10 + '0');	
	}
	// swap
	tmp = input[0];
	input[0] = input[2];
	input[2] = tmp;
	tmp = input[1];
	input[1] = input[3];
	input[3] = tmp;
	// give output
	printf("The decrypted number: ");
	for(i = 0; i < 4; i++)
		printf("%c", input[i]);
	printf("\n");
}	
