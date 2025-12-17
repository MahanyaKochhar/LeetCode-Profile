class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int ans = 0;
        int curr = prices[0];
        for(int j = 1 ; j < prices.size() ; j++)
        {
            if(prices[j] > prices[j - 1])
            {
                continue;
            }
            else
            {
                ans +=  prices[j - 1] - curr;
                curr = prices[j];
            }
        }
        ans +=  prices[prices.size() - 1] - curr;
        return ans;
    }
};
