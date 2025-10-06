class Solution {
public:
    int swimInWater(vector<vector<int>>& grid)
    {
        int n = grid.size();
        auto bfs = [&](int t) -> bool
        {
            queue<pair<int,int>>q;
            vector<vector<bool>>vis(n,vector<bool>(n,false));
            if(grid[0][0] <= t)
            {
                q.push({0,0});
                vis[0][0] = true;
            }
            while(!q.empty())
            {
                auto x = q.front();
                int i = x.first;
                int j = x.second;
                q.pop();
                int x1[] = {1,-1,0,0};
                int y1[] = {0,0,1,-1};
                for(int l = 0 ; l < 4;l++)
                {
                    int new_i = i + x1[l];
                    int new_j = j + y1[l];
                    if(new_i >= 0 && new_i < n && new_j >= 0 && new_j < n && !vis[new_i][new_j] && grid[new_i][new_j] <= t)
                    {
                        vis[new_i][new_j] = true;
                        q.push({new_i,new_j});
                    }
                }
            }
            return vis[n - 1][n - 1];
        };
        for(int i = 0; i < (n * n); i++)
        {
            if(bfs(i))
            {
                return i;
            }
        }
        return n * n - 1;
    }
};
