/*
	Name: Shaurya Gupta
	Roll No: 1601cs43
	Date: 10/01/2017
	Objective: Calculates price of ticket according to 
*/

#include <stdio.h>
#define TOTAL 700

int main(void) {
	char tmp;
	float base, fare;
	int remSeats, usedSeats;
	// GET INPUT
	printf("Enter the base fare: ");
	scanf("%f", &base);
	fare = base;
	printf("Enter the remaining seats: ");
	scanf("%d", &remSeats);
	usedSeats = TOTAL - remSeats;
	// CALCULATE FARE
	if(usedSeats >= TOTAL/2)
		fare = 1.5*base;
	else {
		usedSeats -= TOTAL/10;
		while(usedSeats > 0) {
			fare += base/10;
		usedSeats -= TOTAL/10;
		}
		if(fare > 1.5*base)
			fare = 1.5*base;
	}
	printf("Your ticket price is: %.2f\n", fare);
}
