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
    long long kthLargestLevelSum(TreeNode* root, int k)
    {
        queue<TreeNode*> q;
        q.push(root);
        int c = 1;
        long long sum = 0;
        int cnt = 0;
        vector<long long > vec;
        while(!q.empty())
        {
            for(int i = 0;i < c ;i++)
            {
                TreeNode* v = q.front();
                sum += v->val;
                q.pop();
                if(v->right != NULL)
                {
                    q.push(v->right);
                    cnt++;
                }
                if(v->left != NULL)
                {
                    q.push(v->left);
                    cnt++;
                }
            }
            c = cnt;
            vec.push_back(sum);
            cnt = 0;
            sum = 0;
        }
        sort(vec.rbegin(),vec.rend());
        
        if(vec.size() < k)
            return -1;
        else
            return vec[k-1];
    }
};
