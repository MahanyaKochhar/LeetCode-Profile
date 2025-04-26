/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root)
    {
        int ans = 0;
        auto dfs = [&](auto self,TreeNode* root) -> int {
            if(root == NULL)
            {
                return 0;
            }
            int l = self(self,root->left);
            int r = self(self,root->right);
            ans = max(ans,l + r + 1);
            return max(l,r) + 1;
        };
        dfs(dfs,root);
        return ans - 1;
    }
};
