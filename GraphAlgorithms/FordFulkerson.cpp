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

	Edge<char> edges[] = {	{'a', 'b', 1},  	// a -> b
							{'a', 'c', 1},		// a -> c
							{'b', 'a', 1},		// b -> a
							{'b', 'd', 1},		// b -> d
							{'c', 'b', 1},		// c -> b
							{'c', 'e', 1},		// c -> e
							{'c', 'f', 1},		// c -> f
							{'d', 'a', 1},		// d -> a
							{'d', 'e', 1},		// d -> e
							{'d', 'f', 1},		// d -> f
							{'e', 'b', 1},		// e -> b
							{'e', 'c', 1},		// e -> c
							{'f', 'e', 1},		// f -> e
							{'f', 'd', 1},		// f -> d
							{'f', 'c', 1}		// f -> c
						};

	//vector<char> edg[] =  {};

	DirectedGraph<char> G(vtx, edges, 6, 15);

	cout << "Number of vertices in G: " << G.vertices << endl;

	/// THIS DIDN'T WORK ... I DON'T THINK THE EDGE LIST IS BEING CREATED CORRECTLY!
	// cout << "First edge for every Vertex?" << endl;
	// for (auto lst : G.E) cout << lst[0] << endl;

	G.print();


	return 0;
}