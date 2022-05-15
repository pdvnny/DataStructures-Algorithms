"""

	Parker Dunn (parker_dunn@outlook.com)

	Created 6 May 2022


	Task: Implement a simple queue and the Breadth First Search (BFS) algorithm


	** Actually, I'll stick to using a module implementation of a Queue **

	Notes for using queue.Queue:
	- Some info on this queue: https://www.geeksforgeeks.org/queue-in-python/
	- "Queue" is a built-in module of Python
	- Syntax for creating an object --> "queue.Queue(maxsize)" OR "Queue(maxsize)"
		- maxsize = 0 creates an infinitely large queue
	- Functions!
		(1) maxsize 	-> returns number of items allowed
		(2) empty() 	-> boolean operation; True if queue is empty
		(3) get()		-> Remove and return an item from the queue. If queue is empty, wait until an item is available
		(4) put() 		-> put an item into the queue; if the queue is full, wiat until a free slot is available before adding the item

	- WARNING: unlike c++ implementations, this implementation of a queue seems to use a buffer that automatically manages
		overloading the queue or pulling too many elements from the queue. IT MAY BE EASY TO LOSE TRACK OF CALLS TO THE QUEUE
		BECAUSE ERRORS MAY NOT ALWAYS RAISE WHEN MY CODE MAKES A MISTAKE

"""

from queue import Queue


""" ASSUMED STRUCTURE OF THE GRAPH

	Each node is a tuple: (id/key, list of neighbors, capacity)

"""

# **************** BFS FUNCTION ********************
def BFS(G, s, t):

	# SETUP - create a queue
	myQ = Queue(maxsize = len(G) * 2)

	# SETUP - create output arrays that are modified by the algo
	predecessors = [-1 for i in range(len(G))]
	st_path = []

	# SETUP - select node s to start from



	return predecessors, st_path

"""
	For identifying the shortest st_path, while working through the Queue use some code like this	
	
	if (!st_path):   <-- Python lists are implicitly "False" when empty
		st_path.append(t)
		st_path.append(current element pulled from the queue)


	Using this approach, I will have to reverse the elements of "st_path" before returning them

"""


# *************** USING BFS **********************

# qSize = 10000  # can be adjusted, picked a random number that seemed large enough for now - NVM, DON'T NEED THIS


