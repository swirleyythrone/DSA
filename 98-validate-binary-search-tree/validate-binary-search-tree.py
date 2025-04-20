class Solution:
    def validate(self, root, min_val, max_val):
        if not root:
            return True
        if not (min_val < root.val < max_val):
            return False
        return (self.validate(root.left, min_val, root.val) and
                self.validate(root.right, root.val, max_val))

    def isValidBST(self, root):
        return self.validate(root, float('-inf'), float('inf'))
