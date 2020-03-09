#include "RationalPoint.h"

bool RationalPoint::equals(const RationalPoint &a) const {
	return x.equals(a.x) && y.equals(a.y);
}

string RationalPoint::toString() const {
	return x.toString() + "," + y.toString();
}

size_t my_hash::operator()(RationalPoint const& a) const {
	return hash<string>{}(a.toString());
}

