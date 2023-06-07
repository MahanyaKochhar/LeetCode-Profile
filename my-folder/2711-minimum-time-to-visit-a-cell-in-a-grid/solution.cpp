class Solution {
public:
    int minimumTime(vector<vector<int>>& grid)
    {
        vector<vector<int>>d(grid.size(),vector<int>(grid[0].size()));
        for(int i = 0 ; i < grid.size() ; i++)
        {
            for(int j = 0 ; j < grid[i].size() ; j++)
            {
                d[i][j] = INT_MAX;
            }
        }
        // d[0][0] = 0;
        priority_queue< pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq;
        if(grid[0][1] <= 1)
        {
            pq.push({1,{0,1}});
            d[0][1] = 1;
        }
        if(grid[1][0] <= 1)
        {
            pq.push({1,{1,0}});
            d[1][0] = 1;
        }
        while(!pq.empty())
        {
            pair<int,pair<int,int>>p = pq.top();
            int a = p.first;
            int b = p.second.first;
            int c = p.second.second;
            if(d[b][c] != a)
                continue;
            pq.pop();
            vector<int>x{-1,1,0,0};
            vector<int>y{0,0,1,-1};
            for(int i = 0 ; i < 4 ;i++)
            {
                int currx = b + x[i];
                int curry = c + y[i];
                if(currx >=0 && currx < grid.size() && curry >= 0 && curry < grid[0].size())
            {
                int curr = a, req = grid[currx][curry];
                if(a + 1 >= req)
                {
                    // d[currx][curry] = d[b][c] + 1;
                    if(a + 1 < d[currx][curry])
                    {
                        d[currx][curry] = a + 1;
                        pq.push({a + 1,{currx,curry}});
                    }
                }
                else
                {
                    if(curr % 2 == req % 2)
                    {
                        if(req + 1 < d[currx][curry])
                        {
                            d[currx][curry] = req + 1;
                            pq.push({req + 1, {currx,curry}});
                        }
                        
                    }
                    else
                    {
                        if(req < d[currx][curry])
                        {
                            d[currx][curry] = req;
                            pq.push({req,{currx,curry}});
                        }
                    }
                }
            }
            }
        }
        if(d[grid.size() - 1][grid[0].size() - 1] == INT_MAX)
            return -1;
        else
            return d[grid.size() - 1][grid[0].size() - 1];
    }
};
