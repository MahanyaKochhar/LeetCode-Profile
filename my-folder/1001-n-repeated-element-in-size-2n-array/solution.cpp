class Solution {
public:
    int repeatedNTimes(vector<int>& nums)
    {
        map<int,int>mp;
        for(auto& x : nums)
        {
            mp[x]++;
        }
        for(auto [k,v] : mp)
        {
            if(v == (nums.size() / 2))
            {
                return k;
            }
        }
        return -1;
    }
};
