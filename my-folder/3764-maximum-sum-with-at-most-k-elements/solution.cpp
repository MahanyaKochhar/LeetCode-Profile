class Solution {
public:
        long long maxSum(vector<vector<int>>& grid, vector<int>& limits,int k)
    {
        long long sum = 0;
        priority_queue<pair<int,int>> pq;
        for(int i = 0 ; i < grid.size(); i++)
        {
            for(int j = 0 ; j < grid[i].size(); j++)  
            {
                pq.push({grid[i][j],i});
            }
        }
        int curr = 0;
        while(curr != k)
        {
            auto a = pq.top();
            int b = a.first;
            int c = a.second;
            pq.pop();
            if(limits[c] > 0)
            {
                sum += b;
                limits[c]--;
                curr++;
            }    
        }
        return sum;
    }
};
