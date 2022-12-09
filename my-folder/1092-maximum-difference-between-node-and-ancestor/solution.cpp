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
    multiset<int>s;
    int fin=0;
    void findAns(TreeNode* root)
    {
        if(root==NULL)
            return;
        for(auto x:s)
        {
            fin=max(fin,abs(root->val-x));
        }
        s.insert(root->val);
        findAns(root->left);
        findAns(root->right);
        s.erase(s.find(root->val));
        
    }
    int maxAncestorDiff(TreeNode* root)
    {
        s.clear();
        findAns(root);
        return fin;
    }
};
