class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections)
    {
        int cnt = 0;
        int cnt_edges = 0;
        vector<bool>vis (n, false);
        vector<vector<int>> adjlist(n);
        for(int i = 0 ; i < connections.size() ; i++)
        {
            adjlist[connections[i][0]].push_back(connections[i][1]);
            adjlist[connections[i][1]].push_back(connections[i][0]);
        }
        auto dfs = [&](auto self, int V)->void
        {
            cnt += 1;
            cnt_edges += adjlist[V].size();
            vis[V] = true;
            for(auto u : adjlist[V])
            {
                if(!vis[u])
                    self(self, u);
            }
        };
        int ans = 0, ex = 0;
        for(int i = 0 ; i < n ; i++)
        {
            if(!vis[i])
            {
                
                ans++;
                cnt = 0;
                cnt_edges = 0;
                dfs(dfs,i);
                ex += cnt_edges / 2 - (cnt - 1);
                
            }
            
        }
        if(ex >= (ans - 1))
        {
            return ans - 1;
        }
        else
        {
            return -1;
        }


    }
};
