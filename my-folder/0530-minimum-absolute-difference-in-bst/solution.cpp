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
    int mini=INT_MAX;
    TreeNode* prev=NULL;
    void findans(TreeNode* root)
    {
        if(root==NULL)
            return;
        findans(root->left);
         if(prev!=NULL)
        {
            mini=min(mini,abs(root->val-prev->val));
        }
        prev=root;
        findans(root->right);
    }
    int getMinimumDifference(TreeNode* root)
    {
        findans(root);
        return mini;
    }
};
