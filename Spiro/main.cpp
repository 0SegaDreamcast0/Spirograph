#include "SFML/Graphics.hpp"

using namespace sf;

int main()
{
	ContextSettings setting;
	setting.antialiasingLevel = 8;
	RenderWindow window(VideoMode(800, 600), "SFML", 7U, setting);

	CircleShape circle(30);

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
		window.display();
	}

	return 0;
}