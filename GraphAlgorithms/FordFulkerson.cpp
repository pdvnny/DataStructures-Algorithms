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

	int edges[][3] = {	{100, 101, 1},  	// a -> b
						{100, 102, 1},		// a -> c
						{101, 100, 1},		// b -> a
						{101, 103, 1},		// b -> d
						{102, 101, 1},		// c -> b
						{102, 104, 1},		// c -> e
						{102, 105, 1},		// c -> f
						{103, 100, 1},		// d -> a
						{103, 104, 1},		// d -> e
						{103, 105, 1},		// d -> f
						{104, 101, 1},		// e -> b
						{104, 102, 1},		// e -> c
						{105, 104, 1},		// f -> e
						{105, 103, 1},		// f -> d
						{105, 102, 1}		// f -> c
					};


	Graph G(6); /// This current version of the Graph depends completely on the vertices being numbered starting at 100
				/// and increasing without gaps from there

	for (auto edge : edges)
		G.addEdge(edge[0], edge[1], edge[2]);

	cout << "Number of vertices in G: " << G.size() << endl;
	G.print();
	cout << "\n";

	/// As of march 19 2022, BFS seems to be working well for the simple Graph data structure

	G.BFS(100);

	G.BFS(105);


	return 0;
}