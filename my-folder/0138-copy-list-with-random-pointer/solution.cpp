/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head)
    {
        Node* dummy = new Node(0);
        Node* prev = dummy;
        Node* curr = head;
        map<Node*,Node*>mp;
        while(curr != NULL)
        {
            Node* newNode = new Node(curr->val);
            mp[curr] = newNode;
            newNode->random = curr;
            prev->next = newNode;
            prev = newNode;
            curr = curr->next;
        }
        Node* newCurr = dummy->next;
        while(newCurr != NULL)
        {
            newCurr->random  = mp[newCurr->random->random];
            newCurr = newCurr->next;
        }
        return dummy->next;
    }
};
