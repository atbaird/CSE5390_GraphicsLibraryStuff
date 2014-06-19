#include "Chao.h"

Chao::Chao() {
	animations.resize(5);

	ofImage spriteSheet;
	spriteSheet.loadImage("chao.png");

	//idle
	ofImageExt idle1, idle2;
	idle1 = ofImageExt(spriteSheet, 0,0,23,25);
	idle2 = ofImageExt(spriteSheet, 23,0,23,25);
	animations[0].addSprite(idle1);
	animations[0].addSprite(idle2);

	//walk left
	ofImageExt left1, left2, left3;
	left1 = ofImageExt(spriteSheet, 220, 25,21,2);
	left2 = ofImageExt(spriteSheet, 240,25,21,25);
	left3 = ofImageExt(spriteSheet, 280,25,21,25);
	animations[1].addSprite(left1);
	animations[1].addSprite(left2);
	animations[1].addSprite(left1);
	animations[1].addSprite(left3);

	//walk right
	ofImageExt right1, right2, right3;
	right1 = ofImageExt(spriteSheet, 220,25,21,25);
	right2 = ofImageExt(spriteSheet, 280,25,21,25);
	right3 = ofImageExt(spriteSheet, 240,25,21,25);
	
	animations[2].addSprite(right1);
	animations[2].addSprite(right2);
	animations[2].addSprite(right1);
	animations[2].addSprite(right3);

	//walk up
	ofImageExt up1, up2, up3;
	up1 = ofImageExt(spriteSheet, 156,25,21,25);
	up2 = ofImageExt(spriteSheet, 177,25,21,25);
	up3 = ofImageExt(spriteSheet, 199,25,21,25);

	animations[3].addSprite(up1);
	animations[3].addSprite(up2);
	animations[3].addSprite(up1);
	animations[3].addSprite(up3);

	//walk down
	ofImageExt down1, down2;
	down1 = ofImageExt(spriteSheet, 0,25,23,25);
	down2 = ofImageExt(spriteSheet, 23,25,23,25);
	animations[4].addSprite(down1);
	animations[4].addSprite(idle1);
	animations[4].addSprite(down2);
	animations[4].addSprite(idle1);

	for(size_t i = 0; i < animations.size(); i++) {
		animations[i].setLoop(true);
		animations[i].setVisible(true);
		animations[i].setRunning(false);
	}

}

Chao::~Chao() {

}

void Chao::testSprites(clock_t currentTime) {
	for(size_t i = 0; i < animations.size(); i++) {
		animations[i].start(currentTime);
	}

}
void Chao::update(clock_t currentTime) {
	for(size_t i = 0; i < animations.size(); i++) {
		animations[i].update(currentTime);
	}
}
void Chao::drawTest() {
	animations[0].drawCurrentSprite(0,0);
	animations[1].drawCurrentSprite(26,0);
	animations[2].drawCurrentSprite(52,0);
	animations[3].drawCurrentSprite(0,26);
	animations[4].drawCurrentSprite(26,26);
}