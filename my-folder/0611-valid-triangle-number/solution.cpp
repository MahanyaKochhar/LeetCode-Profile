class Solution {
public:
    int triangleNumber(vector<int>& nums)
    {
        int ans = 0;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size();i++)
        {
            for(int j = i + 1 ; j < nums.size(); j++)
            {
                int l = nums[i] + nums[j];
                auto it = lower_bound(nums.begin(),nums.end(),nums[i] + nums[j]);
                it--;
                int pos = it - nums.begin();
                ans += max(0,pos - j);
            }
        }
        return ans;
    }
};
