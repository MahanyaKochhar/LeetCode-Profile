class Solution {
public:
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price)
    {
        vector<vector<int>>adjlist(n);
        for(int i=0;i<edges.size();i++)
        {
            adjlist[edges[i][0]].push_back(edges[i][1]);
            adjlist[edges[i][1]].push_back(edges[i][0]);
        }
        vector<long long int>f(n),g(n);
        for(int i=0;i<n;i++)
        {
            f[i]=price[i];
            g[i]=0;
        }
        auto dfs=[&](auto self,int V,int pv)->void
        {
            for(auto u:adjlist[V])
            {
                if(u==pv)
                    continue;
                self(self,u,V);
                if(f[u]+price[V]>f[V])
                {
                    g[V]=f[V];
                    f[V]=f[u]+price[V];

                }
                else if(g[V]<f[u]+price[V])
                {
                    g[V]=f[u]+price[V];
                }
            }
        };
        dfs(dfs,0,-1);
        vector<long long int>h(n);
        auto dfs2=[&](auto self,int V,int pv)->void
        {
            for(auto u:adjlist[V])
            {
                if(u==pv)
                    continue;
                if(f[u]+price[V]!=f[V])
                    h[u]=max(h[V]+price[u],f[V]+price[u]);
                else
                     h[u]=max(h[V]+price[u],g[V]+price[u]);
                self(self,u,V);
            }
        };
        dfs2(dfs2,0,-1);
        long long int ans=0;
        for(int i=0;i<n;i++)
        {
            long long int maxi=max(f[i]-price[i],h[i]-price[i]);
            ans=max(ans,maxi);
        }
        return ans;
    }
};
