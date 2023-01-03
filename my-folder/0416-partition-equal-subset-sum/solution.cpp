bool dp[201][20001];
bool vis[201][20001];
bool subsetSum(vector<int>nums,int n,int sum)
{
    // vis[n][sum]=true;
    if(n==0)
    {
        if(sum==0)
            return true;
        else
            return false;
    }
    if(vis[n][sum])
        return dp[n][sum];
    if(sum>=nums[n-1])
        dp[n][sum]=subsetSum(nums,n-1,sum-nums[n-1])||subsetSum(nums,n-1,sum);
    else
        dp[n][sum]=subsetSum(nums,n-1,sum);
        vis[n][sum]=true;
        return dp[n][sum];

}
class Solution {
public:
    bool canPartition(vector<int>& nums)
    {
        memset(dp,false,sizeof(dp));
        memset(vis,false,sizeof(vis));
        int s=0;
        for(int i=0;i<nums.size();i++)
        {
            s+=nums[i];
        }
        if(s%2!=0)
            return false;
        else
        {
            return subsetSum(nums,nums.size(),s/2);
        }
    }
};
