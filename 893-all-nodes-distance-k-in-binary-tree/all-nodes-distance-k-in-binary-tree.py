from collections import deque, defaultdict

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def markParents(self, root, parent_track):
        q = deque()
        q.append(root)
        while q:
            curr = q.popleft()
            if curr.left:
                parent_track[curr.left] = curr
                q.append(curr.left)
            if curr.right:
                parent_track[curr.right] = curr
                q.append(curr.right)

    def distanceK(self, root, target, k):
        parent_track = dict()
        self.markParents(root, parent_track)

        visited = set()
        q = deque()
        q.append(target)
        visited.add(target)
        curr_level = 0

        while q:
            if curr_level == k:
                break
            curr_level += 1
            for _ in range(len(q)):
                curr = q.popleft()
                if curr.left and curr.left not in visited:
                    q.append(curr.left)
                    visited.add(curr.left)
                if curr.right and curr.right not in visited:
                    q.append(curr.right)
                    visited.add(curr.right)
                if curr in parent_track and parent_track[curr] not in visited:
                    q.append(parent_track[curr])
                    visited.add(parent_track[curr])

        return [node.val for node in q]
