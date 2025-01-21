#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <iostream>
#include <random>

//// User includes

#include "ParticleSystem.cpp"


int main()
{

		sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Particles System");

		sf::Clock clock;

	
		std::random_device rd;
		std::mt19937 gen(rd());

		std::vector<ParticleSystem> ps;
		//ParticleSystem ps({ 100, 100 });
		
		ps.push_back(ParticleSystem({100, 200}));
		ps.push_back(ParticleSystem({ 400, 300 }));

		while (window.isOpen()) {
			while (const std::optional event = window.pollEvent()) {
				if (event->is<sf::Event::Closed>()) {
					window.close();
				}

				if (const auto mousePressed = event->getIf<sf::Event::MouseButtonPressed>()) {
					if (mousePressed->button == sf::Mouse::Button::Right) {
						float mx = static_cast<float>(sf::Mouse::getPosition(window).x);
						float my = static_cast<float>(sf::Mouse::getPosition(window).y);
						
					}
				}
			}

			sf::Time dt = clock.restart();
			
			
			for (int x = 0; x < ps.size(); x++) {
				ps[x].update(dt, window);
			}
			//ps.update(dt, window);
					
			window.clear();
			
			for (int x = 0; x < ps.size(); x++) {
				ps[x].draw(window);
				
			}
			//ps.draw(window);
			window.display();

		}

		return 0;

}