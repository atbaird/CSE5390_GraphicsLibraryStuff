#include "Animation.h"

#ifndef BUSH_H
#define BUSH_H

class Bush {
public:
	Bush();
	~Bush();
	void setLocation(float, float);
	void draw();
	void setScale(float, float);
	float getYSize();
	float getXSize();
	float getX();
	float getY();
private:
	Animation anim;
	float x, y;

};

#endif