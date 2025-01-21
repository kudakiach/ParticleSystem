#include <SFML/graphics.hpp>
#include <iostream>
#include <random>

class Particle : public sf::Drawable, public sf::Transformable {
private:
	sf::Vector2f m_position;
	sf::Vector2f m_acceleration;
	sf::Vector2f m_velocity;
	float lifespan;
	sf::RectangleShape shape;
	

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
		states.transform *= getTransform();

		target.draw(shape);
	}

public:
	Particle(sf::Vector2f position) : m_position(position){
		shape.setPosition(m_position);
		
		shape.setSize({10, 10});
		
		std::random_device rd;
		std::mt19937 gen(rd());

		shape.setFillColor(sf::Color(randomInt(0, 255)));

		m_velocity = sf::Vector2f(std::uniform_real_distribution(200.f, 300.f)(gen), 
			std::uniform_real_distribution(200.f, 300.f)(gen));
		m_acceleration = sf::Vector2f(std::uniform_real_distribution(-1.f, 1.f)(gen),
			std::uniform_real_distribution(-1.f,1.f)(gen));
		lifespan = 255;
	}

	sf::RectangleShape getShape() {
		return shape;
	}

	bool isDead() {
		if (lifespan < 0.0) {
				return true;
		}
		else {
			return false;
		}
	}


	float randomFloat(float start, float end) {
		std::random_device rd;
		std::mt19937 gen(rd());

		return std::uniform_real_distribution(start, end)(gen);
	}

	float randomInt(float start, float end) {
		std::random_device rd;
		std::mt19937 gen(rd());

		return std::uniform_real_distribution(start, end)(gen);
	}
	

	void handleWallCollision(int w, int h) {

		if (m_position.x > w - shape.getSize().x / 2 || m_position.x < 0) {
			m_acceleration.x *= -1;
		}
		if (m_position.y > h - shape.getSize().y  / 2|| m_position.y < 0) {
			m_acceleration.y *= -1;
		}
	}

	// Update function
	void update(sf::Time dt) {
		float elapsed = 0;

		lifespan -= 1.f;
		shape.setFillColor(sf::Color( randomInt(0,255), randomInt(0, 255), randomInt(0, 255), lifespan));
		m_position.x += m_velocity.x * m_acceleration.x * dt.asSeconds();
		m_position.y += m_velocity.y * m_acceleration.y * dt.asSeconds();
		shape.setPosition(m_position);


	}

};