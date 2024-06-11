#include "Obstacles.h"

sf::Vector2f Obstacles::GetPos()
{
	return pos;
}

void Obstacles::SetPos(sf::Vector2f newPos)
{
	this->pos = newPos;
}

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

int Obstacles::GetCoolDown()
{
	return coolDown;
}

void Obstacles::SetCoolDown(float newCoolDown)
{
	this->coolDown = newCoolDown;
}

void Obstacles::InitObstacle(Obstacles& obstacle)
{
	pos = { 1366, 520 };
	speed = 450.0f;
	coolDown = 5;

	SetPos(pos);
	SetSpeed(speed);
	SetCoolDown(coolDown);
}

void Obstacles::MoveObstacle(Obstacles& obstacle, float deltaTime, float& timer)
{
	pos.x -= speed * deltaTime;
}

void Obstacles::DrawObstacle(Obstacles& obstacle)
{
	sf::RectangleShape obstacleShape;

	obstacleShape.setPosition(obstacle.GetPos());
	obstacleShape.setFillColor(sf::Color::White);
	obstacleShape.setSize({ 40, 80 });

	obstacle.SetShape(obstacleShape);
}

bool Obstacles::IsObstacleInCoolDown(Obstacles& obstacle, float& timer)
{
	float randNum;

	randNum = rand() % obstacle.GetCoolDown() + 2;

	if (timer > randNum)
	{
		return false;
	}
	else
	{
		return true;
	}

	timer = 0;
}



