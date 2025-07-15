class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals)
    {
        auto cmp = [] (const vector<int>&a , const vector<int>& b) -> bool {
            if(a[1] == b[1])
            {
                return a[0] < b[0];
            }
            return a[1] < b[1];
        };
        sort(intervals.begin(),intervals.end(),cmp);
        vector<int>endI;
        for(auto& x : intervals)
        {
            endI.push_back(x[1]);
        }
        vector<int>dp(intervals.size(),1);
        dp[0] = 1;
        int fin = 0;
        for(int i = 1 ; i < intervals.size();i++)
        {
            dp[i] = dp[i - 1];
            auto it = upper_bound(endI.begin(),endI.end(),intervals[i][0]);
            if(it == endI.begin())
            {
                continue;
            }
            it--;
            int idx = it - endI.begin();
            dp[i] = max(dp[i - 1],dp[idx] + 1);
        }
        return intervals.size() - dp[intervals.size() - 1];
    }
};
