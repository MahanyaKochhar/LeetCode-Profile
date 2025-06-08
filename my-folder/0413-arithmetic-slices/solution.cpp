class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums)
    {
        if(nums.size() < 3)
        {
            return 0;
        }
        int l = 0;
        int diff = nums[1] - nums[0];
        int ans = 0;
        for(int r = 2 ; r < nums.size(); r++)
        {
            if(nums[r - 1] + diff != nums[r])
            {
                int ele = r - 1 - l - 1;
                ans += ((ele) * (ele + 1)) / 2;
                l = r - 1;
                diff = nums[r] - nums[r - 1];
            }

        }
        int ele = nums.size() - 1 - l - 1;
        ans += ((ele) * (ele + 1)) / 2;
        return ans;
        
    }
};
