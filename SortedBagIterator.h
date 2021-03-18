#pragma once
#include "SortedBag.h"
#include "Stack.h"

class Stack;
class SortedBag;

class SortedBagIterator
{
	friend class SortedBag;
	friend class Stack;

private:
	const SortedBag& bag;
	SortedBagIterator(const SortedBag& b);
	Node* index;
	//Stack st;
	int nr;

public:

	TComp getCurrent();
	bool valid();
	void next();
	void first();

	//Zusatzfunction
	void prev();
	void last();
};

