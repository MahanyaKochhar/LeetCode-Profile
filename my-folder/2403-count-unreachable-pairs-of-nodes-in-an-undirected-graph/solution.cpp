class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges)
    {
        int cnt = 0;
        vector<bool>vis (n, false);
        vector<vector<int>> adjlist(n);
        for(int i = 0 ; i < edges.size() ; i++)
        {
            adjlist[edges[i][0]].push_back(edges[i][1]);
            adjlist[edges[i][1]].push_back(edges[i][0]);
        }
        auto dfs = [&](auto self, int V)->void
        {
            cnt += 1;
            vis[V] = true;
            for(auto u : adjlist[V])
            {
                if(!vis[u])
                    self(self, u);
            }
        };
        long long int total = 0;
        vector<long long int>ans;
        for(int i = 0 ; i < n ; i++)
        {
            if(!vis[i])
            {
                cnt = 0;
                dfs(dfs,i);
                total += cnt;
                ans.push_back(cnt);

                
            }
            
        }
        long long fin = 0;
        for(int i = 0 ; i < ans.size() - 1 ; i++)
        {
            total = total - ans[i];
            fin += (long long)(total * ans[i]);
        }
        return fin;
    }
};
