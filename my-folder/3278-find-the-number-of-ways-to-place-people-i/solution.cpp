class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points)
    {
        int ans = 0;
        auto cmp = [&](const vector<int>&a,const vector<int>&b) -> bool
        {
            if(a[0] == b[0])
            {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        };
        sort(points.begin(),points.end(),cmp);
        for(int i = 0 ; i < points.size();i++)
        {
            for(int j = i + 1 ; j < points.size(); j++)
            {
                if(points[j][1] <= points[i][1])
                {
                    int e = 0;
                    for(int k = i + 1 ; k < j ; k++)
                    {
                        if(points[k][1] >= points[j][1] && points[k][1] <= points[i][1])
                        {
                            e = 1;
                            break;
                        }
                    }
                    if(e == 0)
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
