class Solution {
public:
    long long countQuadruplets(vector<int>& nums)
    {
        long long int ans=0;
        vector<vector<int>>pre(nums.size(),vector<int>(nums.size()));
        vector<vector<int>>suff(nums.size(),vector<int>(nums.size()));
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[j]>nums[i])
                    pre[i][j]=pre[i][j-1]+1;
                else
                    pre[i][j]=pre[i][j-1];
            }
        }
        for(int i=nums.size()-1;i>=0;i--)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(nums[j]<nums[i])
                    suff[j][i]=suff[j+1][i]+1;
                else
                    suff[j][i]=suff[j+1][i];
            }
        }
        for(int j=0;j<nums.size();j++)
        {
            for(int k=j+1;k<nums.size();k++)
            {
                if(nums[j]>nums[k])
                {
                    ans+=(pre[j][nums.size()-1]-pre[j][k])*(suff[0][k]-suff[j][k]);
                }
            }
        }
        return ans;
    }
};
