class Solution {
public:
    long long maxProduct(vector<int>& nums)
    {
        int sz = nums.size() - 1;
        sort(nums.begin(),nums.end());
        using ll = long long;
        ll ans = max((ll)nums[0] * (ll)nums[sz] * -1e5,max((ll)nums[sz] * (ll)nums[sz - 1] * 1e5,(ll)nums[0] * (ll)nums[1] * 1e5));
        return ans;

    }
};
