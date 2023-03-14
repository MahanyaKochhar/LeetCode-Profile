class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums)
    {
        map<long long int ,long long int>mp;
        mp[0] = 1;
        long long int curr = 0, ans = 0;
        for(int i = 0; i < nums.size() ; i++)
        {
            curr = curr ^ nums[i];
            if(mp.find(curr) != mp.end())
                ans += mp[curr];
            mp[curr]++;
        }
        return ans;
    }
};
