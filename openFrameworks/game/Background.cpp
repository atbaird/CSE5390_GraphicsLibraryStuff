#include "Background.h"

Background::Background() {
	dirtpatches.resize(2);
	ofImage spriteSheet;
	spriteSheet.loadImage("ChaoGardenAssets.png");

	cells.resize(10); //y
	for(size_t i = 0; i < cells.size(); i++) {
		for(size_t j = 0; j < 11; j++) {
			cells[i].push_back(ofImageExt(spriteSheet, 0,0, 15,15));
		}
	}
	setScale(4,4);
	setStart(0,0);
	dirtpatches[0].setPosition(0,0);
	dirtpatches[1].setPosition(0,0);
	dirtpatches[0].setScale(4,4);
	dirtpatches[1].setScale(4,4);
}

Background::~Background() {

}

void Background::setStart(float x, float y) {
	xStart = x;
	yStart = y;
	updatePatches();
}

void Background::updatePatches() {
	dirtpatches[0].setPosition(xStart + (6.5 * cells[0][0].getXScale() * cells[0][0].getXSize()),yStart + (1 * cells[0][0].getYScale() * cells[0][0].getYSize()));
	dirtpatches[1].setPosition(xStart + (9 * cells[0][0].getXScale() * cells[0][0].getXSize()), yStart + (-0.75 * cells[0][0].getYScale() * cells[0][0].getYSize()));
}

void Background::setScale(float x, float y) {
	for(size_t i = 0; i < cells.size(); i++) {
		for(size_t j = 0; j < cells[i].size(); j++) {
			cells[i][j].setScale(x,y);
		}
	}
	updatePatches();
}

void Background::draw() {
	float x = xStart;
	float y = yStart;

	for(size_t i = 0; i < cells.size(); i++) {
		for(size_t j = 0; j < cells[i].size(); j++) {
			cells[i][j].draw(x,y);
			x += (cells[i][j].getXSize() * cells[i][j].getXScale());
		}
		x = xStart;
		y += (cells[i][0].getYSize() * cells[i][0].getYScale());
	}

	for(size_t i = 0; i < dirtpatches.size(); i++) {
		dirtpatches[i].draw();
	}
}

float Background::getXLength() {
	float returnMe = 0;
	int numOfX = cells[0].size();
	int scale = cells[0][0].getXScale();
	int size = cells[0][0].getXSize();
	returnMe = numOfX * scale * size;
	return returnMe;
}

float Background::getYLength() {
	float returnMe = 0;
	int numOfY = cells.size();
	int scale = cells[0][0].getYScale();
	int size = cells[0][0].getYSize();
	returnMe = numOfY * scale * size;
	return returnMe;
}
float Background::getXStart() {
	return xStart;
}
float Background::getYStart() {
	return yStart;
}