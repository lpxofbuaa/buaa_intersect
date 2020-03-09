#pragma once
#include "Point.h"
#include "GeometryShape.h"
#include <vector>

class GeometryStatistic {
private:
	unordered_set<RationalPoint*, my_hash> *rational_points;
	vector<Line> lines;
public:
	GeometryStatistic();
	void feed(Line &l);
	void line_line_intersect(Line &l1, Line &l2);
};
