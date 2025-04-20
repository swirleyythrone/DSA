from collections import deque

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def widthOfBinaryTree(self, root: TreeNode) -> int:
        if not root:
            return 0
        
        max_width = 0
        q = deque([(root, 0)])  # (node, index)

        while q:
            level_length = len(q)
            _, level_head_index = q[0]  # get the minimum index at this level
            for i in range(level_length):
                node, index = q.popleft()
                # Normalize index to prevent overflow
                index -= level_head_index
                if node.left:
                    q.append((node.left, 2 * index + 1))
                if node.right:
                    q.append((node.right, 2 * index + 2))
            # width is last index - first index + 1
            max_width = max(max_width, index + 1)

        return max_width
