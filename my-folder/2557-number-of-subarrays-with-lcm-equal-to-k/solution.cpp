class Solution
{
public:
    int subarrayLCM(vector<int>& nums, int k)
    {
        long long int v[nums.size()][nums.size()];
        memset(v,-1,sizeof(v));
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
        	for(int j=i;j<nums.size();j++)
        	{
        		if(j==i)
        			v[i][j]=nums[i];
        		else
                {
                    if(v[i][j-1]!=-1)
        			    v[i][j]=((v[i][j-1])/(__gcd(v[i][j-1],(long long int)nums[j])))*nums[j];
                    if(v[i][j]>k)
                        v[i][j]=-1;
                }
        		if(v[i][j]==k)
        			ans++;
        	}
        }
        return ans;

    }
};
