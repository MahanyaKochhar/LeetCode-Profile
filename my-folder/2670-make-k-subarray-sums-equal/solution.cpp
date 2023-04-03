class Solution {
public:
    long long makeSubKSumEqual(vector<int>& arr, int k)
    {
        vector< vector<int>> adjlist(arr.size());
        vector<bool> vis(arr.size());
        for(int i = 0 ; i < arr.size() ; i++)
        {
            int l = i ;
            int r = (i + k) % arr.size();
            adjlist[l].push_back(r);
            adjlist[r].push_back(l);
        }
        vector<int>ans;
        auto dfs = [&](auto self,int V)->void
        {
            vis[V] = true;
            ans.push_back(arr[V]);
            for(auto u : adjlist[V])
            {
                if(!vis[u])
                    self(self,u);
            }
        };
        long long fin = 0;
        for(int i = 0 ; i < arr.size() ; i++)
        {
            if(!vis[i])
            {
                ans.clear();
                dfs(dfs, i);
                sort(ans.begin() ,ans.end());
                int m = (ans.size() / 2);
                for(int i = 0 ; i < ans.size() ; i++)
                    fin += abs(ans[i] - ans[m]);
            }
        }
        return fin;
    }
};
