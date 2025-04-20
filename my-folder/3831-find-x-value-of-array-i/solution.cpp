class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k)
    {
        vector<vector<long long>>dp(nums.size(),vector<long long>(k,0));
        dp[0][nums[0] % k] = 1;
        for(int i = 1 ; i < nums.size();i++)
        {
            dp[i][nums[i] % k] = 1;
            for(int j = 0 ; j < k ;j++)
            {
                dp[i][((long long)nums[i] * j) % k] += dp[i - 1][j];
            }
        }
        vector<long long>fin;
        for(int j = 0 ; j < k; j++)
        {
            long long ans = 0;
            for(int i = 0 ; i < nums.size();i++)
            {
                ans += dp[i][j];
            }
            fin.push_back(ans);
        }
        return fin;
    }
};
