class Solution {
public:
    ListNode* oddEvenList(ListNode* head)
    {
    	if(head==NULL)
    		return NULL;
        ListNode* odd=head;
        ListNode* tmp1=odd;
        ListNode* even=head->next;
        ListNode* tmp2=even;
        if(even==NULL)
        	return head;
        while(true)
        {
	        tmp1->next=tmp1->next->next;
            if(tmp1->next!=NULL)
	        	tmp1=tmp1->next;
	        else
	        	break;
	        tmp2->next=tmp2->next->next;
	       
	        if(tmp2->next!=NULL)
	        	 tmp2=tmp2->next;
	        else
	        	break;
	    }
	    tmp1->next=even;
	    return odd;


    }
};
