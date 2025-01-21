#include <SFML/graphics.hpp>
#include "Particle.cpp"
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
		particles.push_back(Particle(m_origin));
	}

	void setOrigin(sf::Vector2f origin) {
		m_origin = origin;
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
	
	void changeTheme(sf::Color color) {
		for (size_t i = 0; i < particles.size(); i++) {
		
			
		}
	}



	void update(sf::Time dt, sf::RenderWindow& window) {
		for (size_t i = 0; i < particles.size(); i++) {
			particles[i].update(dt);
			particles[i].handleWallCollision(window.getSize().x, window.getSize().y);
		}
		addParticle();
		std::cout << particles.size() << "\n";
		removeDeadParticles();
		
	}
};