/**************************************************************
 * 
 *  Parker Dunn (pgdunn@bu.edu)
 * 
 * 	11 March 2022
 * 
 * 	DESCRIPTION
 * 
 * 	Need to do a min-cut on a flow network for a future project
 * 	so I am playing around with how I can implement this algo.
 * 
 * 	I'll start with the most basic implementation and build out
 * 	the algo for my specific purpose (image segmentation) as
 * 	I go.
 * 
 * 	Other scripts developed for this...
 * 	(1) DFS.h
 * 	(2) 
 * 
 * *************************************************************/

#include<vector>

//#include "DFS.h"
#include "graph.h"

using namespace std;


int main() {

	char vtx[] = {'a', 'b', 'c', 'd', 'e', 'f'};

	vector<char> edg[] =   {{'b', 'c'},				// a -> b, c
							{'a', 'd'},				// b -> a, d
							{'b', 'e', 'f'},        // c -> b, e, f
							{'a', 'e', 'f'},		// d -> a, e, f
							{'b', 'c'},				// e -> b, c
							{'e', 'd', 'f'}
							};

	Graph<char> G(vtx, edg, 6, 15);

	cout << "Number of vertices in G: " << G.vertices << endl;

	/// THIS DIDN'T WORK ... I DON'T THINK THE EDGE LIST IS BEING CREATED CORRECTLY!
	cout << "First edge for every Vertex?" << endl;
	for (auto lst : G.E) cout << lst[0] << endl;

	G.print();


	return 0;
}