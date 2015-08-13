#pragma once
#include <windows.h>
#include "Triangle.h"

class Heart {
private:
	SYSTEMTIME time;
	static const int triangle_num = 20;
	Triangle *triangle[triangle_num];
public:
	Heart();
	void drawHeart();
};
