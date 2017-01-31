/*
	Name: Shaurya Gupta
	Roll No. : 1601CS43
	Date: 31/01/2017
	Objective: takes two numbers and outputs their binary rep, hamming weight, hamming distance and hex representation.
*/

#include <stdio.h>
#include <string.h>

// this function reverse the given string of length len
void reverse(char *s, int len) {
	int i = 0;
	char tmp;
	for(; i < len/2; i++) {
		tmp = s[i];	
		s[i] = s[len - i - 1];
		s[len - i - 1] = tmp;
	}	
}

// this function returns length of binary string as well as modifies output string to contain binary of int x.
int binary(int x, char *output) {
	int len = 0;
	while(x) {
		output[len] = (x%2) + '0';
		x /= 2;
		len++;
	}
	output[len] = '\0';
	reverse(output, len);
	return len;
}

// this function returns the hamming weight of given binary
int hamWeight(char *s1, int len) {
	int weight = 0, i = 0;
	for(; i < len; i++)
		weight += (s1[i] == '1') ? 1 : 0;
	return weight; 
}
// this function returns hamming distance of strings s1 and s2 of same length len
int hamDist(char *s1, char *s2, int len) {
	int dist = len, i = 0;
	for(; i < len; i++)
		dist -= (s1[i] == s2[i]) ? 1 : 0;
	return dist;
}
// this function takes in pointers to binary and hex as well as the length of binary, then stores hexadecimal value in hex.
void binToHex(char *bin, char *hex, int len) {
	int i = len - 1, hexlen = 0;
	for(; i > len%4; i-=4) {
		int digit = (bin[i] - '0') * 1 + (bin[i-1] - '0') * 2 + (bin[i-2] - '0') * 4 + (bin[i-3] - '0') * 8;
		hex[hexlen] = (digit <= 9) ? digit + '0': (digit - 10 + 'A');
		hexlen++;
	}
	if(i >= 0) {
		int currPow = 1, digit = 0;
		for(; i >= 0; i--) {
			digit += currPow * (bin[i] - '0');
			currPow *= 2;
		}
		hex[hexlen] = (digit <= 9) ? digit + '0': (digit - 10 + 'A');
		hexlen++;
	}
	hex[hexlen] = '\0';
	reverse(hex, hexlen);
}

int main(void) {
	int i, a, b;
	char binA[35], binB[35], hexA[10], hexB[10]; // stores binary and hexadecimal respectively
	printf("Enter two decimal integers: ");
	scanf("%d%*c%d", &a, &b); // take input
	int lenA, lenB; // length of binary string representation of each number
	// generate binary
	lenA = binary(a, binA);
	printf("The binary representation for %d is %s\n", a, binA);
	lenB = binary(b, binB);	
	printf("The binary representation for %d is %s\n", b, binB);
	// output hamming weights
	printf("Hamming weight for the first string = %d\n", hamWeight(binA, lenA));
	printf("Hamming weight for the second string = %d\n", hamWeight(binB, lenB));
	// if same length of binary, output their hamming distances.
	if(lenA == lenB)
		printf("Hamming distance between the two strings = %d\n", hamDist(binA, binB, lenA));
	// generate hexadecimal
	binToHex(binA, hexA, lenA); 
	binToHex(binB, hexB, lenB);
	// output their hexadecimal 
	printf("The hexadecimal representation for the first string = %s\n", hexA);
	printf("The hexadecimal representation for the second string = %s\n", hexB);
}