class MyCalendarTwo {
public:
    map<int,int>mp;
    MyCalendarTwo() {
        
    }
    bool canAdd(int n)
    {
        int cnt=0;
        for(auto x:mp)
        {
            cnt+=x.second;
            if(cnt>2)
                return false;
        }
        return true;
    }
    bool book(int start, int end)
    {
        mp[start]++;
        mp[end]--;
        if(canAdd(2))
        {
            return true;
        }
        else
        {
            mp[end]++;
            mp[start]--;
            return false;
        }
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
