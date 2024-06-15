class Solution {
public:
    int minIncrementForUnique(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());
        int maxOccupied = -1;
        int ans = 0;
        for(auto x: nums)
        {
            if(x > maxOccupied)
            {
                maxOccupied = x;
            }
            else 
            {
                ans += (maxOccupied + 1 - x);
                maxOccupied = (maxOccupied + 1);
            }
        }
        return ans;
    }
};
