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
    TreeNode* invertfunc(TreeNode* root)
    {
        if(root==NULL)
            return root;
        root->left=invertfunc(root->left);
        root->right=invertfunc(root->right);
        TreeNode* tmp=root->left;
        root->left=root->right;
        root->right=tmp;
        return root;
    }
    TreeNode* invertTree(TreeNode* root)
    {
        TreeNode* ans=invertfunc(root);
        return ans;
    }
};
