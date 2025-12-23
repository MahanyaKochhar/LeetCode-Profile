class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events)
    {
        int ans = 0;
        vector<int>endS;
        vector<int>pre;
        int maxi = -1;
        auto cmp = [&](vector<int>& a, vector<int>& b) -> bool {
            if(a[1] == b[1])
            {
                return a[0] < b[0];
            }
            else
            {
                return a[1] < b[1];
            }
        };
        sort(events.begin(), events.end(), cmp);
        for(int i = 0 ; i < events.size() ; i++)
        {
            endS.push_back(events[i][1]);
            pre.push_back(max(maxi,events[i][2]));
            maxi = max(maxi,events[i][2]);
        }
        for(int i = 0 ; i < events.size() ; i++)
        {
            auto it = lower_bound(endS.begin(),endS.end(),events[i][0]);
            if(it == endS.begin())
            {
                ans = max(ans,events[i][2]);
            }
            else
            {
                it--;
                int idx = it - endS.begin();
                ans = max(ans,events[i][2] + pre[idx]);
            }
        }
        return ans;
    }
};
