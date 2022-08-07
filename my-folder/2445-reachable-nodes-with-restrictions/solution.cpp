class Solution {
public:
    vector<bool>visi;
    int dfs(int node,vector<vector<int>>&adjlist,vector<bool>&can)
    {
        int cnt=0;
        visi[node]=true;
        for(auto x:adjlist[node])
        {
            if(visi[x]==false)
            {
                int v=dfs(x,adjlist,can);
                cnt+=v;
            }
        }
                if(can[node]==false)
                    return cnt+1;
                else
                    return 0;
            }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted)
    {
        vector<bool>can(n,false);
        visi.resize(n,false);
        for(int j=0;j<restricted.size();j++)
        {
            can[restricted[j]]=true;
        }
        vector<vector<int>> adjlist(n);
        for(int i=0;i<edges.size();i++)
        {
            adjlist[edges[i][0]].push_back(edges[i][1]);
            adjlist[edges[i][1]].push_back(edges[i][0]);
        }
        return dfs(0,adjlist,can);
    }
};
