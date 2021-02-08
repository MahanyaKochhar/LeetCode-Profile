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
class Solution {
public:
    map<int,int>mp;
    ListNode* deleteDuplicates(ListNode* head) {
    countind(head);
    ListNode* l4=NULL,*l5=NULL;
    for(auto x:mp)
    {
    if(x.second==1)
    {
    if(l4==NULL)
    {
    l4=new ListNode(x.first);
    l5=l4;
    }
    else
    {
    ListNode* tmp=new ListNode(x.first);
    l5->next=tmp;
    l5=l5->next;
    }

    }
    }
    return l4;
    }


       void countind(ListNode* head) 
       {
       if(head==NULL)
        return;
        mp[head->val]++;
        deleteDuplicates(head->next);
    }
};
