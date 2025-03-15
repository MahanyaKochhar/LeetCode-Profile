class Solution {
public:
    int findNumberOfLIS(vector<int>& nums)
    {
        vector<int>d(nums.size(),1);
        vector<vector<int>>cnt(nums.size(),vector<int>(nums.size() + 1,0));
        for(int i = 0 ; i < nums.size();i++)
        {
            cnt[i][1] = 1;
        }
        int ans = 1;
        for(int i = 0 ; i < nums.size();i++)
        {
            for(int j = i - 1 ; j >= 0 ;j--)
            {
                if(nums[i] > nums[j])
                {
                    d[i] = max(d[j] + 1, d[i]);
                    ans = max(ans,d[i]);
                    cnt[i][d[j] + 1] += cnt[j][d[j]];
                }
            }
        }
        int fin = 0;
        for(int i = 0 ; i < nums.size(); i++)
        {
            fin += cnt[i][ans];
        }
        return fin;
    }
};
