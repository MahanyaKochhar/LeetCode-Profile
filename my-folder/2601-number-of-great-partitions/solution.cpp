const int mod=1e9+7;
int binaryexp(long long int A,long long int B)
{
    long long int res=1;
    while(B!=0)
    {
        if(B&1)
            res=(res*A)%mod;
        A=(A*A)%mod;
        B=B/2;
    }
    return (int)res;
}
class Solution {
public:
    int countPartitions(vector<int>& nums, int k)
    {
        long long int tsum=0;
        for(int i=0;i<nums.size();i++)
        {
            tsum+=nums[i];
        }
        if(2*k>tsum)
            return 0;
        int dp[nums.size()+1][1001];
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=1;i<=nums.size();i++)
        {
            for(int j=0;j<=k;j++)
            {
                if(nums[i-1]<=j)
                    dp[i][j]=(dp[i-1][j]+dp[i-1][j-nums[i-1]])%mod;
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        int cnt_total=binaryexp(2,nums.size());
        for(int j=0;j<k;j++)
        {
            cnt_total=(cnt_total-(dp[nums.size()][j]*2)%mod+mod)%mod;
        }
        return cnt_total;
    }
};
