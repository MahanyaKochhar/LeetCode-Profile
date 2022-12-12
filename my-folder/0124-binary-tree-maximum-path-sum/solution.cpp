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
    map<TreeNode*,int>mp;
    vector<int>f,g,h;
    int cnt;
    int ans=-1001;
    void setNodes(TreeNode* root)
    {
        queue<TreeNode*>q;
        q.push(root);
         cnt=1;
        while(!q.empty())
        {
            TreeNode* add=q.front();
            mp[add]=cnt;
            cnt++;
            q.pop();
            if(add->left!=NULL)
                q.push(add->left);
            if(add->right!=NULL)
                q.push(add->right);

        }
    }
    int compute(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int node_no=mp[root];
        int val1=compute(root->left);
        int val2=compute(root->right);
        f[node_no]=max(0,max(val1,val2));
        g[node_no]=max(0,min(val1,val2));
        return f[node_no]+root->val;
    }
    void computeH(TreeNode* root)
    {
        if(root==NULL)
            return;
        TreeNode* add=root;
        TreeNode* ch1=add->left;
        TreeNode* ch2=add->right;
        ans=max(ans,max(f[mp[add]]+g[mp[add]]+add->val,add->val+f[mp[add]]+h[mp[add]]));
        if(ch1!=NULL)
        {
            if(f[mp[add]]==f[mp[ch1]]+ch1->val)
                h[mp[ch1]]=max(h[mp[add]]+add->val,add->val+g[mp[add]]);
            else
                h[mp[ch1]]=max(h[mp[add]]+add->val,add->val+f[mp[add]]);
        }
        if(ch2!=NULL)
        {
            if(f[mp[add]]==f[mp[ch2]]+ch2->val)
                h[mp[ch2]]=max(h[mp[add]]+add->val,add->val+g[mp[add]]);
            else
                h[mp[ch2]]=max(h[mp[add]]+add->val,add->val+f[mp[add]]);
        }
        computeH(root->left);
        computeH(root->right);
    }
    int maxPathSum(TreeNode* root)
    {
        mp.clear();
        f.resize(30001,0);
        g.resize(30001,0);
        h.resize(30001,0);
        setNodes(root);
        compute(root);
        computeH(root);
        return ans;
    }
};
