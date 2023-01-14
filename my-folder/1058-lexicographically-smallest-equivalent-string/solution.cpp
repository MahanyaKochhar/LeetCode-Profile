class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr)
    {
        bool vis[26][26];
        memset(vis,false,sizeof(vis));
        vector<vector<int>>adjlist(26);
        for(int i=0;i<s1.length();i++)
        {
            int x=s1[i]-'a';
            int y=s2[i]-'a';
            if(x>y)
                swap(x,y);
            if(!vis[x][y]&&x!=y)
            {
                adjlist[x].push_back(y);
                adjlist[y].push_back(x);
                vis[x][y]=true;
            }

        }
        
        string ans="";
        for(int i=0;i<baseStr.length();i++)
        {
            int mini=26;
            vector<bool>vis(26,false);
            auto dfs=[&](auto self,int V)->void
            {
                mini=min(mini,V);
                vis[V]=true;
                for(auto u:adjlist[V])
                {
                    if(vis[u])
                        continue;
                    self(self,u);
                }
            };
            dfs(dfs,baseStr[i]-'a');
            ans.push_back((char)('a'+mini));
        }
            
        return ans;
    }
};
