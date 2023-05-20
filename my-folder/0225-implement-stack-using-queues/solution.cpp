class MyStack {
public:
    queue<int> q1, q2;
    MyStack()
    {
        
    }
    void push(int x)
    {
        q1.push(x);
    }
    
    int pop()
    {
        int x = q1.size();
        int i = 0;
        while(i < x - 1)
        {
            q2.push(q1.front());
            q1.pop();
            i++;
        }
        int ans = q1.front();
        q1.pop();
        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        return ans;
    }
    int top()
    {
        int x = q1.size();
        int i = 0;
        while(i < x - 1)
        {
            q2.push(q1.front());
            q1.pop();
            i++;
        }
        int ans = q1.front();
        cout << i;
        q1.pop();
        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        q1.push(ans);
        return ans;
    }
    bool empty()
    {
        if(!q1.empty())
            return false;
        else
            return true;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
