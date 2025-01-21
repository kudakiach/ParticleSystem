#pragma once
#include <SFML/graphics.hpp>
#include <iostream>
#include <random>

class Particle : public sf::Drawable, public sf::Transformable {


public:

	Particle(sf::Vector2f position);

	sf::RectangleShape& getShape();

	void handleWallCollision(int w, int h);

	// Update function
	void update(sf::Time dt, sf::RenderWindow& window);
	bool isDead();
	void applyForce(sf::Vector2f force);

private:
	sf::Vector2f m_position;
	sf::Vector2f m_acceleration;
	sf::Vector2f m_velocity;
	sf::RectangleShape shape;
	float lifespan = 255.f;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
		states.transform *= getTransform();
		target.draw(shape);
	}

};