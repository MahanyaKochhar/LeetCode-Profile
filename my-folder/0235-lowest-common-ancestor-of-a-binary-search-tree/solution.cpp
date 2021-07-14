/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* treeTraversal(TreeNode* root,int p,int q)
    {
        if(root->val>=p&&root->val<=q)
            return root;
        else if(root->val>=p&&root->val>=q) 
         return treeTraversal(root->left,p,q);
     else
        return treeTraversal(root->right,p,q);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        int val1=p->val,val2=q->val;
        int val3=min(val1,val2);
        int val4=max(val1,val2);
       TreeNode* ans= treeTraversal(root,val3,val4);
       return ans;
    }
};
