#include "ofImageExt.h"

ofImageExt::ofImageExt() {
	setFloats(0,0,0,0);
}
ofImageExt::ofImageExt(ofImage & img) {
	setAll(img, 0,0,0,0);
}
ofImageExt::ofImageExt(ofImage & img, float xst, float yst, float xsz, float ysz) {
	setAll(img, xst, yst, xsz, ysz);
}

ofImageExt::~ofImageExt() {

}

void ofImageExt::setAll(ofImage & img, float xst, float yst, float xsz, float ysz) {
	setFloats(xst, yst, xsz, ysz);
	image = img;
}
void ofImageExt::setFloats(float xst, float yst, float xsz, float ysz) {
	xStart = xst;
	yStart = yst;
	xSize = xsz;
	ySize = ysz;
	xScale = 1;
	yScale = 1;
}

void ofImageExt::draw(float x, float y) {
	int a = 0;
	int b = 0;
	if(xScale < 0) {
		a = -1;
	}
	if(yScale < 0) {
		b = -1;
	}

	image.drawSubsection( x + (xSize * xScale * a), y  + (ySize * yScale * b), xSize* xScale, ySize * yScale,xStart , yStart , xSize, ySize);
}

float ofImageExt::getXSize() {
	return xSize;
}

float ofImageExt::getYSize() {
	return ySize;
}

void ofImageExt::setScale(float x, float y) {
	if(x != 0) {
		xScale = x;
	}
	if(y != 0) {
		yScale = y;
	}
}

float ofImageExt::getXScale() {
	return xScale;
}
float ofImageExt::getYScale() {
	return yScale;
}