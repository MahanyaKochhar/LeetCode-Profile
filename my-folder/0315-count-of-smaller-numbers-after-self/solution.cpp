class Solution {
public:
    vector<int> countSmaller(vector<int>& nums)
    {
        vector<int>pre(2e5,0);
        vector<int>ans(nums.size(),0);
        auto update = [&](int v) -> void {
            while(v < pre.size())
            {
                pre[v] += 1;
                v += (v&-v);
            }
        };

        auto find = [&](int v) -> int {
            int sum = 0;
            while(v > 0)
            {
                sum += pre[v];
                v -= (v&-v);
            }
            return sum;
        };
        for(int i = nums.size() - 1; i >= 0 ; i--)
        {
            int v = nums[i] + 1e5;
            ans[i] = find(v - 1);
            update(v);
        }
        return ans;
    }
};
