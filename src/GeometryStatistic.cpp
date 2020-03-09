#include "GeometryStatistic.h"

GeometryStatistic::GeometryStatistic() {
	rational_points = new unordered_set<RationalPoint*, my_hash>();
}

void GeometryStatistic::feed(Line &l) {
	for (vector<Line>::iterator i = lines.begin(); i != lines.end(); ++i) {
		line_line_intersect(*i, l);
	}
}

void GeometryStatistic::line_line_intersect(Line &l1, Line &l2) {
	RationalNumber new_x;
	RationalNumber new_y;
	long long b = (l2.a_x * l2.b_y - l2.a_y * l2.b_x) * (l1.a_x - l1.b_x)
		- (l1.a_x * l1.b_y - l1.a_y * l1.b_x) * (l2.a_x - l2.b_x);
	long long a = (l1.a_y - l1.b_y) * (l2.a_x - l2.b_x) - (l1.a_x - l1.b_x) * (l2.a_y - l2.b_y);
	if (a != 0) {
		new_x = RationalNumber(b, a);
		new_y = RationalNumber((l1.a_y - l1.b_y) * b + (l1.a_x * l1.b_y - l1.a_y * l1.b_x) * a
			, a * (l1.a_x - l1.b_x));
		rational_points->insert(new RationalPoint(new_x, new_y));
	}
}