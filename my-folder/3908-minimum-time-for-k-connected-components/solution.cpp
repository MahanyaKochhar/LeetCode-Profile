class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, int k)
    {
        int l = -1 , r = 1e9;
        auto good = [&](int time)-> bool {
            vector<vector<int>>adjList(n);
            for(auto& u : edges)
            {
                if(u[2] > time)
                {
                    adjList[u[0]].push_back(u[1]);
                    adjList[u[1]].push_back(u[0]);
                }
            }
            vector<bool>vis(n);

            auto dfs = [&](auto self,int u) -> void {
           vis[u] = true;
           for(auto& v : adjList[u])
            {
                if(!vis[v])
                {
                    self(self,v);
                }
            }
            };
            int curr = 0;
            for(int i = 0 ; i < n; i++)
            {
                if(!vis[i]) 
                {
                    curr++;
                    dfs(dfs,i);
                }
            }
            if(curr >= k)
            {
                return true;
            }
            else
            {
                return false;
            }
        };

        while(l + 1 < r)
        {
            int mid = (l + r) / 2;
            if(good(mid))
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }
        return r;
    }
};
