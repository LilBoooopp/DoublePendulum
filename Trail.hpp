#pragma once
#include <SFML/Graphics.hpp>
#include <deque>

class Trail {
	public:
		Trail(std::size_t maxPoints = 1000);
		void	addPoint(sf::Vector2f point);
		void	draw(sf::RenderWindow& window);
	private:
		std::deque<sf::Vector2f> points;
		std::size_t	maxSize;
};
