class Solution {
public:
    int longestValidParentheses(string s)
    {
        stack<int>s1;
        int dp[s.length() + 1];
        memset(dp, 0 , sizeof(dp));
        for(int i = 0 ; i < s.length() ; i++)
        {
            if(s[i] == ')')
            {
                if(s1.empty())
                    dp[i] = 0;
                else
                {
                    int j = s1.top();
                    s1.pop();
                    if(j - 1 >= 0)
                        dp[i] = dp[j - 1] + (i - j + 1);
                    else
                        dp[i] = (i - j + 1);
                }
            }
            else
            {
                s1.push(i);
            }
        }
        int ans = 0;
        for(int i = 0 ; i < s.length() ; i++)
            ans = max(ans, dp[i]);
        return ans;
    }
};
