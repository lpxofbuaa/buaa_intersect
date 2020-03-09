#pragma once
#include "Point.h"

class RationalPointCollection {
private:
	unordered_set<RationalPoint*, my_hash> *points;
public:
	RationalPointCollection();
	void push(RationalPoint* a);
	int size();
};