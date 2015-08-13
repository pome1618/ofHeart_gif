#include "Triangle.h"
#include "math.h"
#include "ofGLRenderer.h"

Triangle::Triangle(int z,int offset_size) {
	this->z = z;
	this->offset_size = offset_size;
	offset_angle = 0;
	angle_mag = 0;
	direct = rand() % 2;
}

void Triangle::calcSize(int time){
	if (0 <= time && time < 360) {
		size = abs(time - 180) - 180;
	}
	else if (360 <= time && time <860) {
		size = 250 - abs(time - 360 - 250);
	}
	else {
		size = 0;
	}
	size += offset_size;
}

void Triangle::calcPoint() {
	for (int i = 0;i < 3;i++) {
		double angle = (2.0/3.0*i+1.0/2.0)*PI+offset_angle*DEG_TO_RAD;
		x[i] = size*cos(angle);
		y[i] = size*sin(angle);
	}
}

void Triangle::calcOffsetAngle() {
	if (ofGetFrameNum() % 60 == 0) {
		if (rand() % 4 == 0) {
			direct= 1^direct;
		}
		angle_mag = (rand() % 20+angle_mag)/2.0;
	}
	offset_angle += direct?angle_mag/60.0:-angle_mag / 60.0;
}

void Triangle::drawTriangle(int time) {
	calcOffsetAngle();
	calcSize(time);
	calcPoint();
	ofSetColor(150, 0, 0,200);
	ofDrawTriangle(x[0], y[0], z, x[1], y[1], z, x[2], y[2], z);
}
