class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b)
    {
        long long dp[b.size() + 1][5];
        memset(dp,0,sizeof(dp));
        dp[0][1] = -1e11;
        for(int i = 1 ;i <= b.size() ; i++)
        {
            for(int j = 1 ;j <= 4 ; j++)
            {
                if(i >= j)
                {
                    dp[i][j] = max(dp[i - 1][j - 1] + (long long)(b[i - 1]) * (long long)a[j - 1],dp[i - 1][j]);
                }
                else
                {
                    dp[i][j] = -1e11;
                }
            }
        }
        return dp[b.size()][4];
    }
};
