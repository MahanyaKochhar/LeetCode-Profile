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
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int>fin;
        stack<TreeNode*>s;
        if(root!=NULL)
            s.push(root);
        while(!s.empty())
        {
            fin.push_back(s.top()->val);
            TreeNode* curr=s.top();
            s.pop();
            if(curr->right!=NULL)
                s.push(curr->right);
            if(curr->left!=NULL)
                s.push(curr->left);
            
        }
        return fin;
    }
};
