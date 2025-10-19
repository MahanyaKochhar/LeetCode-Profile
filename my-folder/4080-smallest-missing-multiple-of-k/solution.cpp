class Solution {
public:
    int missingMultiple(vector<int>& nums, int k)
    {
        set<int>s(nums.begin(),nums.end());
        for(int i = 1; i <= 101; i++)
        {
            if(!s.contains(k * i))
            {
                return k * i;
            }
        }
        return k;
    }
};
