class Solution {
public:
    int countSubarrays(vector<int>& nums)
    {
        int sum = 0, mid = 1;
        int cnt = 0;
        for(int i = 0 ; i < 3 ;i++)
        {
            sum += nums[i];
        }

        if(2 * (sum - nums[mid]) == nums[mid])
        {
            cnt++;
        }
        for(int r = 3 ; r < nums.size();r++)
        {
            sum += nums[r];
            sum -= nums[r - 3];
            mid++;
            if(2 * (sum - nums[mid]) == nums[mid])
            {
                cnt++;
            }
        }
        return cnt;
    }
};
