class Solution {
public:
    int numberOfComponents(vector<vector<int>>& properties, int m)
    {
        vector<vector<int>>adjlist(properties.size());
        for(int i = 0 ; i < properties.size(); i++)
        {
            for(int j = i + 1 ; j < properties.size() ; j++)
            {
                   vector<int>a = properties[i];
                   vector<int>b = properties[j];
                   sort(a.begin(),a.end());
                   sort(b.begin(),b.end());
                   int k = 0,l = 0, cnt = 0;
                   vector<bool>vis(102,false);
                   while(k < a.size() && l < b.size())
                   {
                       if(a[k] == b[l])
                       {
                           if(!vis[a[k]])
                           {
                               cnt++;
                               vis[a[k]] = true;
                           }
                           k++;
                           l++;
                       }
                       else if(a[k] > b[l])
                       {
                           l++;
                       }
                       else
                       {
                           k++;
                       }
                   }
                if(cnt >= m)
                {
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);
                }
            }    
        }
        vector<bool> vis(101,false);
        int ans = 0;
        auto dfs = [&] (auto self,int u) -> void {
            vis[u] = true;
            for(auto v : adjlist[u])
            {
                if(!vis[v])
                {
                    self(self,v);
                }
            }
        };

        for(int i = 0 ; i < properties.size();i++)
        {
            if(!vis[i])
            {
                
                ans++;
                dfs(dfs,i);
            }
        }
        return ans;
    }
};
