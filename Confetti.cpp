#include "Confetti.h"

Confetti::Confetti(sf::Vector2f position) : Particle(position) {
	getShape().setFillColor(sf::Color::Red);
}

void  Confetti::update(sf::Time dt, sf::RenderWindow &window) {
	Particle::update(dt, window);
	getShape().setRotation(sf::degrees(30));
	getShape().setFillColor(sf::Color::Red);
}
