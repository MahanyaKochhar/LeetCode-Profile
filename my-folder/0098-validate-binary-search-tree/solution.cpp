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
bool isValid(TreeNode* root,long long int lft,long long int rft)
{
    if(root==NULL)
        return true;
    if(root->val>lft&&root->val<rft)
    {
        return isValid(root->left,lft,root->val)&&isValid(root->right,root->val,rft);
    }
    return false;
}
class Solution {
public:
    bool isValidBST(TreeNode* root)
    {
        return isValid(root,-1e14,1e14);
    }
};
