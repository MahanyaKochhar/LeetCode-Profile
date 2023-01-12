class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels)
    {
        vector<vector<int>> dp(n,vector<int>(26,0));
        vector<vector<int>> adjlist(n);
        for(int i = 0; i < edges.size(); i++)
        {
            adjlist[edges[i][0]].push_back(edges[i][1]);
            adjlist[edges[i][1]].push_back(edges[i][0]);
        }
        auto dfs=[&](auto self, int V, int pv)->void
        {
            dp[V][labels[V]-'a']++;
            for(auto u : adjlist[V])
            {
                if(u == pv)
                    continue;
                self(self, u, V);
                for(int i = 0; i < 26; i++)
                {
                    dp[V][i]+=dp[u][i];
                }

            }
        };
        dfs(dfs, 0, -1);
        vector<int> ans(n);
        for(int i = 0; i < n; i++)
        {
            ans[i] = dp[i][labels[i]-'a'];
        }
        return ans;
    }
};
