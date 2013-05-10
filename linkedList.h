/*
 *  linkedList.h                                 
 *                                                
 *  COSC 052 Summer 2012                          
 *  Project #3                                    
 *                                                
 *  Due on:         JUL 30, 2012                  
 *  Created on:     JUL 20, 2012                  
 *  Last edited on: JUL 29, 2012                  
 *  Author: Jayant Gandhi                           
 *  netID:  jg492                         
 * 
 *
 *  In accordance with the class policies and Georgetown's
 *  Honor Code, I certify that, with the exception of the 
 *  class resources and those items noted below, I have neither
 *  given nor received any assistance on this project. 
 */

#ifndef COSC052Summer2012P03v01_linkedList_h
#define COSC052Summer2012P03v01_linkedList_h

#include <iostream> 
#include <cstdlib>
#include <cassert>
#include "node.h"
#include "linkedListIterator.h"

template <class T>
class linkedList
{
private:
    void copyList(const linkedList<T>& otherList);
      //Function to make a copy of otherList.
      //Postcondition: A copy of otherList is created and 
      //               assigned to this list.
    
    void reversePrint(node<T> *current) const;
      //Function for reverse print recursion
      //Postcondition: The list is output in reverse order
    
	void swapNodes(node<T>*, node<T>*);
	  //Function to switch the location of two nodes
	  //Postcondition: the info stored in each node is switched

protected:
    int count;             //stores number of elements in list
    node<T> *head;    //stores pointer to first node
    node<T> *tail;    //stores pointer to last node
    
public:
    linkedList<T>& operator=(const linkedList<T>& otherList);
      //Overloaded assignment operator
      //Postcondition: Values of otherList are assigned to this list.
    
    linkedList();
      //default constructor
      //Initializes the list to an empty state.
      //Postcondition: head = NULL, tail = NULL, count = 0
    
    linkedList(const linkedList<T>& otherList);
      //copy constructor
      //Postcondition: Values of otherList are copied to this list.
    
    ~linkedList();
      //destructor
      //Deletes all the nodes from the list.
      //Postcondition: The list object is destroyed.
    
    void initializeList();
      //Initialize the list ot an empty state
      //Postcondition: head = NULL, tail = NULL, count = 0
    
    bool isEmpty() const;
      //Function to determine whether the list is empty.
      //Postcondition: Returns true if empty, false otherwise
    
    void print() const;
      //Function to output data contained in each node
      //Postcondition: Output is displayed on screen specific to 
      //               particular node element type
    
    void printListReversed() const;
      //Function to print a singly linked list in reverse
      //Postcondition: Output is dispalyed on screen.  The output
      //               is specific to the particular node element
      //               type and the order is the reverse of 
      //               how the nodes are stored in the list
    
    int length() const;
      //Function to return the number of nodes in the list.
      //Postcondition: The value of count is returned.
    
    void destroyList();
      //Function to delete all nodes formt he list
      //Postcondition: head = NULL, tail = NULL, count = 0
    
    T firstElement() const;
      //Function to return the first element of the list
      //Precondition: The list must exist and not be empty
      //Postcondition: If the list is empty program terminates
      //               Otherwise first element of list is returned
    
    T lastElement() const;
      //Function to return the last element of the list
      //Precondition: The list must exist and not be empty
      //Postcondition: If the list is empty program terminates
      //               Otherwise last element of list is returned
    
    
    bool search(const T& searchItem) const;
      //Function to search the list for an entry matching
      //the function argument
      //Postcondition: Return true if searchItem is in the list
      //               otherwise return false
    
    void addFirst(const T&);
      //Function to insert a new item at the beginning of the list
      //Postcondition: The new item is inserted in the list
      //               head points to the start of the list
      //               tail points to the last item in the list
      //               count is incremented by 1
    
    void addLast(const T&);
      //Function to insert a new item at the end of the list
      //Postcondition: The new item is inserted in the list
      //               head points to the start of the list
      //               tail points to the last item in the list
      //               count is incremented by 1    
    
