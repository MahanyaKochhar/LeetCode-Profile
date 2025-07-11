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
        ListNode *lag = head;
        ListNode *lead = head;
        ListNode *prev = NULL;
        int cnt = 0;
        while(cnt != n)
        {
            cnt++;
            lead = lead->next;
        }
        while(lead != NULL)
        {
            lead = lead->next;
            prev = lag;
            lag = lag->next;
        }
        if(prev != NULL)
        {
            prev->next = lag->next;
        }
        else
        {
            head = lag->next;
        }
        return head;
    }
};
