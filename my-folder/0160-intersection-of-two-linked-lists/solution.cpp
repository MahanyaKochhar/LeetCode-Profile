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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *currA = headA;
        ListNode *currB = headB;
        int cntA = 0,cntB = 0;
        while(currA != NULL)
        {
            cntA++;
            currA = currA->next;
        }
        while(currB != NULL)
        {
            cntB++;
            currB = currB->next;
        }
        if(cntA >= cntB)
        {
            int diff = cntA - cntB;
            while(diff != 0)
            {
                headA = headA->next;
                diff--;
            }
        }
        else
        {
            int diff = cntB - cntA;
            while(diff != 0)
            {
                headB = headB->next;
                diff--;
            }
        }

        while(headA != NULL && headB != NULL)
        {
            if(headA == headB)
            {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};
