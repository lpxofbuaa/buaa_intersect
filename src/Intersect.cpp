#include "stdafx.h"
#include <iostream>
#include "GeometryStatistic.h"
#include "Point.h"
#include "Reader.h"


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

int main(int argc, char* argv[])
{
	/*GeometryStatistic *test = new GeometryStatistic();
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
	//check(test);*/

	if (argc == 5) {
		string in_file;
		string out_file;
		if (argv[1][0] == '-' && argv[1][1] == 'i') {
			in_file = argv[2];
		}
		if (argv[3][0] == '-' && argv[3][1] == 'o') {
			out_file = argv[4];
		}
		Reader read(in_file, out_file);
		GeometryStatistic *statistic = new GeometryStatistic();
		read.read();
		for (vector<Line>::iterator i = read.lines.begin(); i != read.lines.end(); ++i) {
			statistic->feed(*i);
		}
		for (vector<Circle>::iterator i = read.circles.begin(); i != read.circles.end(); ++i) {
			statistic->feed(*i);
		}
		read.write(statistic->getPointCount());
		//cout << statistic->getPointCount() << endl;
		cout << statistic->rational_points->size() << endl;
		cout << statistic->unrational_points->size() << endl;
	}
	//cout << argc << endl;
}




