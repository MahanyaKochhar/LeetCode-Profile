/**
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
    int cnt=0;
    int sumsub(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int l1=sumsub(root->left);
        int l2=sumsub(root->right);
        cnt+=abs(l1-l2);
        return root->val+l1+l2;
    }
    int findTilt(TreeNode* root)
    {
        sumsub(root);
        return cnt;
    }
};
