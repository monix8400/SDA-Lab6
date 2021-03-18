#pragma once
#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <exception>

class SortedBagIterator;

struct NodeStack
{
	Node* elem;
	NodeStack* next;
};

class Stack
{
	friend class SortedBagIterator;

public:
	
	NodeStack* last;

	//int len;


	//constructor
	Stack();

	//adds an element to the stack
	void push(Node* e);

	//returns the element
	//throws exception if the stack is empty
	Node* top();

	//removes and returns the element
	//throws exception if the stack is empty
	Node* pop();

	//checks if the stack is empty
	bool isEmpty();

	//destructor
	~Stack();

};

