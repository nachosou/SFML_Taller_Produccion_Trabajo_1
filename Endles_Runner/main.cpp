#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Obstacles.h"

using namespace std;

void main()
{
	sf::RenderWindow window(sf::VideoMode(1366, 768), "Endless Runner");

	Player player;
	Obstacles groundObstacles;
	Obstacles* obstacle;

	float floorPosY = 599;
	sf::RectangleShape floor;
	floor.setPosition({ 0, floorPosY });
	floor.setFillColor(sf::Color::Blue);
	floor.setSize({ 1366, 10 });

	float timer = 0;

	player.InitPlayer(player);
	groundObstacles.InitObstacle(groundObstacles);

	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Event event;

		sf::Time time = clock.restart();
		float deltaTime = time.asSeconds();

		timer += deltaTime;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.clear();
		window.draw(player.GetShape());
		window.draw(groundObstacles.GetShape());
		window.draw(floor);
		window.display();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			break;
		}

		if (!groundObstacles.IsObstacleInCoolDown(groundObstacles, timer))
		{
			obstacle = new Obstacles();
			obstacle->InitObstacle();
		}

		if (obstacle->GetPos().x <= 0.0f)
		{
			delete obstacle;
		}

		player.MovePlayer(deltaTime);
		player.DrawPlayer(player);

		obstacle->MoveObstacle(groundObstacles, deltaTime, timer);
		obstacle->DrawObstacle(groundObstacles);

		cout << obstacle->GetPos().x << endl;
	}
}

