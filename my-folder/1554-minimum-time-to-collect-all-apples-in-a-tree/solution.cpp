class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple)
    {
        vector<vector<int>>adjlist(n);
        for(int i=0;i<edges.size();i++)
        {
            adjlist[edges[i][0]].push_back(edges[i][1]);
            adjlist[edges[i][1]].push_back(edges[i][0]);
        }
        int time[n];
        memset(time,0,sizeof(time));
        auto dfs=[&](auto self,int V,int pv)->void
        {
            for(auto u:adjlist[V])
            {
                if(u==pv)
                    continue;
                self(self,u,V);
                time[V]+=time[u];
            }
            if(V!=0&&(hasApple[V]==true||time[V]!=0))
                time[V]+=2;
        };
        dfs(dfs,0,-1);
        return time[0];
    }
};
