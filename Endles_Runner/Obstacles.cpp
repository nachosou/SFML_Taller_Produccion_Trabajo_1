#include "Obstacles.h"

sf::RectangleShape Obstacles::GetShape()
{
	return shape;
}

void Obstacles::SetShape(sf::RectangleShape newShape)
{
	this->shape = newShape;
}

float Obstacles::GetSpeed()
{
	return speed;
}

void Obstacles::SetSpeed(float newSpeed)
{
	this->speed = newSpeed;
}

float Obstacles::GetCoolDown()
{
	return coolDown;
}

void Obstacles::SetCoolDown(float newCoolDown)
{
	this->coolDown = newCoolDown;
}

