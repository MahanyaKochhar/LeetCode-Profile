class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
       vector<bool>dp(s.length() + 1, false);
       dp[0] = true;
       set<string>st;
       for(auto x: wordDict)
       {
            st.insert(x);
       }
       for(int i = 1; i <= s.length() ;i++)
       {
        for(int j = i ; j >= 1 ; j--)
        {
            string tmp = s.substr(j - 1, i - 1 - (j - 1) + 1);
            if(st.contains(tmp))
            {
                dp[i] = dp[i] | dp[j - 1];
            }
        }
       }
       return dp[s.length()];
    }
};
