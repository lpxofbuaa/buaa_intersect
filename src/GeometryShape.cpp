#include "stdafx.h"
#include "GeometryShape.h"

Line::Line(int x1, int y1, int x2, int y2) {
	a_x = x1;
	a_y = y1;
	b_x = x2;
	b_y = y2;
}

Line::Line() {}

Circle::Circle() {}

Circle::Circle(int aa, int bb, int cc) {
	a = aa;
	b = bb;
	r = cc;
}