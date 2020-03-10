#include "stdafx.h"
#include "GeometryStatistic.h"
#include <iostream>

using namespace std;


GeometryStatistic::GeometryStatistic() {
	rational_points = new unordered_set<RationalPoint*, my_hash, my_equal>();
	unrational_points = new unordered_set<UnRationalPoint*, double_hash, double_equal>();
}

void GeometryStatistic::feed(Line &l) {
	for (vector<Line>::iterator i = lines.begin(); i != lines.end(); ++i) {
		line_line_intersect(*i, l);
	}
	for (vector<Circle>::iterator i = circles.begin(); i != circles.end(); ++i) {
		line_circle_intersect(l, *i);
	}
	lines.push_back(l);
}

void GeometryStatistic::feed(Circle &c) {
	for (vector<Line>::iterator i = lines.begin(); i != lines.end(); ++i) {
		line_circle_intersect(*i, c);
	}
	for (vector<Circle>::iterator i = circles.begin(); i != circles.end(); ++i) {
		circle_circle_intersect(c, *i);
	}
	circles.push_back(c);
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

void GeometryStatistic::line_circle_intersect(Line &l, Circle &c) {
	RationalNumber k(l.b_y - l.a_y, l.b_x - l.a_x);
	RationalNumber b(l.a_x*l.b_y - l.b_x*l.a_y, l.a_x - l.b_x);
	RationalNumber tmp = b.sub(c.b);
	RationalNumber tmp_1 = k.mult(tmp).sub(c.a);
	RationalNumber delta = tmp_1.mult(delta);

	RationalNumber k2_1 = k.mult(k).add(1);
	RationalNumber b_n = b.sub(c.b);
	b_n = b_n.mult(b_n);
	RationalNumber tmp2 = b_n.add(c.a * c.a - c.r * c.r);
	tmp2 = tmp2.mult(k2_1);
	delta = delta.sub(tmp2).mult(4);

	if (not delta.sign()) {
		return;
	}

	if (delta.canSqrt()) {
		delta = delta.Sqrt();
		RationalNumber aa = tmp_1.mult(-2).add(delta);
		RationalNumber bb = tmp2.mult(4);
		RationalNumber x1 = aa.div(bb);
		RationalNumber y1 = k.mult(x1).add(b);

		aa = tmp_1.mult(-2).sub(delta);
		RationalNumber x2 = aa.div(bb);
		RationalNumber y2 = k.mult(x2).add(b);
		rational_points->insert(new RationalPoint(x1, y1));
		rational_points->insert(new RationalPoint(x2, y2));
	}
	else {
		double t1 = tmp_1.toDouble();
		double t2 = tmp2.toDouble();
		double d = sqrt(delta.toDouble());

		double x1 = (-2 * t1 + d) / (4 * t2);
		double y1 = k.toDouble() * x1 + b.toDouble();

		double x2 = (-2 * t1 - d) / (4 * t2);
		double y2 = k.toDouble() * x2 + b.toDouble();

		unrational_points->insert(new UnRationalPoint(x1, y1));
		unrational_points->insert(new UnRationalPoint(x2, y2));
	}


}

void GeometryStatistic::circle_circle_intersect(Circle &c1, Circle &c2) {
	
}

int GeometryStatistic::getPointCount() {
	return rational_points->size();
}

bool GeometryStatistic::containsPoint(RationalPoint *a) {
	return rational_points->find(a) != rational_points->end();
}