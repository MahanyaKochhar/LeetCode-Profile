class Solution {
public:
    int findFinalValue(vector<int>& nums, int original)
    {
        set<int>s(nums.begin(),nums.end());
        while(s.contains(original))
        {
            original = 2 * original;
        }
        return original;
    }
};
