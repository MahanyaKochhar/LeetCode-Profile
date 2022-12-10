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
    long long int ans=0;
    const int mod=1e9+7;
    int subSum(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        return root->val+subSum(root->left)+subSum(root->right);
    }
    int findAns(TreeNode* root,int val1)
    {
        if(root==NULL)
            return 0;
        int curr=root->val+findAns(root->left,val1)+findAns(root->right,val1);
        int val2=val1-curr;
        ans=max(ans,(long long int)val2*curr);
        return curr;
    }
    int maxProduct(TreeNode* root)
    {
        int val1=subSum(root);
        findAns(root,val1);
        int fin=ans%mod;
        return fin;
    }
};
