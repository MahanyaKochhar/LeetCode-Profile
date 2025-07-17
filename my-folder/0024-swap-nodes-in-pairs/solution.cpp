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
    ListNode* swapPairs(ListNode* head)
    {
        ListNode* dummy = new ListNode(0,head);
        ListNode* prev = dummy;
        ListNode* lag = head;
        while(lag != NULL && lag->next != NULL)
        {
            ListNode* nx = lag->next->next;
            prev->next = lag->next;
            lag->next->next = lag;
            lag->next = nx;
            prev = lag;
            lag = nx;
        }
        return dummy->next;
    }
};
