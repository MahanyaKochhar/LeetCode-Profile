class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides)
    {
        using ll = long long;
        auto cmp = [&](const vector<int>& a, const vector<int>&b) -> bool {
            if(a[1] == b[1])
            {
                return a[0] < b[0];
            }
            return a[1] < b[1];
        };
        sort(rides.begin(),rides.end(),cmp);
        vector<ll>dp(rides.size());
        vector<int>ends(rides.size());
        for(int i = 0 ; i < rides.size(); i++)
        {
            ends[i] = rides[i][1];
        }
        dp[0] = rides[0][1] - rides[0][0] + rides[0][2];
        for(int i = 1; i < rides.size(); i++)
        {
            auto it = upper_bound(ends.begin(),ends.end(),rides[i][0]);
            int idx = -1;
            if(it != ends.begin())
            {
                it--;
                idx = it - ends.begin();
            }
            dp[i] = max(dp[i - 1], rides[i][1] - rides[i][0] + rides[i][2] + (idx != -1 ? dp[idx] : 0));
        }
        return dp[rides.size() - 1];
    }
};
