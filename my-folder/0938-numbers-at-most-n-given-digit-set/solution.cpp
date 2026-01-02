class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n)
    {
        vector<int>d;
        while(n != 0)
        {
            d.push_back(n % 10);
            n = n / 10;
        }
        reverse(d.begin(),d.end());
        vector<vector<int>>dp(d.size(),vector<int>(2,0));
        for(int i = 0 ; i < digits.size() ; i++)
        {
            if(stoi(digits[i]) < d[0])
            {
                dp[0][0] += 1;
            }
            else if(stoi(digits[i]) == d[0])
            {
                dp[0][1] += 1;
            }
        }
        dp[0][0] += 1;
        for(int i = 1 ; i < d.size() ; i++)
        {
            for(int j = 0 ; j < digits.size() ; j++)
            {
                if(stoi(digits[j]) < d[i])
                {
                    dp[i][0] += dp[i - 1][0] + dp[i - 1][1];
                }
                else if(stoi(digits[j]) == d[i])
                {
                    dp[i][1] += dp[i - 1][1];
                    dp[i][0] += dp[i - 1][0];
                }
                else
                {
                    dp[i][0] += dp[i - 1][0];
                }
            }
            dp[i][0] += 1;
        }
        return dp[d.size() - 1][0] - 1 + dp[d.size() - 1][1];
    }
};
