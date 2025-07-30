class Solution {
public:
    int longestSubarray(vector<int>& nums)
    {
        int maxi = -1;
        for(auto x: nums)
        {
            maxi = max(x,maxi);
        }
        int cnt = 0,ans = 0;
        for(int i = 0 ; i < nums.size(); i++)
        {
            if(nums[i] == maxi)
            {
                cnt++;
            }
            else
            {
                ans = max(ans,cnt);
                cnt = 0;
            }
        }
        ans = max(ans,cnt);
        return ans;
    }
};
