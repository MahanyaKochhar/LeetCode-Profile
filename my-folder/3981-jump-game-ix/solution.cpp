class Solution {
public:
    vector<int> maxValue(vector<int>& nums)
    {
        vector<int>pre(nums.size(),0);
        pre[0] = nums[0];
        for(int i = 1 ; i < nums.size(); i++)
        {
            pre[i] = max(pre[i - 1],nums[i]);
        }
        vector<int>ans(nums.size());
        int minR = nums[nums.size() - 1];
        int r = nums.size() - 1;
        ans[nums.size() - 1] = pre[nums.size() - 1];
        for(int i = nums.size() - 2; i >= 0 ; i--)
        {
            if(pre[i] > minR)
            {
                ans[i] = ans[i + 1];
            }
            else
            {
                ans[i] = pre[i];
            }

            if(nums[i] < minR)
            {
                minR = nums[i];
                r = i;
            }
        }
        return ans;
    }
};
