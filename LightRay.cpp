#include "LightRay.h"
#include "OpaqueObject.h"
#include "Point.h"
#include <iostream>

LightRay::LightRay(int x0, int y0, int x1, int y1, std::vector<OpaqueObject> obj) {
	originColour = sf::Color(255, 255, 255, 255);
	ray = sf::VertexArray(sf::Lines, 2);
	ray[0].position = sf::Vector2f(x0,y0);
	ray[1].position = sf::Vector2f(x1, y1);
	ray[0].color = originColour;
	ray[1].color = sf::Color::Transparent;
	checkRay(obj);
}

void LightRay::checkRay(std::vector<OpaqueObject> obj) {

	sf::Rect<float> rayRect = ray.getBounds();

	for (int i = 0; i < obj.size(); i++) {

		sf::Rect<float> oRect = obj[i].line.getBounds();

		if (rayRect.intersects(oRect)) {
			Point r1 = Point(ray[0].position.x, ray[0].position.y);
			Point r2 = Point(ray[1].position.x, ray[1].position.y);
			Point l1 = Point(obj[i].line[0].position.x, obj[i].line[0].position.y);
			Point l2 = Point(obj[i].line[1].position.x, obj[i].line[1].position.y);
			Point intersect = getIntersect(r1, r2, l1, l2);

			/*double x = abs(ray[1].position.x - ray[0].position.x);
			double y = abs(ray[1].position.y - ray[0].position.y);
			double oldl = sqrt(pow(x, 2) + pow(y, 2));

			x = abs(intersect.x - ray[0].position.x);
			y = abs(intersect.y - ray[0].position.y);
			double newl = sqrt(pow(x, 2) + pow(y, 2));
			if (newc < 0) {
				newc = 0;
			}
			ray[0].color = originColour;*/

			double x = abs(ray[1].position.x - ray[0].position.x);
			double y = abs(ray[1].position.y - ray[0].position.y);
			double oldl = ceil(sqrt(pow(x, 2) + pow(y, 2)));
			x = abs(intersect.x - ray[0].position.x);
			y = abs(intersect.y - ray[0].position.y);
			double newl = sqrt(pow(x, 2) + pow(y, 2));
			//std::cout << "Old:" << oldl << "   New:" << newl << std::endl;
			if (newl < oldl) {
				ray[1].position = sf::Vector2f(intersect.x, intersect.y);
				/*double newc = 1 - (newl / oldl);
				newc *= 255;
				std::cout << newc << std::endl;
				ray[1].color = sf::Color(255, 255, 255, newc);*/
			}

		}
	}
}

