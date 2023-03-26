class Solution
{
public:
    int longestCycle(vector<int>& edges)
    {
        vector< bool> vis(edges.size()), on_stack(edges.size());
        int fin = -1;
        vector<int>cnt(edges.size());
        auto dfs = [&](auto self, int V ,int c)->void
        {
            vis[V] = true;
            cnt[V] = c;
            on_stack[V] = true;
            int u = edges[V];
            if(u == -1)
            {
                on_stack[V] = false;
                return ;
            }
            if(on_stack[u])
            {
               fin =  c + 1 - cnt[u];
            }
            else if(! vis[u])
                self(self, u , c + 1);
            on_stack[V] = false;
        };
        int ans = -1;
        for(int i = 0 ; i < edges.size() ; i++)
        {
            if(!vis[i])
            {
                dfs(dfs, i , 0);
                ans = max(fin , ans);
                fin = -1;
        }
    }
    return ans;
    }
};