    void deleteNode(const T& deleteItem);
      //Function to delete an item from the list
      //Postcondition: If found, the node containing the 
      //               deleteItem is removed from the list
      //               head points to the start of the list
      //               tail points to the last item in the list
      //               count is decremented by 1   
    
    linkedListIterator<T> begin() const;
      //Function to return an iterator at the beginning of the list
      //Postcondition: Returns an iterator with current set to first
    
    linkedListIterator<T> end() const;
      //Function to return an iterator one element past the end of the list
      //Postcondition: Returns an iterator with current set to NULL   
    
	void bubbleSortList();
	  //Function to sort the list using bubble sort algorithm
	  //Postcondition: list is sorted in non-decending order based
	  //on conditions of type T

	void selectionSortList();
	  //Function to sort the list using selection sort algorithm
	  //Postcondition: list is sorted in decending order based
	  //on conditions of type T
    
};

//Implementation:
//function to copy otherList to this list
template <class T>
void linkedList<T>::copyList (const linkedList<T>& otherList)
{
	node<T> *newNode, *current, *temp;

	if (head != NULL)
		initializeList();
	
	if(otherList.head == NULL)
		head = NULL;

	else
	{
		try
		{
			//copy first object
			current = otherList.head;
			newNode = new node<T>;
			newNode->info = current->info;
			newNode->next = NULL;
			head = newNode;
			temp = newNode;
			current = current->next;
			//copy remaining objects
			while (current != NULL)
			{
				newNode = new node<T>;
				newNode->info = current->info;
				newNode->next = NULL;
				temp->next = newNode;
				tail = newNode;
				temp = temp->next;
				current = current->next;
			}//end while
		}//end try
		catch (std::bad_alloc be)
		{
			std::cout << "Error copying linked list." << be.what() <<std::endl;
			delete this;
		}//end catch
	}//end else
	count = otherList.count;
}//end copyList

//reversePrint Function
template <class T>
void linkedList<T>::reversePrint(node<T> *current) const
{
	if (current != NULL)
	{
		reversePrint(current->next);
		std::cout << current->info << std::endl;
	}
}

//swap node function
template <class T>
void linkedList<T>::swapNodes(node<T>* nodeOne, node<T>* nodeTwo)
{
	T tempInfo;
	tempInfo = nodeOne->info;
	nodeOne->info=nodeTwo->info;
	nodeTwo->info=tempInfo;
}

//overloaded assignment operator
template <class T>
linkedList<T>& linkedList<T>::operator=(const linkedList<T>& otherList)
{
	if(this != &otherList)
		copyList(otherList);
	return *this;
}

//default constructor
template <class T>
linkedList<T>::linkedList()
{
	head = NULL;
	tail = NULL;
	count = 0;
}

//copy constructor
template <class T>
linkedList<T>::linkedList(const linkedList<T>& otherList)
{
	copyList(otherList);
}

//destructor
template <class T>
linkedList<T>::~linkedList()
{
	initializeList();
}

//initializer function
template <class T>
void linkedList<T>::initializeList()
{
	node<T> *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
	tail = NULL;
	count = 0;
}

//is empty functoin
template <class T>
bool linkedList<T>::isEmpty() const
{
	return (head == NULL);
}

//print function
template <class T>
void linkedList<T>::print() const
{
	linkedListIterator<T> printer(head);

	while (printer != NULL)
	{
		std::cout<< (*printer) << ' ';
		++printer;
	}
}

//print the list in reverse
template <class T>
void linkedList<T>::printListReversed() const
{
	reversePrint(head);
	std::cout << std::endl;
}

//length function
template <class T>
int linkedList<T>::length() const
{
	return count;
}

//destroy list function
template <class T>
void linkedList<T>::destroyList()
{
	initializeList();
}

//function to return the first element
template <class T>
T linkedList<T>::firstElement() const
{
	assert(head != NULL);
	return head->info;
}

//function to return the last element
template <class T>
T linkedList<T>::lastElement() const
{
	assert(tail != NULL);
	return tail->info;
}

