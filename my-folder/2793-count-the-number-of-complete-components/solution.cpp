class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges)
    {
        int parent[n];
        long long int sz[n];
        for(int i = 0 ; i <  n ; i++)
        {
            parent[i] = i ;
            sz[i] = 1;
        }
        auto root1 =[&](auto self, int a)->int
        {
                if(parent[a] == a)
                    return a;
                return parent[a] = self(self,parent[a]);
        };
        for(int i = 0 ; i < edges.size() ; i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            auto unionof = [&](int a, int b)->void
            {
                auto root1 =[&](auto self, int a)->int
                {
                    if(parent[a] == a)
                        return a;
                    return parent[a] = self(self,parent[a]);
                };
                int rootA = root1(root1,a);
                int rootB = root1(root1,b);
                if(rootA != rootB)
                {
                    if(sz[rootA] >= sz[rootB])
                    {
                        sz[rootA] += sz[rootB];
                        cout << sz[rootA] << " ";
                        parent[rootB] = rootA;
                    }
                    else
                    {
                        sz[rootB] += sz[rootA];
                        cout << sz[rootB] << " ";
                        parent[rootA] = rootB;
                    }
                }
            };
            unionof(a, b);
        }
        map<int,int>mp,mp1;
        for(int i = 0 ; i < n ; i++)
        {
            int x = root1(root1, i);
            mp[x]++;
        }
        for(int i = 0 ; i < edges.size() ;i++)
        {
            int x = root1(root1,edges[i][0]);
            mp1[x]++;
        }
        int ans = 0;
        for(auto x: mp)
        {
            if((x.second * (x.second - 1)) / 2 <= mp1[x.first])
                ans++;
        }
        return ans;
    }
};
