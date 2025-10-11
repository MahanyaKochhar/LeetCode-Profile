class Solution {
public:
    int maxPartitionFactor(vector<vector<int>>& points)
    {
        if(points.size() == 2)
        {
            return 0;
        }
        auto good = [&](long long v) -> bool {
            vector<vector<int>>adjlist(points.size());
            for(int i = 0 ; i < points.size(); i++)
            {
                for(int j = i + 1 ; j < points.size();j++)
                {
                    if(abs(points[j][0] - points[i][0]) + abs(points[j][1] - points[i][1]) < v)
                    {
                        adjlist[i].push_back(j);
                        adjlist[j].push_back(i);
                    }
                }
            }
            vector<bool>vis(adjlist.size());
            vector<int>color(adjlist.size());
            bool valid = true;
            auto dfs = [&](auto self,int u,int col) -> void {
                vis[u] = true;
                color[u] = col;
                for(auto v : adjlist[u])
                {
                    if(!vis[v])
                    {
                        self(self,v, 1 - col);
                    }
                    else if(color[v] == col)
                    {
                        valid = false;
                    }
                }
            };

            for(int i = 0 ; i < points.size();i++)
            {
                if(!vis[i])
                {
                    dfs(dfs,i,0);
                }
            }
            return valid;
        };
        
        long long  l = 0,r = 1e11 + 1;
        while(l + 1 < r)
        {
            long long mid = (l + r) / 2;
            if(good(mid))
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }
        return l;
    }
};
