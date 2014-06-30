#include "Chao.h"

Chao::Chao() {
	animations.resize(6);
	chaoBall.resize(1);

	ofImage spriteSheet;
	spriteSheet.loadImage("chao.png");

	//idle
	ofImageExt idle1, idle2;
	idle1 = ofImageExt(spriteSheet, 0,0,22,25);
	animations[0].addSprite(idle1);

	//walk left
	ofImageExt left1, left2, left3;
	left1 = ofImageExt(spriteSheet, 221, 26,20,25);
	left2 = ofImageExt(spriteSheet, 241,26,19,25);
	left3 = ofImageExt(spriteSheet, 281,26,19,25);
	animations[1].addSprite(left1);
	animations[1].addSprite(left2);
	animations[1].addSprite(left1);
	animations[1].addSprite(left3);

	//walk right
	ofImageExt right1, right2, right3;
	right1 = ofImageExt(spriteSheet, 221,26,20,25);
	right2 = ofImageExt(spriteSheet, 281,26,19,25);
	right3 = ofImageExt(spriteSheet, 241,26,19,25);
	
	animations[2].addSprite(right1);
	animations[2].addSprite(right2);
	animations[2].addSprite(right1);
	animations[2].addSprite(right3);

	//walk up
	ofImageExt up1, up2, up3;
	up1 = ofImageExt(spriteSheet, 157,26,19,24);
	up2 = ofImageExt(spriteSheet, 177,26,21,25);
	up3 = ofImageExt(spriteSheet, 199,26,21,25);

	animations[3].addSprite(up1);
	animations[3].addSprite(up2);
	animations[3].addSprite(up1);
	animations[3].addSprite(up3);

	//walk down
	ofImageExt down1, down2;
	down1 = ofImageExt(spriteSheet, 0,26,23,25);
	down2 = ofImageExt(spriteSheet, 23,26,23,25);
	animations[4].addSprite(down1);
	animations[4].addSprite(idle1);
	animations[4].addSprite(down2);
	animations[4].addSprite(idle1);

	//idle 2
	idle2 = ofImageExt(spriteSheet, 22,0,21,25);
	animations[5].addSprite(idle2);

	//chaoBall
	ofImageExt ballPos1, ballPos2, ballPos3;
	ballPos1 = ofImageExt(spriteSheet, 3, 267, 5, 16);
	ballPos2 = ofImageExt(spriteSheet, 3,268, 5,16);
	ballPos3 = ofImageExt(spriteSheet, 3,266,5,16);
	chaoBall[0].addSprite(ballPos1);
	chaoBall[0].addSprite(ballPos2);
	chaoBall[0].addSprite(ballPos1);
	chaoBall[0].addSprite(ballPos3);

	for(size_t i = 0; i < animations.size(); i++) {
		animations[i].setLoop(true);
		animations[i].setVisible(true);
		animations[i].setRunning(false);
		animations[i].setDelay(1000);
	}

	for(size_t i = 0; i < chaoBall.size(); i++) {
		chaoBall[i].setLoop(true);
		chaoBall[i].setVisible(true);
		chaoBall[i].setRunning(false);
		chaoBall[i].setDelay(1000);
	}

	setScale(3,3);

	lastMoveDecision = clock();
	x = 0;
	y = 0;
	setLimits(0,800,0,700);
	genRandMov();
}

Chao::~Chao() {

}

void Chao::setLimits(float xM, float xMax, float yM, float yMax) {
	xMin = xM;
	xLimit = xMax - (23 * currentXScale);
	yMin = yM;
	yLimit = yMax - (25 * currentYScale);
}

