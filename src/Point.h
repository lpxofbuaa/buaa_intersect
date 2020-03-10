#pragma once
#include "RationalNumber.h"
#include "stdafx.h"
#include <unordered_set>
#include <string>
#include <map>

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

class UnRationalPoint {
public:
	double x;
	double y;
	UnRationalPoint();
	UnRationalPoint(double a, double b);
};

struct my_hash {
	size_t operator()(RationalPoint* const& a) const;
};

struct my_equal {
	bool operator()(RationalPoint* const& a, RationalPoint* const& b) const;
};

struct double_hash {
	size_t operator()(UnRationalPoint* const& a) const;
};

struct double_equal {
	bool operator()(UnRationalPoint* const& a, UnRationalPoint* const& b) const;
};