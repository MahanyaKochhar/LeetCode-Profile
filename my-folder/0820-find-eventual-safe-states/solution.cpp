class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph)
    {
        vector<vector<int>> adjList(graph.size());
        vector<int>indegree(graph.size());
        vector<int>ans;
        for(int i = 0 ; i < graph.size(); i++)
        {
            for(int j = 0 ; j < graph[i].size() ; j++)
            {
                adjList[graph[i][j]].push_back(i);
                indegree[i]++;
            }
        }
        queue<int>q;
        for(int i = 0 ; i < indegree.size();i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int u = q.front();
            ans.push_back(u);
            q.pop();
            for(auto v : adjList[u])
            {
                indegree[v]--;
                if(indegree[v] == 0)
                {
                    q.push(v);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
