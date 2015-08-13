#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetWindowTitle("Heart");
	ofBackground(15, 0, 0);
	ofSetFrameRate(60);
	ofEnableAlphaBlending();
	light.enable();
	ofEnableDepthTest();
	ofEnableSmoothing();
	light.setDirectional();
	light.setPosition(ofGetWidth() / 2, ofGetHeight() / 2 - 600,0);
	light.setAmbientColor(ofFloatColor(1.0, 1.0, 1.0, 1.0));
	light.setDiffuseColor(ofFloatColor(1.0, 1.0, 1.0));
	light.setSpecularColor(ofFloatColor(0,0, 0));
	gifEncoder.setup(ofGetWidth(), ofGetHeight());
	gifEncoder.setDitherMode(OFX_GIF_DITHER_NONE);
	ofAddListener(ofxGifEncoder::OFX_GIF_SAVE_FINISHED, this, &ofApp::onGifSaved);
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2 + 400, -400);
	ofRotateX(100);
	ofRotateY(0);
	ofRotateZ(0);
	heart.drawHeart();
	if (ofGetFrameNum()>=180&&ofGetFrameNum() % 6 == 0) {
		captureFrame();
	}
	if (ofGetFrameNum() == 360) {
		gifEncoder.save("result.gif");
	}
}

void ofApp::onGifSaved(string &fileName) {
	cout << "gif saved as " << fileName << endl;
}
void ofApp::exit() {
	gifEncoder.exit();
}

void ofApp::captureFrame() {
	ofImage img;
	img.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
	gifEncoder.addFrame(img);
}

void ofApp::keyReleased(int key) {
	switch (key) {
	case ' ':
		captureFrame();
		break;
	case 's':
		cout << "start saving\n" << endl;
		gifEncoder.save("test.gif");
		break;
	default:
		break;
	}
}