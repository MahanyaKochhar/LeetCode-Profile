class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination)
    {
        vector<vector<int>>adjlist(n);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }
        vector<bool>vis(n,false);
        auto dfs=[&](auto self,int V)->bool
        {
            if(destination==V)
                return true;
            bool res=false;
            vis[V]=true;
            for(auto u:adjlist[V])
            {
                if(vis[u]==true)
                    continue;
                res=res|self(self,u);
            }
            return res;
        };
        return dfs(dfs,source);
    }
};
