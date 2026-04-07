#ifndef _HUGEINTEGER_H_
#define _HUGEINTEGER_H_

#include <iostream>
#include <string>
using namespace std;

class HugeInteger
{
public:
	HugeInteger();
	HugeInteger(const string value);
	void input(const string value);
	int get_integer(int i) const;
	void set_integer(int i,int val);
	bool isEqualTo(const HugeInteger& , const HugeInteger&) const;
	bool isNotEqualTo(const HugeInteger&, const HugeInteger&) const;
	bool isGreaterThan(const HugeInteger&, const HugeInteger&) const;
	bool isLessThan(const HugeInteger&, const HugeInteger&) const;
	bool isGreaterThanOrEqualTo(const HugeInteger&, const HugeInteger&) const;
	bool isLessThanOrEqualTo(const HugeInteger&, const HugeInteger&) const;
	bool isZero(const HugeInteger&) const;
	HugeInteger multiply(const HugeInteger& h1, const HugeInteger& h2) const;
	HugeInteger modular(const HugeInteger& h1, const HugeInteger& h2) const;
	HugeInteger operator+(const HugeInteger& h1 );
	HugeInteger operator-(const HugeInteger& h1 );
	void print() const;


private:
	int integer[40];

};
#endif // !_HUGEINTEGER_H_

