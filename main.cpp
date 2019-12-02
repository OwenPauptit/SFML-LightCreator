#include <iostream>
#include <SFML/Graphics.hpp>
#include "PointLight.h"
#include "LightRay.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(640, 480), "Light");
	window.setVerticalSyncEnabled(true);

	int numRays = 100000;

	PointLight plight = PointLight(numRays, 400, 300, 240);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
			}
		}
		window.clear(sf::Color::Black);
		for (int i = 0; i < plight.light.size(); i++) {
			window.draw(plight.light[i].ray);
		}
		window.display();
	}
}