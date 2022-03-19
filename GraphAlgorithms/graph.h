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
#include <list>

using namespace std;

class Graph {

    int vertices;
    list<int>* adj; /// A pointer to an array containing adjacency lists
    list<int>* adj_wt;

public:

    Graph(int n) {
        this->vertices = n;
        adj = new list<int>[vertices];
        adj_wt = new list<int>[vertices];
    }

    int size() { return this->vertices; }

    void addEdge(int src, int dst, int wt);
    void print();

    void BFS(int src);

};

void Graph::addEdge(int src, int dst, int wt) {
    ///cout << "Started addEdge()" << endl;

    adj[src-100].push_back(dst);    /// Add dst to src's list

    //cout << "Saved Edge Destination" << endl;

    /// I am adopting this structure from an example and the provided example is designed to specifically
    /// work with vertices starting at 0 and increasing ... so I adapted my version (for now) to work similarly
    /// which is the reason for the "src-100" for now.

    adj_wt[src-100].push_back(wt);
    //cout << "Saved Edge Weight" << endl << "\n";
}

void Graph::print() {
    for (int i = 0; i < vertices; i++) {
        cout << "Node " << i+100 << ": ";
        auto e = adj[i].begin();
        auto wt = adj_wt[i].begin();
        while (e != adj[i].end()) {
            cout << "[" << *e << ", " << *wt << "] ";
            e++;
            wt++;
        }
        cout << endl;
    }
}

void Graph::BFS(int src) {

    /// Setting up "visited" mechanism
    bool* visited = new bool[vertices];
    for (int b = 0; b < vertices; b++) visited[b] = false;

    /// Setting up "predecessor" array
    int* predecessor = new int[vertices];
    for (int p = 0; p < vertices; p++) predecessor[p] = -1;

    /// More setup - queue & src & iterator for getting edges
    list<int> queue;
    queue.push_back(src);
    
    visited[src-100] = true;
    predecessor[src-100] = src-100;
    
    list<int>::iterator itr;
    int current;

    /// The actual algorithm
    while (!queue.empty()) {

        current = queue.front();
        queue.pop_front();

        /// iterating through all neighbors of current node
        for (itr = adj[current-100].begin(); itr != adj[current-100].end(); ++itr) {
            
            /// only if not visited -> add to queue, mark visited, save current node as predecessor
            if (!visited[(*itr)-100]) {
                queue.push_back(*itr);
                visited[(*itr)-100] = true;
                predecessor[(*itr)-100] = current;
            }

            /// END for
        }
        
        /// END while
    }

    /// PRINTING OUT PREDECESSOR ARRAY
    list<int> q;
    bool* printed = new bool[vertices];
    
    q.push_back(src);
    printed[src-100] = true;

    cout << "BFS Result: \nSource: ";

    while (!q.empty()) {
        current = q.front();
        q.pop_front();
        cout << current << " -> ";

        for (int i = 0; i < vertices; i++) {
            if (predecessor[i] == current and !printed[i]) {
                q.push_back(i+100);
                cout << (i+100) << " ";
                printed[i] = true;
            }
        }
        cout << endl;
    }

    delete [] visited;
    delete [] predecessor;
    delete [] printed;
    
}

/************** MORE COMPLICATED GRAPH IMPLEMENATION BELOW **************/

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