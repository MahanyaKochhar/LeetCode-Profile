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
    TreeNode* recoverFromPreorder(string traversal)
    {
        int cnt = 0, prevCnt = 0;
        TreeNode* root = NULL;
        TreeNode* curr = root;
        map<TreeNode* , TreeNode*> par;
        string no = "";
        for(int i = 0 ; i < traversal.length();i++)
        {
            if(traversal[i] == '-')
            {
                if(no != "")
                {
                    if(root == NULL)
                    {
                        TreeNode* newNode = new TreeNode(stoi(no));
                        root = newNode;
                        curr = newNode;
                        no = "";
                        cnt = 1;
                        continue;
                    }
                    if(cnt > prevCnt)
                    {
                        prevCnt = cnt;
                        TreeNode* newNode = new TreeNode(stoi(no));
                        no = "";
                        curr->left = newNode;
                        par[newNode] = curr;
                        curr = newNode;
                        
                    }
                    else
                    {
                        int jmp = prevCnt - cnt + 1;
                        prevCnt = cnt;
                        while(jmp != 0)
                        {
                            curr = par[curr];
                            jmp--;
                        }
                        TreeNode* newNode = new TreeNode(stoi(no));
                        no = "";
                        curr-> right = newNode;
                        par[newNode] = curr;
                        curr = newNode;
                    }
                    cnt = 0;
                }
                cnt ++;
            }
            else
            {
                no.push_back(traversal[i]);
            }
        }
        if(root == NULL)
        {
            
            TreeNode* newNode = new TreeNode(stoi(no));
            root = newNode;
            curr = newNode;
            return root;
            
        }
        if(cnt > prevCnt)
        {
            prevCnt = cnt;
            TreeNode* newNode = new TreeNode(stoi(no));
            no = "";
            curr->left = newNode;
            par[newNode] = curr;
            curr = newNode;
        }
        else
        {
            int jmp = prevCnt - cnt + 1;
            prevCnt = cnt;
            while(jmp != 0)
            {
                curr = par[curr];
                jmp--;
            }
            TreeNode* newNode = new TreeNode(stoi(no));
            no = "";
            curr-> right = newNode;
            par[newNode] = curr;
            curr = newNode;
        }
        return root;
    }
};
