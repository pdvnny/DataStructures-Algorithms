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


	/// creating a bunch of things to push
	int elements[size][2];

	for (int i = 1; i < (size+1); i++) {
			elements[i-1][0] = i;    // KEY
			elements[i-1][1] = i*10;	// DATA
	}

	for (int j = 0; j < size; j++)
		myHeap->push(elements[j][0], elements[j][1]);


	return 0;
}