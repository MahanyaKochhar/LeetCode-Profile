class Solution {
public:
    vector<int> minCosts(vector<int>& cost)
    {
        vector<int>ans(cost.size());
        int curr = 101;
        for(int i = 0 ; i < cost.size();i++)
        {
            curr = min(curr,cost[i]);
            ans[i] = curr;
        }
        return ans;
    }
};
