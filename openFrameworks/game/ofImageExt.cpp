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
	image.drawSubsection(xStart, yStart, xSize, ySize, x, y);
}
