class Solution {
public:
    bool good(int m, vector<vector<int>>& grid)
    {
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>t(grid.size(),vector<int>(grid[0].size(), INT_MAX));
        for(int i = 0 ; i < grid.size() ; i++)
        {
            for(int j = 0 ; j < grid[i].size() ; j++)
            {
                if(grid[i][j] == 1)
                {
                    t[i][j] = 0;
                    q.push({i,{j,0}});
                }
            }
        }
        while(!q.empty())
        {
            pair<int,pair<int,int>> a = q.front();
            q.pop();
            int x = a.first;
            int y = a.second.first;
            int time = a.second.second;
            int mov_x[4] = {0,0,1,-1};
            int mov_y[4] ={1,-1,0 ,0};
            for(int k = 0 ; k < 4 ; k++)
            {
                int curr_x = x + mov_x[k];
                int curr_y = y + mov_y[k];
                if(curr_x >=0 && curr_x < grid.size() && curr_y >= 0 && curr_y < grid[0].size() && grid[curr_x][curr_y] == 0)
                {
                    if(t[curr_x][curr_y] > time + 1)
                    {
                        t[curr_x][curr_y] = time + 1;
                        q.push({curr_x,{curr_y, time + 1}});
                    }
                }
            }
        }
        queue<pair<int,pair<int,int>>>q1;
        bool vis[grid.size()][grid[0].size()];
        memset(vis,false,sizeof(vis));
        if(t[0][0] <= m)
            return false;
        else
            q1.push({0,{0,m}});
        vis[0][0] = true;
        while(!q1.empty())
        {
            pair<int,pair<int,int>> a = q1.front();
            q1.pop();
            int x = a.first;
            int y = a.second.first;

            if(x == grid.size() - 1 && y == grid[0].size() - 1 )
                return true;
            int time = a.second.second;
            int mov_x[4] = {0,0,1,-1};
            int mov_y[4] ={1,-1,0 ,0};
            for(int k = 0 ; k < 4 ; k++)
            {
                int curr_x = x + mov_x[k];
                int curr_y = y + mov_y[k];
                if(curr_x >=0 && curr_x < grid.size() && curr_y >= 0 && curr_y < grid[0].size() && grid[curr_x][curr_y] != 2)
                {
                    if(!vis[curr_x][curr_y] && t[curr_x][curr_y] > time + 1)
                    {
                        q1.push({curr_x,{curr_y, time + 1}});
                        vis[curr_x][curr_y] = true;
                    }
                    else if(curr_x == grid.size() - 1 && curr_y == grid[0].size() - 1)
                    {
                        if(!vis[curr_x][curr_y] && t[curr_x][curr_y] == time + 1)
                        {
                            q1.push({curr_x,{curr_y,time + 1}});
                            vis[curr_x][curr_y] = true;
                        }
                    }
                }
            }
            }
            return false;

    }
    int maximumMinutes(vector<vector<int>>& grid)
    {
        int l = -1, r = 1e9 + 1;
        while(l + 1 < r)
        {
            int mid = (l + r) / 2;
            if(good(mid,grid))
                l = mid;
            else
                r = mid;
        }
        return l;
    }
};
