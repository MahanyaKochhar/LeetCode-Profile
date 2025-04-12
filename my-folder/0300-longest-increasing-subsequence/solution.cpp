class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        vector<int>d(nums.size() + 1, INT_MAX);
        d[0] = INT_MIN;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            auto it = upper_bound(d.begin(),d.end(),nums[i]);
            int idx = it - d.begin();
            if(d[idx] > nums[i] && d[idx - 1] < nums[i])
            {
                d[idx] = nums[i];
            }
        }
        int ans = 0;
        for(int i = 1 ; i < d.size();i++)
        {
            if(d[i] != INT_MAX)
            {
                ans = i;
            }
        }
        return ans;
    }
};
