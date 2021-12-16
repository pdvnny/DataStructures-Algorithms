# -*- coding: utf-8 -*-
"""
Created on Tue Dec 14 19:09:38 2021

@author: dvnny


 !! THIS IS NOT MY WORK & IT IS NOT MY INTENTION TO PASS THIS OFF AS MY WORK !!

 I copied this code from Geeks for Geeks (website) to better understand how
 this algorithm is coded.

 Reference: https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
"""

"""
AS NOTED BELOW, this implementation is specific for an adjacency matrix representation
of a graph!
"""

# Python program for Dijkstra's single
# source shortest path algorithm. The program is
# for adjacency matrix representation of the graph

# Library for INT_MAX
import sys

class Graph():

	def __init__(self, vertices):
		self.V = vertices
		self.graph = [[0 for column in range(vertices)]
					for row in range(vertices)]

	def printSolution(self, dist):
		print("Vertex \tDistance from Source")
		for node in range(self.V):
			print(node, "\t", dist[node])

	# A utility function to find the vertex with
	# minimum distance value, from the set of vertices
	# not yet included in shortest path tree
	def minDistance(self, dist, sptSet):

		# Initialize minimum distance for next node
        # initializing to INF basically
		min = sys.maxint

		# Search for nearest vertex not in the
		# shortest path tree
		for u in range(self.V):
			if dist[u] < min and sptSet[u] == False:
				min = dist[u]
				min_index = u

		return min_index

	# Function that implements Dijkstra's single source
	# shortest path algorithm for a graph represented
	# using adjacency matrix representation
	def dijkstra(self, src):

		dist = [sys.maxint] * self.V      # all V distances to "infinity"
		dist[src] = 0
		sptSet = [False] * self.V         # separate already visited nodes from non-visited

        # NOTE: for the loop below, the first iteration would have all distances
        #   as infinity, so x would be the source vertex! After this step,
        #   we would be selecting the minimum distance node and "moving" to it
        #   to check/updates its neighbors

		for cout in range(self.V):

			# Pick the minimum distance vertex from
			# the set of vertices not yet processed.
			# x is always equal to src in first iteration
			x = self.minDistance(dist, sptSet)

			# Put the minimum distance vertex in the
			# shortest path tree
			sptSet[x] = True

			# Update dist value of the adjacent vertices
			# of the picked vertex only if the current
			# distance is greater than new distance and
			# the vertex in not in the shortest path tree
			for y in range(self.V):
				if(self.graph[x][y] > 0 and sptSet[y] == False and \
				dist[y] > dist[x] + self.graph[x][y]):
						dist[y] = dist[x] + self.graph[x][y]

		self.printSolution(dist)

# Driver program
g = Graph(9)
g.graph = [[0, 4, 0, 0, 0, 0, 0, 8, 0],
		[4, 0, 8, 0, 0, 0, 0, 11, 0],
		[0, 8, 0, 7, 0, 4, 0, 0, 2],
		[0, 0, 7, 0, 9, 14, 0, 0, 0],
		[0, 0, 0, 9, 0, 10, 0, 0, 0],
		[0, 0, 4, 14, 10, 0, 2, 0, 0],
		[0, 0, 0, 0, 0, 2, 0, 1, 6],
		[8, 11, 0, 0, 0, 0, 1, 0, 7],
		[0, 0, 2, 0, 0, 0, 6, 7, 0]
		];

g.dijkstra(0);

# This code is contributed by Divyanshu Mehta
