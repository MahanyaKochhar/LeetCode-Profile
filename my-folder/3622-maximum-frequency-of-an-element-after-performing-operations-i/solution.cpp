class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations)
    {
        map<int,int>mp;
        for(auto& x: nums)
        {
            mp[x]++;
        }
        sort(nums.begin(),nums.end());
        int lt = nums[0] - k, rt = nums[nums.size() - 1] + k;
        int ans = 0;
        for(int i = lt ; i <= rt; i++)
        {
            int lft = i - k;
            int rgt = i + k;
            auto it1 = lower_bound(nums.begin(),nums.end(),lft);
            int idx1 = it1 - nums.begin();
            auto it2 = upper_bound(nums.begin(),nums.end(),rgt);
            it2--;
            int idx2 = it2 - nums.begin();
            ans = max(ans, min(idx2 - idx1 + 1,numOperations + mp[i]));
        }
        return ans;
    }
};
