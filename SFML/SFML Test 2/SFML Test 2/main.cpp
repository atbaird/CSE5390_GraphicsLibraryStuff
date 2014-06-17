#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Chao.h"
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(600,600), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	sf::Texture testTex1, testTex2, testTex3;
	//testTexture.loadFromFile("chao.png");
	//22 by 25 pix.

	testTex1.loadFromFile("chao.png", sf::IntRect(1,25,22,25)); //left foot
	testTex2.loadFromFile("chao.png",sf::IntRect(0,0,22,25)); //stand
	testTex3.loadFromFile("chao.png",sf::IntRect(23,25,22,25)); //right foot

	sf::Time curTime, lastChanged;

	sf::Sprite sprite1, sprite2, sprite3, animSprite1, animSprite2, animSprite3;
	sprite1.setTexture(testTex1);
	sprite2.setTexture(testTex2);
	sprite3.setTexture(testTex3);

	sprite1.scale(sf::Vector2f(2.f, 2.f));
	sprite2.scale(sf::Vector2f(2.f, 2.f));
	sprite3.scale(sf::Vector2f(2.f, 2.f));

	animSprite1 = sprite1;
	animSprite2 = sprite2;
	animSprite3 = sprite3;

	Animation anim, anim1, anim2, anim3;

	anim.addFrame(animSprite1);
	anim.addFrame(animSprite2);
	anim.addFrame(animSprite3);
	anim.addFrame(animSprite2);
	anim.setPosition(46,100);
	anim.setScale(2,2);
	anim.setDelay((long)750);
	anim.Loop();

	sf::Texture left1, left2, left3; //11 *23 = 23 + 230 = 253
	left1.loadFromFile("chao.png",sf::IntRect(220, 25,21,25)); //stand
	left2.loadFromFile("chao.png", sf::IntRect(240,25,21,25)); //left foot
	left3.loadFromFile("chao.png",sf::IntRect(280,25,21,25)); //right foot

	anim1.addFrameTexture(left1);
	anim1.addFrameTexture(left2);
	anim1.addFrameTexture(left1);
	anim1.addFrameTexture(left3);
	anim1.Loop();
	anim1.setDelay((long)750);
	anim1.setScale(2,2);
	anim1.setPosition(0,50);

	sf::Texture up1, up2, up3;
	up1.loadFromFile("chao.png",sf::IntRect(156,25,21,25)); //stand
	up2.loadFromFile("chao.png",sf::IntRect(177,25,21,25)); //right foot
	up3.loadFromFile("chao.png",sf::IntRect(199,25,21,25)); //left foot

	anim2.addFrameTexture(up1);
	anim2.addFrameTexture(up2);
	anim2.addFrameTexture(up1);
	anim2.addFrameTexture(up3);
	anim2.Loop();
	anim2.setDelay((long)750);
	anim2.setScale(2,2);
	anim2.setPosition(0,0);

	Chao chao = Chao();


	clock_t prev = clock();

	int i = 0;

	bool forwards = true;


	while(window.isOpen()) {
		sf::Event event;
		while(window.pollEvent(event)) {
			if(event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear();
		
		window.draw(shape);

		clock_t curTime = clock();
		if(anim.getRunning() == false) {
			anim.start(curTime);
			anim.show();
			anim1.start(curTime);
			anim1.show();
			anim2.start(curTime);
			anim2.show();
		} else {
			anim.update(curTime);
			anim1.update(curTime);
			anim2.update(curTime);
		}
		chao.update(curTime);
		window.draw(anim.getCurrentSprite());
		window.draw(anim1.getCurrentSprite());
		window.draw(anim2.getCurrentSprite());
		window.draw(chao.getCurrentSprite());
		window.display();
	}
	return 0;
}