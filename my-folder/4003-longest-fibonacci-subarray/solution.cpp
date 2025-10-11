class Solution {
public:
    int longestSubarray(vector<int>& nums)
    {
        int ans = 2;
        int l = 0;
        for(int r = 2; r < nums.size();r++)
        {
            if(nums[r] != nums[r - 1] + nums[r - 2])
            {
                l = r - 1;
            }
            ans = max(ans,r - l + 1);
        }
        return ans;
    }
};
