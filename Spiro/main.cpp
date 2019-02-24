#include "SFML/Graphics.hpp"
#include <iostream>

using namespace sf;

class Spirograph
{
public:
	Spirograph(const Vector2f& position) : 
		position(position), 
		circle(3),
		line(LinesStrip),
		r(0),
		alpha(0),
		alpha0(0)
	{
		circle.setOrigin(3, 3);

	}

	void update()
	{
		alpha += 0.01;
		alpha0 += 0.0004;
		r = 10 * (2 + 3 * cos(alpha));
		Vector2f tran;
		tran.x = r * cos(alpha);
		tran.y = r * sin(alpha);
		line.append(Vertex(position + tran));
		circle.setPosition(position + tran);
	}

	CircleShape circle;
	VertexArray line;

	

private:
	Vector2f position;
	float r;
	float alpha;
	float alpha0;
	
};



int main()
{

	ContextSettings setting;
	setting.antialiasingLevel = 8;
	RenderWindow window(VideoMode(800, 600), "SFML", 7U, setting);

	Spirograph spiro(Vector2f(400, 300));

	std::cout << "asd";

	while (window.isOpen())
	{
		spiro.update();
		

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
		window.draw(spiro.line);
		window.draw(spiro.circle);
		window.display();
	}

	return 0;
}