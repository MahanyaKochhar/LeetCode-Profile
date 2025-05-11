class Solution {
public:
    long long maxSpending(vector<vector<int>>& values)
    {
        using pii = pair<int,int>;
        priority_queue<pair<int,pii>>pq;
        for(int i = 0 ; i < values.size();i++)
        {
            int l = values[i].size() - 1;
            pq.push({-values[i][l],{i,l}});
        }
        long long ans = 0, d = 1;
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            long long val = -it.first;
            int i = it.second.first;
            int j = it.second.second;
            ans += (val * d);
            d++;
            if(j > 0)
            {
                pq.push({-values[i][j - 1],{i,j - 1}});
            }
        }
        return ans;
        
    }
};
