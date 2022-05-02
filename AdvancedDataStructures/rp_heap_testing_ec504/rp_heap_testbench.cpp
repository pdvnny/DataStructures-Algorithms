/**********************************************

	Parker Dunn (pgdunn@bu.edu)
	EC 504 Final Project

	Testbench for my first version of rp_heap.h


***********************************************/


#include <iostream>

#include "rp_heap.h"

using namespace std;

int main() {

	rp_heap* myHeap = new rp_heap();
	int size = 10;
    int heap_extract;


	/// creating a bunch of things to push
	int elements[size][2];

	for (int i = 1; i < (size+1); i++) {
			elements[i-1][0] = i;    // KEY
			elements[i-1][1] = i*10;	// DATA
	}

	for (int j = 0; j < size; j++)
		myHeap->push(elements[j][1], elements[j][0]);


    cout << "\nThe size of myHeap is " << myHeap->size() << "\n" << endl;

    cout << "\nExtracting 4 Nodes now..." << endl;

    for (int j = 0; j < 4; j++) {
        heap_extract = myHeap->extract_min();
        cout << "Extraction #" << (j+1) << ": " << heap_extract << endl;
    }

    cout << "\nTime to decrease some keys..." << endl;

    myHeap->decreaseKey(10, 5);
    myHeap->decreaseKey(9, 8);
    cout << "\n";

    for (int j = 4; j < size; j++) {
        heap_extract = myHeap->extract_min();
        cout << "Extraction #" << (j+1) << ": " << heap_extract << endl;
    }

	return 0;
}