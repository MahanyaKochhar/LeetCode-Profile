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
int i;
class Solution {
public:

TreeNode* buildAns(vector<int>& inorder, int l ,int r , vector<int>& postorder)
    {
        if(i < 0 || l > r)
            return NULL;
        int pos = -1;
        for(int j = l ; j <= r ; j++)
        {
            if(postorder[i] == inorder[j])
            {
                pos = j;
                break;
            }
        }
        if(pos == -1)
            return NULL ;
        TreeNode* root = new TreeNode(postorder[i]);
        i--;
        root->right = buildAns(inorder, pos + 1, r, postorder);
        root->left = buildAns(inorder, l , pos - 1, postorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        i = inorder.size() -1 ;
        return buildAns(inorder,0, inorder.size() - 1, postorder);
    }
};
