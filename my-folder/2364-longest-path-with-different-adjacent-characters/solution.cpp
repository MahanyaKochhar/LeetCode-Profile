class Solution {
public:
    int longestPath(vector<int>& parent, string s)
    {
        vector<vector<int>>adjlist(s.length());
        vector<int>f(s.length(),1);
        vector<int>g(s.length(),1);
        for(int i=0;i<parent.size();i++)
        {
        	if(parent[i]!=-1)
        		adjlist[parent[i]].push_back(i);
        }
        auto dfs=[&](auto self,int V)->void
        {
        	for(auto u:adjlist[V])
        	{
        		self(self,u);
        		if(s[u]!=s[V])
        		{
        			if(f[u]+1>f[V])
        			{
        				g[V]=f[V];
        				f[V]=f[u]+1;
        			}
        			else if(f[u]+1>g[V])
        			{
        				g[V]=f[u]+1;
        			}
        		}
        	}
        };
        dfs(dfs,0);
        int ans=0;
        for(int i=0;i<s.length();i++)
        {
        	ans=max(ans,f[i]+g[i]-1);
        }
        return ans;
    }
};
