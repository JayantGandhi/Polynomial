//term.cpp
//implementatin for term.h

#include "term.h"
#include <iostream>

std::ostream& operator<<(std::ostream& oStr, const term& myTerm)
{
	if (myTerm.exp ==1)
		oStr << myTerm.coeff << "x";
	if (myTerm.exp ==0)
		oStr << myTerm.coeff;
	if (myTerm.exp > 1)
		oStr << myTerm.coeff << "x^" << myTerm.exp;
	return oStr;
}

term::term()
{
	coeff=0;
	exp=0;
}

term::term(int a, int b)
{
	coeff=a;
	if (b>=0)
		exp=b;
	else
	{
		b=0;
		std::cout << "ERROR: Negative Exponent in term(int,int)." << std::endl;
	}
}

term::term(const term& t)
{
	coeff=t.coeff;
	exp=t.exp;
}

term term::operator* (const term& t)
{
	term result;
	result.coeff=(this->coeff*t.coeff);
	result.exp=(this->exp+t.exp);
	return result;
}

bool term::operator> (const term& t) const
{
	return ((exp)>(t.exp));
}
