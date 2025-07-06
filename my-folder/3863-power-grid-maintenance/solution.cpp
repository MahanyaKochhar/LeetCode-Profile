class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries)
    {

      vector<vector<int>>adjList(c + 1);
      vector<bool>vis(c + 1, false);
      map<int,set<int>>mp;
      vector<int>conn(c + 1);
      vector<int>ans;
        
      for(int i = 0 ; i < connections.size();i++)
      {
          int u = connections[i][0];
          int v = connections[i][1];
          adjList[u].push_back(v);
          adjList[v].push_back(u);
      }    
       
       auto dfs = [&](auto self,int u,int curr) -> void {
           vis[u] = true;
           mp[curr].insert(u);
           conn[u] = curr;
           for(auto v : adjList[u])
            {
                if(!vis[v])
                {
                    self(self,v,curr);
                }
            }
       };

        int curr = 1;
        for(int i = 1; i <= c ; i++)
        {
            if(!vis[i])
            {
                dfs(dfs,i,curr);
                curr++;
            }
        }

        for(auto u : queries)
        {
            int type = u[0];
            int x = u[1];
            if(type == 2)
            {
                mp[conn[x]].erase(x);
            }
            else
            {
                if(mp[conn[x]].find(x) != mp[conn[x]].end())
                {
                    ans.push_back(x);
                }
                else 
                {
                    if(mp[conn[x]].size() == 0)
                    {
                        ans.push_back(-1);
                    }
                    else
                    {
                        ans.push_back(*(mp[conn[x]].begin()));
                    }
                }
            }    
        }
        return ans;

        

        
        
        
        
    }
};
