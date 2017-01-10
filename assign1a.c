/*
	Name: Shaurya Gupta
	Roll No: 1601cs43
	Date: 10/01/2017
	Objective: Gets the height and weight of a person and returns the BMI and weight category.
*/

#include <stdio.h>

int main(void) {
	float weight, height, bmi;
	// get input and calculate bmi
	printf("Please enter your weight and height (separated by comma): ");
	scanf("%f,%f", &weight, &height);
	bmi = weight/height/height;
	printf("Your BMI is: %.1f and you are ", bmi);
	// according to bmi, give the weight category.	
	if(bmi < 18.45)
		printf("underweight.\n");
	else if(bmi < 24.95)
		printf("normal.\n");
	else if(bmi < 29.95)
		printf("overweight.\n");
	else printf("obese.\n");
	return 0;
}
