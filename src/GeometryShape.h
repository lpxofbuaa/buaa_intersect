#pragma once
#include "Point.h"
#include "stdafx.h"

class Line {
public:
	int a_x, a_y, b_x, b_y;
	Line();
	Line(int x1, int y1, int x2, int y2);
};

class Circle {
public:
	int a, b, r;
	Circle();
	Circle(int aa, int bb, int cc);
};