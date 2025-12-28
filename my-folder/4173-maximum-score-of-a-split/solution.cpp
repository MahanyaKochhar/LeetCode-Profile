class Solution {
public:
    long long maximumScore(vector<int>& nums)
    {
        using ll = long long;
        vector<ll>pre(nums.size(),0);
        vector<ll>suffMin(nums.size());
        pre[0] = nums[0];
        suffMin[nums.size() - 1] = INT_MAX;
        for(int i = 1 ; i <= nums.size() - 1 ; i++)
        {
            pre[i] += pre[i - 1] + nums[i];
            suffMin[nums.size() - i - 1] = min((ll)nums[nums.size() - i],suffMin[nums.size() - i]);
        }
        ll score = INT_MIN;
        for(int i = 0 ; i < nums.size() - 1 ; i++)
        {
            score = max(score,pre[i] - suffMin[i]);
        }
        return score;
    }
};
