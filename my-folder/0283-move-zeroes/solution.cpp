class Solution {
public:
    void moveZeroes(vector<int>& nums)
    {
        int idx = 0;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(nums[i] != 0)
            {
                nums[idx] = nums[i];
                idx++;
            }
        }
        for(int j = idx ; j < nums.size() ; j++)
        {
            nums[j] = 0;
        }
    }
};
