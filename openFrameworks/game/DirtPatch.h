#include "ofImageExt.h"
#include <vector>

#ifndef DIRTPATCH_H
#define DIRTPATCH_H

class DirtPatch {
public:
	DirtPatch();
	~DirtPatch();
	void draw();
	void setScale(float,float);
	void setPosition(float,float);

private:
	float startx, starty;
	vector<ofImageExt> images;
};

#endif