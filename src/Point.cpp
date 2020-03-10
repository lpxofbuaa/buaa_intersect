#include "stdafx.h"
#include "Point.h"
#include <iostream>

using namespace std;


RationalPoint::RationalPoint(RationalNumber &x, RationalNumber &y) {
	this->x = x;
	this->y = y;
	this->hashstring = this->toString();
	//cout << toString() << endl;
}

RationalPoint::RationalPoint() {}

bool RationalPoint::equals(const RationalPoint &a) const {
	return x.equals(a.x) && y.equals(a.y);
}

string RationalPoint::toString() const {
	return x.toString() + "," + y.toString();
}

size_t my_hash::operator()(RationalPoint* const& a) const {
	return hash<string>{}(a->hashstring);
}

bool my_equal::operator()(RationalPoint* const& a, RationalPoint* const& b) const {
	return a->equals(*b);
}



