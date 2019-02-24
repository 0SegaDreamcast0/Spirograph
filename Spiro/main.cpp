#include "SFML/Graphics.hpp"
#include <iostream>

using namespace sf;

int main()
{
	ContextSettings setting;
	setting.antialiasingLevel = 8;
	RenderWindow window(VideoMode(800, 600), "SFML", 7U, setting);

	CircleShape circle(30);
	RectangleShape square(Vector2f(60, 60));
	square.setPosition(400, 400);

	std::cout << "asd";

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				window.close();
			}
		}

		window.clear(Color::Black);
		window.draw(circle);
		window.draw(square);
		window.display();
	}

	return 0;
}