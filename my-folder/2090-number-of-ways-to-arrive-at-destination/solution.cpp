class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads)
    {
        vector<vector<pair<int,int>>> adjlist(n);
        priority_queue<pair<long long int,long long int>, vector<pair<long long int,long long int>>, greater<pair<long long int,long long int>>>pq;
        vector<long long int>d(n,LLONG_MAX);
        vector<int>ans(n,0);
        d[0] = 0;
        ans[0] = 1;
        pq.push({0,0});
        const int mod = 1000000007;
        for(int i = 0 ; i < roads.size();i++)
        {
            adjlist[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adjlist[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        while(!pq.empty())
        {
            pair<int,int>x = pq.top();
            int d_u= x.first;
            int u = x.second;
            pq.pop();
            if(d_u > d[u])
            {
                continue;
            }
            for(auto v : adjlist[u])
            {
                int dist = v.second;
                int to = v.first;
                if(d[to] > d[u] + dist)
                {
                    d[to] = d[u] + dist;
                    pq.push({d[to],to});
                    ans[to] = ans[u] % mod;
                }
                else if(d[to] == d[u] + dist)
                {
                    ans[to] = (ans[to] + ans[u]) % mod;
                }
            }
        }
        return ans[n - 1];
    }
};
