#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	srand(time(NULL));
	chao = Chao();
	background = Background();
	background.setStart(160,90);
	chao.setLimits(background.getXStart(), background.getXLength() + background.getXStart(), 
		background.getYStart(), background.getYStart() + background.getYLength());
	chao.testSprites(clock());

	chao.randomizeStartPos();

	for(size_t i = 0; i < 11; i++) {
		Bush bush;
		bush.setScale(background.getXScale(), background.getYScale());
		bushes.push_back(bush);
	}
	bushes[0].setLocation(background.getXStart() - 30, background.getYStart() +5);
	bushes[1].setLocation(background.getXStart() + 100, background.getYStart() - (bushes[1].getYSize()/2));
	bushes[2].setLocation(background.getXStart() - 30 , background.getYStart() +100);
	bushes[3].setLocation(background.getXStart() + 35, background.getYStart() +55);
	bushes[4].setLocation(background.getXStart() + +85, background.getYStart() + 100);
	bushes[5].setLocation(background.getXStart() + 120, background.getYStart() +30);
	bushes[6].setLocation(background.getXStart() + 200, background.getYStart() -10);
	bushes[7].setLocation(background.getXStart() + 300, background.getYStart() +5);
	bushes[8].setLocation(background.getXStart() - 30, background.getYStart() + 300);
	bushes[9].setLocation(background.getXStart() + 350, background.getYStart() +515);
	bushes[10].setLocation(background.getXStart() + 410, background.getYStart() +540);
}

//--------------------------------------------------------------
void ofApp::update(){
	ofBackground(255);
	clock_t clk = clock();
	chao.update(clk, bushes);
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255);
	background.draw();
	//chao.drawTest();
	for(size_t i = 0; i < bushes.size(); i++) {
		bushes[i].draw();
	}
	chao.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
