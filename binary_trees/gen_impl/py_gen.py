
import time

class TreeNode:
	def __init__(self, data):
		self.data = data
		self.left = None
		self.right = None

def morris_traversal(root):
	current = root

	while current:
		if current.left is None:
			print(current.data, end=" ")
			current = current.right
		else:
			# Find the inorder predecessor of current
			pre = current.left
			while pre.right and pre.right != current:
				print(pre.data)
				time.sleep(1)
				pre = pre.right
			pre.right = current
			current = current.left
			time.sleep(1)
			print(current.data)

# Driver program to test above functions
if __name__ == '__main__':
	"""
	Constructed binary tree is
			1
		/ \
		2	 3
	/ \
	4	 5
	"""
	root = TreeNode(1)
	root.left = TreeNode(2)
	root.right = TreeNode(3)
	root.left.left = TreeNode(4)
	root.left.right = TreeNode(5)

	morris_traversal(root)
