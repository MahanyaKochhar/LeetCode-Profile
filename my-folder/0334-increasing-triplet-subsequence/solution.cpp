class Solution {
public:
    bool increasingTriplet(vector<int>& nums)
    {
        vector<int>v;
        for(int i=0;i<nums.size();i++)
        {
            auto it=lower_bound(v.begin(),v.end(),nums[i]);
            if(it==v.end())
                v.push_back(nums[i]);
            else
                *it=nums[i];
        }
        if(v.size()>=3)
            return true;
        else
            return false;
    }
};
