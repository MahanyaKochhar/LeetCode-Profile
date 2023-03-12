class Solution {
public:
    int findIntegers(int n)
    {
        string s = "";
        while(n != 0)
        {
            if(n & 1)
                s.push_back('1');
            else
                s.push_back('0');
            n = n / 2;
        }
        reverse(s.begin() , s.end());
        int dp[s.length() + 1][2][2];
        memset(dp , 0 ,sizeof(dp));
        dp[1][0][0] = 1;
        dp[1][1][1] = 1;
        for(int i = 2 ; i <= s.length() ; i++)
        {
                if(s[i - 1] - '0' == 0)
                {
                    dp[i][1][0] = dp[i-1][1][0] + dp[i-1][1][1];
                    dp[i][0][0] = dp[i-1][0][0] + dp[i-1][0][1];
                    dp[i][0][1] = dp[i-1][0][0];
                }
                else
                {
                    dp[i][1][1] = dp[i-1][1][0];
                    dp[i][0][1] = dp[i-1][0][0];
                    dp[i][0][0] = dp[i-1][1][0] +dp[i-1][1][1] + dp[i-1][0][0] + dp[i-1][0][1];
                }
        }
        return dp[s.length()][0][0] + dp[s.length()][0][1] + dp[s.length()][1][0] + dp[s.length()][1][1] ;
    }
};
