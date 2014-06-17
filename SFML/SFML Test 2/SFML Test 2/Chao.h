#include "Animation.h"

#ifndef CHAO_H
#define CHAO_H

class Chao {
public:
	Chao();
	~Chao();
	void changeWindowConstraints(float, float, float, float);
	void update(clock_t);
	sf::Sprite & getCurrentSprite();
	void hideAll();
	void stopAll();
private:
	void keepImagesSamePosScale();
	void setTwoSpeedsOneLesser(float&, float&, bool, bool);
	bool randBool();

	vector<Animation> animations, chaoBall;
	bool pause, visible;
	int currentAnimation;
	float xScale, yScale, xCor, yCor, xSpeed, ySpeed;
	float begXWall, endXWall, begYWall, endYWall;
	long frameSpeed;
	clock_t lastMoveDecision;
};

#endif