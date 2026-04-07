#include "HugeInteger.h"
using namespace std;

HugeInteger::HugeInteger()
{
	for (int i = 0; i < 40; i++)
		integer[i] = 0;
}

HugeInteger::HugeInteger(const string value)
{
	if(value.size()> 40)
	{
		cout << "输入的数过大" << endl;
		exit(1);
	}
	for (int i = 0; i < 40; i++)
		integer[i] = 0;
	for (int j = value.size()-1; j>=0;j--)
	{
		if (value[j] < '0' || value[j] > '9')
		{
			cout << "输入的数不合法" << endl;
			exit(1);
		}
		integer[j] = int(value[value.size() - 1 - j]-'0');
	}
}

bool HugeInteger::isEqualTo(const HugeInteger& h1, const HugeInteger& h2) const
{
	for (int i = 0; i < 40; i++)
		if (h1.integer[i] != h2.integer[i])
			return false;
	return true;
}

bool HugeInteger::isNotEqualTo(const HugeInteger& h1, const HugeInteger& h2) const
{
	if (!isEqualTo(h1, h2))
		return true;
}

bool HugeInteger::isGreaterThan(const HugeInteger& h1, const HugeInteger& h2) const
{
	for (int i = 0; i < 40; i++)
		if (h1.integer[i] > h2.integer[i])
			return true;
	return false;
}

bool HugeInteger::isLessThan(const HugeInteger& h1, const HugeInteger& h2) const
{
	for (int i = 0; i < 40; i++)
		if (h1.integer[i] < h2.integer[i])
			return true;
	return false;
}

bool HugeInteger::isGreaterThanOrEqualTo(const HugeInteger& h1, const HugeInteger& h2) const
{
	if (isGreaterThan(h1, h2) || isEqualTo(h1, h2))
		return true;
	return false;
}

bool HugeInteger::isLessThanOrEqualTo(const HugeInteger& h1, const HugeInteger& h2) const
{
	if (isLessThan(h1, h2) || isEqualTo(h1, h2))
		return true;
	return false;
}

bool HugeInteger::isZero(const HugeInteger& h1) const
{
	for (int i = 0; i < 40; i++)
		if (h1.integer[i] != 0)
			return false;
	return true;
}

int HugeInteger::get_integer(int i) const
{
	return integer[i];
}

void HugeInteger::set_integer(int i,int val)
{
	integer[i] = val;
}
HugeInteger HugeInteger::operator+(const HugeInteger& h1)
{
	HugeInteger temp("0");
	for (int i = 0; i <= 38; i++)
	{
		temp.set_integer(i, temp.get_integer(i) + this->get_integer(i) + h1.get_integer(i));
		if (temp.get_integer(i) >= 10)
		{
			temp.set_integer(i, temp.get_integer(i) - 10);
			temp.set_integer(i + 1, temp.get_integer(i + 1) + 1);
		}
	}
	temp.set_integer(39, temp.get_integer(39)+this->get_integer(38) + h1.get_integer(38));
	if (temp.get_integer(39) >= 10)
	{
		cout << "结果溢出" << endl;
		exit(1);
	}
	else
	{
		return temp;
		
	}
	
}

HugeInteger HugeInteger::operator-(const HugeInteger& h1)
{
	HugeInteger temp;
	for (int i = 0; i <= 38; i++)
	{
		temp.set_integer(i,temp.get_integer(i)+this->get_integer(i) - h1.get_integer(i));
		if (temp.get_integer(i) < 0)
		{
			temp.set_integer(i, temp.get_integer(i) + 10);
			temp.set_integer(i + 1, temp.get_integer(i + 1) - 1);
		}
	}
	if (temp.get_integer(39)+this->get_integer(39)- h1.get_integer(39) < 0)
	{
		cout << "结果溢出" << endl;
		exit(1);
	}
	else
	{
		temp.set_integer(39, temp.get_integer(39)+this->get_integer(39) - h1.get_integer(39));
		return temp;
	}
}

HugeInteger HugeInteger::multiply(const HugeInteger& h1, const HugeInteger& h2) const
{
	HugeInteger temp;
	for (int i = 0; i < 40; i++)
		for (int j = 0; j < 40; j++)
		{
			if (i + j < 40)
				temp.set_integer(i + j, temp.get_integer(i + j) + h1.get_integer(i) * h2.get_integer(j));
			else if (h1.get_integer(i) * h2.get_integer(j) != 0)
			{
				cout << "结果溢出" << endl;
				exit(1);
			}
		}
	for (int k = 0; k < 39; k++)
		if (temp.get_integer(k) >= 10)
		{
			temp.set_integer(k, temp.get_integer(k) - 10);
			temp.set_integer(k + 1, temp.get_integer(k + 1) + 1);
		}
	if (temp.get_integer(39) >= 10)
	{
		cout << "结果溢出" << endl;
		exit(1);
	}
	else
		return temp;
}


HugeInteger HugeInteger::modular(const HugeInteger& h1, const HugeInteger& h2) const
{
	if (isZero(h2))
	{
		cout << "除数不能为0" << endl;
		exit(1);
	}
	HugeInteger remainder("0");
	for (int i = 39; i >= 0; i--)
	{
		for (int j = 39; j > 0; j--)
			remainder.set_integer(j, remainder.get_integer(j - 1));
		remainder.set_integer(0, h1.get_integer(i));
		while (!isLessThan(remainder, h2))
			remainder = remainder - h2;
	}
	return remainder;
}
void  HugeInteger::print() const 
{
	int tmp = 0;
	for (int i = 39; i >= 0; i--)
	{
		if(integer[i] != 0)
		{
			tmp = i;
			break;
		}
	}
	for (int j = tmp; j >= 0; j--)
		cout << integer[j];
}

void HugeInteger::input(const string value)
{
	if (value.size() > 40)
	{
		cout << "输入的数过大" << endl;
		exit(1);
	}
	for (int i = 0; i < 40; i++)
		integer[i] = 0;
	for (int j = value.size() - 1; j >= 0; j--)
	{
		if (value[j] < '0' || value[j] > '9')
		{
			cout << "输入的数不合法" << endl;
			exit(1);
		}
		integer[j] = int(value[value.size() - 1 - j]-'0');
	}
}