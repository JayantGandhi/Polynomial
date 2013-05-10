//poly.h
//class implementation for polynomials of one variable
#ifndef POLY_H
#define POLY_H

#include "linkedList.h"
#include "linkedListIterator.h"
#include "term.h"
#include <iostream>
#include <string>
#include <vector>

class poly
{
public:
	poly();
		//default constructor
		//postcondition: initializes linked list polyomial with no terms and numOfTerms=0;
	poly(int c[], int e[], int size);
		//constructor with parameters
		//precondition: arrays c and e must have the same number of members
		//				inserts a term with coeff=c[i] and exp=e[i] for each pair of members of the arrays 
	poly(const poly& p);
		//copy constructor
		//postcondition: this poly has a true copy of p.polynomial and this poly numOfTerms=p.numOfterms
	~poly();
		//destructor
		//postcondition: initializes polynomial which deallocates the linked list memory
	void insertTerm (int c, int e);
		//function to insert a term to polynomial based on two ints
		//postcondition: a term with coeff=c and exp=e is inserted to the back of
		//				the list
	void insertTerm (const term& t);
		//function to insert a term to polynomial based on a term
		//postcondition: a term with coeff=t.coeff and exp=t.exp is inserted to the
		//				back fo the list
	void printPoly () const;
		//function to print out the polynomial to the console
		//precondition: must have a poly that has been sorted
		//postcondition: the terms of the polynomial are displayed in the format cx^e+...
		//				in the order that they appear in the linked list
	int getNumOfTerms () const;
		//function to return the number of terms in a polynomial
		//postcondition: returns numOfTerms
	void sortPoly();
		//function to sort the polynomial based on magnitude
		//postcondition: polynomial is sorted in descending order based on magnitude
	poly operator+ (const poly& p);
		//overloaded additoin operator to add two polynomials together
		//precondition: both polys must be sorted beforehand
		//postcondition: returns the sum of the two polynomials
	poly operator- (const poly& p);
		//overloaded subtraction operator to subtract two polynomials together
		//precondition: both polys must be sorted beforehand
		//postcondition: returns the difference of the two polynomials
	poly operator* (const poly& p);
		//overloaded multiplication operator to multiply two polynomials together
		//precondition: both polys must be sorted beforehand
		//postcondition: returns the product of the two polynomials

private:
	linkedList<term> polynomial;
		//linked list of terms used to store the polynomial
	int numOfTerms;
		//variable to store the number of terms in a polynomial
};


#endif