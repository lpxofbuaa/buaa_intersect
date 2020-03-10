#pragma once
#include "RationalNumber.h"
#include "stdafx.h"
#include <unordered_set>
#include <string>

using namespace std;

class RationalPoint {
private:
	RationalNumber x;
	RationalNumber y;
public:
	string hashstring;
	RationalPoint();
	RationalPoint(RationalNumber &x, RationalNumber &y);
	bool equals(const RationalPoint &b) const;
	string toString() const;
};

struct my_hash {
	size_t operator()(RationalPoint* const& a) const;
};

struct my_equal {
	bool operator()(RationalPoint* const& a, RationalPoint* const& b) const;
};