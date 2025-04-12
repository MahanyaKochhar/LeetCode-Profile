class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int l = 0;
        int sum = 0;
        int ans = 1e6;
        for(int r = 0 ; r < nums.size();r++)
        {
            sum += nums[r];
            while(sum >= target)
            {
                ans = min(ans, r - l + 1);
                sum -= nums[l];
                l++;
            }
        }
        return ans == 1e6 ? 0 : ans;
    }
};
