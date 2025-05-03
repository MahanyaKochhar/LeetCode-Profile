class StockSpanner {
public:
    stack<pair<int,int>>s;
    StockSpanner()
    {
        
    }

    int next(int price)
    {
        int cnt = 0;
        while(!s.empty() && price >= s.top().first)
        {
            int delCnt = s.top().second;
            cnt += delCnt + 1;
            s.pop();
        }
        s.push({price,cnt});
        return cnt + 1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
