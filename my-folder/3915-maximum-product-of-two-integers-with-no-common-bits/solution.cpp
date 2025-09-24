class Solution {
public:
    long long maxProduct(vector<int>& nums)
    {
        using ll = long long;
        int maxi = 0;
        for(auto& x : nums)
        {
            maxi = max(maxi,x);
        }
        int msb = log2(maxi);
        int maxMask = (1 << (msb + 1));
        vector<int>dp(maxMask,-1);
        for(auto& x : nums)
        {
            dp[x] = x;
        }
        for(int b = 0 ; b < 20; b++)
        {
            for(int j = 0 ; j < maxMask; j++)
            {
                if(j & (1 << b))
                {
                    dp[j] = max(dp[j],dp[j ^ (1 << b)]);
                }
            }
        }
        ll ans = 0;
        for(int i = 0; i < nums.size();i++)
        {
            int cmp = (maxMask - 1) ^ nums[i];
            if(dp[cmp] != -1)
            {
                ans = max(ans,(ll)dp[cmp] * (ll)nums[i]);
            }
        }
        return ans;
    }
};
