class StockSpanner {
public:
    vector<int>ans;
    vector<int>prices;
    int curr;
    StockSpanner(){
        curr=0;
        
    }
    
    int next(int price)
    {
        
        prices.push_back(price);
        
        if(prices.size()==1)
        {
            ans.push_back(1);
            curr++;
            return 1;
        }
        int ch=curr-1;
         if(prices[curr]>=prices[ch])
        {
             while(ch>=0&&prices[curr]>=prices[ch])
             {
            ch=ch-ans[ch];
             }
             ans.push_back(curr-ch);
             curr++;
             return curr-1-ch;
        }
        else
        {
            ans.push_back(1);
            curr++;
            return 1;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
