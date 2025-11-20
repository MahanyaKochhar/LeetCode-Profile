class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals)
    {
        auto cmp = [](const vector<int>&a,const vector<int>&b) -> bool {
            if(a[1] == b[1])
            {
                return a[0] <= b[0];
            }
            return a[1] < b[1];
        };
        sort(intervals.begin(),intervals.end(),cmp);
        set<int>st;
        for(int i = 0 ; i < intervals.size(); i++)
        {
            int l = intervals[i][0];
            int r = intervals[i][1];
            int cnt = 0;
            for(auto& x : st)
            {
                if(l <= x && r >= x)
                {
                    cnt++;
                }
            }
            if(cnt >= 2)
            {
                continue;
            }
            else
            {
                while(cnt < 2)
                {
                    int sz = st.size();
                    st.insert(r);
                    r--;
                    if(st.size() > sz)
                        cnt++;
                }
            }
        }
        
        return st.size();
    }
};
