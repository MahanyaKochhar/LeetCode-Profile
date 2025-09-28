class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points)
    {
        using pii = pair<int,int>;
        vector<vector<pii>> adjlist(points.size());
        for(int i = 0 ; i < points.size();i++)
        {
            for(int j = i + 1; j < points.size(); j++)
            {
                int d = abs(points[j][0] - points[i][0]) + abs(points[j][1] - points[i][1]);
                adjlist[i].push_back({j,d});
                adjlist[j].push_back({i,d});
            }
        }
        int ans = 0;
        priority_queue<pii>pq;
        pq.push({0,0});
        vector<bool>vis(points.size(),false);
        while(!pq.empty())
        {
            auto x = pq.top();
            int d = -x.first;
            int node = x.second;
            pq.pop();
            if(vis[node])
            {
                continue;
            }
            ans += d;
            vis[node] = true;
            for(auto& v : adjlist[node])
            {
                int to = v.first;
                int weight = v.second;
                if(!vis[to])
                {
                    pq.push({-weight,to});
                }
            }
        }
        return ans;

    }
};
