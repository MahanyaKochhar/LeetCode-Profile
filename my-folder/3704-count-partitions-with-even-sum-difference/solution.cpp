class Solution {
public:
    int countPartitions(vector<int>& nums) {
        vector<int> pre(nums.size());
        int cnt = 0;
        for(int i = 0 ; i < nums.size(); i++)
        {
            if(i == 0)
            {
                pre[i] = nums[i];
            }
            else
                pre[i] = pre[i - 1] + nums[i];
        }

        for(int i = 0 ; i < nums.size() - 1 ;i++)
        {
            int l = pre[i] ; 
            int r = pre[nums.size() - 1] - l;
            if( (l - r) % 2 == 0)
                cnt++;
        }
        return cnt;
    }
};
