#include "Player.h"

sf::Vector2f Player::GetPos()
{
	return pos;
}

void Player::SetPos(sf::Vector2f newPos)
{
	this->pos = newPos;
}

int Player::GetSpeed()
{
	return speed;
}

void Player::SetSpeed(int newSpeed)
{
	this->speed = newSpeed;
}

int Player::GetScore()
{
	return score;
}

void Player::SetScore(int newScore)
{
	this->score = newScore;
}