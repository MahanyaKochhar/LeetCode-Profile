class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges)
    {
        int n = coins.size();
        vector<vector<int>> adjlist(coins.size());
        for(int i = 0 ; i < edges.size() ; i++)
        {
            adjlist[edges[i][0]].push_back(edges[i][1]);
            adjlist[edges[i][1]].push_back(edges[i][0]);
        }
        vector< vector< int>> cnt(coins.size());
        vector<int>ans(n) , f(n , INT_MIN);
        auto dfs = [&](auto self, int V, int pv)->void
        {
            if(coins[V] == 1)
            {
                f[V] = 0;
                cnt[V].push_back(0);
            }
            for(auto u : adjlist[V])
            {
                if(u == pv)
                    continue;
                self(self, u , V);
                if(f[u] != INT_MIN )
                    cnt[V].push_back(f[u] + 1);
            }
            sort(cnt[V].rbegin() , cnt[V].rend());
            if(cnt[V].size() > 0)
                f[V] = max(f[V], cnt[V][0]);
            for(auto u : adjlist[V])
            {
                if(f[u] >= 2)
                {
                    ans[V] += ans[u] + 2;
                }   
            }
        };
        vector<int> out_max(n , INT_MIN);
        vector<int> fin(n),g(n);
        auto dfs2 = [&](auto self, int V, int pv)->void
        {
            fin[V] = ans[V] + g[V];
            for(auto u : adjlist[V])
            {
                if(u == pv)
                    continue;
                if(cnt[V].size() > 0 && f[u] + 1 == cnt[V][0])
                {
                    if(out_max[V] != INT_MIN)
                        out_max[u] = out_max[V] + 1;
                    if(cnt[V] . size() > 1 )
                        out_max[u] = max(out_max[V] + 1 , cnt[V][1] + 1);
                }
                else
                {
                    if(out_max[V] != INT_MIN)
                        out_max[u] = out_max[V] + 1;
                    if(cnt[V] . size() >= 1 )
                        out_max[u] = max(out_max[V] + 1 , cnt[V][0] + 1);
                }
                if(out_max[u] > 2)
                {
                    if(f[u] >= 2)
                        g[u] = g[V] - 2 - ans[u] + 2 + ans[V];  
                    else
                        g[u] = g[V] + ans[V] + 2;
                }
                self(self, u , V);
            }
        };
        dfs(dfs, 0 , -1);
        dfs2(dfs2, 0 , -1);
        int mini = INT_MAX;
        for(int i = 0 ; i < n ; i++)
            mini = min(mini, fin[i]);
        return mini;


    }
};
