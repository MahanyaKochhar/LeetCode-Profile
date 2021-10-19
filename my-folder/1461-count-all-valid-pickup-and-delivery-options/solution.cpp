class Solution {
public:
    int countOrders(int n)
    {
        const long long int mod=1e9+7;
        long long int dp[501];
        dp[1]=1;
        for(int j=2;j<=n;j++)
        {
            dp[j]=(dp[j-1]*(2*j)*(2*j-1)/2)%mod;
        }
        return dp[n];
    }
};
