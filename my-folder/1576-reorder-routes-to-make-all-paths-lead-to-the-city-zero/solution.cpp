class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections)
    {
        vector< vector< int >>adjlist(n);
        set< pair<int ,int>>s;
        for(int i = 0 ; i < connections.size() ; i++)
        {
            s.insert({connections[i][0],connections[i][1]});
            adjlist[connections[i][0]].push_back(connections[i][1]);
            adjlist[connections[i][1]].push_back(connections[i][0]);
        }
        int cnt = 0;
        auto dfs = [&](auto self , int V , int pv)->void
        {
            for(auto u : adjlist[V])
            {
                if(u == pv)
                    continue;
                if(s.find({V, u}) != s.end())
                    self(self, u ,V);
                else
                {
                    cnt++;
                    self(self,u, V);
                }
            }
        };
        dfs(dfs, 0, -1);
        return (n - 1 - cnt);
    }
};
