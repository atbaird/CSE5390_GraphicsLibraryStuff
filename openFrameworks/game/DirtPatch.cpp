#include "DirtPatch.h"

DirtPatch::DirtPatch() {
	ofImage spriteSheet;
	spriteSheet.loadImage("ChaoGardenAssets.png");
	for(size_t i = 0; i < 4; i++) {
		images.push_back(ofImageExt(spriteSheet, 19,0, 30, 23));
	} //should go top left, top right, bottom left, bottom right
}
DirtPatch::~DirtPatch() {

}

void DirtPatch::setScale(float x, float y) {
	
	images[0].setScale(x, -1 * y);
	images[1].setScale(-1 * x, -1 *y);
	images[2].setScale(x, y);
	images[3].setScale(-1 * x, y);
}
void DirtPatch::setPosition(float x, float y) {
	startx = x;
	starty = y;
}

void DirtPatch::draw() {
	float x= 0;
	float y = 0;
	for(size_t i = 0; i < images.size(); i++) {
		images[i].draw(startx + x, starty + y);

		if(x == 0) {
			x = images[i].getXSize() * images[i].getXScale();
		} else {
			x = 0;
			y = images[i].getYSize() * images[i].getYScale();
			if(images[i].getYScale() < 0) {
				y = y * -1;
			}
		}
	}
}