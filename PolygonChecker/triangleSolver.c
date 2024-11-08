#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "triangleSolver.h"

char* analyzeTriangle(int side1, int side2, int side3) {
	char* result = "";
	if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
		result = "Not a triangle";
	}
	else if ((side1 + side2) < side3 || (side2 + side3) < side1 || (side1 + side3) < side2) {
		result = "Cannot form a triangle";
	}
	else if (side1 == side2 && side1 == side3) {

		result = "Equilateral triangle ";
			
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

int calculateangle(int a, int b, int c) {
	double cosangle = (b * b + c * c - a * a) / (2 * b * c);
	double angle = acos(cosangle) *(180/3.14159265);
	

	
}

int printangle(int a, int b, int c) {
	double angle1 = calculateangle(a, b, c);
	double angle2 = calculateangle(b, a, c);
	double angle3 = calculateangle(c, a, b);
	printf("First angle: %.2f degrees", angle1);
	printf("Second angle: %.2f degrees", angle2);
	printf("Third angle: %.2f degrees", angle3);
	return 0;
}