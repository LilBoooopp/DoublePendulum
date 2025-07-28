#include "Pendulum.hpp"
#include <cmath>

Pendulum::Pendulum(float l1, float l2, float m1, float m2, sf::Vector2f o)
	: length1(l1), length2(l2), mass1(m1), mass2(m2), origin(o),
	angle1(1.2f), angle2(1.8f), vel1(0), vel2(0), acc1(0), acc2(0),
	circle1(10), circle2(10), line1(sf::Lines, 2), line2(sf::Lines, 2) {
	circle1.setFillColor(sf::Color::Red);
	circle1.setOrigin(10, 10);
	circle2.setFillColor(sf::Color::Green);
	circle2.setOrigin(10, 10);
}

void Pendulum::update(float dt) {
	if (usePhysics && !dragging1 && !dragging2) {
		computePhysics(dt);
	}
	updateShapes();
}

void Pendulum::computePhysics(float dt) {
	float num1 = -gravity * (2 * mass1 + mass2) * sin(angle1);
	float num2 = -mass2 * gravity * sin(angle1 - 2 * angle2);
	float num3 = -2 * sin(angle1 - angle2) * mass2;
	float num4 = vel2 * vel2 * length2 + vel1 * vel1 * length1 * cos(angle1 - angle2);
	float den = length1 * (2 * mass1 + mass2 - mass2 * cos(2 * angle1 - 2 * angle2));
	acc1 = (num1 + num2 + num3 * num4) / den;

	num1 = 2 * sin(angle1 - angle2);
	num2 = vel1 * vel1 * length1 * (mass1 + mass2);
	num3 = gravity * (mass1 + mass2) * cos(angle1);
	num4 = vel2 * vel2 * length2 * mass2 * cos(angle1 - angle2);
	den = length2 * (2 * mass1 + mass2 - mass2 * cos(2 * angle1 - 2 * angle2));
	acc2 = (num1 * (num2 + num3 + num4)) / den;

	vel1 += acc1 * dt;
	vel2 += acc2 * dt;
	angle1 += vel1 * dt;
	angle2 += vel2 * dt;
}

void Pendulum::updateShapes() {
	cachedPos1 = origin + sf::Vector2f(length1 * sin(angle1), length1 * cos(angle1));
	cachedPos2 = cachedPos1 + sf::Vector2f(length2 * sin(angle2), length2 * cos(angle2));

	line1[0].position = origin;
	line1[1].position = cachedPos1;
	line2[0].position = cachedPos1;
	line2[1].position = cachedPos2;

	line1[0].color = line1[1].color = sf::Color::White;
	line2[0].color = line2[1].color = sf::Color::White;

	circle1.setPosition(cachedPos1);
	circle2.setPosition(cachedPos2);
}

void Pendulum::draw(sf::RenderWindow& window) {
	window.draw(line1);
	window.draw(circle1);
	window.draw(line2);
	window.draw(circle2);
}

void Pendulum::setAngles(float a1, float a2) {
	angle1 = a1;
	angle2 = a2;
	vel1 = vel2 = 0;
}

void Pendulum::enablePhysics(bool enable) {
	usePhysics = enable;
}

void Pendulum::startDrag(sf::Vector2f mouse) {
	float	d2 = std::hypot(mouse.x - cachedPos2.x, mouse.y - cachedPos2.y);
	float	d1 = std::hypot(mouse.x - cachedPos1.x, mouse.y - cachedPos1.y);

	if (d2 < 20) dragging2 = true;
	else if (d1 < 20) dragging1 = true;
}

void Pendulum::stopDrag() {
	dragging1 = dragging2 = false;
}

void Pendulum::dragMass(sf::Vector2f mouse, int index) {
	if (dragging2) {
		angle2 = std::atan2(mouse.x - cachedPos1.x, mouse.y - cachedPos1.y);
		vel2 = 0;
	} else if (dragging1) {
		angle1 = std::atan2(mouse.x - origin.x, mouse.y - origin.y);
		vel1 = 0;
	}
}

sf::Vector2f Pendulum::getMass1Pos() const {
	return (cachedPos1);
}

sf::Vector2f Pendulum::getMass2Pos() const {
	return (cachedPos2);
}

bool Pendulum::isDragging() const {
	return (dragging1 || dragging2);
}
