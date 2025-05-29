class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2)
    {
        vector<vector<int>>adjList1(edges1.size() + 1);
        vector<vector<int>>adjList2(edges2.size() + 1);
        vector<int>odd1(adjList1.size(),0);
        vector<int>eve1(adjList1.size(),0);
        vector<int>odd2(adjList2.size(),0);
        vector<int>eve2(adjList2.size(),0);
        vector<int>ans1(adjList1.size(),0);
        vector<int>ans2(adjList2.size(),0);
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

        auto dfs = [] (auto self,vector<vector<int>>& adjList,vector<int>&odd,vector<int>&eve,int u,int p) -> void  {
            for(auto v : adjList[u])
            {
                if(v != p)
                {
                    self(self,adjList,odd,eve,v,u);
                    odd[u] += eve[v];
                    eve[u] += odd[v];
                }
            }
            eve[u] += 1;
        };

        auto dfs2 = [] (auto self,vector<vector<int>>& adjList,vector<int>&odd,vector<int>&eve,int u,int p,bool take,vector<int>& ans) -> void
        {
            if(take)
            {
                ans[u] = odd[u];
            }
            else
            {
                ans[u] = eve[u];
            }
            for(auto v : adjList[u])
            {
                if(v != p)
                {
                    odd[u] -= eve[v];
                    eve[u] -= odd[v];
                    eve[v] += odd[u];
                    odd[v] += eve[u];
                    self(self,adjList,odd,eve,v,u,take,ans);
                    eve[v] -= odd[u];
                    odd[v] -= eve[u];
                    eve[u] += odd[v];
                    odd[u] += eve[v];
                }
            }
        };

        dfs(dfs,adjList1,odd1,eve1,0,-1);
        dfs(dfs,adjList2,odd2,eve2,0,-1);
        dfs2(dfs2,adjList1,odd1,eve1,0,-1,0,ans1);
        dfs2(dfs2,adjList2,odd2,eve2,0,-1,1,ans2);

        int maxi = 0;
        for(auto x : ans2)
        {
            maxi = max(maxi,x);
        }
        for(int i = 0 ; i < ans1.size(); i++)
        {
            ans1[i] += maxi;
        }
        return ans1;
    }
};
