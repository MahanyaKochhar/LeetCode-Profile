class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s)
    {
        string st = to_string(start - 1);
        string end = to_string(finish);
        auto countInRange = [&] (string curr) -> long long {
            int idx = curr.length() - s.length();
            if(idx < 0)
            {
                return 0;
            }
            long long int dp[17][2];
            memset(dp,0,sizeof(dp));
            for(int i = 0 ; i <= 9 ; i++)
            {
                if(i > limit)
                {
                    continue;
                }
                else if(i < (curr[0] - '0'))
                {
                    if((idx == 0 && s[0] - '0' == i) || idx > 0)
                        dp[0][0] += 1;
                }
                else if(i == (curr[0] - '0'))
                {
                    if((idx == 0 && s[0] - '0' == i) || idx > 0)
                        dp[0][1] += 1;
                }
            }
            for(int i = 1 ; i < curr.length();i++)
            {
                for(int j = 0 ; j <= 9 ; j++)
                {
                    if(j > limit)
                    {
                        continue;
                    }

                    if(j < curr[i] - '0')
                    {
                        if((idx <= i && s[i - idx] - '0' == j) || idx > i)
                            dp[i][0] += dp[i - 1][0] + dp[i - 1][1];
                    }
                    else if(j == curr[i] - '0')
                    {
                        if((idx <= i && s[i -idx] - '0' == j) || idx > i)
                        {
                            dp[i][0] += dp[i - 1][0];
                            dp[i][1] += dp[i - 1][1];
                        }
                    }
                    else
                    {
                        if((idx <= i && s[i - idx] - '0' == j) || idx > i)
                            dp[i][0] += dp[i - 1][0];
                    }
                }
            }
            return dp[curr.length() - 1][0] + dp[curr.length() - 1][1];
        };

        return countInRange(end) - countInRange(st);
    }
};
