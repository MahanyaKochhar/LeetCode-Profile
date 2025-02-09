class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long total = (nums.size() * (nums.size() - 1)) / 2;
        map<long long,long long>mp;
        for(int i = 0 ; i < nums.size();i++)
        {
            int x = nums[i] - i;
            mp[x]++;
        }
        long long good = 0;
        for(auto x : mp)
        {
            if(x.second > 1)
            {
                good += ((x.second) * (x.second - 1)) / 2;
            }
        }
        return total - good;
    }
};
