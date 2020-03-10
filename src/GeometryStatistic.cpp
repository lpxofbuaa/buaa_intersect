#include "stdafx.h"
#include "GeometryStatistic.h"
#include <iostream>

using namespace std;


GeometryStatistic::GeometryStatistic() {
	rational_points = new unordered_set<RationalPoint*, my_hash, my_equal>();
}

void GeometryStatistic::feed(Line &l) {
	for (vector<Line>::iterator i = lines.begin(); i != lines.end(); ++i) {
		line_line_intersect(*i, l);
	}
	lines.push_back(l);
}

void GeometryStatistic::line_line_intersect(Line &l1, Line &l2) {
	RationalNumber new_x;
	RationalNumber new_y;
	long long b = (l2.a_x * l2.b_y - l2.a_y * l2.b_x) * (l1.a_x - l1.b_x)
		- (l1.a_x * l1.b_y - l1.a_y * l1.b_x) * (l2.a_x - l2.b_x);
	long long a = (l1.a_y - l1.b_y) * (l2.a_x - l2.b_x) - (l1.a_x - l1.b_x) * (l2.a_y - l2.b_y);
	if (a != 0) {
		new_x = RationalNumber(b, a);
		//cout << b << "/" << a << endl;
		new_y = RationalNumber((l1.a_y - l1.b_y) * b + (l1.a_x * l1.b_y - l1.a_y * l1.b_x) * a
			, a * (l1.a_x - l1.b_x));
		//cout << (l1.a_y - l1.b_y) * b + (l1.a_x * l1.b_y - l1.a_y * l1.b_x) * a << "/" << a * (l1.a_x - l1.b_x) << endl;
		rational_points->insert(new RationalPoint(new_x, new_y));
	}
}

int GeometryStatistic::getPointCount() {
	return rational_points->size();
}

bool GeometryStatistic::containsPoint(RationalPoint *a) {
	return rational_points->find(a) != rational_points->end();
}