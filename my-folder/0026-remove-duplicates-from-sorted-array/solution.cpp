class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int index = 0;
        int prev = -101;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(nums[i] != prev)
            {
                nums[index] = nums[i];
                index++;
                prev = nums[i];
            }
        }
        return index;
    }
};
