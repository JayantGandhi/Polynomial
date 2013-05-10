//term.h
//struct for each term of a polynomial

#ifndef TERM_H
#define TERM_H

#include <iostream>

struct term
{
	friend std::ostream& operator<< (std::ostream&, const term&);
		//overloaded stream insertion operator for terms
		//precondition: have an initialized term
		//postcondition: outputs the term in the format cx^e where c=coefficient
		//				and e=exponent; special conditions for when exp=0or1

    int coeff;
		//variable to hold the term's coefficient
	int exp;
		//variable to hold the term's exponent
	term();
		//default constructor
		//postcondition: coeff=0 and exp=0
	term(int, int);
		//constructor with parameters
		//postcondition: creates a term with coeff=firstint and exp=secondint
	term(const term&);
		//copy constructor
		//postcondition: creates a term where coeff=passedterm.coeff and 
		//				exp=passedterm.exp
	term operator* (const term&);
		//overloaded multiplication operator for terms
		//postcondition: multiply terms in the appropriate manner (coeff*coeff/exp+exp)
	bool operator> (const term&) const;
		//overloaded greater than comparison operator for terms
		//used in sorting
		//postconditoin: returns true if lhs.exp>rhs.exp

#endif