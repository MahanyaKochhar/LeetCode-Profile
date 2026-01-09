# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def subtreeWithAllDeepest(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        q = deque()
        q.append((root,0))
        depth = {}
        max_depth = -1
        sz = {}
        deep = {}
        ans = None
        min_size = 1001
        while len(q) != 0:
            curr_tuple = q.popleft()
            node = curr_tuple[0]
            h = curr_tuple[1]
            depth[node.val] = h
            max_depth = max(max_depth,h)
            if node.left:
                q.append((node.left,h + 1))
            if node.right:
                q.append((node.right, h + 1))

        cnt = 0  
        for key,value in depth.items():
            if value == max_depth:
                cnt += 1

        def dfs(node):
            nonlocal min_size
            nonlocal ans
            sz[node] = 1
            
            if depth[node.val] == max_depth:
                deep[node] = 1
            else:
                deep[node] = 0

            if node.left:
                dfs(node.left)
                sz[node] += sz[node.left]
                deep[node] += deep[node.left]

            if node.right:
                dfs(node.right)
                sz[node] += sz[node.right]
                deep[node] += deep[node.right]
    
            if deep[node] == cnt:
                if sz[node] < min_size:
                    min_size = sz[node]
                    ans = node

        dfs(root)
        return ans
        
