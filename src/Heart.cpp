#include "Heart.h"

Heart::Heart() {
	for (int i = 0;i < triangle_num;i++) {
		triangle[i] = new Triangle(i*35,200+i*15);
	}
}

void Heart::drawHeart() {
	GetSystemTime(&time);
	for (int i = 0;i < triangle_num;i++) {
		triangle[i]->drawTriangle(time.wMilliseconds/10-i*2);
	}
}
