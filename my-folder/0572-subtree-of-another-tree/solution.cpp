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
    int e=0;
    bool checker(TreeNode* root,TreeNode* subRoot)
    {
        if(root==NULL&&subRoot==NULL)
            return true;
        if(root==NULL||subRoot==NULL)
            return false;
        if(root->val!=subRoot->val)
            return false;
        return checker(root->left,subRoot->left)&&checker(root->right,subRoot->right);
    }
    void check(TreeNode* root,TreeNode* subRoot)
    {
        if(root==NULL)
            return;
        if(root->val==subRoot->val)
        {
            bool v=checker(root,subRoot);
            if(v==true)
                e++;
        }
        check(root->left,subRoot);
        check(root->right,subRoot);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot)
    {
        check(root,subRoot);
        if(e>0)
            return true;
        else
            return false;
    }
};
