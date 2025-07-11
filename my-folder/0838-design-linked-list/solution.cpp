class Node
{
    public:
    int val;
    Node* next;
    Node(int value,Node* nx)
    {
        val = value;
        next = nx;
    }
};

class MyLinkedList
{
public:
    Node* head;
    MyLinkedList() {
        head = NULL;
    }
    
    int get(int index)
    {
        Node* curr = head;
        while(index != 0 && curr != NULL)
        {
            index--;
            curr = curr->next;
        }
        if(index == 0 && curr != NULL)
        {
            return curr->val;
        }
        else
        {
            return -1;
        }
    }
    
    void addAtHead(int val)
    {
        Node* newNode = new Node(val,head);
        head = newNode;
        cout << head->val;
    }
    
    void addAtTail(int val)
    {
        Node* curr = head;
        Node* prev = NULL;
        while(curr != NULL)
        {
            prev = curr;
            curr = curr->next;
        }
        if(prev == NULL)
        {
            addAtHead(val);
        }
        else
        {
            Node* newNode = new Node(val,NULL);
            prev->next = newNode;
        }
    }
    
    void addAtIndex(int index, int val)
    {
        Node* curr = head;
        Node* prev = NULL;
        while(index != 0 && curr != NULL)
        {
            prev = curr;
            curr = curr->next;
            index--;
        }
        if(index == 0 && curr != NULL)
        {
            if(prev == NULL)
            {
                addAtHead(val);
            }
            else
            {
                Node* newNode = new Node(val,curr);
                prev->next = newNode;
            }
        }
        else if(index == 0 && curr == NULL)
        {
            addAtTail(val);
        }
    }
    
    void deleteAtIndex(int index)
    {
        Node* curr = head;
        Node* prev = NULL;
        while(index != 0 && curr != NULL)
        {
            prev = curr;
            curr = curr->next;
            index--;
        }
        if(index == 0 && curr != NULL)
        {
            if(prev == NULL)
            {
                head = head->next;
            }
            else
            {
                prev->next = curr->next;
            }
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
