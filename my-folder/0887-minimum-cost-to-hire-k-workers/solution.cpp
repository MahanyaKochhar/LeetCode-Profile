class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k)
    {
        using pdi = pair<double,int>;
        vector<pdi>rates(wage.size());
        for(int i = 0 ; i < wage.size(); i++)
        {
            double r = (double)wage[i] / quality[i];
            rates[i] = {r,quality[i]};
        }
        sort(rates.begin(),rates.end());
        priority_queue<int>pq;
        int sum = 0;
        double ans = 1e12 - 1;
        for(int i = 0 ; i < rates.size(); i++)
        {
            sum += rates[i].second;
            pq.push(rates[i].second);
            if(pq.size() > k)
            {
                sum -= pq.top();
                pq.pop();
            }
            if(pq.size() == k)
            {
                ans = min(ans,sum * rates[i].first);
            }
        }
        return ans;
    }
};
