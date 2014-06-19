#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	chao = Chao();
	chao.testSprites(clock());
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
	chao.drawTest();
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
