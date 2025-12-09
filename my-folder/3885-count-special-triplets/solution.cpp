class Solution {
public:
    int specialTriplets(vector<int>& nums)
    {
        vector<int>lft(nums.size());
        vector<int>rgt(nums.size());
        map<int,int>mp;
        map<int,int>rmp;
        const int mod = 1e9 + 7;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            int req = nums[i] * 2;
            lft[i] = mp[req];
            mp[nums[i]]++;
        }
        for(int i = nums.size() - 1; i >= 0 ; i--)
        {
            int req = nums[i] * 2;
            rgt[i] = rmp[req];
            rmp[nums[i]]++;
        }
        long long ans = 0;
        for(int i = 0 ; i < nums.size();i++)
        {
            ans = (ans + ((long long)lft[i] * (long long)rgt[i]) % mod) % mod;
        }
        return (int)ans;
    }
};
