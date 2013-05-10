/*
 *  linkedListIterator.h                                 
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


#ifndef COSC052Summer2012P03v02_linkedListIterator_h
#define COSC052Summer2012P03v02_linkedListIterator_h

#include "node.h"

template <class T>
class linkedListIterator
{
public:
    linkedListIterator();
      //Default constructor
      //Postcondition: current = NULL
    
    linkedListIterator(node<T> *ptr);
      //Constructor with parameter.
      //Postcondition: current = ptr
    
    T operator*();
      //Function to overload the dereferencing operator *.
      //Postcondition: Returns the info contianed in the node
    
    linkedListIterator operator++();
      //Function to overload the pre-increment operator.
      //Postcondition: The iterator is advanced to the next node.
    
    bool operator==(const linkedListIterator<T>& rHS) const; 
      //Function to overload the equality operator
      //Postcondition: Returns true if this iterator is equal
      //               to the interator specified 
      //               by rHS (right hand side iterator)
      //               otherwise returns false
    
    bool operator!=(const linkedListIterator<T>& rHS) const; 
      //Function to overload the inequality operator
      //Postcondition: Returns true if this iterator is not equal
      //               to the interator specified 
      //               by rHS (right hand side iterator) 
      //               otherwise returns false       
    
    
private:
    node<T> *current;  //pointer to point to the current 
                            //node in the linked list
};

//default constructor
template <class T>
linkedListIterator<T>::linkedListIterator()
{
	current =NULL;
}

//copy constructor
template <class T>
linkedListIterator<T>::linkedListIterator(node<T> *ptr)
{
	current = ptr;
}
//overloaded operators
template <class T>
T linkedListIterator<T>::operator*()
{
	return current->info;
}

template <class T>
linkedListIterator<T> linkedListIterator<T>::operator++()
{
	current = current->next;
	return *this;
}

template <class T>
bool linkedListIterator<T>::operator==(const linkedListIterator<T>& otherIterator) const
{
	return (current == otherIterator.current);
}

template <class T>
bool linkedListIterator<T>::operator!=(const linkedListIterator<T>& otherIterator) const
{
	return (current != otherIterator.current);
}


#endif
