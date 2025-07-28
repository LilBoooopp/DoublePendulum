#include <SFML/Graphics.hpp>
#include "Pendulum.hpp"
#include "Trail.hpp"

int main() {
	float simulationSpeed = 1.0f;

	sf::RenderWindow window(sf::VideoMode(800, 600), "Double Pendulum");
	window.setFramerateLimit(60);

	Pendulum pendulum(150.0f, 150.0f, 10.0f, 10.0f, {400, 100});
	Trail trail(1500);

	bool simulationMode = true;

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed ||
				(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
				window.close();	
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
				simulationMode = !simulationMode, pendulum.enablePhysics(simulationMode);
			if (event.key.code == sf::Keyboard::Right)
				simulationSpeed *= 1.2f;
			if (event.key.code == sf::Keyboard::Left)
				simulationSpeed *= 0.8f;

			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
				pendulum.startDrag(sf::Vector2f(sf::Mouse::getPosition(window)));
			if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
				pendulum.stopDrag();

			if (event.type == sf::Event::MouseMoved)
				pendulum.dragMass(sf::Vector2f(sf::Mouse::getPosition(window)), 0);
		}
		pendulum.update(0.032f * simulationSpeed);
		if (simulationMode && !pendulum.isDragging())
			trail.addPoint(pendulum.getMass2Pos());
		window.clear(sf::Color::Black);
		trail.draw(window);
		pendulum.draw(window);
		window.display();
	}

	return 0;
}
