class Solution {
public:
    bool partitionArray(vector<int>& nums, int k)
    {
        if(nums.size() % k != 0)
        {
            return false;
        }
        map<int,int>mp;
        for(auto& x : nums)
        {
            mp[x]++;
        }
        int groups = nums.size() / k;
        for(auto& [k,v] : mp)
        {
            if(v > groups)
            {
                return false;
            }
        }
        return true;
    }
};
