#pragma once
#include "stdafx.h"
#include "Point.h"
#include "GeometryShape.h"

#include <vector>

class GeometryStatistic {
public:
	unordered_set<RationalPoint*, my_hash, my_equal> *rational_points;
	vector<Line> lines;
	GeometryStatistic();
	void feed(Line &l);
	void line_line_intersect(Line &l1, Line &l2);
	int getPointCount();
	bool containsPoint(RationalPoint *a);
};
