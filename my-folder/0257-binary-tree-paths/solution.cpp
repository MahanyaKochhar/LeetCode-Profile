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
    vector<string>ans;
    void allpaths(TreeNode* root,queue<int>q)
    {
        if(root->left==NULL&&root->right==NULL)
        {
            q.push(root->val);
            string s1="";
            while(!q.empty())
            {
                int x=q.front();
                q.pop();
                string s=to_string(x);
                s1+=s;
                if(!q.empty())
                s1+="->";
            }
            ans.push_back(s1);
            return;
        }
        q.push(root->val);
        if(root->left!=NULL)
        allpaths(root->left,q);
    if(root->right!=NULL)
        allpaths(root->right,q);

    }
    vector<string> binaryTreePaths(TreeNode* root)
    {
        queue<int>q;
        allpaths(root,q);
        return ans;
    }
};
