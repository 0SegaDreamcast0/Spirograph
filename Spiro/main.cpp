#include "SFML/Graphics.hpp"
#include <iostream>

using namespace sf;

int main()
{
	ContextSettings setting;
	setting.antialiasingLevel = 8;
	RenderWindow window(VideoMode(800, 600), "SFML", 7U, setting);

	Vector2f position(400, 300);
	CircleShape circle(3);
	circle.setOrigin(3, 3);

	VertexArray line(LinesStrip);

	float r(0);
	float alpha(0);
	float alpha0(50);

	std::cout << "asd";

	while (window.isOpen())
	{
		alpha += 0.01;
		alpha0 += 0.0004;

		Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				window.close();
			}
		}

		r = 100 * cos(4 * alpha + alpha0);

		position.x = 400 + r * cos(alpha);
		position.y = 300 + r * sin(alpha);
		line.append(Vertex(position));
		circle.setPosition(position);

		window.clear(Color::Black);
		window.draw(circle);
		window.draw(line);
		window.display();
	}

	return 0;
}