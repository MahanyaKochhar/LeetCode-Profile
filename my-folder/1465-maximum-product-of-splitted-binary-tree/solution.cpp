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
    int maxProduct(TreeNode* root)
    {
        using ll = long long;
        map<TreeNode*,int>mp;
        const int mod = 1e9 + 7;
        auto dfs = [&](auto self,TreeNode* node) -> void
        {
            mp[node] = node->val;
            if(node->left != NULL)
            {
                self(self,node->left);
                mp[node] += mp[node->left];
            }
            if(node->right != NULL)
            {
                self(self,node->right);
                mp[node] += mp[node->right];
            }
        };
        dfs(dfs,root);
        int total = mp[root];
        ll maxi = 0;
        for(auto& [k,v] : mp)
        {
            int rest = total - v;
            maxi = max(maxi,(ll)rest * (ll)v);
        }
        return maxi % mod;
    }
};
