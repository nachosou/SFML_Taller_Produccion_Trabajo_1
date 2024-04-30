#pragma once
#include "SFML/System.hpp"

class Player
{
protected:
	sf::Vector2f pos;
	sf::Vector2i size;
	int speed;
	int score;

public:
	sf::Vector2f GetPos();
	void SetPos(sf::Vector2f newPos);
	int GetSpeed();
	void SetSpeed(int newSpeed);
	int GetScore();
	void SetScore(int newScore);

};