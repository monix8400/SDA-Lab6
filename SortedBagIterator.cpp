#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <exception>
#include <iostream>

using namespace std;

Stack st;

//Komplexitat:
//best case: Θ(1)
//worst case: O(n)
//avg case: O(n)
SortedBagIterator::SortedBagIterator(const SortedBag& b) : bag(b) {
	Node* node = new Node;
	node = bag.root;
	nr = 0;
	while (node != nullptr) {//mergem pana la cel mai din stanga nod, si pe masura ce inaintam bagam si fiecare nod in stiva
		st.push(node);
		node = node->kind_L;
	}
	
	if (!st.isEmpty()) {//ca sa accesam nodurile scoatem pe rand cate un nod din stiva
		index = st.top();
		st.pop();
	}
}

//Komplexitat:
//best case: Θ(1)
//worst case: Θ(1)
//avg case: Θ(1)
TComp SortedBagIterator::getCurrent() {
	if (valid()){
		if (index != nullptr)
			return index->value;
	}
	else
		throw exception{};
	return NULL_TCOMP;
}

//Komplexitat:
//best case: Θ(1)
//worst case: Θ(1)
//avg case: Θ(1)
bool SortedBagIterator::valid() {	//daca bag ul nu e gol si nodul nu e ultimul, inseamna ca nodul e valid
	if (bag.isEmpty())
		return false;
	if (index != nullptr)
		return true;
	else
		return false;
}

//Komplexitat:
//best case: Θ(1)
//worst case: O(n)
//avg case: O(n)
void SortedBagIterator::next() {
	if (bag.isEmpty())
		throw exception{};
	if (index == nullptr)
		throw exception{};

	index = index->kind_R;
	while ( index!= nullptr){	//merge la cel mai din stanga nod, si la fel pe masura ce inaintam punem si nodurile in stack
		st.push(index);
		index = index->kind_L;
	}
	nr++;	//numaram nodurile parcurse din bag
	if (!st.isEmpty() && nr!=bag.size()) {	//scoatem urmatorul nod din stack
		index = st.top();
		st.pop();
	}
}

//Komplexitat:
//best case: Θ(1)
//worst case: O(n)
//avg case: O(n)
void SortedBagIterator::first() {
	Node* node = new Node;
	node = bag.root;
	nr = 0;
	while (node != nullptr) {	//mergem pana la cel mai din stanga nod, si pe masura ce inaintam bagam si fiecare nod in stiva
		st.push(node);
		node = node->kind_L;
	}
	if (!st.isEmpty()) {	//ca sa accesam nodurile scoatem pe rand cate un nod din stiva
		index = st.top();
		st.pop();
	}
}

//Komplexitat:
//best case: Θ(1)
//worst case: O(n)
//avg case: O(n)
void SortedBagIterator::prev() {
	if (bag.isEmpty())
		throw exception{};
	if (index == nullptr)
		throw exception{};

	index = index->kind_L;
	while (index != nullptr) {	//merge la cel mai din drepta nod, si la fel pe masura ce inaintam punem si nodurile in stack
		st.push(index);
		index = index->kind_R;
	}
	nr++;	//numaram nodurile parcurse din bag
	if (!st.isEmpty() && nr != bag.size()) {	//scoatem urmatorul nod din stack
		index = st.top();
		st.pop();
	}
}

//Komplexitat:
//best case: Θ(1)
//worst case: O(n)
//avg case: O(n)
void SortedBagIterator::last() {
	Node* node = new Node;
	node = bag.root;
	nr = 0;
	while (node != nullptr) {	//mergem pana la cel mai din dreapta nod, si pe masura ce inaintam bagam si fiecare nod in stiva
		st.push(node);
		node = node->kind_R;
	}
	if (!st.isEmpty()) {	//ca sa accesam nodurile scoatem pe rand cate un nod din stiva
		index = st.top();
		st.pop();
	}
}
