class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k)
    {
        using ll = long long;
        vector<ll>pre(prices.size(),0);
        pre[0] = prices[0] * strategy[0];
        for(int i = 1 ; i < pre.size() ; i++)
        {
            pre[i] = pre[i - 1] + (strategy[i] * prices[i]);
        }
        ll profit = pre[pre.size() - 1];
        ll curr = 0;
        for(int i = (k / 2) ; i < k ; i++)
        {
            curr += prices[i];
        }
        profit = max(profit,curr + pre[pre.size() - 1] - pre[k - 1]);
        for(int i = k ; i < pre.size() ; i++)
        {
            curr += prices[i];
            curr -= prices[i - (k / 2)];
            profit = max(profit,curr + pre[i - k] + pre[pre.size() - 1] - pre[i]);
        }
        return profit;
    }
};
