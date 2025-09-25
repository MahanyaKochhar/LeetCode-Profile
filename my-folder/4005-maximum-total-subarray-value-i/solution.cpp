class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k)
    {
        using ll = long long;
        sort(nums.begin(),nums.end());
        ll num1 = nums[0];
        ll num2 = nums[nums.size() - 1];
        return (num2 - num1) * (ll)k;
    }
};
