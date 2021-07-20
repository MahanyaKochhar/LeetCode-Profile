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
    int maxi=0;
    int finddiameter(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int ans1=finddiameter(root->left);
        int ans2=finddiameter(root->right);
        int s1=ans1+ans2;
        maxi=max(maxi,s1);
        return max(ans1,ans2)+1;

    }
    int diameterOfBinaryTree(TreeNode* root)
    {
        finddiameter(root);
        return maxi;
    }
};
