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
    TreeNode* ans;
    int value;
    map<TreeNode*,bool>mp;
    void dfs(TreeNode* cloned)
    {
        if(cloned==NULL)
        {
            return;
        }
        if(cloned->val==value)
        {
            ans=cloned;
            return;  
        }
        if(!mp[cloned])
        {
            mp[cloned]=true;
            dfs(cloned->left);
            dfs(cloned->right);
        }
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        value=target->val;
        dfs(cloned);
        return ans;
    }
};
