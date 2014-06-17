#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

#ifndef ANIMATION_H
#define ANIMATION_H

class Animation {
public:
	Animation();
	~Animation();
	
	void start(clock_t);
	void stop();
	void show();
	void hide();
	void update(clock_t);

	void setPosition(float,float);
	void setXPosition(float);
	void setYPosition(float);
	void setScale(float,float);
	void setXScale(float);
	void setYScale(float);
	void setDelay(long);
	void addFrame(sf::Sprite&);
	void addFrameTexture(sf::Texture&);
	void setFrame(sf::Sprite&, int);
	void setFrameTexture(sf::Texture&, int);
	void setVisible(bool);
	void Loop();

	long getDelay();
	bool getVisible();
	bool getRunning();
	bool getLooped();
	float getXPosition();
	float getYPosition();
	int getCurrentFrame();
	clock_t getLastChanged();
	float getXScale();
	float getYScale();
	sf::Sprite & getCurrentSprite();
	sf::Sprite & getSprite(int);


private:
	void resetSpriteScales();
	void resetSpritePositions();

	vector<sf::Sprite> sprites;
	bool visible, running, loop;
	clock_t lastChanged;
	long frameSpeedDelay;
	int currentFrame;
	float xCor, yCor, xScale, yScale;
};

#endif