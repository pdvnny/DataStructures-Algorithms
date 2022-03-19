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

template <class k>
class Edge {
public:
    k start;
    k end;
    int weight;
};

template <class k>
class Node {
public:
    k key;
    vector<Edge<k>> edges;
};


template <class v>
class DirectedGraph {
public:
    
    int vertices;
    int edges;
    vector<Node<v>> V;
    //vector<Edge<v>> E;

    DirectedGraph(v verts[], Edge<char> edgs[], int n_vert, int n_edges) {
        this->vertices = n_vert;
        this->edges = n_edges;


        /// Copying over vertices
        for (int i = 0; i < vertices; i++) { //V.push_back(verts[i]);
            Node<v> tmp_node;
            tmp_node.key = verts[i];
            V.push_back(tmp_node);
        }

        /// Copying the edges
        //for (auto lst : E) E.push_back(lst);  /// <-- should be saving an entire vector that represents and adjancency list each time
        for (int i = 0; i < edges; i++) {
            v src = edgs[i].start;

            /// find src node in list of vertices
            int j = 0;
            while (V[j].key != src) j++;

            /// save edge to the node
            V[j].edges.push_back(edgs[i]);
        }
    }

    ~DirectedGraph() {}

    void print() {
        for (int i = 0; i < vertices; i++) {
            Node n = V.at(i);
            cout << "Vertex " << n.key << ": ";
            for (auto edge : V.at(i).edges) cout << edge.end << ", ";
            cout << endl;
        }
    }

};


#endif