#include "Chao.h"

Chao::Chao() {
	size_t numOfAnimations = 5;
	animations.resize(numOfAnimations);

	currentAnimation = 2;
	pause = false;
	visible = false;
	xScale = 2;
	yScale = 2;
	xCor = 0;
	yCor = 0;
	xSpeed = 0;
	ySpeed = 0;
	frameSpeed = 750;
	lastMoveDecision = clock();
	begXWall = 0;
	begYWall = 0;
	endXWall = 600;
	endYWall = 600;
	xCor = (float)(rand() % (int)endXWall);
	yCor = (float)(rand()% (int)endYWall);
	
	//idle animation
	sf::Texture idle1,idle2;
	idle1.loadFromFile("chao.png", sf::IntRect(0,0,23,25));
	idle1.loadFromFile("chao.png",sf::IntRect(23,0,23,25));
	animations[0].addFrameTexture(idle1);
	animations[0].addFrameTexture(idle2);

	//walk left
	sf::Texture left1, left2, left3; //11 *23 = 23 + 230 = 253
	left1.loadFromFile("chao.png",sf::IntRect(220, 25,21,25)); //stand
	left2.loadFromFile("chao.png", sf::IntRect(240,25,21,25)); //left foot
	left3.loadFromFile("chao.png",sf::IntRect(280,25,21,25)); //right foot
	animations[1].addFrameTexture(left1);
	animations[1].addFrameTexture(left2);
	animations[1].addFrameTexture(left1);
	animations[1].addFrameTexture(left3);

	//walk right
	sf::Texture right1, right2, right3;
	right1.loadFromFile("chao.png", sf::IntRect(220,25,21,25));
	right2.loadFromFile("chao.png", sf::IntRect(280,25,21,25));
	right3.loadFromFile("chao.png", sf::IntRect(240,25,21,25));
	sf::Sprite rSprite1, rSprite2, rSprite3;
	rSprite1.setTexture(right1);
	rSprite2.setTexture(right2);
	rSprite3.setTexture(right3);
	animations[2].addFrame(rSprite1);
	animations[2].addFrame(rSprite2);
	animations[2].addFrame(rSprite1);
	animations[2].addFrame(rSprite3);
	

	//walk up
	sf::Texture up1, up2, up3;
	up1.loadFromFile("chao.png",sf::IntRect(156,25,21,25)); //stand
	up2.loadFromFile("chao.png",sf::IntRect(177,25,21,25)); //right foot
	up3.loadFromFile("chao.png",sf::IntRect(199,25,21,25)); //left foot
	animations[3].addFrameTexture(up1);
	animations[3].addFrameTexture(up2);
	animations[3].addFrameTexture(up1);
	animations[3].addFrameTexture(up3);

	//walk down
	sf::Texture down1, down2;
	down1.loadFromFile("chao.png", sf::IntRect(0,25,23,25));
	down2.loadFromFile("chao.png", sf::IntRect(23,25,23,25));
	animations[4].addFrameTexture(down1);
	animations[4].addFrameTexture(idle1);
	animations[4].addFrameTexture(down2);
	animations[4].addFrameTexture(idle1);

	for(size_t i = 0; i < animations.size(); i++) {
		animations[i].setPosition(xCor, yCor);
		animations[i].setVisible(false);
		animations[i].setScale(xScale,yScale);
		animations[i].setDelay(frameSpeed);
		animations[i].Loop();
	}
	
	animations[2].setScale(-2.f,2.f);

}
Chao::~Chao() {

}

void Chao::hideAll() {
	for(size_t i = 0; i < animations.size(); i++) {
		animations[i].setVisible(false);
	}
}
void Chao::stopAll() {
	for(size_t i = 0; i < animations.size(); i++) {
		animations[i].stop();
	}
}

void Chao::update(clock_t currentTime) {
	if( (currentTime - lastMoveDecision) >= 5000) {
		int random = rand() % animations.size();
		animations[currentAnimation].stop();
		animations[currentAnimation].hide();
		switch(random) {
		case 0: //stand still
			currentAnimation = 0;
			xSpeed = 0;
			ySpeed = 0;
			break;
		case 1: //mostly leftward movement
			currentAnimation = 1;
			setTwoSpeedsOneLesser(xSpeed, ySpeed, false, randBool());
			break;
		case 2: //mostly rightward movement
			currentAnimation = 2;
			setTwoSpeedsOneLesser(xSpeed, ySpeed, true, randBool());
			break;
		case 3: //mostly upward movement
			setTwoSpeedsOneLesser(ySpeed, xSpeed, false, randBool());
			currentAnimation = 3;
			break;
		case 4: //mostly downward movement
			setTwoSpeedsOneLesser(ySpeed, xSpeed, true, randBool());
			currentAnimation = 4;
			break;
		default: //stand still
			currentAnimation = 0;
			xSpeed = 0;
			ySpeed = 0;
			break;
		}
		animations[currentAnimation].start(currentTime);
		animations[currentAnimation].show();
		lastMoveDecision = currentTime;
	} else {
		float newX = xCor + xSpeed;
		float newY = yCor + ySpeed;
		animations[currentAnimation].update(currentTime);
		if(newX + (22 * xScale) >= endXWall) {
			newX = endXWall - (22 * xScale);
		} else if(newX < 0) {
			newX = 0;
		}
		if(newY + (25 *yScale) >= endYWall) {
			newY = endYWall - (25*yScale);
		} else if(newY < 0) {
			newY = 0;
		}
		xCor = newX;
		yCor = newY;
		keepImagesSamePosScale();
	}
	cout << "Current Animation: " << currentAnimation << "\n";

}
void Chao::changeWindowConstraints(float xStart, float yStart, float xEnd, float yEnd) {
	begXWall = xStart;
	begYWall = yStart;
	endXWall = xEnd;
	endYWall = yEnd;
}

sf::Sprite & Chao::getCurrentSprite() {
	return animations[currentAnimation].getCurrentSprite();
}


void Chao::keepImagesSamePosScale() {
	for(size_t i = 0; i < animations.size(); i++) {
		animations[i].setPosition(xCor, yCor);
		animations[i].setScale(xScale, yScale);
		animations[i].setDelay(frameSpeed);
	}
}
void Chao::setTwoSpeedsOneLesser(float& greater, float& lesser, bool greaterPos, bool lesserPos) {
	greater = (float)(1 + (rand() % 2));
	if(greater > 0) {
		lesser = (float)(rand() % (int)greater);
	} else {
		lesser = 0;
	}
	if(greaterPos == false) {
		greater = greater * -1;
	} if(lesserPos == false) {
		lesser = lesser * -1;
	}
}
bool Chao::randBool() {
	int random = rand() % 2;
	if(random == 0) {
		return true;
	}
	return false;
}