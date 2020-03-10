#include "stdafx.h"
#include <iostream>
#include "GeometryStatistic.h"
#include "Point.h"


using namespace std;

void check(GeometryStatistic *test) {
	RationalNumber a(4, 3);
	RationalNumber b(1, 2);
	RationalNumber c(3, 1);
	RationalNumber d(-2, 1);
	RationalPoint p1(a, a);
	RationalPoint p2(b, b);
	RationalPoint p3(c, d);
	RationalPoint *tmp = (*test->rational_points->begin());
	my_hash my;
	my_equal eq;
	cout << "ww" << endl;
	cout << p1.toString() << endl;
	cout << tmp->toString() << endl;
	cout << "ee" << endl;
	cout << my.operator()(&p1) << endl;
	cout << my.operator()(tmp) << endl;
	cout << eq.operator()(&p1, tmp) << endl;
	cout << "FFF" << endl;
	
	cout << test->containsPoint(&p1) << endl;
	cout << test->rational_points->size() << endl;
	test->rational_points->insert(&p1);
	cout << test->containsPoint(&p1) << endl;
	cout << test->rational_points->size() << endl;
}

int main()
{
	GeometryStatistic *test = new GeometryStatistic();
	RationalNumber a(4, 3);
	RationalNumber b(1, 2);
	RationalNumber c(3, 1);
	RationalNumber d(-2, 1);
	Line l1(0, 0, 1, 1);
	Line l2(1, 0, 0, 1);
	Line l3(1, 2, 2, 0);
	test->feed(l1);
	test->feed(l2);
	test->feed(l3);
	for (unordered_set<RationalPoint*, my_hash, my_equal>::iterator i = test->rational_points->begin(); i != test->rational_points->end(); ++i) {
		//cout << (*i)->toString() << endl;
	}
	//check(test);
}




