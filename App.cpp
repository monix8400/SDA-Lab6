#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <iostream>
#include "ShortTest.h"
#include "ExtendedTest.h"
#include <assert.h>
#include <exception>

using namespace std;


int main() {
	testAll();
	cout << "Short Test-DONE" << endl;
	testAllExtended();
	cout<<"Extended Test-DONE"<<endl;

	cout << "Test over" << endl;
	system("pause");
}
