#pragma once
#include <random>

class Triangle {
private:
	int x[3];
	int y[3];
	int z;
	int size;
	std::random_device rand;
	int offset_size;
	double offset_angle;
	bool direct;
	int angle_mag;
	void calcSize(int time);
	void calcPoint();
	void calcOffsetAngle();
public:
	Triangle(int z,int offset_size);
	void drawTriangle(int time);
};
