class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper)
    {
        sort(nums.begin(),nums.end());
        long long ans=0;
        for(int i=0;i<nums.size();i++)
        {
            auto it1=upper_bound(nums.begin(),nums.end(),upper-nums[i]);
            auto it2=lower_bound(nums.begin(),nums.end(),lower-nums[i]);
            if(it2==nums.end())
                continue;
            else
            {
                int id=it2-nums.begin();
                if(id<=i)
                    id=(i+1);
                if(it1==nums.end())
                {
                    ans+=(nums.size()-id);
                }
                else
                {
                    int pos=it1-nums.begin();
                    if(pos>id)
                        ans+=(pos-id);
                
                }
                
                
            }
        }
        return ans;
    }
};
