#include <iostream>
#include "GeometryStatistic.h"
#include "Point.h"

using namespace std;

int main()
{
	unordered_set<RationalPoint*, my_hash, my_equal> *test = new unordered_set<RationalPoint*, my_hash, my_equal>();

	for (int i = 0; i < 1000; ++i) {
		RationalNumber a = RationalNumber(3, 4);
		RationalNumber b = RationalNumber(6, 800);
		test->insert(new RationalPoint(a, b));
	}

	cout << test->size() << endl;
	RationalNumber a = RationalNumber(3, 4);
	RationalNumber b = RationalNumber(5, 6);
	test->insert(new RationalPoint(a, b));
	cout << test->size() << endl;
}


