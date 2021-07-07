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
    int mincalc(TreeNode* root)
    {
        if(root==NULL)
            return 100001;
       int lf=mincalc(root->left);
       int rf= mincalc(root->right);
        if(lf==100001&&rf==100001)
            return 1;
        else
            return min(1+lf,1+rf);
    }
    int minDepth(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int ans=mincalc(root);
        return ans;
    }
};
