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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* ptr1=head,*ptr2=NULL,*ptr3=NULL;
        int cnt=0;
        while(ptr1!=NULL)
        {
            cnt++;
            if(ptr2!=NULL)
                ptr2=ptr2->next;
            if(ptr3!=NULL)
                ptr3=ptr3->next;
            ptr1=ptr1->next;
            if(cnt==n)
                ptr2=head;
            if(cnt==n+1)
            ptr3=head;
            
            
        }
        if(ptr3!=NULL)
        ptr3->next=ptr2->next;
            else
                head=ptr2->next;
        return head;
    }
};
