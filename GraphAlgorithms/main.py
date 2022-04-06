# Parker Dunn (pgdunn@bu.edu)

from graphalgos import Graph
from graphalgos import BellmanFord


# Creating a graph to run Djikstra's on

g = Graph()

# Edges out of O
g.add_edge(0, 1, 3)
g.add_edge(0, 4, 7)
g.add_edge(0, 2, 4)

# Edges out of 1
g.add_edge(1, 3, 3)
g.add_edge(1, 0, 3)
g.add_edge(1, 7, 6)
g.add_edge(1, 4, 3)

# Edges out of 2
g.add_edge(2, 0, 4)
g.add_edge(2, 4, 5)
g.add_edge(2, 5, 3)

# Edges out of 3
g.add_edge(3, 1, 3)
g.add_edge(3, 7, 4)

# Edges out of 4
g.add_edge(4, 0, 7)
g.add_edge(4, 1, 3)
g.add_edge(4, 7, 4)
g.add_edge(4, 8, 7)
g.add_edge(4, 6, 2)
g.add_edge(4, 5, 4)
g.add_edge(4, 2, 5)

# Edges out of 5
g.add_edge(5, 4, 4)
g.add_edge(5, 6, 3)
g.add_edge(5, 9, 4)
g.add_edge(5, 2, 3)

# Edges out of 6
g.add_edge(6, 8, 5)
g.add_edge(6, 9, 3)
g.add_edge(6, 5, 3)
g.add_edge(6, 4, 2)

# Edges out of 7
g.add_edge(7, 3, 4)
g.add_edge(7, 8, 5)
g.add_edge(7, 4, 4)
g.add_edge(7, 1, 6)

# Edges out of 8
g.add_edge(8, 7, 5)
g.add_edge(8, 4, 7)
g.add_edge(8, 6, 5)
g.add_edge(8, 10, 4)

# Edges out of 9
g.add_edge(9, 5, 4)
g.add_edge(9, 6, 3)
g.add_edge(9, 10, 5)

dist, prev = g.dijkstras(0, 10)

# print(f"Distances: {dist}\nPredecessor {prev}")

# Copying dictionaries to lists
dist_keys = list(dist.keys())
dist_keys.sort()
dist_sorted = [(key, dist[key]) for key in dist_keys]

prev_keys = list(prev.keys())
prev_keys.sort()
prev_sorted = [(key, prev[key]) for key in prev_keys]

print("Distances")
for v in dist_sorted:
	print(f"Vertex {v[0]} -> {v[1]}")
print("\n")

print("Predecessor")
for v in prev_sorted:
	print(f"Vertex {v[0]} -> {v[1]}")
print("\n")

# print("Distance")
# for key, item in dist.items():
# 	print(f"Vertex {key} -> {item}")

# print("Predecessor")
# for key, item in prev.items():
# 	print(f"Vertex {key} -> {item}")