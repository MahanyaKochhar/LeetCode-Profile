class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
    {
        vector<pair<int,int>>adjlist[n+1];
        for(int i=0;i<flights.size();i++)
        {
                adjlist[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        vector<int>stops(n,INT_MAX); priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{src,k}});
        while(!pq.empty())
        {
            pair<int,pair<int,int>>pa=pq.top();
            int val=pa.first;
            int curr=pa.second.first;
            int st=pa.second.second;
            pq.pop();
            if(stops[curr]<k-st||st<-1)
                continue;
            if(curr==dst)
            {
                return val;
            }
            stops[curr]=k-st;
        for(int i=0;i<adjlist[curr].size();i++)
        {
            int x=adjlist[curr][i].first;
            int y=adjlist[curr][i].second;
            pq.push({val+y,{x,st-1}});
        }
    }
        return -1;
    }
        
};
