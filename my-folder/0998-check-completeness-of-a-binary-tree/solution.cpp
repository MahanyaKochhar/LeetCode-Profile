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
    bool isCompleteTree(TreeNode* root)
    {
        int e = 0;
        queue< TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* r = q.front();
            q.pop();
            if(r->left != NULL)
            {
                if(e == 1)
                    return false;
                q.push(r->left);
            }
            else
            {
                e = 1;
            }
            if(r->right != NULL)
            {
                if(e == 1)
                    return false;
                q.push(r->right);
            }
            else
                e = 1;
        }
        return true;
    }
};
