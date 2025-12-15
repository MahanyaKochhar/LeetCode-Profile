class Solution {
public:
    long long getDescentPeriods(vector<int>& prices)
    {
        using ll = long long;
        ll ans = 1;
        int l = 0;
        for(int r = 1 ; r < prices.size(); r++)
        {
            if(prices[r] + 1 == prices[r - 1])
            {
                ans += (r - l + 1);
            }
            else
            {
                l = r;
                ans += (r - l + 1);
            }
        }
        return ans;
    }
};
