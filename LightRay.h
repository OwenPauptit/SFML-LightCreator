#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class LightRay {
public:
	sf::VertexArray ray;
	LightRay(int, int, int, int);
};