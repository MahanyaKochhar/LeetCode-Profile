class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points)
    {
        auto cmp = [&](const vector<int> &a ,const vector<int> &b)
        {
            if(a[0] == b[0])
            {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        };

        int ans = 0;
        sort(points.begin(),points.end(),cmp);
        for(int l = 0 ; l < points.size(); l++)
        {
            int mini = -1e9 - 1;
            for(int r = l + 1 ; r < points.size(); r++)
            {
                if(points[r][1] <= points[l][1])
                {
                    if(points[r][1] > mini)
                    {
                        ans++;
                        mini = points[r][1];
                    }
                }

            }
        }
        return ans;
    }
};
