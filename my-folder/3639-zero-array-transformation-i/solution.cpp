class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries)
    {
        vector<int> pre(nums.size() + 3,0);
        for(int i = 0 ; i < queries.size();i++)
        {
            int l = queries[i][0] + 1;
            int r = queries[i][1] + 1;
            pre[l] += 1;
            pre[r + 1] -= 1;
        }
        for(int i = 1 ; i < pre.size();i++)
        {
            pre[i] += pre[i - 1];
        }
        for(int i = 1 ; i <= nums.size() ; i++)
        {
            if(nums[i - 1] - pre[i] > 0)
            {
                return false;
            }
        }
        return true;
    }
};
