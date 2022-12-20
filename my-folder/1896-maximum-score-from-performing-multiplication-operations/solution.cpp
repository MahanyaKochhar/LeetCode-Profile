class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers)
    {
        vector<vector<int>>dp(multipliers.size()+2,vector<int>(multipliers.size()+2,-1e9));
        dp[0][0]=0;
        for(int i=0;i<multipliers.size()+1;i++)
        {
        	for(int j=0;j<multipliers.size()+1;j++)
        	{
        		if(i==0&&j==0)
        			continue;
        		if(i!=0&&i+j<=multipliers.size())
        			dp[i][j]=max(dp[i][j],dp[i-1][j]+nums[i-1]*multipliers[i+j-1]);
        		if(j!=0&&i+j<=multipliers.size())
        			dp[i][j]=max(dp[i][j],dp[i][j-1]+nums[nums.size()-j]*multipliers[i+j-1]);
        	}
        }
        int ans=-1e9;
        for(int i=0;i<=multipliers.size();i++)
        {
        	int j=multipliers.size()-i;
        	ans=max(ans,dp[i][j]);
        }
        return ans;
    }
};
