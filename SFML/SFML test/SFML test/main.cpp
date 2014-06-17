#include <SFML/Graphics.hpp>

int main()
{

	//set up for font and text
	//need to add in font files to working directory for it to work.
	sf::Font font;
	sf::Text text;
	font.loadFromFile("Courier New");
	if (!font.loadFromFile("Courier New"))
	{
		// error...
	}
	text.setFont(font);
	text.setString("Hello World");
	text.setCharacterSize(24);
	text.setColor(sf::Color::Blue);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);


	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!"); //creates window of 200 px by 200 px
	sf::CircleShape shape(100.f); //creates a circle
	shape.setFillColor(sf::Color::Green); //sets color to green 
	bool a = false;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close(); //sets window to close


			if(event.type == sf::Event::KeyPressed) {
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
					if(a == false) {
						a = true;
						window.setSize(sf::Vector2u(640, 480));
					} else {
						a = false;
						window.setSize(sf::Vector2u(200, 200));
					}
				}
			}
		}

		window.clear(); //clears previous image
		window.draw(shape); //draws new image
		window.draw(text);
		window.display(); //shows the image to viewer.
	}

	return 0;
}