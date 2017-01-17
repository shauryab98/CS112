/*
	Name: Shaurya Gupta
	Roll No: 1601CS43
	Date: 17/01/2017
	Objective: Take x, y minutes as input and find who wins the race and by what distance.
*/
#include <stdio.h>

int main(void) {
	double x,y, timeHare, timeTortoise = 20.0; // timeForTortoise to reach finish line is a fixed value
	// take input from user, x, y
	printf("Enter X = ");
	scanf("%lf%*c", &x);
	printf("Enter Y = ");
	scanf("%lf%*c", &y);
	// if the hare reaches the finish line within x minutes, y becomes useless
	if(x >= 18/1.4)
		y = 0;
	// calculate time for hare, it's speed is 1.4
	timeHare = 18/1.4 + y;
	// if Tortoise reaches first
	if(timeHare > timeTortoise) {
		printf("Winner: Tortoise\n");
		printf("Winning distance margin: %.1lf metres\n", 18.0 - 1.4*(timeTortoise - y));
	}
	// if hare wins
	else if(timeHare < timeTortoise) {
		printf("Winner: Hare\n");
		printf("Winning distance margin: %.1lf metres\n", 18.0 - 0.9*timeHare);		
	}
	// tie condition
	else {
		printf("Winner: Both\n");
		printf("Winning distance margin: %d metres\n", 0);		
	}
}
