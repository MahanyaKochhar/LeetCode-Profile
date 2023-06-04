class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums)
    {
        vector<int>loc(nums.size() + 1);
        for(int i = 0 ; i < nums.size() ; i++)
        {
            loc[nums[i]] = i + 1;
        }
        int ans = nums.size() - loc[nums.size()];
        if(loc[1] > loc[nums.size()])
            loc[1]--;
        ans += loc[1] - 1;
        return ans;
    }
};
