#pragma once
#include<unordered_set>
#include<string>

using namespace std;

class RationalNumber {
private:
	long long molecule;
	long long denominator;
public:
	RationalNumber() {};
	RationalNumber(long long n, long long m);
	string toString() const;
	double toDouble() const;
	bool equals(const RationalNumber &b) const;
};
