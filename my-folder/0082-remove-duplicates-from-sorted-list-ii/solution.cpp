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
    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode *curr = NULL;
        ListNode *ans = NULL;
        if(head == NULL)
        {
            return head;
        }
        ListNode *lag = head;
        ListNode *lead = head;
        while(lead != NULL)
        {
            while(lead != NULL && lead->val == lag->val)
            {
                lead = lead->next;
            }
            if(lag->next == lead)
            {
                if(ans == NULL)
                {
                    ans = lag;
                    curr = lag;
                }
                else
                {
                    curr->next = lag;
                    curr = lag;
                }
                lag = lag->next;
            }
            else
            {
                lag = lead;
            }
        }
        if(curr != NULL)
            curr->next = NULL;
        return ans;


    }
};
