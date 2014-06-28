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
}

//--------------------------------------------------------------
void ofApp::update(){
	ofBackground(255);
	clock_t clk = clock();
	chao.update(clk);
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255);
	background.draw();
	//chao.drawTest();
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
