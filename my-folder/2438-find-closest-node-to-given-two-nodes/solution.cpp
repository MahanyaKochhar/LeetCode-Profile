class Solution {
public:
    void dfs(vector<int>adjlist[],int curr,int d,vector<bool>&vis,vector<int>& dist)
    {
        vis[curr]=true;
        dist[curr]=d;
        for(auto x:adjlist[curr])
        {
            if(!vis[x])
                dfs(adjlist,x,d+1,vis,dist);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2)
    {
        int n=edges.size();
        vector<int>adjlist[n];
        for(int i=0;i<edges.size();i++)
        {
            if(edges[i]!=-1)
                adjlist[i].push_back(edges[i]);
        }
        vector<bool>visited(n);
        vector<int>dist(n,-1);
        vector<bool>visited1(n);
        vector<int>dist1(n,-1);
        dfs(adjlist,node1,0,visited,dist);
        dfs(adjlist,node2,0,visited1,dist1);
        int ans=INT_MAX;int req;
        for(int i=0;i<n;i++)
        {
            if(dist[i]!=-1&&dist1[i]!=-1)
            {
                if(ans>max(dist[i],dist1[i]))
                {
                    ans=min(ans,max(dist[i],dist1[i]));
                    req=i;
            }
            
        }}
        if(ans==INT_MAX)
            return -1;
        else
            return req;
    }
    
};
