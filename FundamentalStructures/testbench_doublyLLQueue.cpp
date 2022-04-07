/***********************************************

	Parker Dunn
	Related to EC 504 - SW HW 4

	Created April 6th, 2022

***********************************************/
#include <iostream>

#include "DoublyLinkedListQueue.h"

using namespace std;

struct vertex {
	int key;
	char id;
public:
	vertex(int num, char chr) {key = num; id = chr;};
};

void printContents(vertex v) {
	cout << "Vertex -> Key: " << v.key << " ID: " << v.id << endl;
}

int main() {

	vertex v1(1, 'a');
	vertex v2(2, 'b');
	vertex v3(3, 'c');
	vertex v4(4, 'd');
	vertex v5(5, 'e');
	vertex v6(6, 'f');

	myQueue<vertex> Q;

	Q.push(&v1);
	Q.push(&v2);
	Q.push(&v3);

	cout << "Size of queue is " << Q.getSize() << endl;

	vertex* tmp = Q.front();
	Q.pop();

	printContents(*tmp);

	cout << "Size of queue is " << Q.getSize() << endl;

	tmp = Q.front();
	Q.pop();

	printContents(*tmp);

	Q.push(&v4);
	Q.push(&v5);
	Q.push(&v6);

	int remaining = Q.getSize();

	cout << "Remaining is " << remaining << endl;

	while (!Q.empty()) {
		tmp = Q.front();
		printContents(*tmp);
		Q.pop();
	}

	return 0;
}