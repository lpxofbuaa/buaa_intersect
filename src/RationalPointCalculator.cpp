#include "RationalPointCalculator.h"

RationalPointCalculator::RationalPointCalculator() {
	points = new unordered_set<RationalPoint*, my_hash>();
}

void RationalPointCalculator::push(RationalPoint *a) {
	points->insert(a);
}

int RationalPointCalculator::size() {
	return points->size();
}