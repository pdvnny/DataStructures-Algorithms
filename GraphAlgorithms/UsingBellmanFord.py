# Parker Dunn (pgdunn@bu.edu)

# Running a Bellman-Ford implementation

"""
Related to EC 504 - HW5 - Problem 2
Date 2 April 2022

"""

from BellmanFord_SimpleImplementation import BellmanFord
from sys import maxsize

# Defining graph - each entry is (u, v, w)
# u = origin vertex
# v = end vertex
# w = weight of edge

G1 = [	[1, 2, 8], [1, 3, 12],
		[2, 5, 5], [2, 7, 7], [2, 4, 6],
		[3, 4, 5], [3, 6, 2],
		[4, 6, 2],
		[5, 6, 5], [5, 9, 9],
		[6, 8, 8],
		[7, 6, -5], [7, 8, 6],
		[8, 9, -3],
		[9, 7, 3]			]

g1_mod = []
for edge in G1:
	g1_mod.append([edge[0]-1, edge[1]-1, edge[2]])

BellmanFord(g1_mod, 9, 15, 0)

