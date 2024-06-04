#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"

using namespace std;

void initPlayer(Player& player);
void drawPlayer(Player& player);

int main()
{
	sf::RenderWindow window(sf::VideoMode(1366, 768), "Endless Runner");

	Player player;

	float floorPosY = 599;
	sf::RectangleShape floor;
	floor.setPosition({ 0, floorPosY });
	floor.setFillColor(sf::Color::Blue);
	floor.setSize({ 1366, 10 });

	initPlayer(player);

	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Event event;

		sf::Time time = clock.restart();
		float dt = time.asSeconds();

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.clear();
		window.draw(player.GetShape());
		window.draw(floor);
		window.display();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			break;
		}

		player.MovePlayer(dt);
		drawPlayer(player);

		cout << player.GetPos().x << endl;
	}

	return 0;
}

void initPlayer(Player& player)
{
	float speed = 150.0f;
	float gravity = 600.0f;
	float jumpForce = -400.0f;

	player.SetSpeed(speed);
	player.SetGravity(gravity);
	player.SetJumpForce(jumpForce); 
}

void drawPlayer(Player& player)
{
	sf::RectangleShape playerShape;

	playerShape.setPosition(player.GetPos());
	playerShape.setFillColor(sf::Color::Red);
	playerShape.setSize({ 40, 40 });

	player.SetShape(playerShape);
}

