# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countNodes(self, root: Optional[TreeNode]) -> int:
        if not root :
            return 0
        
        left_depth = 0
        left_node= root
        while left_node:
            left_depth +=1 
            left_node = left_node.left
        

        right_depth = 0
        right_node = root
        while right_node :
            right_depth +=1 
            right_node = right_node.right

        if right_depth == left_depth :
            return (1 << left_depth) -1

        return 1 + self.countNodes(root.left) + self.countNodes(root.right)       