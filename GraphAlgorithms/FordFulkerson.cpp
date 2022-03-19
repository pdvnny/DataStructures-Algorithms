/**************************************************************
 * 
 *  Parker Dunn (pgdunn@bu.edu)
 * 
 * 	19 March 2022
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
#include "graph.h"

using namespace std;


int main() {

	int vertices[] = {100, 101, 102, 103, 104, 105};

	Edge<char> edges[] = {	{100, 102, 1},  	// a -> b
							{100, 103, 1},		// a -> c
							{102, 100, 1},		// b -> a
							{102, 104, 1},		// b -> d
							{103, 102, 1},		// c -> b
							{103, 105, 1},		// c -> e
							{103, 106, 1},		// c -> f
							{104, 100, 1},		// d -> a
							{104, 105, 1},		// d -> e
							{104, 106, 1},		// d -> f
							{105, 102, 1},		// e -> b
							{105, 103, 1},		// e -> c
							{106, 105, 1},		// f -> e
							{106, 104, 1},		// f -> d
							{106, 103, 1}		// f -> c
						};

	//vector<char> edg[] =  {};

	Graph<char> G(6);

	cout << "Number of vertices in G: " << G.vertices << endl;

	/// THIS DIDN'T WORK ... I DON'T THINK THE EDGE LIST IS BEING CREATED CORRECTLY!
	// cout << "First edge for every Vertex?" << endl;
	// for (auto lst : G.E) cout << lst[0] << endl;

	G.print();


	return 0;
}