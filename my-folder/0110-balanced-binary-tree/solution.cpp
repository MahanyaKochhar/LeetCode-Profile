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
    int ans=0;
    int checkHeight(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int val1=checkHeight(root->left);
        int val2=checkHeight(root->right);
        if(abs(val1-val2)>1)
        {
            ans=1;
        }
        return max(1+val1,1+val2);
    }
    bool isBalanced(TreeNode* root)
    {
        int v=checkHeight(root);
        if(ans==1)
            return false;
        else
            return true;
    }
};
