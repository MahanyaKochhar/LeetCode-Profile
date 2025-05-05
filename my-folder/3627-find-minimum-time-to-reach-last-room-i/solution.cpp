class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime)
    {
        vector<vector<int>>d(moveTime.size(),vector<int>(moveTime[0].size(),INT_MAX));
        d[0][0] = 0;
        priority_queue<pair<int,pair<int,int>>>pq;
        pq.push({0,{0,0}});
        while(!pq.empty())
        {
            auto it = pq.top();
            int curr = -it.first;
            int i = it.second.first;
            int j = it.second.second;
            pq.pop();
            if(d[i][j] < curr)
            {
                continue;
            }

            vector<int>x = {1,-1,0,0};
            vector<int>y = {0,0,1,-1};
            for(int k = 0 ; k < x.size();k++)
            {
                int u = x[k] + i;
                int v = y[k] + j;
                if(u < 0 || u >= moveTime.size() || v < 0 || v >= moveTime[0].size())
                {
                    continue;
                }
                int nowMax = max(curr,moveTime[u][v]) + 1;
                if(nowMax < d[u][v])
                {
                    d[u][v] = nowMax;
                    pq.push({-nowMax,{u,v}});
                }
            }
        }
        return d[moveTime.size() - 1][moveTime[0].size() - 1];
    }
};
