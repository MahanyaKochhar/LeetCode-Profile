class Solution {
public:
    bool validPartition(vector<int>& nums)
    {
        vector<bool>dp(nums.size()+1,false);
        dp[0]=true;
        dp[1]=false;
        for(int i=2;i<=nums.size();i++)
        {
            if(nums[i-1]==nums[i-2])
                dp[i]=dp[i-2]&& true;
            else
                dp[i]=dp[i]||false;
            if(i>=3)
            {
             if((nums[i-3]+1==nums[i-2]&&nums[i-2]+1==nums[i-1])||(nums[i-3]==nums[i-2]&&nums[i-2]==nums[i-1]))
                 dp[i]=dp[i]||(dp[i-3] &&true);
             else
                 dp[i]=dp[i]||false;
            }
        }
        return dp[nums.size()];
    }
};
