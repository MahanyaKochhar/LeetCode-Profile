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
    map<Node*,int>mp1;
    map<int,Node*>mp2;
    Node* head1,*tail1;
    Node* curr,*cpy;
    Node* copyRandomList(Node* head) {
        curr=head;
        listing(head);
        return head1;
    }
        void listing(Node* head)
        {
            int i=0;
        while(head!=NULL)
        {
        if(head1==NULL)
        {
            head1=new Node(head->val);
            mp1[head]=i;

            tail1=head1;
            mp2[i]=tail1;
           i++;
            head=head->next;
            continue;
        }
        Node* temp=new Node(head->val);
        mp1[head]=i;
        mp2[i]=temp;
        tail1->next=temp;
        tail1=tail1->next;
        head=head->next;
        i++;
        
    }
     cpy=head1;
     while(curr!=NULL)
    {
        if(curr->random==NULL)
            cpy->random=NULL;
        else
        {
            int t=mp1[curr->random];
            Node* tempo=mp2[t];
            cpy->random=tempo;

        }
        cpy=cpy->next;
        curr=curr->next;
    } 
}};
