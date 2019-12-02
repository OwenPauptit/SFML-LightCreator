#include "LightRay.h"
#include <iostream>
#include <vector>

LightRay::LightRay(int x0, int y0, int x1, int y1) {
	ray = sf::VertexArray(sf::Lines, 2);
	ray[0].position = sf::Vector2f(x0,y0);
	ray[1].position = sf::Vector2f(x1, y1);
	ray[0].color = sf::Color::White;
	ray[1].color = sf::Color::Transparent;
}