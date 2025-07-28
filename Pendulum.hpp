#pragma once
#include <SFML/Graphics.hpp>

class Pendulum {
	public:
		Pendulum(float l1, float l2, float m1, float m2, sf::Vector2f origin);

		void update(float dt);
		void draw(sf::RenderWindow& window);
		void setAngles(float a1, float a2);
		void enablePhysics(bool enable);
		void dragMass(sf::Vector2f mouse, int index);
		void startDrag(sf::Vector2f mouse);
		void stopDrag();

		sf::Vector2f getMass1Pos() const;
		sf::Vector2f getMass2Pos() const;
		bool isDragging() const;

	private:
		float	length1, length2, mass1, mass2;
		float	angle1, angle2;
		float	vel1, vel2;
		float	acc1, acc2;
		sf::Vector2f	cachedPos1;
		sf::Vector2f	cachedPos2;
		sf::Vector2f	origin;

		bool usePhysics = true;
		bool dragging1 = false;
		bool dragging2 = false;

		float gravity = 9.81f;

		sf::CircleShape circle1, circle2;
		sf::VertexArray line1, line2;

		void computePhysics(float dt);
		void updateShapes();
};