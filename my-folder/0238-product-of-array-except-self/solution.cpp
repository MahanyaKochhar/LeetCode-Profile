class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        vector<int>pre(nums.size()), suff(nums.size());
        pre[0] = nums[0];
        suff[nums.size() - 1] = nums[nums.size() - 1];
        for(int i = 1; i < nums.size();i++)
        {
            pre[i] = pre[i - 1] * nums[i];
        }
        for(int j = nums.size() - 2; j >= 0 ; j--)
        {
            suff[j] = suff[j + 1] * nums[j];
        }
        vector<int> ans(nums.size());
        for(int i = 0 ; i < pre.size() ; i++)
        {
            if(i == 0)
            {
                ans[i] = suff[i + 1];
            }
            else if(i == pre.size() - 1)
            {
                ans[i] = pre[i - 1];
            }
            else
                ans[i] = pre[i - 1] * suff[i + 1];
        }
        return ans;
    }
};
