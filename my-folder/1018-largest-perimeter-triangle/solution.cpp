class Solution {
public:
    int largestPerimeter(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());
        for(int j = nums.size() - 3; j >= 0 ; j--)
        {
            int v = nums[j] + nums[j + 1];
            if(v > nums[j + 2])
            {
                return v + nums[j + 2];
            }
        }
        return 0;
    }
};
