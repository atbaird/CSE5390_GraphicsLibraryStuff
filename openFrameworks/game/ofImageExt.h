#include "ofMain.h"


#ifndef OFIMAGEEXT_H
#define OFIMAGEEXT_H

class ofImageExt {
public:
	ofImageExt();
	ofImageExt(ofImage &);
	ofImageExt(ofImage &, float, float, float, float);
	~ofImageExt();
	void draw(float, float);
	void setAll(ofImage &, float, float, float, float);
	void setFloats(float, float, float, float);
	

private:
	ofImage image;
	float xStart, yStart, xSize, ySize, xScale, yScale; //corridinates on sprite sheet
};

#endif