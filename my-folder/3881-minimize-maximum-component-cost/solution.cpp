class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges, int k)
    {
        int l = -1, r = 1e6 + 1;
        auto good = [&](int val) -> bool {
            vector<vector<int>>adjlist(n);
            for(auto& x : edges)
            {
                int u = x[0];
                int v = x[1];
                int w = x[2];
                if(w <= val)
                {
                    adjlist[u].push_back(v);
                    adjlist[v].push_back(u);
                }
            }
            vector<bool>vis(n,false);
            int cnt = 0;
            auto dfs = [&](auto self,int u)-> void {
                vis[u] = true;
                for(auto& v : adjlist[u])
                {
                    if(!vis[v])
                    {
                        self(self,v);
                    }
                }
            };

            for(int i = 0 ; i < n;i++)
            {
                if(!vis[i])
                {
                    cnt++;
                    dfs(dfs,i);
                }
            }
            return cnt <= k;
            
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
