"""
@author: dvnny
"""

"""

LeetCode - 701. Insert into a Binary Search Tree

DATE: 27 Jan 2022


Explanation:
(1) Given the root node of a BST and a value to insert into the tree
(2) Return the root node of the BST after the insertion

** Guaranteed that the new value does not exist in the original BST

"""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def insertIntoBST(self, root, val):
    	if root is None:				# Terminal condition: reached a point where we have an empty loc on the BST
    		return TreeNode(val=val, left=None, right=None)
    	else:							# Continued Recursion case: call insert on node to left or right
	    	if root.val > val:
	    		root.left = self.insertIntoBST(root.left, val)
	    	else:
	    		root.right = self.insertIntoBST(root.right, val)
	    	return root

def inorder(root):
    if root:
        inorder(root.left)
        print(root.val)
        inorder(root.right)


s = Solution()

tree1 = [20,60,10,30,50,70]
BST1 = TreeNode(40)
for val in tree1:
	s.insertIntoBST(BST1, val)

inorder(BST1)
        

### THIS IMPLEMENTATION WORKS IF WE ARE KEEPING THE BST AS AN ARRAY

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution2:
    def insertIntoBST(self, root, val):
    	
    	# (1) Finding location for insert!
    	n = len(root) - 1
    	loc = 0
    	while (root[loc] != None):
    		if (val < root[loc]):   	# move left which is ----> loc*2 + 1
    			loc = loc*2 + 1
    		else:						# move right which is --> loc*2 + 2
    			loc = loc*2 + 2
    		if (loc > n): 				# next location is outside the bounds of the array
    			newsize = len(root)*2
    			while (len(root) < newsize):
    				root.append(None)

    	# (2) Inserting the new value
    	root[loc] = val
    	return root

s = Solution2()

newRoot1 = s.insertIntoBST(root = [4,2,7,1,3], val = 5)
print(newRoot1)
newRoot2 = s.insertIntoBST(root = [40,20,60,10,30,50,70], val = 25)
print(newRoot2)