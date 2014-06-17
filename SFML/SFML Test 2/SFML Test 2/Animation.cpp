#include "Animation.h"

Animation::Animation() {
	visible = false;
	running = false;
	loop = false;
	lastChanged = clock();
	currentFrame = 0;
	xScale = 1;
	yScale = 1;
	xCor = 0;
	yCor = 0;
	frameSpeedDelay = 1000; //1000 long is 1 second.
}
Animation::~Animation() {

}


void Animation::update(clock_t currentTime) {
	if(running == true) {
		if( (long)(currentTime - lastChanged) >= frameSpeedDelay) {
			currentFrame++;
			lastChanged = currentTime;
		}

		if((size_t)currentFrame >= sprites.size() && loop == true) {
			currentFrame = 0;
		} else if((size_t)currentFrame >= sprites.size() && loop == false) {
			currentFrame = sprites.size()-1;
			stop();
		}

	} else {
		lastChanged = currentTime;
	}
}
void Animation::start(clock_t currentTime) {
	lastChanged = currentTime;
	currentFrame = 0;
	running = true;
}
void Animation::stop() {
	running = false;
}
void Animation::show() {
	visible = true;
}
void Animation::hide() {
	visible = false;
}
void Animation::Loop() {
	loop = !(loop);
}


void Animation::setPosition(float x, float y) {
	setXPosition(x);
	setYPosition(y);
}
void Animation::setXPosition(float x) {
	xCor = x;
	resetSpritePositions();
}
void Animation::setYPosition(float y) {
	yCor = y;
	resetSpritePositions();
}
void Animation::setScale(float x, float y) {
	setXScale(x);
	setYScale(y);
}
void Animation::setXScale(float x) {
	if(abs(x) > 0) {
		xScale = x;
		resetSpriteScales();
	} else {
		cout << "Not a valid x Size\n";
	}
}
void Animation::setYScale(float y) {
	if(abs(y) > 0) {
		yScale = y;
		resetSpriteScales();
	} else {
		cout << "Not a vlid y Size\n";
	}
}
void Animation::setDelay(long delay) {
	if(delay > 0) {
		frameSpeedDelay = delay;
	} else {
		cout << "Not a valid delay\n";
	}
}
void Animation::addFrame(sf::Sprite& sprite) {
	sprite.setPosition(xCor, yCor);
	sprite.setScale(xScale, yScale);
	sprites.push_back(sprite);
}
void Animation::addFrameTexture(sf::Texture& texture) {
	sf::Sprite sprite;
	sprite.setTexture(texture);
	addFrame(sprite);
}
void Animation::setFrame(sf::Sprite& sprite, int index) {
	if(index >= 0 && (size_t)index < sprites.size()) {
		sprite.setPosition(xCor, yCor);
		sprite.setScale(xScale, yScale);
		sprites[index] = sprite;
	}
}
void Animation::setFrameTexture(sf::Texture& texture, int index) {
	sf::Sprite sprite;
	sprite.setTexture(texture);
	setFrame(sprite, index);
}
void Animation::setVisible(bool a) {
	visible = a;
}


void Animation::resetSpriteScales() {
	for(size_t i = 0; i < sprites.size(); i++) {
		sprites[i].setScale(sf::Vector2f(xScale, yScale));
	}
}
void Animation::resetSpritePositions() {
	for(size_t i = 0; i < sprites.size(); i++) {
		sprites[i].setPosition(xCor, yCor);
	}
}


long Animation::getDelay() {
	return frameSpeedDelay;
}
bool Animation::getVisible() {
	return visible;
}
bool Animation::getRunning() {
	return running;
}
bool Animation::getLooped() {
	return loop;
}
float Animation::getXPosition() {
	return xCor;
}
float Animation::getYPosition() {
	return yCor;
}
int Animation::getCurrentFrame() {
	return currentFrame;
}
clock_t Animation::getLastChanged() {
	return lastChanged;
}
float Animation::getXScale() {
	return xScale;
}
float Animation::getYScale() {
	return yScale;
}
sf::Sprite & Animation::getCurrentSprite() {
	return sprites[currentFrame];
}
sf::Sprite & Animation::getSprite(int index) {
	if(index >= 0 && (size_t)index < sprites.size()) {
		return sprites[index];
	}
	return sprites[0];
}