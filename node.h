/*
 *  nodeType.h                                 
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


#ifndef COSC052Summer2012P03v01_nodeType_h
#define COSC052Summer2012P03v01_nodeType_h

template <class T>
struct node
{
    T info;
    node<T> *next;

};

#endif
