const int mod = 1e9 + 7;
class Solution {
public:
    int count(string num1, string num2, int min_sum, int max_sum)
    {
        auto digit_dp = [&](string num2)->int
        {
        int dp[num2.length() + 1][2][401];
        memset(dp,0,sizeof(dp));
        for(int j = 0 ; j < 10 ; j++)
        {
            if(num2[0] - '0' > j)
                dp[1][0][j] = 1;
            else if(num2[0] - '0' == j)
                dp[1][1][j] = 1;
        }
        for(int i = 2; i <= num2.length() ; i++)
        {
            for(int j = 0 ; j < 10 ; j++)
            {
                if(num2[i - 1] - '0' > j)
                {
                    for(int k = 0 ; k <= 400 ;k++)
                    {
                        if(k >= j)
                            dp[i][0][k] = (dp[i][0][k] + (dp[i - 1][0][k - j] + dp[i - 1][1][k - j]) % mod) % mod;
                    }
                    
                }
                else if(num2[i - 1] - '0' == j)
                {
                    for(int k = 0 ; k <= 400 ; k++)
                    {
                        if(k >= j)
                        {
                            dp[i][1][k] = (dp[i][1][k] + dp[i - 1][1][k - j]) % mod;
                            dp[i][0][k] = (dp[i][0][k] + dp[i - 1][0][k - j]) % mod;
                        }
                    }
                    
                }
                else
                {
                    for(int k =0 ;k <=400 ;k++)
                    {
                        if(k >= j)
                            dp[i][0][k] = (dp[i][0][k] + dp[i - 1][0][k - j])  % mod;
                    }
                   
                }
            }
        }
        int ans = 0;
        for(int k = min_sum ; k <= max_sum ; k++)
        {
            if(num2 != num1)
                ans = (ans + (dp[num2.length()][0][k] + dp[num2.length()][1][k]) % mod ) % mod ;
            else
                ans = (ans + dp[num2.length()][0][k]) % mod;
        }
        return ans;
    };
        return (digit_dp(num2) - digit_dp(num1) + mod) % mod;
    }
    
};
