#include "OpaqueObject.h"
#include <iostream>
#include <SFML/Graphics.hpp>

OpaqueObject::OpaqueObject(int x0, int y0, int x1, int y1) {
	line = sf::VertexArray(sf::Lines, 2);
	line[0].position = sf::Vector2f(x0, y0);
	line[1].position = sf::Vector2f(x1, y1);
	line[0].color = colour;
	line[1].color = colour;
}