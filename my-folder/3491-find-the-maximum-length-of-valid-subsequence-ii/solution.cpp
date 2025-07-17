class Solution {
public:
    int maximumLength(vector<int>& nums, int k)
    {
        int fin = 0;
        for(int i = 0 ; i < k ; i++)
        {
            vector<int>dp(k);
            for(int j = 0 ; j < nums.size(); j++)
            {
                int req = (i - (nums[j] % k) + k) % k;
                dp[nums[j] % k] = dp[req] + 1;
            }
            int ans = 0;
            for(int j = 0 ; j < k ; j++)
            {
                ans = max(ans,dp[j]);
            }
            fin = max(fin,ans);
        }
        return fin;
    }
};
