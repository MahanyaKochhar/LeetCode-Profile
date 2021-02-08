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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        int c=0;
        ListNode* head=NULL,*tail=NULL;
        while(l1!=NULL||l2!=NULL)
        {
            
        if(l1==NULL)
        {
            if(head==NULL)
            {
            head=new ListNode(l2->val);
            tail=head;
           
            l2=l2->next;
        }
            else
            {
            ListNode * tmp=new ListNode(l2->val);
                tail->next=tmp;
                tail=tail->next;
                l2=l2->next;
            }
            continue;
        }
        if(l2==NULL)
        {
          if(head==NULL)
            {
            head=new ListNode(l1->val);
            tail=head;
            
            l1=l1->next;
            
        }
            else
            {
              ListNode* tmp=new ListNode(l1->val);
                tail->next=tmp;
                tail=tail->next;
                l1=l1->next;  
            }
            continue;
        }
        if(l1->val>=l2->val)
        {
            if(head==NULL)
            {
            head=new ListNode(l2->val);
            tail=head;
            
            
            l2=l2->next;
            
        }
            else
            {
                ListNode *tmp=new ListNode(l2->val);
                tail->next=tmp;
                tail=tail->next;
                l2=l2->next;
            }
            continue;
        }
        else if(l2->val>l1->val)
        {
           if(head==NULL)
            {
            head=new ListNode(l1->val);
            tail=head;
            
            
            l1=l1->next;
            
        }
            else
            {
               ListNode* tmp=new ListNode(l1->val);
                tail->next=tmp;
                tail=tail->next;
                l1=l1->next;
            }
            continue;
    }}
      return head;  
    }
};
