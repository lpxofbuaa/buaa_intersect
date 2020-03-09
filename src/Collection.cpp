#include "Collection.h"

RationalPointCollection::RationalPointCollection() {
	points = new unordered_set<RationalPoint*, my_hash>();
}

void RationalPointCollection::push(RationalPoint *a) {
	points->insert(a);
}

int RationalPointCollection::size() {
	return points->size();
}