#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "LightRay.h"

class PointLight {
private:
	int intensity, originX, originY;
	double numRays, angle;
public:
	std::vector<LightRay> light;
	PointLight(double, int, int, int);
};