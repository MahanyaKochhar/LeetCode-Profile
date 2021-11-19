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
    ListNode* rotateRight(ListNode* head, int k)
    {
        ListNode* temp=head,*temp2=head;
        int cnt=0;
        ListNode* st=NULL;
        
        while(temp!=NULL)
        {
            cnt++;
            temp=temp->next;
        }
        if(cnt==0)
            return NULL;
        int no=k%cnt;
        if(no==0)
            return head;
        int idx=0;
        while(true)
        {
            if(no+idx+1==cnt)
            {
                 st=temp2->next;
                temp2->next=NULL;
                break;
            }
            temp2=temp2->next;
            idx++;
        }
        ListNode* fin=st;
        while(true)
        {
            if(fin->next==NULL)
            {
                fin->next=head;
                break;
            }
            fin=fin->next;
            
        }
        return st;
        
    }
};
