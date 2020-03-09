#pragma once
#include "RationalPoint.h"

class RationalPointCalculator {
private:
	unordered_set<RationalPoint*, my_hash> *points;
public:
	RationalPointCalculator();
	void push(RationalPoint* a);
	int size();
};