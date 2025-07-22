class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums)
    {
        int ans = 0;
        set<int>s;
        int l = 0, r = 0;
        int sum = 0;
        for(int r = 0 ; r < nums.size(); r++)
        {
            while(l <= r && s.contains(nums[r]))
            {
                s.erase(nums[l]);
                sum -= nums[l];
                l++;
            }
            sum += nums[r];
            s.insert(nums[r]);
            ans = max(ans,sum);
        }
        return ans;
    }
};
