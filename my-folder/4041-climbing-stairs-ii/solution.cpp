class Solution {
public:
    int climbStairs(int n, vector<int>& costs)
    {
        using ll = long long;
        vector<ll>dp(n + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 1 ; i <= n ; i++)
        {
            if(i - 1 >= 0)
            {
                dp[i] = min(dp[i],(ll)costs[i - 1] + dp[i - 1] + 1);
            }
            if(i - 2 >= 0)
            {
                dp[i] = min(dp[i],(ll)costs[i - 1] + dp[i - 2] + 4);
            }
            if(i - 3 >= 0)
            {
                dp[i] = min(dp[i],(ll)costs[i - 1] + dp[i - 3] + 9);
            }
        }
        return (int)dp[n];
    }
};
