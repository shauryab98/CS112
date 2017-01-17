/*
	Name: Shaurya Gupta
	Roll No: 1601CS43
	Date: 17/01/2017
	Objective: Take three points as inputs and check whether collinear or not. If not, output area as well as whether it is acute/obtuse/right.
*/

#include <stdio.h>
#include <math.h>

#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y)) //Macro for maximum of two numbers

int main(void) {
	int i, typeTriangle = 0; //typeTriangle: 0:acute 1:obtuse 2:right
	double points[3][2], area, sideSquare[3], s = 0, sumOfSquares = 0, squareOfLargest = 0, diffSquares;
	// take input from user
	printf("Enter the points:\n");
	for(i = 0; i < 3; i++) {
		printf("Point%d: ", i+1);
		scanf("%*c%lf%*c%lf%*c%*c", &points[i][0], &points[i][1]);		
	}
	// this loop finds square of each side, square of largest side and sum of squares of all sides.
	for(i = 0; i < 3; i++) {
		sideSquare[i] = (pow(points[i][0] - points[(i+1)%3][0], 2) + pow(points[i][1] - points[(i+1)%3][1], 2));
		squareOfLargest = MAX(sideSquare[i], squareOfLargest);
		sumOfSquares += sideSquare[i];
	}
	// calculate area from coordinates using standard formula
	area = ((points[0][0]*(points[1][1] - points[2][1])) + (points[1][0]*(points[2][1] - points[0][1])) + (points[2][0]*(points[0][1] - points[1][1])))/2.0;
	if(area < 0) area = -area; // area is non-negative
	// if area is 0, they are collinear
	if(area == 0) {
		printf("The points are collinear.\n");
	}
	else {
		diffSquares = sumOfSquares - 2*squareOfLargest;  //diffSquares is b^2+c^2-a^2 where a is largest side
		if(diffSquares == 0) typeTriangle = 1; // right angled
		else if(diffSquares < 0) typeTriangle = 2; // obtuse
		// give output
		if(typeTriangle == 0)
			printf("The points are non-collinear. The formed triangle is an acute triangle with area = %lf.\n", area);
		else if(typeTriangle == 1)
			printf("The points are non-collinear. The formed triangle is a right-angled triangle with area = %lf.\n", area);
		else
			printf("The points are non-collinear. The formed triangle is an obtuse triangle with area = %lf.\n", area);			
	}
}
