#include "RationalNumber.h"

RationalNumber::RationalNumber(long long n, long long m) {
	long long before_n = n;
	long long before_m = m;
	bool isBig = n > m;
	if (isBig) {
		long long tmp = n;
		n = m;
		m = tmp;
	}
	while (n != 0) {
		long long rem = m % n;
		m = n;
		n = rem;
	}
	this->molecule = before_n / m;
	this->denominator = before_m / m;
}

RationalNumber::RationalNumber() {}

string RationalNumber::toString() const {
	return to_string(molecule) + "/" + to_string(denominator);
}

double RationalNumber::toDouble() const {
	return molecule / denominator;
}

bool RationalNumber::equals(const RationalNumber &b) const {
	return this->molecule * b.denominator == this->denominator * b.molecule;
}