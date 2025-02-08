class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
    {
        vector<vector<int>>ans;
        vector<vector<bool>>vis1(heights.size(),vector<bool>(heights[0].size(),false));
        vector<vector<bool>>vis2(heights.size(),vector<bool>(heights[0].size(),false));

        auto dfs = [&](auto&& self,int i ,int j,vector<vector<bool>>& vis) -> void {
            vector<int> x1 = {1,-1,0,0};
            vector<int> y1 = {0,0,1,-1};
            vis[i][j] = true;
            for(int k = 0 ; k < x1.size(); k++)
            {
                int x = x1[k] + i;
                int y = y1[k] + j;
                if(x < 0 || x >= heights.size() || y < 0 || y >= heights[0].size() || vis[x][y] || heights[x][y] < heights[i][j])
                {
                    continue;
                }
                self(self,x,y,vis);
            }
        };

        for(int i = 0 ; i < heights.size() ; i++)
        {
            if(!vis1[i][0])
            {
                dfs(dfs,i,0,vis1);
            }
            
            if(!vis2[i][heights[0].size() - 1])
            {
                dfs(dfs,i,heights[0].size() - 1,vis2);
            }
        }

        for(int j = 0 ; j < heights[0].size();j++)
        {
            if(!vis1[0][j])
            {
                dfs(dfs,0,j,vis1);
            }
            if(!vis2[heights.size() - 1][j])
            {
                dfs(dfs,heights.size() - 1,j,vis2);
            }
        }

        for(int i = 0 ; i < vis1.size() ; i++)
        {
            for(int j = 0 ; j < vis1[0].size() ; j++)
            {
                if(vis1[i][j] && vis2[i][j])
                {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
