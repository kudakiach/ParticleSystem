#include <SFML/graphics.hpp>
#include "Particle.h"
#include "Confetti.h"

class ParticleSystem {
private:
	std::vector<Particle> particles;
	sf::Vector2f m_origin;

public:
	ParticleSystem(sf::Vector2f position) : m_origin(position) {}

	void draw(sf::RenderWindow& target) {
		for (int i = 0; i < particles.size(); i++)
			target.draw(particles[i].getShape());
	};

	void addParticle() {
		float r = randomFloat(0.f, 1.f);

		if (r < 0.5f) {
			particles.push_back(Confetti(m_origin));
		}
		else {
			particles.push_back(Particle(m_origin));
		}
		
	}



	void setOrigin(sf::Vector2f origin) {
		m_origin = origin;
	}

	float randomFloat(float start, float end) {
		std::random_device rd;
		std::mt19937 gen(rd());

		return std::uniform_real_distribution(start, end)(gen);
	}

	void removeDeadParticles() {
		particles.erase(
			std::remove_if(
				particles.begin(),
				particles.end(),
				[]( Particle p) {
					return p.isDead();
				}
			),
			particles.end()
		);
	}
	

	void update(sf::Time dt, sf::RenderWindow& window) {
		for (size_t i = 0; i < particles.size(); i++) {
			particles[i].update(dt, window);
			particles[i].applyForce(sf::Vector2f(0.1f, 0.1f));
			
		}	
		addParticle();
		removeDeadParticles();
	}
};