class MedianFinder {
public:
    priority_queue<int>left;
    priority_queue<int>right;

    MedianFinder()
    {
        
    }

    void stabilize()
    {
        if(left.size() > right.size())
        {
            while(left.size() - right.size() > 1)
            {
                int t = left.top();
                left.pop();
                right.push(-t);
            }
        }
        else
        {
            while(right.size() - left.size() > 1)
            {
                int t = right.top();
                right.pop();
                left.push(-t);
            }
        }
    }
    
    void addNum(int num)
    {
        if(left.empty())
        {
            left.push(num);
        }
        else
        {
            if(left.top() > num)
            {
                left.push(num);
            }
            else
            {
                right.push(-num);
            }
        }
        int lsize = left.size();
        int rsize = right.size();
        int diff = abs(lsize - rsize);
        if(diff > 1)
            stabilize();
    }
    
    double findMedian()
    {
        if(left.size() == right.size())    
        {
            return (double)(left.top() + -right.top()) / 2;
        }
        else
        {
            if(left.size() > right.size())
            {
                return (double)left.top();
            }
            else
            {
                return (double)-right.top();
            }
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
