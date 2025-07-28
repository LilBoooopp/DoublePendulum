#include "Trail.hpp"

Trail::Trail(std::size_t maxPoints) : maxSize(maxPoints) {}

void	Trail::addPoint(sf::Vector2f point) {
	if (points.size() >= maxSize)
		points.pop_front();
	points.push_back(point);
}

void Trail::draw(sf::RenderWindow& window) {
	if (points.size() < 2) return;
	sf::VertexArray lines(sf::LinesStrip, points.size());
	for (std::size_t i = 0; i < points.size(); ++i) {
		lines[i].position = points[i];
		lines[i].color = sf::Color(100, 255, 100);
	}
	window.draw(lines);
}
