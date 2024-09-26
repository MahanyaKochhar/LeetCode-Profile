class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int minSoFar = INT_MAX;
        int ans = 0;
        for( auto x : prices)
        {
            minSoFar = min(x,minSoFar);
            ans = max(ans,x - minSoFar);
        }
        return ans;
    }
};
