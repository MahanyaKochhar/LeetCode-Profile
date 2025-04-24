class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums)
    {
        set<int>s;
        for(int i = 0 ; i < nums.size(); i++)
        {
            s.insert(nums[i]);
        }
        int ans = 0;
        for(int i = 0 ; i < nums.size();i++)
        {
            set<int>s1;
            for(int j = i ; j < nums.size();j++)
            {
                s1.insert(nums[j]);
                if(s1.size() == s.size())
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};
