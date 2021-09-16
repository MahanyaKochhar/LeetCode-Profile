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
    TreeNode* deleteop(TreeNode* root,int key)
    {
        if(root==NULL)
            return NULL;
        if(root->val>key)
        {
            root->left=deleteop(root->left,key);
            return root;
        }
        else if(root->val<key)
        {
            root->right=deleteop(root->right,key);
            return root;
        }
        else
        {
            if(root->left==NULL&&root->right==NULL)
            {
                delete root;
                return NULL;
            }
            TreeNode* t1=root->right;
            TreeNode* tmp=t1;
            TreeNode* t2=root->left;
            delete root;
            while(t1!=NULL&&t1->left!=NULL)
            {
                t1=t1->left;
            }
            if(t1==NULL)
                return t2;
            t1->left=t2;
            return tmp;
            
        }
    }
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        if(root==NULL)
            return NULL;
        TreeNode* ans=deleteop(root,key);
        return ans;
    }
};
