class Solution {
public:
    int minXor(vector<int>& nums, int k)
    {
        vector<int>xorA(nums.size(),0);
        xorA[0] = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            xorA[i] = xorA[i - 1] ^ nums[i];
        }
        vector<vector<int>>dp(nums.size(),vector<int>(k,INT_MAX));
        for(int i = 0 ; i < nums.size(); i++)
        {
            dp[i][0] = xorA[i];
        }
        for(int i = 0 ; i < nums.size(); i++)
        {
            for(int l = i ; l >= 0 ; l--)
            {
                int lxor = l - 1 >= 0 ? xorA[l - 1] : 0;
                int rxor = xorA[i] ^ lxor;
                for(int j = 1 ; j < k ; j++)
                {
                    dp[i][j] = min(dp[i][j],max(rxor, l - 1 >= 0 ? dp[l - 1][j - 1] : INT_MAX));
                }
            }
        }
        return dp[nums.size() - 1][k - 1];
    }
};
