class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k)
    {
        vector<int>dp(energy.size());
        for(int i = 0; i < energy.size();i++)
        {
            dp[i] = energy[i];
            if(i >= k)
            {
                dp[i] = max(dp[i],dp[i - k] + energy[i]);
            }
        }
        int ans = INT_MIN;
        for(int j = energy.size() - 1; j > energy.size() - 1 - k ; j--)
        {
            ans = max(ans,dp[j]);
        }
        return ans;
    }
};
