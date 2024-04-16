#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(1366, 768), "SFML window");

	sf::RectangleShape player;

	player.setPosition({200, 200});
	player.setFillColor(sf::Color::Red);
	player.setSize({40, 40});

	while (window.isOpen())
	{
		window.clear();
		window.draw(player);
		window.display();
	}

	return 0;
}