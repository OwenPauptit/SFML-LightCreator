#pragma once

class Point {
public:
	Point(int, int);
	int x, y;
};

Point getIntersect(Point, Point, Point, Point);