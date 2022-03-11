/**********************************************************************
 * 
 * Parker Dunn (pgdunn@bu.edu)
 * 
 * 11 march 2022
 * 
 * Creating Graph class to have a convenient implementation of an adjacency list
 * structure.
 * 
 * Additionally, some graph algos will be implemented here
 * 
 * Graph Algorithms implemented here...
 * (1) BFS
 * (2) DFS
 * 
 * 
 * *******************************************************************/

/// Not sure that I actually did these pre-processor directives correctly

#ifndef GRAPH_HEADER_FILE_H
#define GRAPH_HEADER_FILE_H

#include <vector>
#include <iostream>

using namespace std;

template <class v>
class Graph {
public:
    
    int vertices;
    int edges;
    vector<v> V;
    vector<vector<v>> E;

    Graph(v verts[], vector<v> edges[], int n_vert, int n_edges) {
        this->vertices = n_vert;
        this->edges = n_edges;


        /// Copying over vertices
        for (int i = 0; i < vertices; i++) V.push_back(verts[i]);

        /// Copying the edges
        for (auto lst : E) E.push_back(lst);  /// <-- should be saving an entire vector that represents and adjancency list each time
    }

    ~Graph() {}

    void print() {
        for (int i = 0; i < vertices; i++) {
            cout << "Vertex " << V.at(i) << ": ";
            for (auto edg : E.at(i)) cout << edg << ", ";
            cout << endl;
        }
    }

};


#endif