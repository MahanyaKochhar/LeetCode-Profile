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
    bool check1(TreeNode* lft,TreeNode* rht)
    {
        if(lft==NULL&&rht==NULL)
            return true;
        else if(lft==NULL&&rht!=NULL)
            return false;
        else if(lft!=NULL&&rht==NULL)
            return false;
        if(lft->val==rht->val&&check1(lft->left,rht->right)&&check1(lft->right,rht->left))
           return true;
           else
           return false;
    }
    bool isSymmetric(TreeNode* root)
    {
        if(check1(root->left,root->right))
            return true;
        else
            return false;
    }
};
