//poly.cpp
//implementation of poly.h

#include "poly.h"
#include "linkedList.h"
#include "linkedListIterator.h"
#include "term.h"
#include <iostream>
#include <string>
#include <vector>

poly::poly()
{
	polynomial.initializeList();
	numOfTerms=0;
}

poly::poly(int c[], int e[], int size)
{
	for (int i=0; i<size; i++)
		insertTerm(c[i], e[i]);
	//polynomial.selectionSortList(); //orders the link in descending order based on exponent
}

poly::poly(const poly& p)
{
	polynomial=p.polynomial;
	numOfTerms=p.numOfTerms;
}

poly::~poly()
{
	polynomial.initializeList();
}

void poly::insertTerm(int c, int e)
{
	term temp(c, e);
	polynomial.addLast(temp);
	numOfTerms++;
}

void poly::insertTerm(const term& t)
{
	polynomial.addLast(t);
	numOfTerms++;
}

void poly::printPoly() const
{
	linkedListIterator<term> printer;
	printer = this->polynomial.begin();

	while (printer != NULL)
	{
		std::cout<< (*printer);
		++printer;
		if (printer!= NULL && (*printer).coeff>=0)
			std::cout<<"+";
		if (printer!= NULL && (*printer).coeff<0)
			std::cout << "";
	}
}

int poly::getNumOfTerms() const
{
	return numOfTerms;
}

void poly::sortPoly()
{
	polynomial.bubbleSortList();
}

poly poly::operator+ (const poly& p)
{
	poly result;
	linkedListIterator<term> left; 
	left =(polynomial.begin()); //start iterator for left operand at begining of the list
	linkedListIterator<term> right; 
	right =(p.polynomial.begin()); //start iterator for right operand at begining of the list

	while ((left!=NULL)&&(right!=NULL))
	{
		//see if exponents are equal (addition of like terms)
		if ((*left).exp == (*right).exp)
		{
			result.insertTerm (((*left).coeff+(*right).coeff),(*left).exp);
			++right;
			++left;
		}
		//if the left term is of a higher magnitude than the right term
		//add left term to the result list and advance to next left term
		else if ((*left).exp > (*right).exp)
			{
				result.insertTerm((*left).coeff,(*left).exp);
			++left;
			}
		//if the left term is of a lower magnitude than the right term
		//add right term to the result list and advance to the next right term
		else if ((*left).exp < (*right).exp)
		{
			result.insertTerm((*right).coeff, (*right).exp);
			++right;
		}
		//if the end of the left polynomial is reached first
		//add all remaining terms from the right polynomial to result
		if ((left==NULL)&&(right!=NULL))
		{
			result.insertTerm((*right).coeff, (*right).exp);
			++right;
		}
		//if the end of the right polynomial is reached first
		//add all remaining terms from the left polynomial to result
		if ((left!=NULL)&&(right==NULL))
		{
			result.insertTerm((*left).coeff, (*left).exp);
			++left;
		}
	}
	return result;
}

poly poly::operator- (const poly& p)
{
	poly result;
	linkedListIterator<term> left; 
	left =(this->polynomial.begin()); //start iterator for left operand at begining of the list
	linkedListIterator<term> right; 
	right =(p.polynomial.begin()); //start iterator for right operand at begining of the list

	while ((left!=NULL)&&(right!=NULL))
	{
		//see if exponents are equal (subtraction of like terms)
		if ((*left).exp == (*right).exp)
		{
			result.insertTerm (((*left).coeff-(*right).coeff),(*left).exp);
			++right;
			++left;
		}
		//if the left term is of a higher magnitude than the right term
		//add left term to the result list and advance to next left term
		else if ((*left).exp > (*right).exp)
		{
			result.insertTerm((*left).coeff,(*left).exp);
			++left;
		}
		//if the left term is of a lower magnitude than the right term
		//subtract right term to the result list and advance to the next right term
		else if ((*left).exp < (*right).exp)
		{
			result.insertTerm(-(*right).coeff, (*right).exp);
			++right;
		}
		//if the end of the left polynomial is reached first
		//subtract all remaining terms from the right polynomial to result
		if ((left==NULL)&&(right!=NULL))
		{
			result.insertTerm(-(*right).coeff, (*right).exp);
			++right;
		}
		//if the end of the right polynomial is reached first
		//add all remaining terms from the left polynomial to result
		if ((left!=NULL)&&(right==NULL))
		{
			result.insertTerm((*left).coeff, (*left).exp);
			++left;
		}
	}
	return result;
}

poly poly::operator* (const poly& p) //multiplies polynomials using the vertical method
{
	poly result;
	linkedListIterator<term> left; 
	left =(this->polynomial.begin()); //start iterator for left operand at begining of the list
	linkedListIterator<term> right; 
	right =(p.polynomial.begin()); //start iterator for right operand at begining of the list
	
	//create a vector<poly> to hold the steps of the multiplication process
	std::vector<poly> temp;
	
	//multiply each right term by the whole left polynomial
	while (right != NULL)
	{
		poly section;
		while (left!=NULL)
		{
			section.insertTerm((*left)*(*right));
			++left;
		}
		temp.push_back(section);
		left =(this->polynomial.begin()); //start iterator for left operand at begining of the list
		++right;
	}
	
	//add together all temporary polynomials created in the last step
	int size=temp.size();
	for (int j=0; j<(size-1); j++)
		temp[j+1]=(temp[j]+temp[j+1]);

	result = temp[size-1];

	return result;
}
