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
    map<TreeNode*,TreeNode*>mp;
   void  push(TreeNode* root,vector<int>&vec)
    {
        if(root==NULL)
            return;
        push(mp[root],vec);
        vec.push_back(root->val);
    }
    void fPaths(TreeNode* root,int targetSum,TreeNode* par,vector<vector<int>>&ans)
    {
        if(root==NULL)
            return;
        mp[root]=par;
        if(root->left==NULL&&root->right==NULL)
        {
            if(targetSum==root->val)
            {
                vector<int>v;
                push(root,v);
                ans.push_back(v);
            }
        }
        
        fPaths(root->left,targetSum-root->val,root,ans);
        fPaths(root->right,targetSum-root->val,root,ans);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum)
    {
        vector<vector<int>>ans;
        
        fPaths(root,targetSum,NULL,ans);
        return ans;
    }
};
