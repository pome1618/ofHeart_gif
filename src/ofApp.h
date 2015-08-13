#pragma once

#include "ofMain.h"
#include "Heart.h"
#include "ofxGifEncoder.h"

class ofApp : public ofBaseApp{
private:
	ofLight light;
	Heart heart;

public:
	void setup();
	void draw();
	void onGifSaved(string &fileName);
	void exit();
	void captureFrame();
	void keyReleased(int key);
	vector <ofTexture *> txs; // for previewing
	vector <ofxGifFrame *> pxs;

	int frameW, frameH;
	int nFrames;

	ofVideoGrabber vid;
	ofxGifEncoder gifEncoder;
};
