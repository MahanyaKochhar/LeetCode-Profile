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
    vector<int>level;
    vector<int>depth;
    vector<int>firstMax;
    vector<int>secondMax;
    int computeHeight(TreeNode* root,int lev)
    {
        if(root==NULL)
            return -1;
        level[root->val]=lev;
        depth[root->val]=1+max(computeHeight(root->left,lev+1),computeHeight(root->right,lev+1));
        if(firstMax[lev]<depth[root->val])
        {
            secondMax[lev]=firstMax[lev];
            firstMax[lev]=depth[root->val];
            
        }
        else if(depth[root->val]>secondMax[lev])
        {
            secondMax[lev]=depth[root->val];
        }
        return depth[root->val];
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries)
    {
        level.resize(100001,0);
        firstMax.resize(100001,-1);
        secondMax.resize(100001,-1);
        depth.resize(100001,0);
        computeHeight(root,0);
        vector<int>vec;
        for(int i=0;i<queries.size();i++)
        {
            int v=level[queries[i]];
            if(firstMax[v]==depth[queries[i]])
            {
                if(secondMax[v]==-1)
                    vec.push_back(v-1);
                else
                    vec.push_back(secondMax[v]+v);
            }
            else
                vec.push_back(firstMax[v]+v);
        }
        return vec;
    }
};
