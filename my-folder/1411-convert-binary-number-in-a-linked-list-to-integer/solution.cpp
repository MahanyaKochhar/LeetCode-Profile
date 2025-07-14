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
    int getDecimalValue(ListNode* head)
    {
        string res = "";
        while(head != NULL)
        {
            res.push_back((char)(head->val + '0'));
            head = head->next;
        }
        int ans = 0;
        int curr = 0;
        for(int i = res.length() - 1 ; i >= 0 ; i--)
        {
            ans += pow(2,curr) * (res[i] - '0');
            curr++;
        }
        return ans;
    }
};
