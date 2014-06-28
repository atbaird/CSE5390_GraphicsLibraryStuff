#include "Animation.h"

Animation::Animation() {
	currentSprite = 0;
	loop = false;
	running = false;
	visible = false;
	frameDelay = 1000;
	lastChanged = clock();
}

Animation::~Animation() {

}


void Animation::addSprite(ofImageExt & sprite) {
	sprites.push_back(sprite);
}

void Animation::setDelay(long a) {
	frameDelay = a;
}


void Animation::setVisible(bool a) {
	visible = a;
}
bool Animation::getVisible() {
	return visible;
}

void Animation::setRunning(bool a) {
	running = a;
}
bool Animation::getRunning() {
	return running;
}

void Animation::setLoop(bool a) {
	loop = a;
}
bool Animation::getLoop() {
	return loop;
}


size_t Animation::getCurrentSpriteIndex() {
	return currentSprite;
}
ofImageExt & Animation::getCurrentSprite() {
	if(sprites.size() > 0) {
		return sprites[currentSprite];
	}
}
vector<ofImageExt> Animation::getSprites() {
	return sprites;
}
clock_t Animation::getLastChanged() {
	return lastChanged;
}


void Animation::update(clock_t currentTime) {
	if(sprites.size() > 0 && running == true) {
		if(currentTime - lastChanged > frameDelay) {
			lastChanged = currentTime;
			currentSprite++;
			if(loop == true && currentSprite >= sprites.size()) {
				currentSprite = 0;
			} else if(loop == false && currentSprite >= sprites.size()) {
				currentSprite = sprites.size() -1;
			}
		}
	} else if(sprites.size() > 0 && running == false) {
		lastChanged = currentTime;
	}
}

void Animation::start(clock_t currentTime) {
	lastChanged = currentTime;
	running = true;
	visible = true;
}

void Animation::stop() {
	running = false;
	visible = false;
}
void Animation::drawCurrentSprite(float x, float y) {
	float displaceMe = x;
	if(sprites[currentSprite].getXScale() < 0) {
		displaceMe += sprites[currentSprite].getXSize() * sprites[currentSprite].getXScale();
	}
	sprites[currentSprite].draw(x,y);
}

void Animation::drawAll(float x, float y) {
	float displacex = 0;
	for(size_t i = 0; i < sprites.size(); i++) {
		float displaceMe = displacex;
		if(sprites[i].getXScale() < 0) {
			displaceMe += (sprites[i].getXSize() * sprites[i].getXScale());
		}
		sprites[i].draw(displaceMe, y);
		displacex += (sprites[i].getXSize() * sprites[i].getXScale());
	}
}

void Animation::setScale(float x, float y) {
	for(size_t i = 0; i < sprites.size(); i++) {
		sprites[i].setScale(x,y);
	}
}