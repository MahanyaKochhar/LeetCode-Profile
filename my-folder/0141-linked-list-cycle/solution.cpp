/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    map<ListNode*,bool>mp;
    bool hasCycle(ListNode *head) {
         if(head==NULL)
            return false;
        if(!mp[head])
        {
            mp[head]=true;
            return hasCycle(head->next);
        }
        else
            return true;
           
        
        
        
    }
};
