#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include "triangleSolver.h"
#define M_PI 3.14159265358979323846


char* analyzeTriangle(int side1, int side2, int side3) {
	char* result = "";
	
	if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
		result = "Not a triangle, the length cannot be negative";
	}
	else if ((side1 + side2) < side3 || (side2 + side3) < side1 || (side1 + side3) < side2) {
		result = "Cannot form a triangle, the sum of two sides must be bigger than the third for all three combinations.";
	}
	else if (side1 == side2 && side2 == side3) {
		
		result = "Equilateral triangle";
			
		}
	else if ((side1 == side2 && side1 != side3) || 
		(side1 == side3 && side1 != side2))
	{	
		double angle1 = calculateangle(side1, side2, side3);
		result = "Isosceles triangle";
	}
	else {
		double angle2 = calculateangle(side1, side2, side3);
		result = "Scalene triangle";
	}
	
	return result;
}

double calculateangle(int a, int b, int c) {
	double cosine = (double)(b * b + c * c - a * a) / (2.0 * b * c);

	// Ensure the cosine value is within the valid range [-1, 1] for acos()
	if (cosine < -1.0) { cosine = -1.0; }
	if (cosine > 1.0){ cosine = 1.0;}

	double angle_radians = acos(cosine);

	double angle = angle_radians * (180.0 / M_PI);
	return angle;

	}
	


void printangle(int a, int b, int c) {
	double angle1 = calculateangle(a, b, c);
	double angle2 = calculateangle(b, a, c);
	double angle3 = calculateangle(c, a, b);
	printf("First angle: %.2f degrees", angle1);
	printf("Second angle: %.2f degrees", angle2);
	printf("Third angle: %.2f degrees", angle3);
}