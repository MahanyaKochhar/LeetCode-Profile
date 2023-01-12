class MyCalendar {
public:
    vector<pair<int,int>>v;
    MyCalendar()
    {
        
    }
    
    bool book(int start, int end)
    {
        int e=0;
        for(int i=0;i<v.size();i++)
        {
            if(start<v[i].second&&end>v[i].first)
            {
                e=1;
                break;
            }
        }
        
        if(e==1)
            return false;
        else
        {
            v.push_back({start,end});
            return true;
        }
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
