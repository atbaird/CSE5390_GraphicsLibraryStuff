#include <vector>
#include "DirtPatch.h"

#ifndef BACKGROUND_H
#define BACKGROUND_H

class Background {
public:
	Background();
	~Background();
	void setScale(float,float);
	void draw();
	void setStart(float, float);
	
	float getXLength();
	float getYLength();
	float getXStart();
	float getYStart();

private:
	void updatePatches();

	vector<vector<ofImageExt>> cells; //176 by 160; 11 cells by 10
	vector<DirtPatch> dirtpatches;
	float xStart, yStart;
};

#endif