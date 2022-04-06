"""

	Parker Dunn (pgdunn@bu.edu)
	Graph Algorithms

"""

# File of graph algorithms copied from GeeksForGeeks that I can use for other things
 
# Library for INT_MAX
import sys

""" ******* DJIKSTRA'S ALGORITHM ****** """

# Python program for Dijkstra's single
# source shortest path algorithm. The program is
# for adjacency matrix representation of the graph
 
# Description:
# Implement dijkstras shortest path graph algorithm
#
# Approach:
# This is a single source shortest path(SSSP) algo - starts from a source
# vertex and finds shortest path to every reachable vertex, though we can break
# early if we need shortest path to s specific destination.
# This algo works only if graph doesn't have a negative edge cycle.
# Below is the implementation detail:
# - Start from a source node(dist = 0) and do BFS
# - Push all adjacent nodes(node and edge weights) to priority queue(used
#   python heapq module for this. Edge weights is used as priority
# - Performing BFS keep on updating distance and prev(parent) if we found a
#   better than existing
#
# Complexity:
# O(E*log(V))
#
# NOTE:
# We can achive better runtime by optimizing the priority queue. Best known
# runtime is O(E + Vlog(V)) with fibonacci heap(quite complex to implement)

import heapq

class Graph:
    def __init__(self):
        self.graph = {}

    def add_edge(self, src, dst, weight):
        if src in self.graph:
            self.graph[src].append((dst, weight))
        else:
            self.graph[src] = [(dst, weight)]

    def dijkstras(self, start, end):
        """
        Returns shortest path from start to end node. We can skip end node if
        we want to find shortest distance from start to all reachable nodes.
        """
        pq = []
        # Use python min heap, use tuple with 2 fields - first distance(used as
        # priority) and second one is node.
        heapq.heappush(pq, (0, start))  # start node is at 0 distance
        prev = {}  # Parent of a node, used to find path from start to end

        # Distance of a node from start
        distance = {
            start: 0
        }

        visited = set()

        while len(pq) > 0:
            min_wt, node = heapq.heappop(pq)
            visited.add(node)

            # We already found a better path before we got to processing this
            # node so we can ignore this node
            if node in distance and min_wt > distance[node]:
                continue

            for adj, wt in self.graph.get(node, []):
                # We cannot get a shorter path by revisiting a node we have
                # already visited before because dijkstras algo works in greedy
                # manner
                if adj in visited:
                    continue
                new_dist = distance[node] + wt
                if adj not in distance:
                    distance[adj] = new_dist
                    heapq.heappush(pq, (new_dist, adj))
                    prev[adj] = node

                # Relax edge by updating cost if applicable
                if new_dist < distance[adj]:
                    distance[adj] = new_dist
                    heapq.heappush(pq, (new_dist, adj))
                    prev[adj] = node
            if node == end:  # To find shortest dist to all nodes from start, skip this check
                return distance, prev
        return {}, {}  # Can't reach end node from start

    def find_shortest_path(self, start, end):
        """Prints shortest path from start to end if exists."""
        distance, prev = self.dijkstras(start, end)

        # Construct path
        if end not in distance:
            print(f'{end} is not reachable from {start}')
            return []
        path = [end]
        parent = prev.get(end)
        while parent:
            path.append(parent)
            parent = prev.get(parent)
        path.reverse()
        print(f'Shortest distance from {start} to {end} is {distance[end]}, path: {path}')

""" ****** BELLMAN-FORD ALGORITHM ******* """

def BellmanFord(graph, V, E, src):

	# Initialize distance of all vertices as infinite.
	dis = [maxsize] * V

	# initialize distance of source as 0
	dis[src] = 0

	# Relax all edges |V| - 1 times. A simple
	# shortest path from src to any other
	# vertex can have at-most |V| - 1 edges
	for i in range(V - 1):
		for j in range(E):
			if (dis[graph[j][0]] + graph[j][2] < dis[graph[j][1]]):
				dis[graph[j][1]] = dis[graph[j][0]] + \
									graph[j][2]

	# check for negative-weight cycles.
	# The above step guarantees shortest
	# distances if graph doesn't contain
	# negative weight cycle. If we get a
	# shorter path, then there is a cycle.
	for i in range(E):
		x = graph[i][0]
		y = graph[i][1]
		weight = graph[i][2]
		if dis[x] != maxsize and dis[x] + \
						weight < dis[y]:
			print("Graph contains negative weight cycle")

	print("Vertex Distance from Source")
	for i in range(V):
		print("%d\t\t%d" % (i, dis[i]))
