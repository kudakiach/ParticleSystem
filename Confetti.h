#pragma once
#include <SFML/Graphics.hpp>
#include "Particle.h"
class Confetti : public Particle
{
public:
	Confetti(sf::Vector2f position);

	void update(sf::Time dt, sf::RenderWindow& window);
	
private:

};

