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
    int rob(TreeNode* root)
    {
        
        auto robbingHouses = [](auto self,TreeNode* root) -> pair<int,int> {
            if(root == NULL)
            {
                return {0,0};
            }
            pair<int,int> l1 = self(self,root->left);
            pair<int,int> l2 = self(self,root->right);
            int currMax = max(root->val + l1.second + l2.second, l1.first + l2.first);
            return {currMax,l1.first + l2.first};
        };
        pair<int,int> ans = robbingHouses(robbingHouses,root);
        return max(ans.first,ans.second);
    }
};
