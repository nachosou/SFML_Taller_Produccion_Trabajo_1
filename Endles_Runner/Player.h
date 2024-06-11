#pragma once
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"

class Player
{
protected:
	sf::Vector2f pos;
	sf::RectangleShape shape;
	float speed;
	int score;
	float gravity;
	float jumpForce;
	bool isJumping;

public:
	sf::Vector2f GetPos();
	void SetPos(sf::Vector2f newPos);
	float GetSpeed();
	void SetSpeed(float newSpeed);
	int GetScore();
	void SetScore(int newScore);
	float GetGravity();
	void SetGravity(float newGravity);
	float GetJumpForce();
	void SetJumpForce(float jumpForce);
	sf::RectangleShape GetShape();
	void SetShape(sf::RectangleShape newShape);
	
	void MovePlayer(float dt);
	void InitPlayer(Player& player);
	void DrawPlayer(Player& player);
};