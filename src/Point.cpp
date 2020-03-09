#include "Point.h"

RationalPoint::RationalPoint(RationalNumber &x, RationalNumber &y) {
	this->x = x;
	this->y = y;
}

RationalPoint::RationalPoint() {}

bool RationalPoint::equals(const RationalPoint &a) const {
	return x.equals(a.x) && y.equals(a.y);
}

string RationalPoint::toString() const {
	return x.toString() + "," + y.toString();
}

size_t my_hash::operator()(RationalPoint* const& a) const {
	return hash<string>{}(a->toString());
}

bool my_equal::operator()(RationalPoint* const& a, RationalPoint* const& b) const {
	return a->equals(*b);
}



