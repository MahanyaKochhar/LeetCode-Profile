class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int s = 0, e = 0;
        int ans = 0;
        for(int i = 1 ; i < prices.size(); i++)
        {
            if(prices[i] > prices[i - 1])
            {
                e = i;
            }
            else
            {
                ans += prices[e] - prices[s];
                s = i;
                e = i;

            }
        }
        ans += prices[e] - prices[s];
        return ans;
        
    }
};
