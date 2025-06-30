class Solution {
public:
    int findLHS(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());
        int ans = 0;
        for(int i = 0 ; i < nums.size();i++)
        {
            auto it = upper_bound(nums.begin(),nums.end(),nums[i] + 1);
            it--;
            if(*it == nums[i] + 1)
            {
                int idx = it - nums.begin();
                ans = max(ans,idx - i + 1);
            }
        }
        return ans;
    }
};
