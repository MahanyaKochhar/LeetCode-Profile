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
    void preOrder(TreeNode* root,vector<int>&fin)
    {
        if(root==NULL)
            return;
        fin.push_back(root->val);
        preOrder(root->left,fin);
        preOrder(root->right,fin);
    }
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int>fin;
        preOrder(root,fin);
        return fin;
    }
};
