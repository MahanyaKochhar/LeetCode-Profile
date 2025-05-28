class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k)
    {
        vector<vector<int>>adjList1(edges1.size() + 1);
        vector<vector<int>>adjList2(edges2.size() + 1);
        for(auto x : edges1)
        { 
            adjList1[x[0]].push_back(x[1]);
            adjList1[x[1]].push_back(x[0]);
        }
        for(auto x : edges2)
        {
            adjList2[x[0]].push_back(x[1]);
            adjList2[x[1]].push_back(x[0]);
        }
        vector<int>ans1(adjList1.size(),0);
        vector<int>ans2(adjList2.size(),0);
        auto dfs = [&] (auto self,vector<vector<int>>&adjList,int maxD,int u,int p,int cnt) -> int {
            int ans = 0;
            if(cnt > maxD)
            {
                return 0;
            }
            for(auto v : adjList[u])
            {
                if(v != p)
                {
                    ans += self(self,adjList,maxD,v,u,cnt + 1);
                }
            }
            return ans + 1;
        };

        for(int i = 0 ; i < ans1.size();i++)
        {
            ans1[i] = dfs(dfs,adjList1,k,i,-1,0);
        }
        int maxi = 0;
        for(int i = 0 ; i < ans2.size();i++)
        {
            ans2[i] = dfs(dfs,adjList2,k - 1,i,-1,0);
            maxi = max(ans2[i],maxi);
        }
        for(int i = 0; i < ans1.size();i++)
        {
            ans1[i] += maxi;
        }
        return ans1;
    }
};
