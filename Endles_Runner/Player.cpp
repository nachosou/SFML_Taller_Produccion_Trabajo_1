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

void Player::MovePlayer(float deltaTime)
{
	pos.x = 40;

	if (pos.y <= 560)
	{
		speed += gravity * deltaTime;
		
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

	pos.y += speed * deltaTime;

	if (isJumping && speed > 0)
	{
		isJumping = false;
	}
}

void Player::InitPlayer(Player& player)
{
	speed = 150.0f;
	gravity = 600.0f;
	jumpForce = -400.0f;

	player.SetSpeed(speed);
	player.SetGravity(gravity);
	player.SetJumpForce(jumpForce);
}

void Player::DrawPlayer(Player& player)
{
	sf::RectangleShape playerShape;

	playerShape.setPosition(player.GetPos());
	playerShape.setFillColor(sf::Color::Red);
	playerShape.setSize({ 40, 40 });

	player.SetShape(playerShape);
}