class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points)
    {
        vector<pair<int,int>>pa;
        for(int i=0;i<points.size();i++)
        {
            pa.push_back({points[i][0],points[i][1]});
        }
        sort(pa.begin(),pa.end());
        int lmax=pa[0].first;
        int rmin=pa[0].second;
        int cnt=1;
        for(int i=1;i<pa.size();i++)
        {
            if(pa[i].first>rmin)
            {
                cnt++;
                lmax=pa[i].first;
                rmin=pa[i].second;
            }
            else
            {
                lmax=max(lmax,pa[i].first);
                rmin=min(rmin,pa[i].second);
            }
        }
        return cnt;
    }
};
