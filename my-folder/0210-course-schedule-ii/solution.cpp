class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<vector<int>>adjList(numCourses);
        for(auto x: prerequisites)
        {
            int a = x[0];
            int b = x[1];
            adjList[b].push_back(a);
        }
        vector<int>color(numCourses,0);
        vector<int>ans;
        int cycle = 0;
        auto dfs = [&](auto self,int v) -> void {
            color[v] = 1;
            for(auto u : adjList[v])
            {
                if(color[u] == 0)
                {
                    self(self,u);
                }
                else if(color[u] == 1)
                {
                    cycle = 1;
                }
            }
            color[v] = 2;
            ans.push_back(v);
        };

        for(int i = 0 ; i < numCourses; i++)
        {
            if(color[i] == 0)
            {
                dfs(dfs,i);
            }
        }
        if(cycle == 1)
        {
            return {};
        }
        else
        {
            reverse(ans.begin(),ans.end());
            return ans;
        }
    }
};
