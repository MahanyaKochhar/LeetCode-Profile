class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums)
    {
        int ans = 0;
        vector<int>pre(nums.size(),0);
        vector<int>suff(nums.size(),0);
        pre[0] = 1;
        suff[nums.size() - 1] = 1;
        for(int i = 1 ; i < nums.size() ; i++)
        {
            if(nums[i] > nums[i - 1])
            {
                pre[i] += pre[i - 1] + 1;
            }
            else
            {
                pre[i] = 1;
            }

            if(nums[nums.size() - 1 - i] < nums[nums.size() - i])
            {
                suff[nums.size() - 1 - i] += suff[nums.size() - i] + 1;
            }
            else
            {
                suff[nums.size() - 1 - i] = 1;
            }
        }
        for(int i = 0 ; i < nums.size() - 1;i++)
        {
            ans = max(ans,min(pre[i],suff[i + 1]));
        }
        return ans;
    }
};
