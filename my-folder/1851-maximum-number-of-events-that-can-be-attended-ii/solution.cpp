class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k)
    {
        auto cmp = [](const vector<int> &a, const vector<int> &b) -> bool {
            if(a[1] == b[1])
            {
                return a[0] < b[0];
            }
            return a[1] < b[1];
        };
        sort(events.begin(),events.end(),cmp);
        vector<int>endTimes;
        for(auto& x : events)
        {
            endTimes.push_back(x[1]);
        }
        vector<vector<int>>dp(events.size(),vector<int>(k,0));
        dp[0][0] = events[0][2];
        for(int i = 1 ; i < k ; i++)
        {
            dp[0][i] = events[0][2];
        }
        for(int i = 1; i < events.size() ; i++)
        {
            dp[i][0] = max(dp[i - 1][0],events[i][2]);
            auto it = lower_bound(endTimes.begin(),endTimes.end(),events[i][0]);
            int idx = -1;
            if(it != endTimes.begin())
            {
                it--;
                idx = it - endTimes.begin();
            }
            for(int j = 1 ; j < k ; j++)
            {
                dp[i][j] = max(dp[i - 1][j],events[i][2] + (idx != -1 ? dp[idx][j - 1] : 0));
            }
        }
        return dp[events.size() - 1][k - 1];
        // int ans = 0;
        // for(int i = 0 ; i < k ;i++)
        // {
        //     ans = max(ans,dp[events.size() - 1][i]);
        // }
        // return ans;
    }
};
