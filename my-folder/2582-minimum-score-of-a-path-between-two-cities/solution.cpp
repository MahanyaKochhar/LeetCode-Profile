class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads)
    {
        vector<bool>vis (n + 1, false);
        vector<vector<pair<int , int>>> adjlist(n + 1);
        for(int i = 0 ; i < roads.size() ; i++)
        {
            adjlist[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adjlist[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        int ans = 1e5;
        auto dfs = [&](auto self, int V)->void
        {
            vis[V] = true;
            for(auto u : adjlist[V])
            {
                ans = min(ans, u.second);
                if(!vis[u.first])
                    self(self, u.first);
            }
        };
        dfs(dfs,1);
        return ans;
    }
};
