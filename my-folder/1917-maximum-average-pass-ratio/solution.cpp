class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents)
    {
        auto calculateGain = [&](int pass, int total) -> double {
            return (double) (pass + 1) / (total + 1) - (double) pass/ total;
        };

        priority_queue<pair<double,pair<int,int>>>pq;
        for(auto& x : classes)
        {
            pq.push({calculateGain(x[0],x[1]),{x[0],x[1]}});
        }
        while(extraStudents != 0)
        {
            auto x = pq.top();
            pq.pop();
            int pass = x.second.first + 1;
            int total = x.second.second + 1;
            pq.push({calculateGain(pass,total),{pass,total}});
            extraStudents--;
        }
        double ans = 0;
        while(!pq.empty())
        {
            auto x = pq.top();
            pq.pop();
            int pass = x.second.first;
            int total = x.second.second;
            ans += (double) pass / total;
        }
        ans = ans / classes.size();
        return ans;
    }
};
