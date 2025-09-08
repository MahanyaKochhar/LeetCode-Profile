class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime)
    {
        int dp[(1 << 14)][16];
        for(int i = 0 ; i < (1 << 14);i++)
        {
            for(int j = 0 ; j < 16;j++)
            {
                dp[i][j] = 1e9;
            }
        }
        dp[0][sessionTime] = 1;
        for(int i = 0 ; i < (1 << tasks.size()); i++)
        {
            for(int j = 0 ; j < tasks.size();j++)
            {
                if(i & (1 << j))
                {
                    for(int k = 0 ; k <= sessionTime; k++)
                    {
                        if(tasks[j] <= k)
                        {
                            dp[i][k - tasks[j]] = min(dp[i ^ (1 << j)][k],dp[i][k - tasks[j]]);
                        }
                        else
                        {
                            dp[i][sessionTime - tasks[j]] = min(dp[i][sessionTime - tasks[j]],dp[i ^ (1 << j)][k] + 1);
                        }
                    }
                }
            }
        }
        int ans = 1e9 + 10;
        for(int i = 0 ; i <= sessionTime; i++)
        {
            ans = min(ans,dp[(1 << tasks.size()) - 1][i]);
        }
        return ans;
    }
};
