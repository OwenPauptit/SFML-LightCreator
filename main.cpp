#include <iostream>
#include <SFML/Graphics.hpp>
#include "PointLight.h"
#include "LightRay.h"
#include "OpaqueObject.h"
#include <vector>

int main() {
	sf::RenderWindow window(sf::VideoMode(640, 480), "Light");
	window.setVerticalSyncEnabled(true);

	int numRays = 100000;

	std::vector <OpaqueObject> objects = {  /*OpaqueObject(400,400,600,300), */OpaqueObject(280,160,210,240)};
	std::vector <PointLight> plights = { PointLight(numRays, 100, 300, 240, objects) };

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:

				window.close();
			}
		}
		window.clear(sf::Color::Black);
		for (int k = 0; k < plights.size(); k++){
			for (int i = 0; i < plights[k].light.size(); i++) {
				window.draw(plights[k].light[i].ray);
			}
		}
		for (int i = 0; i < objects.size(); i++) {
			window.draw(objects[i].line);
		}
		window.display();
	}

	return 0;
}