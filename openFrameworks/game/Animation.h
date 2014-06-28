#include "ofImageExt.h"
#include <vector>

using namespace std;


#ifndef ANIMATION_H
#define ANIMATION_H

class Animation {
public:
	Animation();
	~Animation();
	void addSprite(ofImageExt &);
	void setVisible(bool);
	bool getVisible();
	void setRunning(bool);
	bool getRunning();
	void setLoop(bool);
	bool getLoop();
	size_t getCurrentSpriteIndex();
	ofImageExt & getCurrentSprite();
	vector<ofImageExt> getSprites();
	clock_t getLastChanged();

	void update(clock_t);
	void start(clock_t);
	void stop();
	void drawCurrentSprite(float, float);
	void drawAll(float, float);
	void setScale(float, float);
	void setDelay(long);
private:
	vector<ofImageExt> sprites;
	clock_t lastChanged;
	size_t currentSprite;
	long frameDelay;
	bool visible, running, loop;

};

#endif