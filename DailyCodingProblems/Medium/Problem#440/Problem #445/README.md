# Pruning a Binary Tree to Remove Subtrees Containing All Zeros

## Problem Description

Given a binary tree where each node has a value of either `0` or `1`, the task is to prune the tree by removing all subtrees that contain only nodes with the value `0`. The goal is to return the pruned tree.

## Solution Approach

The solution involves a recursive approach to traverse the tree and prune the necessary subtrees. Here's a step-by-step breakdown of the approach:

1. **Recursive Helper Function**: We define a helper function that will be called recursively for each node in the tree. This function will return `None` if the subtree rooted at the current node should be pruned (i.e., it contains only zeros and no ones).

2. **Base Case**: If the current node is `None`, we return `None`. This handles the case where we reach a leaf node's child.

3. **Recursive Case**: For each node, we recursively call the helper function on its left and right children. This ensures that we process the entire subtree rooted at the current node.

4. **Pruning Condition**: After processing the left and right subtrees, we check if the current node's value is `0` and if both its left and right children are `None` (indicating that they were pruned). If this condition is met, we return `None` to prune the current node as well.

5. **Return Node**: If the current node should not be pruned, we return the node itself.

6. **Initial Call**: We start the pruning process by calling the helper function on the root of the tree.

7. **Printing the Pruned Tree**: To verify the correctness of the pruning, we define a function `printTree` that performs an in-order traversal of the tree and prints the node values.
