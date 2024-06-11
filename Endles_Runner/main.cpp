#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"

using namespace std;

void main()
{
	sf::RenderWindow window(sf::VideoMode(1366, 768), "Endless Runner");

	Player player;

	float floorPosY = 599;
	sf::RectangleShape floor;
	floor.setPosition({ 0, floorPosY });
	floor.setFillColor(sf::Color::Blue);
	floor.setSize({ 1366, 10 });

	player.InitPlayer(player);

	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Event event;

		sf::Time time = clock.restart();
		float deltaTime = time.asSeconds();

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

		player.MovePlayer(deltaTime);
		player.DrawPlayer(player);

		cout << player.GetPos().x << endl;
	}
}

