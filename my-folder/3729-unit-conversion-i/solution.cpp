class Solution {
public:
    vector<int> baseUnitConversions(vector<vector<int>>& conversions)
    {
        vector<long long>ans(conversions.size() + 1,1);
        const int mod = 1e9 + 7;
        vector<vector<pair<int,int>>>adjList(conversions.size() + 1);
        for(int i = 0 ; i < conversions.size();i++)
        {
            int from = conversions[i][0];
            int to = conversions[i][1];
            int conv = conversions[i][2];
            adjList[from].push_back({to,conv});
        }


        auto dfs = [&](auto self,int u,int p) -> void {
            for(auto v : adjList[u])
            {
                if(v.first == p)
                {
                    continue;
                }
                ans[v.first] = (ans[u] % mod * v.second % mod) % mod;
                self(self,v.first,u);
            }    
        };
        ans[0] = 1;
        dfs(dfs,0,-1);
        vector<int>fin;
        for(int i = 0 ; i < ans.size();i++)
        {
            fin.push_back(ans[i]);
        }    
        return fin;
    }
};
