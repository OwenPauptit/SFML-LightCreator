#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "OpaqueObject.h"

class LightRay {
private:
	sf::Color originColour;
	void checkRay(std::vector<OpaqueObject>);
public:
	sf::VertexArray ray;
	LightRay(int, int, int, int, std::vector<OpaqueObject>);
};