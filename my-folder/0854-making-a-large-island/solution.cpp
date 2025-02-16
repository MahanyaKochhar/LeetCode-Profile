class Solution {
public:
    int largestIsland(vector<vector<int>>& grid)
    {
        vector<vector<vector<int>>>mat(grid.size(),vector<vector<int>>(grid[0].size()));
        vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(),false));
        auto dfs = [&](auto self,int i,int j,int cm) -> int {
            vector<int>x1 = {1,-1,0,0};
            vector<int>y1 = {0,0,1,-1};
            int ans = 1;
            vis[i][j] = true;
            for(int k = 0 ; k < x1.size();k++)
            {
                int x = x1[k] + i;
                int y = y1[k] + j;
                if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || vis[x][y])
                {
                    continue;
                }
                if(grid[x][y] == 0)
                {
                    mat[x][y].push_back(cm);
                }
                else
                {
                    ans += self(self,x,y,cm);
                }
            }
            return ans;
        };

        int cm = 0;
        vector<int>sz;
        for(int i = 0 ; i < grid.size(); i++)
        {
            for(int j = 0 ; j < grid[0].size();j++)
            {
                if(!vis[i][j] && grid[i][j] == 1)
                {
                    int ans = dfs(dfs,i,j,cm);
                    sz.push_back(ans);
                    cm++;
                }
            }
        }
        int ans = 1;
        
        for(int i = 0 ; i < sz.size();i++)
        {
            ans = max(ans,sz[i]);
        }
        for(int i = 0 ; i < grid.size(); i++)
        {
            for(int j = 0 ; j < grid[0].size();j++)
            {
                if(grid[i][j] == 0)
                {
                    set<int> poss(mat[i][j].begin(),mat[i][j].end());
                    vector<vector<int>>res;
                    for(auto x : poss)
                    {
                        res.push_back({sz[x],x});
                        ans = max(ans,sz[x] + 1);
                    }
                    int tmp = 0;
                    for(int l = 0 ; l < res.size() ; l++)
                    {
                        tmp += res[l][0];
                    }
                    ans = max(ans,tmp + 1);
                }   
            }
        }
        return ans;
    }
};
