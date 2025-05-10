class Solution {
public:
    int numDecodings(string s)
    {
        vector<int>dp(s.length() + 1,0);
        dp[0] = 1;
        if(s[0] != '0')
        {
            dp[1] += dp[0];
        }
        for(int i = 2 ; i <= s.length();i++)
        {
            if(s[i - 1] != '0')
            {
                dp[i] += dp[i - 1];
            }
            if(s[i - 2] != '0')
            {
                string tmp = "";
                tmp.push_back(s[i - 2]);
                tmp.push_back(s[i - 1]);
                int x = stoi(tmp);
                if(x <= 26)
                {
                    dp[i] += dp[i - 2];
                }
            }
        }
        return dp[s.length()];
    }
};
