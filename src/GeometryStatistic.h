#pragma once
#include "stdafx.h"
#include "Point.h"
#include "GeometryShape.h"

#include <vector>

class GeometryStatistic {
public:
	unordered_set<RationalPoint*, my_hash, my_equal> *rational_points;
	unordered_set<UnRationalPoint*, double_hash, double_equal> *unrational_points;
	vector<Line> lines;
	vector<Circle> circles;
	GeometryStatistic();
	void feed(Line &l);
	void feed(Circle &c);
	void line_line_intersect(Line &l1, Line &l2);
	void line_circle_intersect(Line &l1, Circle &c1);
	void circle_circle_intersect(Circle &c1, Circle &c2);
	int getPointCount();
	bool containsPoint(RationalPoint *a);
};
