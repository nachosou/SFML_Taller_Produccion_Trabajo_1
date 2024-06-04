#include "Player.h"

sf::Vector2f Player::GetPos()
{
	return pos;
}

void Player::SetPos(sf::Vector2f newPos)
{
	this->pos = newPos;
}

float Player::GetSpeed()
{
	return speed;
}

void Player::SetSpeed(float newSpeed)
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

float Player::GetGravity()
{
	return gravity;
}

void Player::SetGravity(float newGravity)
{
	this->gravity = newGravity;
}

float Player::GetJumpForce()
{
	return jumpForce;
}

void Player::SetJumpForce(float newJumpForce)
{
	this->jumpForce = newJumpForce;
}

sf::RectangleShape Player::GetShape()
{
	return shape;
}

void Player::SetShape(sf::RectangleShape newShape)
{
	this->shape = newShape;
}

void Player::MovePlayer(float dt)
{
	pos.x = 40;

	if (pos.y <= 560)
	{
		speed += gravity * dt;
		
	}
	else
	{
		speed = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && speed == 0)
	{
		speed = jumpForce;
		isJumping = true;
	}

	pos.y += speed * dt;

	if (isJumping && speed > 0)
	{
		isJumping = false;
	}
}