#pragma once
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"

class Obstacles
{
protected:
	sf::Vector2f pos;
	sf::RectangleShape shape;
	float speed;
	float coolDown;

public:
	sf::RectangleShape GetShape();
	void SetShape(sf::RectangleShape newShape);
	float GetSpeed();
	void SetSpeed(float newSpeed);
	float GetCoolDown();
	void SetCoolDown(float newCoolDown);

};

