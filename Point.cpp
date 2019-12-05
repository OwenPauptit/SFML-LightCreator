#include <iostream>
#include "Point.h"

Point::Point(int x0, int y0) {
	x = x0;
	y = y0;
}

Point getIntersect(Point A, Point B, Point C, Point D) {
	double a1 = B.y - A.y;
	double b1 = A.x - B.x;
	double c1 = a1 * (A.x) + b1 * (A.y);

	// a2x + b2y = c2;
	double a2 = D.y - C.y;
	double b2 = C.x - D.x;
	double c2 = a2 * (C.x) + b2 * (C.y);

	// determinant
	double det = a1 * b2 - a2 * b1;

		// parallel line
		/*if det == 0:
	return (float('inf'), float('inf'))*/

		// intersect point(x, y)
	double x = ((b2 * c1) - (b1 * c2)) / det;
	double y = ((a1 * c2) - (a2 * c1)) / det;
	Point intersect = Point(x, y);
	return intersect;
}