class Solution {
public:
    int setbits(int no)
{
	int cnt=0;
	while(no!=0)
	{
		if(no&1)
			cnt++;
		no=no>>1;
	}
	return cnt;
}
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2)
    {
        long long vd=(1<<(nums1.size()));
        vector<long long>dp(vd,INT_MAX);
        dp[0]=0;
        for(long long i=0;i<vd;i++)
        {
            int cnt=setbits(i);
            for(int j=0;j<nums2.size();j++)
            {
                if(i&(1<<j))
                {
                    
                 dp[i]=min(dp[i],dp[i^(1<<j)]+(nums1[cnt-1]^nums2[j]));
                }
            }
        }
        return int(dp[vd-1]);
    }
};
