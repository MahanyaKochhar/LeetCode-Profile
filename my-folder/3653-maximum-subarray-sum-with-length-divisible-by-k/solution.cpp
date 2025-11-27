class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k)
    {
        using ll = long long;
        vector<ll>pre(nums.size() + 1,0);
        vector<ll>dp(nums.size() + 1, -1e15);
        ll ans = -1e17;
        for(int i = 1 ; i <= nums.size();i++)
        {
            pre[i] = pre[i - 1] + nums[i - 1];
        }
        for(int i = k ; i <= nums.size();i++)
        {
            dp[i] = max(pre[i] - pre[i - k],pre[i] - pre[i - k] + dp[i - k]);
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};
