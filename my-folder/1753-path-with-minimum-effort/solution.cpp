class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights)
    {
        vector<vector<int>>d(heights.size(),vector<int>(heights[0].size(),INT_MAX));
        d[0][0] = 0;
        priority_queue<pair<int,pair<int,int>>>pq;
        pq.push({0,{0,0}});
        while(!pq.empty())
        {
            auto x = pq.top();
            pq.pop();
            int curr = -x.first;
            int i = x.second.first;
            int j = x.second.second;
            if(d[i][j] != curr)
                continue;
            vector<int>x1 = {1,-1,0,0};
            vector<int>y1 = {0,0,1,-1};
            for(int k = 0 ; k < x1.size();k++)
            {
                int nx = x1[k] + i;
                int ny = y1[k] + j;
                if(nx >= 0 && nx < heights.size() && ny >= 0 && ny < heights[0].size())
                {
                    int upd = max(curr,abs(heights[nx][ny] - heights[i][j]));
                    if(d[nx][ny] > upd)
                    {
                        d[nx][ny] = upd;
                        pq.push({-upd,{nx,ny}});
                    }
                }
            }
        }
        return d[heights.size() - 1][heights[0].size() - 1];
    }
};
