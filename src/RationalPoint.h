#pragma once
#include "RationalNumber.h"
#include <unordered_set>

class RationalPoint {
private:
	RationalNumber x;
	RationalNumber y;
public:
	bool equals(const RationalPoint &b) const;
	string toString() const;
};

struct my_hash {
	size_t operator()(RationalPoint const& a) const;
};