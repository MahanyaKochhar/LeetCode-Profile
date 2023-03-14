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
int ans = 0;
class Solution {
public:
    void calculate(TreeNode* root , int v)
    {
        if(root == NULL)
            return ;
            v = v * 10 + root->val;
        if(root->left  == NULL && root->right == NULL)
        {
            ans += v;
            return;
        }
        calculate(root->left, v);
        calculate(root->right, v);
    }
    int sumNumbers(TreeNode* root)
    {
        ans = 0;
        calculate(root , 0);
        return ans;
    }
};
