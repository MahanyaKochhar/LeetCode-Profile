class Solution {
public:
    int minCost(vector<vector<int>>& grid)
    {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        
        vector<vector<int>>d(grid.size(),vector<int>(grid[0].size(),INT_MAX));
        d[0][0] = 0;
        while(!pq.empty())
        {
            pair<int,pair<int,int>>a = pq.top();
            pq.pop();
            int curr = a.first;
            int i = a.second.first;
            int j = a.second.second;
            if(curr != d[i][j])
                continue;
            vector<int>x{0,0,1,-1};
            vector<int>y{1,-1,0,0};
            for(int k = 0 ; k < 4 ; k++)
            {
                int currx = i + x[k];
                int curry = j + y[k];
                if(currx >= 0 && currx < grid.size() && curry >= 0 && curry < grid[0].size())
                {
                    int ch = 0;
                    if(k + 1 == grid[i][j])
                        ch = 0;
                    else
                        ch = 1;
                    if(ch + d[i][j] < d[currx][curry])
                    {
                        d[currx][curry] = ch + d[i][j];
                        pq.push({d[currx][curry],{currx,curry}});
                    }
                }
            }
        }
        return d[grid.size() - 1][grid[0].size() - 1];
    }
};