//search function
template <class T>
bool linkedList<T>::search(const T& searchItem) const
{
	linkedListIterator<T> searcher(head);
	bool found = false;

	while (searcher != NULL && !found)
	{
		if (*searcher == searchItem)
			found = true;
		else
			++searcher;
	}

	return found;
}

//function to add item to the beginning of the list
template <class T>
void linkedList<T>::addFirst(const T& newObject)
{
	try
	{
		node<T> *newNode;
		newNode = new node<T>;
		newNode->info = newObject;

		newNode->next = head;
		head = newNode;

		count++;

		if (tail == NULL)
			tail = newNode;
	}
	catch (std::bad_alloc be)
	{
		std::cout << "Error adding item to beginning of list." << be.what() <<std::endl;
	}
}

//function ot add item to the end of the list
template <class T>
void linkedList<T>::addLast(const T& newObject)
{
	try
	{
		node<T> *newNode;
		newNode = new node<T>;
		newNode->info = newObject;
		newNode->next = NULL;

		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
			count++;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
			count++;
		}
	}
	catch (std::bad_alloc be)
	{
		std::cout << "Error adding item to end of list." << be.what() <<std::endl;
	}
}

//function to delete a node
template <class T>
void linkedList<T>::deleteNode(const T& deleteItem)
{
	node<T> *current, *trailCurrent;
	bool found;

	if (head == NULL)
		std::cout << "Cannot delete an item from an empty list..." << std::endl;
	else
	{
		if (head->info == deleteItem)
		{
			current = head;
			head = head->next;
			count--;

			if (head == NULL)
				tail = NULL;

			delete current;
		}
		else
		{
			found = false;
			trailCurrent = head;
			current = head->next;

			while (current != NULL && !found)
			{
				if (current->info != deleteItem)
				{
					trailCurrent = current;
					current = current->next;
				}
				else
					found = true;
			}//end while

			if (found)
			{
				trailCurrent->next = current->next;
				count--;

				if (tail == current)
					tail = trailCurrent;

				delete current;
			}
			else
				std::cout << "The item to be deleted could not be found in the list." << std::endl;
		}//end else
	}//end else
}//end deleteNode

//sets the iterator to the beginning
template <class T>
linkedListIterator<T> linkedList<T>::begin() const
{
	linkedListIterator<T> temp(head);
	return temp;
}

//sets iterator to the end
template <class T>
linkedListIterator<T> linkedList<T>::end() const
{
	linkedListIterator<T> temp(tail);
	return temp;
}

//bubble sort function
template <class T>
void linkedList<T>::bubbleSortList()
{
	int iteration, location;
	node<T> *current, *trailCurrent;

	for (iteration = 1; iteration < length(); iteration++)
	{
		//move pointers to beginning of list for each iteration
		trailCurrent = head;
		current = trailCurrent->next;

		for (location = 0; location < length()-1; location ++)
		{
			if (current->info > trailCurrent->info)
			{
				swapNodes(current, trailCurrent);
			}
			current=current->next;
			trailCurrent=trailCurrent->next;
		}//end 2nd for
		//if (iteration%1000 == 0)
			//std::cout << "In loop, " << iteration << " sorted." << std::endl;
	}//end 1st for
}//end bubbleSortList()

//selection sort function
template <class T>
void linkedList<T>::selectionSortList()
{
	int sorted, location;
	node<T> *current, *placeHolder;
	T largestValue;
	placeHolder = head;

	for (sorted = 0; sorted < length()-1; sorted++)
	{
		//assume smallest value is at the start of unsorted list
		largestValue = placeHolder->info;
		current = placeHolder;

		for (location = sorted + 1; location < length(); location++)
		{
			if (current->info > largestValue)
			{
				//swap nodes and set largest value to current
				swapNodes(current, placeHolder);
				largestValue = current->info;
			}
			//move current
			current = current->next;
		}//end 2nd for

		//move placeHolder to next position
		placeHolder = placeHolder->next;
		//if (sorted%1000 == 0)
			//std::cout << "In loop, " << sorted << " sorted." << std::endl;
	}//end 1st for
}



#endif
