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
    int maxLevelSum(TreeNode* root)
    {
        vector<int>ans;
        queue<pair<TreeNode*,int>>q;
        q.push({root,1});
        while(!q.empty())
        {
            auto i = q.front();
            TreeNode* node = i.first;
            int val = node->val;
            int level = i.second;
            if(ans.size() < level)
            {
                ans.push_back(val);
            }
            else
            {
                ans[level - 1] += val;
            }
            q.pop();
            if(node->left != NULL)
            {
                q.push({node->left,level + 1});
            }
            if(node->right != NULL)
            {
                q.push({node->right,level + 1});
            }
        }
        int maxi = INT_MIN;
        int lev = -1;
        for(int i = 0 ; i < ans.size() ; i++)
        {
            if(ans[i] > maxi)
            {
                maxi = ans[i];
                lev = i + 1;
            }
        }
        return lev;
    }
};
