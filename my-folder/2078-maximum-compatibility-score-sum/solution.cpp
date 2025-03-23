class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors)
    {
        int m = students.size();
        vector<vector<int>>dp(1 << m, vector<int>(1 << m,-1));
        dp[0][0] = 0;
        auto compatibility = [&] (int i, int j) -> int {
            int cnt = 0;
            for(int k = 0 ; k < students[i].size();k++)
            {
                cnt += ((students[i][k] == mentors[j][k]) ? 1 : 0);
            }
            return cnt;
        };
        for(int i = 0 ; i < (1 << m);i++)
        {
            for(int j = 0 ; j < (1 << m);j++)
            {
                for(int k = 0 ; k < m ; k++)
                {
                    for(int l = 0 ; l < m;l++)
                    {
                        if((i & (1 << k)) && (j & (1 << l)))
                        {
                            int cnt = compatibility(k,l);
                            dp[i][j] = max(dp[i][j], cnt + dp[i ^ (1 << k)][j ^ (1 << l)]);
                        }
                    }
                }
            }
        }
        return dp[(1 << m) - 1][(1 << m) - 1];
    }
};
