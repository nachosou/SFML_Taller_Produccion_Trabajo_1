#pragma once
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include <cstdlib>

class Obstacles
{
protected:
	sf::Vector2f pos;
	sf::RectangleShape shape;
	float speed;
	int coolDown;

public:
	sf::Vector2f GetPos();
	void SetPos(sf::Vector2f newPos);
	sf::RectangleShape GetShape();
	void SetShape(sf::RectangleShape newShape);
	float GetSpeed();
	void SetSpeed(float newSpeed);
	int GetCoolDown();
	void SetCoolDown(float newCoolDown);

	void InitObstacle(Obstacles& obstacle);
	void MoveObstacle(Obstacles& obstacle, float deltaTime, float& timer);
	void DrawObstacle(Obstacles& obstacle);
	bool IsObstacleInCoolDown(Obstacles& obstacle, float& timer);
};

