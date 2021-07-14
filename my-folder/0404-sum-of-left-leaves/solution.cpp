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
    void reqSum(TreeNode* root,string prevMove,int& s)
    {
        if(root->left==NULL&&root->right==NULL)
        {
            if(prevMove=="left")
                s+=root->val;
            
        }
        if(root->left!=NULL)
        reqSum(root->left,"left",s);
    if(root->right!=NULL)
        reqSum(root->right,"right",s);
    }
    int sumOfLeftLeaves(TreeNode* root)
    {
        string prevMove="right";
        int s=0;
        reqSum(root,prevMove,s);
        return s;
    }
};
