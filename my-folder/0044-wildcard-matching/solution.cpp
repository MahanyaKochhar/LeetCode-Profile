class Solution {
public:
    bool isMatch(string s, string p)
    {
        bool dp[s.length() + 1][p.length() + 1];
        memset(dp, false , sizeof(dp));
        dp[0][0] = true;
        for(int i = 0 ; i < p.length() && p[i] == '*' ; i++)
            dp[0][i + 1] = true;
        for(int i = 1 ; i <= s.length() ; i++)
        {
            for(int j = 1 ; j <= p.length() ; j++)
            {
                if(p[j - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else if(p[j - 1] == '*')
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                else 
                {
                    if(p[j - 1] == s[i - 1])
                        dp[i][j] = dp[i - 1][j - 1];
                    else 
                        dp[i][j] = false;
                }
            }
        }
        return dp[s.length() ][p.length()];
        
    }
};
