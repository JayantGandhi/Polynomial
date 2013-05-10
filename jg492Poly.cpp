// jg492Poly.cpp : Defines the entry point for the console application.
//

#include "poly.h"
#include "linkedList.h"
#include "linkedListIterator.h"
#include "term.h"
#include <cstring>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <stack>
#include <string>
#include <fstream>
#include <cstring>
#include <iostream>

using namespace std;

bool fileInput (string fileName, stack<poly>& inputStack);


int main(int argc, const char* argv[])
{
	stack<poly> myStack;
	
	if (argc<2)
	{
		cout<<"Please restart program with an input file in the command line."<<endl;
		return 2;
	}

	//string file = "C:\\Users\\Jayant\\Downloads\\COSC 051\\jg492Poly\\test.txt";
	string file(argv[1]);
	cout<<file<<endl;

	if (fileInput(file, myStack))
	{
		cout<<"Final Answer"<<endl;
	}
	else
		cout<<"Problem with input file.";

	return 0;
}

bool fileInput (string fileName, stack<poly>& inputStack)
{
	bool allOK = true;
	char *data;
	string line;
	vector<int> termPair;

	cout <<"Opening input file..."<<endl;
	ifstream polyData;
	polyData.open(fileName.c_str());

	if (!polyData)
	{
		allOK = false;
		polyData.close();
		cout << "Sorry, I cannot seem to find this file. \nPlease restart the program.";
		return allOK;
	}
	while(getline(polyData, line))
	{
		stringstream s(line);
		string typeOfLine;
        string strCoeff;
        string strExp;

		s >> typeOfLine;

		if (typeOfLine.compare("p:") == 0) //line is a polynomial
		{
			//create temp poly and ints to store coeff and exp
			poly p;
			int c, e;
			while(s >> strCoeff)
			{
                termPair.push_back(atoi(strCoeff.c_str()));
                //read exp of pair
                s >> strExp;
                termPair.push_back(atoi(strExp.c_str()));
            }
			//read term pairs into a polynomial list
			for(int i=0; i < termPair.size(); i +=2)
				p.insertTerm(termPair[i], termPair[i+1]);
			//push poly onto a stack
			inputStack.push(p);
			//empty out termPair for next set of data
			termPair.clear();
		}
		else if (typeOfLine.compare("o:") == 0) //line is a operator
		{
			//make sure the has at least two members
			if (inputStack.size() < 2)
			{
				cout << "Operation found too soon! Please edit input data and try again." << endl;
				allOK = false;
				return allOK;
			}

			else
			{
				string strOpr;
				s >> strOpr;
				if (strOpr.compare("+")==0)
				{
					poly first, second;
					first = inputStack.top();
					inputStack.pop();
					second = inputStack.top();
					second.sortPoly();
					second.printPoly();
					cout<<endl;
					cout<<"+"<<endl;
					first.sortPoly();
					first.printPoly();
					cout<<endl;
					inputStack.push(first+second);
					cout<<"="<<endl;
					poly temp = inputStack.top();
					temp.printPoly();
					cout<<endl;
				}
				if (strOpr.compare("-")==0)
				{
					poly first, second;
					first = inputStack.top();
					inputStack.pop();
					second = inputStack.top();
					second.sortPoly();
					second.printPoly();
					cout<<endl;
					cout<<"-"<<endl;
					first.sortPoly();
					first.printPoly();
					cout<<endl;
					inputStack.push(second-first);
					cout<<"="<<endl;
					poly temp = inputStack.top();
					temp.printPoly();
					cout<<endl;
				}
				if (strOpr.compare("*")==0)
				{
					poly first, second;
					first = inputStack.top();
					inputStack.pop();
					second = inputStack.top();
					second.sortPoly();
					second.printPoly();
					cout<<endl;
					cout<<"*"<<endl;
					first.sortPoly();
					first.printPoly();
					cout<<endl;
					inputStack.push(first*second);
					cout<<"="<<endl;
					poly temp = inputStack.top();
					temp.printPoly();
					cout<<endl;
				}
			}
		}
	}
	if(inputStack.empty())
	{
		cout<<"Nothing in stack.";
		return false;
	}
}


