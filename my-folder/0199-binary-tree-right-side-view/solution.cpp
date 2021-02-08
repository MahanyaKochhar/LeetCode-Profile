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
    vector<int>ans;
    vector<int>ans2;
    vector<int> rightSideView(TreeNode* root) {
        ans.resize(301);
        View(root,NULL,0);
        for(int i=0;i<301;i++)
        {
            if(ans[i]==0)
                break;
            else
             ans2.push_back(ans[i]);
        }
        return ans2;
        }
         void View(TreeNode* root,TreeNode* parent,int count)
         {
         if(root==NULL)
         {
         return;
         }
             ans[count]=root->val;
             
            View(root->left,root,count+1);
            View(root->right,root,count+1);
        }
    };
