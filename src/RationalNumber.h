#pragma once
#include<unordered_set>
#include<string>

using namespace std;

class RationalNumber {
private:
	long long molecule;
	long long denominator;
public:
	RationalNumber(long long n, long long m);
	string toString();
	double toDouble();
	bool equals(const RationalNumber &b);
};
