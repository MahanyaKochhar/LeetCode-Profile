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
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        ListNode* head = NULL, *tmp;
        priority_queue<pair< int , ListNode*>> pq;
        for(int i = 0 ; i < lists.size() ; i++)
        {
            if(lists[i] != NULL)
            {
                pq.push({-lists[i]->val,lists[i]});
            }
        }
        while(!pq.empty())
        {
            pair<int, ListNode*> p = pq.top();
            pq.pop();
            if(p.second->next != NULL)
                pq.push({-p.second->next->val, p.second->next});
            if(head == NULL)
            {
                head = p.second;
                tmp = p.second;
            }
            else
            {
                tmp ->next = p.second;
                tmp = tmp->next;
            }

        }
        tmp->next = NULL;
        return head;
    }
};
