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
    ListNode* removeNodes(ListNode* head)
    {
        deque<pair<int,ListNode*>>q;
        ListNode* fin=NULL;
        while(head!=NULL)
        {
            int val1=head->val;
            while(!q.empty()&&q.back().first<val1)
            {
                q.pop_back();
            }
            q.push_back({val1,head});
            head=head->next;
        }
        ListNode* ans=NULL;
        while(!q.empty())
        {
            int v=q.front().first;
            ListNode* ptr=q.front().second;
            q.pop_front();
            if(fin==NULL)
            {
                ans=ptr;
                fin=ptr;
                fin->val=v;
            }
            else
            {
                fin->next=ptr;
                fin=fin->next;
                fin->val=v;
            }
        }
        return ans;
    }
};
