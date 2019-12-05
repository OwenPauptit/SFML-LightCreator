#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class OpaqueObject {
private:
	sf::Color colour = sf::Color::Blue;
public:
	sf::VertexArray line;
	OpaqueObject(int, int, int, int);
};