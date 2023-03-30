class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges)
    {
        vector<set<int>> adjlist(coins.size());
        vector<bool>vis(coins.size());
        queue< int >q;
        for(int i = 0 ; i < edges.size() ; i++)
        {
            adjlist[edges[i][0]].insert(edges[i][1]);
            adjlist[edges[i][1]].insert(edges[i][0]);
        }
        for(int i = 0 ; i < edges.size() + 1 ; i++)
        {
            if(adjlist[i].size() == 1)
                q.push(i);
        }
        while(! q.empty())
        {
            int id = q.front();
            q.pop();
            if(coins[id] == 1)
                continue;
            else
            {
                vis[id] = true;
                // if(adjlist[id].size() == 0)
                //     continue;
                int node = *adjlist[id].begin();
                adjlist[id].clear();
                adjlist[node].erase(id);
                if(adjlist[node].size() == 1)
                    q.push(node);
            }
        }
        for(int i = 0 ; i < edges.size() + 1 ; i++)
        {
            if(adjlist[i].size() == 1)
                q.push(i);
        }
        while(! q.empty())
        {
            int id = q.front();
            q.pop();
            vis[id] = true;
            int node = *adjlist[id].begin();
            adjlist[id].clear();
            adjlist[node].erase(id);
            if(adjlist[node] . size() == 1)
            {
                vis[node] = true; 
            }
        }
        int cnt = 0;
        for(int i = 0 ; i < coins.size() ; i++)
        {
            if(!vis[i])
                cnt++;
        }
        return max(0, (cnt - 1) * 2 );



    }
};
