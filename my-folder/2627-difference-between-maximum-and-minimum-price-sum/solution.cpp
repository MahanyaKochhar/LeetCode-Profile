bool cmp(const pair<int,int>&a,const pair<int,int>&b)
{
    return a.first > b.first;
}
class Solution {
public:
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price)
    {
        vector<vector<int>> adjlist(n);
        for(int i = 0;i < edges.size(); i++)
        {
            adjlist[edges[i][0]].push_back(edges[i][1]);
            adjlist[edges[i][1]].push_back(edges[i][0]);
        }
        long long dp[n][2];
        memset(dp, 0, sizeof(dp));
        long long ans=0;
        auto dfs=[&](auto self, int V, int pv)->void
        {

            dp[V][1] = price[V];
            vector<pair<long long,long long>>p1, p2;
            for(auto u : adjlist[V])
            {
                if(u == pv)
                    continue;
                self(self, u, V);
                p1.push_back({dp[u][1],u});
                p2.push_back({dp[u][0],u});
                dp[V][1] = max(dp[V][1], dp[u][1] + price[V]);
                dp[V][0] = max(dp[V][0], dp[u][0] + price[V]);
            }
            sort(p1.begin(),p1.end(),cmp);
            sort(p2.begin(),p2.end(),cmp);
            if(p1.size()==0)
            {
                // ans=max(ans, (long long) price[V]);
            }
            else if(p1.size() == 1)
            {
                ans = max(ans, p2[0].first + price[V]);
                ans = max(ans, p1[0].first);
            }
            else if(p1.size() > 1)
            {
                if(p1[0].second != p2[0].second)
                {
                    ans=max(ans,p2[0].first + p1[0].first + price[V]);
                }
                else
                {
                    long long maxi=max(p1[0].first + p2[1].first + price[V], price[V] + p1[1].first + p2[0].first);
                    ans = max(ans, maxi);
                }
            }
        };
        dfs(dfs,0,-1);
        return ans;
    }
};
