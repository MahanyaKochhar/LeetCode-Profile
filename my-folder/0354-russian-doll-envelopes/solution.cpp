class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes)
    {
        auto cmp = [](const vector<int>& a, const vector<int> &b) -> bool {
            if(a[0] == b[0])
            {
                return a[1] >  b[1];
            }
            return a[0] < b[0];
        };
        sort(envelopes.begin(),envelopes.end(),cmp);
        vector<int>dp(envelopes.size() + 2,INT_MAX);
        dp[0] = INT_MIN;
        for(int i = 0 ; i < envelopes.size(); i++)
        {
            auto it = lower_bound(dp.begin(),dp.end(),envelopes[i][1]);
            int index = it - dp.begin();
            if(dp[index] > envelopes[i][1])
            {
                dp[index] = envelopes[i][1];
            }
        }
        int ans = -1;
        for(int i = 0 ; i < dp.size(); i++)
        {
            if(dp[i] != INT_MAX)
            {
                ans = i;
            }
        }
        return ans;
    }
};
