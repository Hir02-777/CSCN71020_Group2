#include <stdio.h>
#include <stdbool.h>

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

		double angle1 = calculateangle(side1, side2, side3);
		double angle2 = calculateangle(side2, side3, side3);
		double angle3 = calculateangle(side3, side1, side2);
		result = "Equilateral triangle, the three angles in the triangle are: \n"
				 "%.2f degrees\n", angle1);
				 "%.2f degrees\n", angle2);
				 "%.2f degrees\n", angle3);
		

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
	double cosangle = (b * b + c * c - a * a) / (2 * b * c);
	double angle = acos(cosangle) *180/3.14159265;
	return angle;

}