#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "LightRay.h"
#include "PointLight.h"
#include <vector>
#include <iostream>

PointLight::PointLight(double rayNum, int intens, int ox, int oy) {
	originX = ox;
	originY = oy;
	intensity = intens;
	numRays = rayNum;
	angle = 360 / rayNum;
	std::cout << angle << std::endl;
	double currentAngle = 0, x, y, temp;
	std::vector<std::vector<double>> coords;
	std::vector<double> t;

	for (int r = 0; r < numRays; r++) {
		currentAngle += angle;
		std::cout << currentAngle << std::endl;
		if (currentAngle == 0 || currentAngle == 360) {
			y = -1 * intensity;
			x = 0;
		}
		else if (currentAngle == 180) {
			y = intensity;
			x = 0;
		}
		else if (currentAngle == 90) {
			y = intensity;
			x = 0;
		}
		else if (currentAngle == 270) {
			y = -1 * intensity;
			x = 0;
		}
		else{

			if (currentAngle < 90) {
				temp = currentAngle;
			}
			else if (currentAngle < 180) {
				temp = 180 - currentAngle;
			}
			else if (currentAngle < 270) {
				temp = 270 - currentAngle;
			}
			else if (currentAngle < 360) {
				temp = 360 - currentAngle;
			}

			x = intensity * sin(temp);
			y = intensity * cos(temp);

		}
		x += originX;
		y += originY;
		t = { x,y };
		coords.push_back(t);
	}
	for (int i = 0; i < coords.size(); i++) {
		light.push_back(LightRay(originX, originY, coords[i][0], coords[i][1]));
	}
}