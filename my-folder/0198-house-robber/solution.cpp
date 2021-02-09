class Solution {
public:
        int dp[401];
    int rob(vector<int>& nums) {
            int n=nums.size();
            memset(dp,-1,sizeof(dp));
        int ans=robbinghouses(nums,n);
            return ans;
    }
        int robbinghouses(vector<int>arr,int pos)
        {
                if(pos<=0)
                        return 0;
                if(dp[pos]!=-1)
                        return dp[pos];
                return dp[pos]=max(arr[pos-1]+robbinghouses(arr,pos-2),robbinghouses(arr,pos-1));
        }
};
