#include "Stack.h"
#include "SortedBag.h"
#include "SortedBagIterator.h"

//Komplexitat:
//best case: Θ(1)
//worst case: Θ(1)
//avg case: Θ(1)
Stack::Stack(){
	last = nullptr;
}


//Komplexitat:
//best case: Θ(1)
//worst case: Θ(1)
//avg case: Θ(1)
void Stack::push(Node* e){	//adds an element to the stack

	NodeStack* newnode = new NodeStack;
	newnode->elem = e;
	newnode->next = nullptr;
	if (last == nullptr)
		last = newnode;
	else
	{
		newnode->next = last;
		last = newnode;
	}
}

//Komplexitat:
//best case: Θ(1)
//worst case: Θ(1)
//avg case: Θ(1)
Node* Stack::top(){	//returns the element

	if (last == nullptr)
		//throw exception{};
		return nullptr;
	Node* topElem = last->elem;
	return topElem;
}

//Komplexitat:
//best case: Θ(1)
//worst case: Θ(1)
//avg case: Θ(1)
Node* Stack::pop(){	//removes and returns the element

	if (last == nullptr)
		//throw exception{};
		return nullptr;

	NodeStack* firstNode = new NodeStack;
	firstNode = last;
	Node* topElem = firstNode->elem;
	last = last->next;
	delete firstNode;

	return topElem;
}

//Komplexitat:
//best case: Θ(1)
//worst case: Θ(1)
//avg case: Θ(1)
bool Stack::isEmpty(){	//checks if the stack is empty

	if (last != nullptr)
		return false;
	
	return true;
}

//Komplexitat:
//best case: Θ(1)
//worst case: Θ(n)
//avg case: Θ(n)
Stack::~Stack(){ //deletes the stack
	while (last != nullptr)
	{
		NodeStack* firstNode = last;
		last = last->next;
		delete firstNode;
	}
}

