class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k)
    {
        map < int , int > mp;
        int odd_count = 0;
        mp[0] = 1;
        int ans = 0;
        for(int i = 0; i < nums.size() ; i++)
        {
            if(nums[i] % 2 != 0)
                odd_count++;
            mp[odd_count]++;
            if(odd_count >= k)
                ans += mp[odd_count - k];
        }
        return ans;
    }
};
