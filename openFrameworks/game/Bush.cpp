#include "Bush.h"

Bush::Bush() {
	ofImage image;
	image.loadImage("ChaoGardenAssets.png");
	anim.addSprite(ofImageExt(image, 0,24,24,21));
	x = 0;
	y = 0;
}
Bush::~Bush() {

}

void Bush::draw() {
	anim.drawCurrentSprite(x,y);
}

void Bush::setScale(float sX, float sY) {
	anim.setScale(sX, sY);
}

void Bush::setLocation(float xl, float yl) {
	x = xl;
	y = yl;
}

float Bush::getYSize() {
	ofImageExt eh = anim.getCurrentSprite();
	return eh.getYSize() * eh.getYScale();
}
float Bush::getXSize() {
	ofImageExt eh = anim.getCurrentSprite();
	return eh.getXSize() * eh.getXScale();
}

float Bush::getX() {
	return x;
}
float Bush::getY() {
	return y;
}