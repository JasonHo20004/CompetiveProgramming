class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def prune(root):
    def helper(node):
        if not node:
            return None

        node.left = helper(node.left)
        node.right = helper(node.right)

        if node.val == 0 and not node.left and not node.right:
            return None
        return node
    return helper(root)

def printTree(root):
    if not root:
        return
    print(root.val, end=" ")
    printTree(root.left)
    printTree(root.right)

root = TreeNode(0)
root.left = TreeNode(1)
root.right = TreeNode(0)
root.left.left = TreeNode(1)
root.left.right = TreeNode(0)
root.left.left = TreeNode(0)
root.left.right = TreeNode(0)

pruned_tree = prune(root)
printTree(pruned_tree)
