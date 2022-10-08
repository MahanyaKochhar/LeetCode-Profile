class MedianFinder {
public:
    priority_queue<int>p;
    priority_queue<int,vector<int>,greater<int>>q;
    MedianFinder()
    {
        
    }
    
    void addNum(int num)
    {
        if(p.size()==0)
            p.push(num);
        else if(num>=p.top())
        {
            q.push(num);
            if(q.size()-p.size()==2)
            {
                int x=q.top();
                q.pop();
                p.push(x);
            }
        }
        else
        {
            p.push(num);
            if(p.size()-q.size()==2)
            {
                int x=p.top();
                p.pop();
                q.push(x);
            }
        }
            
    }
    
    double findMedian()
    {
        if(p.size()==q.size())
        {
            double fin=double(p.top()+double(q.top()))/2;
            return fin;
        }
        else
            return (p.size()>q.size()? p.top():q.top());
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
