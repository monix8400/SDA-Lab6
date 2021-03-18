#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <iostream>

using namespace std;

//Komplexitat:
//best case: Θ(1)
//worst case: Θ(1)
//avg case: Θ(1)
SortedBag::SortedBag(Relation r) {
	rel = r;
	root = new Node;
	root = nullptr;

	nr_nodes = 0;
}

//Komplexitat:
//best case: Θ(1)
//worst case: O(n)
//avg case: O(n)
Node* SortedBag::insert_rec(Node* node, TComp e) {
	if (node == nullptr) { //daca arborele este gol, atunci punem radacina
		Node* new_node = new Node;
		new_node->value = e;
		node = new_node;
	}
	else //daca nu adaugam in functie de relatie
		if (!rel(node->value, e))
			node->kind_L = insert_rec(node->kind_L, e);
		else
			node->kind_R = insert_rec(node->kind_R, e);
	return node;
}

//Komplexitat:
//best case: Θ(1)
//worst case: O(n)
//avg case: O(n)
void SortedBag::add(TComp e) {//adaugam un nod arborelui
	root = insert_rec(root,e);
	nr_nodes++;
}

//Komplexitat:
//best case: Θ(1)
//worst case: O(n)
//avg case: O(n)
TComp SortedBag::min(Node* node) {
	Node* index = new Node;
	index = node;
	if (index == nullptr)//daca arborele este gol
		return NULL_TCOMP;
	while (index->kind_L != nullptr) //cat timp nodul are copii in stanga, mergem pana la ultimul nod
		index = index->kind_L;	//ultimu nod fiind cel mai mic nod din arborele
	return index->value;
}

//Komplexitat:
//best case: Θ(1)
//worst case: O(n)
//avg case: O(n)
Node* SortedBag::removeRec(Node* node, TComp elem) {
	if (node == nullptr) //daca arborele este gol
		return nullptr;
	else //daca nu este gol
		if (rel(elem,node->value) && node->value!=elem){//cautam nodul de sters in functie de relatie pe partea stanga
			node->kind_L = removeRec(node->kind_L, elem);
			return node;
		}
		else
			if (!rel(elem,node->value) && node->value!=elem){//cautam nodul de sters in functie de relatie pe partea dreapta
				node->kind_R = removeRec(node->kind_R, elem);
				return  node;
			}
			else{ // am gasit elementul care trebuie sters
				if (node->kind_L == nullptr && node->kind_R == nullptr) //daca nu are copii
					return nullptr;
				else
					if (node->kind_L == nullptr && node!=root)//daca are doar un copil drept, il returneaza
						return node->kind_R;
					else 
						if (node->kind_R == nullptr && node != root)//daca are doar un copil copilul stang, il returneaza
							return  node->kind_L;
					else{//daca are ambii copii, cauta minimul 
						TComp minim = min(node->kind_R);
						node->value = minim;
						node->kind_R = removeRec(node->kind_R, minim);
						return node;
					}
			}	
}

//Komplexitat:
//best case: Θ(1)
//worst case: O(n)
//avg case: O(n)
bool SortedBag::remove(TComp e) {

	if (!search(e))	//daca nu exista nodul care trebuie sters
		return false;

	if (isEmpty())	//daca arborele este gol
		return false;

	Node* sters = removeRec(root, e);
	nr_nodes--;
	return true;
}

//Komplexitat:
//best case: Θ(1)
//worst case:O(n) 
//avg case: O(n)
bool SortedBag::search(TComp elem) const {

	Node* index = new Node;
	bool found = false;
	index = root;
	while (index != nullptr and !found)// parcurg arborele pana gasesc elementul cautat sau pana la sfarsitul acestuia daca nu gasesc elementul
		if (index->value == elem)
			found = true;
		else 
			if (rel(index->value, elem))
				index = index->kind_R;
			else
				index = index->kind_L;
	return found;
}

//Komplexitat:
//best case: Θ(1)
//worst case: O(n)
//avg case: O(n)
int SortedBag::nrOccurrences(TComp elem) const {
	Node* index =nullptr;
	int nr = 0; // variabila in care retin nr de aparitii ale lui elem
	index = root; 
	
	while (index != nullptr) { // parcurg arborele si cand gasesc elementul cresc numarul de aparitii
		if (index->value == elem)
			nr++;
		if (rel(index->value, elem))
			index = index->kind_R;
		else
			index = index->kind_L;
	}
	return nr;
}


//Komplexitat:
//best case: Θ(1)
//worst case: Θ(1)
//avg case: Θ(1)
int SortedBag::size() const {
	if (!isEmpty()) //returneza nr de noduri din arbore daca acesta nu e gol
		return nr_nodes;
	return 0;
}

//Komplexitat:
//best case: Θ(1)
//worst case: Θ(1)
//avg case: Θ(1)
bool SortedBag::isEmpty() const {
	if (nr_nodes == 0)	//daca arborele nu are noduri
		return true;
	return false;
}

//Komplexitat:
//best case: Θ(1)
//worst case: Θ(1)
//avg case: Θ(1)
SortedBagIterator SortedBag::iterator() const {
	return SortedBagIterator(*this);
}

//Komplexitat:
//best case: Θ(1)
//worst case: Θ(1)
//avg case: Θ(1)
SortedBag::~SortedBag() {
	delete root;
}
