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
 int ans=-1e9;
class Solution {
public:
    int solve(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int val1=solve(root->left);
        int val2=solve(root->right);
        int firstMax=max(0,max(val1,val2));
        int secondMax=max(0,min(val1,val2));
        
        ans=max(ans,firstMax+secondMax+root->val);
        return firstMax+root->val;
    }
    int maxPathSum(TreeNode* root)
    {
        ans=-1e9;
        solve(root);
        return ans;
    }
};
