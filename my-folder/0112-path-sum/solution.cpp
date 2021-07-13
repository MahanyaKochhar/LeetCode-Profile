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
    bool checkans(TreeNode* node,int sum)
    {
        if(node->left==NULL&&node->right==NULL)
        {
            if(sum-(node->val)==0)
                return true;
            else
                return false;
        }
        bool ans1=false,ans2=false;
        if(node->left!=NULL)
            ans1=checkans(node->left,sum-(node->val));
        if(node->right!=NULL)
            ans2=checkans(node->right,sum-(node->val));
        return ans1||ans2;
    }
    bool hasPathSum(TreeNode* root, int targetSum)
    {
        if(root==NULL)
            return false;
        bool ans=checkans(root,targetSum);
        return ans;
    }
};