void Chao::testSprites(clock_t currentTime) {
	for(size_t i = 0; i < animations.size(); i++) {
		animations[i].start(currentTime);
	}
	for(size_t i = 0; i < chaoBall.size(); i++) {
		chaoBall[i].start(currentTime);
	}
}
void Chao::genRandMov() {
	moveDec = rand() % animations.size();
	if(moveDec == 0) {
		xSpeed = 0;
		ySpeed = 0;
	} else if(moveDec == 1) {
		xSpeed = -1;
		ySpeed = 0;
	} else if(moveDec == 2) {
		xSpeed = 1;
		ySpeed = 0;
	} else if(moveDec == 3) {
		ySpeed = -1;
		xSpeed = 0;
	} else if(moveDec == 4) {
		ySpeed = 1;
		xSpeed = 0;
	} else if(moveDec == 5) {
		xSpeed = 0;
		ySpeed = 0;
	}
}

void Chao::update(clock_t currentTime, vector<Bush>& bushes) {
	for(size_t i = 0; i < animations.size(); i++) {
		animations[i].update(currentTime);
	}
	for(size_t i = 0; i < chaoBall.size(); i++) {
		chaoBall[i].update(currentTime);
	}

	if(currentTime - lastMoveDecision > 5000) {
		lastMoveDecision = currentTime;
		genRandMov();
	}
	float testX = x+ xSpeed;
	float testX2 = testX + (23* currentXScale);
	float testY = y + ySpeed;
	float testY2 = testY + (25 * currentYScale);
	for(size_t i = 0; i < bushes.size(); i++) {
		float bushXSize = bushes[i].getXSize();
		float bushYSize = bushes[i].getYSize();
		float bushX = bushXSize + bushes[i].getX();
		float bushY = bushYSize + bushes[i].getY();
		if(testX < bushX && testX > bushes[i].getX() && ((testY < bushY && testY > bushes[i].getY()) || (testY2 < bushY && testY2 > bushes[i].getY()))) {
			cout << " " << i << " true";
		} else if(testX2 <bushX && testX2 > bushes[i].getX() && ((testY < bushY && testY > bushes[i].getY()) || (testY2 < bushY && testY2 > bushes[i].getY()))) {
			cout << " " << i << " true";
		} else {
			cout << " " << i << " false";
		}
	}
	cout << "\n";
	x = testX;
	y = testY;

	if(x < xMin) {
		x = xMin;
	}
	if(x >= xLimit) {
		x = xLimit -1;
	}
	if(y < yMin) {
		y = yMin;
	}
	if( y >= yLimit) {
		y = yLimit - 1;
	}
	
}

void Chao::draw() {
	animations[moveDec].drawCurrentSprite(x,y);
	if(moveDec == 0 || moveDec == 5 || moveDec == 1 || moveDec == 4) {
		
		chaoBall[0].drawCurrentSprite(x + ((currentXScale * 23)/2), y - (16 * currentYScale));
	} else {
		chaoBall[0].drawCurrentSprite(x + ((currentXScale * 23)/4), y - (16*currentYScale));
	}
}
void Chao::drawTest() {
	animations[0].drawAll(0,0);
	animations[1].drawAll(0,52);
	animations[2].drawAll(0,104);
	animations[3].drawAll(0,156);
	animations[4].drawAll(0,208);
	animations[5].drawAll(0,264);

	animations[0].drawCurrentSprite(180, 0);
	animations[1].drawCurrentSprite(180,52);
	animations[2].drawCurrentSprite(180,104);
	animations[3].drawCurrentSprite(180,156);
	animations[4].drawCurrentSprite(180,208);
	animations[5].drawCurrentSprite(180,264);
}

void Chao::setScale(float x, float y) {
	currentXScale = x;
	currentYScale = y;
	for(size_t i = 0; i < animations.size(); i++) {
		animations[i].setScale(x,y);
	}
	animations[2].setScale(-1*x,y);
	for(size_t i = 0; i < chaoBall.size(); i++) {
		chaoBall[i].setScale(x,y);
	}
}

void Chao::randomizeStartPos() {
	x = xMin + ( rand() % (int)(xLimit - xMin));
	y = yMin + (rand() % (int)(yLimit - yMin));
}