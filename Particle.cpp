#include "Particle.h"

	Particle::Particle(sf::Vector2f position) : m_position(position) {

		shape.setPosition(m_position);
		std::random_device rd;
		std::mt19937 gen(rd());

		m_velocity = sf::Vector2f(std::uniform_real_distribution(200.f, 300.f)(gen),
			std::uniform_real_distribution(200.f, 300.f)(gen));
		m_acceleration = sf::Vector2f(0,0);

		shape.setSize({ 1, 1 });
	}

	sf::RectangleShape& Particle::getShape() {
		return shape;
	}


	void Particle::handleWallCollision(int w, int h) {

		if (m_position.x > w - shape.getSize().x / 2 || m_position.x < 0) {
			m_acceleration.x *= -1;
		}
		if (m_position.y > h - shape.getSize().y / 2 || m_position.y < 0) {
			m_acceleration.y *= -1;
		}
	}

	bool Particle::isDead() {
		
			if (lifespan < 0.0) {
				return true;
			}
			else {
				return false;
			}
		

	}

	void Particle::applyForce(sf::Vector2f force) {
		m_acceleration.x += force.x;
		m_acceleration.y += force.y;
	}

	// Update function
	void Particle::update(sf::Time dt, sf::RenderWindow &window) {
		
		lifespan -= 2.f;

		m_position.x += m_velocity.x * m_acceleration.x * dt.asSeconds();
		m_position.y += m_velocity.y * m_acceleration.y * dt.asSeconds();
		shape.setPosition(m_position);
		handleWallCollision(window.getSize().x, window.getSize().y);
	}
