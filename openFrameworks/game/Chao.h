#include "Bush.h"


#ifndef CHAO_H
#define CHAO_H

class Chao {
public:
	Chao();
	~Chao();
	void testSprites(clock_t);
	void update(clock_t, vector<Bush>&);
	void drawTest();
	void updateScreenLimits(float, float);
	void draw();
	void setScale(float,float);
	void setLimits(float, float, float, float);
	void randomizeStartPos();
private:
	void genRandMov();

	vector<Animation> animations, chaoBall;
	clock_t lastMoveDecision;
	int moveDec;
	float x, y, xSpeed, ySpeed, xLimit, yLimit, xMin, yMin, currentXScale, currentYScale;
};

#endif