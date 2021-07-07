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
    void takemiddle(int l,int r,vector<int>nums,vector<int>&ans)
    {
        if(l>=r)
            return;
        int mid=(l+r)/2;
        int v=nums[mid];
        ans.push_back(v);
        takemiddle(l,mid,nums,ans);
        takemiddle(mid+1,r,nums,ans);

    }
    TreeNode* insert(TreeNode* root,int val)
    {
        TreeNode* newNode=new TreeNode(val);
        if(root==NULL)
        {
            root=newNode;
        }
        else if(root->val>=val)
        {
            root->left=insert(root->left,val);
        }
        else
        {
            root->right=insert(root->right,val);
        }
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        int sz=nums.size();
        vector<int>ans;
        takemiddle(0,sz,nums,ans);
        TreeNode* root=NULL;
        for(int i=0;i<ans.size();i++)
        {
            root=insert(root,ans[i]);
        }
        return root;
    }
};

