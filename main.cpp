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

		ParticleSystem ps({ 100, 100 });
		ParticleSystem ps1({ 500, 500 });

		while (window.isOpen()) {
			while (const std::optional event = window.pollEvent()) {
				if (event->is<sf::Event::Closed>()) {
					window.close();
				}

				if (const auto mousePressed = event->getIf<sf::Event::MouseButtonPressed>()) {
					if (mousePressed->button == sf::Mouse::Button::Right) {
						
						
					}
				}
			}

			sf::Time dt = clock.restart();
			float mx = sf::Mouse::getPosition(window).x;
			float my = sf::Mouse::getPosition(window).y;
			

			ps.update(dt, window);
			ps1.update(dt, window);


			
			
			window.clear();
			
			
			ps.draw(window);
			ps1.draw(window);

			window.display();

		}

		return 0;

}