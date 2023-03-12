/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    vector< int > v;
    // TreeNode* insert(TreeNode* root , vector<int>& v, int mid)
    // {
    //     if(root == NULL)
    //     {
    //         TreeNode* f = new TreeNode(v[mid]);
    //         return f ;
    //     }
    // }
    TreeNode* insertBST(vector<int>&v, int l , int r)
    {
        if(l > r)
        {
           return NULL;
        }
        int mid = (l + r) / 2;
        // root = insert(root , v , mid);
        TreeNode* f = new TreeNode(v[mid]);
        f->left = insertBST( v,l , mid - 1);
        f-> right = insertBST(v, mid + 1 , r);
        return f;
    }
    TreeNode* sortedListToBST(ListNode* head)
    {
        while(head != NULL)
        {
            v.push_back(head->val);
            head = head->next;
        }
        return insertBST(v,0, v.size() - 1);
    }
};
