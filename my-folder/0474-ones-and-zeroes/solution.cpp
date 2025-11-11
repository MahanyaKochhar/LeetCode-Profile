class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n)
    {
        int dp[601][101][101];
        memset(dp,0,sizeof(dp));
        vector<pair<int,int>>cnts;
        for(auto& str : strs)
        {
            int cnt = 0;
            for(int i = 0; i < str.length(); i++)
            {
                if(str[i] == '0')
                {
                    cnt++;
                }
            }
            cnts.push_back({cnt,str.length() - cnt});
        }

        for(int i = 1 ; i <= cnts.size();i++)
        {
            for(int j = 0 ; j <= m ;j++)
            {
                for(int k = 0; k <= n;k++)
                {
                    if(cnts[i - 1].first <= j && cnts[i - 1].second <= k)
                    {
                        dp[i][j][k] = max(1 + dp[i - 1][j - cnts[i - 1].first][k - cnts[i - 1].second],dp[i - 1][j][k]);
                    }
                    else
                    {
                        dp[i][j][k] = dp[i - 1][j][k];
                    }
                }
            }
        }
        int ans = 0;
        for(int j = 0 ; j <= m; j++)
        {
            for(int k = 0 ; k <= n;k++)
            {
                ans = max(ans,dp[cnts.size()][j][k]);
            }
        }
        return ans;
    }
};
