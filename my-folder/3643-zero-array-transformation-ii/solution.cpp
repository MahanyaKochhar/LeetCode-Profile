class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries)
    {
        auto good = [&] (int mid) -> bool {
            vector<int> pre(nums.size() + 3,0);
            for(int i = 0 ; i < mid ; i++)
            {
                int l = queries[i][0] + 1;
                int r = queries[i][1] + 1;
                int val = queries[i][2];
                pre[l] += val;
                pre[r + 1] -= val;
            }
            for(int i = 1 ; i < pre.size() ;i++)
            {
                pre[i] += pre[i - 1];
            }
            for(int i = 1 ; i <= nums.size();i++)
            {
                if(nums[i - 1] - pre[i] > 0)
                {
                    return false;
                }
            }
            return true;
        };

        int l = -1, r = queries.size() + 1;
        while(l + 1 < r)
        {
            int mid = (l + r) / 2;
            if(good(mid))
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }
        return r == queries.size() + 1 ? -1 : r;
    }
};
