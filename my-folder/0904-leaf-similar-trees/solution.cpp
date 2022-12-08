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
vector<int>v;
class Solution {
public:
    void addLeaves(TreeNode* root)
    {
        if(root==NULL)
            return;
        addLeaves(root->left);
        addLeaves(root->right);
        if(root->left==NULL&&root->right==NULL)
            v.push_back(root->val);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2)
    {
        v.clear();
        addLeaves(root1);
        vector<int>v1=v;
        v.clear();
        addLeaves(root2);
        vector<int>v2=v;
        if(v1==v2)
            return true;
        else
            return false;
    }
};
