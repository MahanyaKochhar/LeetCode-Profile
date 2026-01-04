class Solution {
public:
    int minLength(vector<int>& nums, int k)
    {
        using ll = long long;
        int ans = INT_MAX;
        map<int,int>mp;
        int l = 0;
        ll sum = 0;
        for(int r = 0 ; r < nums.size() ; r++)
        {
            mp[nums[r]]++;
            int toAdd = (mp[nums[r]] == 1) ? nums[r] : 0 ;
            sum += toAdd;
            while(sum >= k)
            {
                ans = min(ans, r - l + 1);
                mp[nums[l]]--;
                int toSubtract = (mp[nums[l]] > 0) ? 0 : nums[l];
                sum -= toSubtract;
                l++;
            }
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};
