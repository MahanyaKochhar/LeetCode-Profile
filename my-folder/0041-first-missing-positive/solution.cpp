class Solution {
public:
    int firstMissingPositive(vector<int>& nums)
    {
        nums.push_back(-1);
        for(int i = 0 ; i < nums.size() ; i++)
        {
            int target = nums[i];
            while(target >= 0 && target < nums.size() && nums[target] != target)
            {
                // int new_target = nums[target];
                // nums[target] = target;
                // target = new_target;
                swap(nums[target], nums[i]);
                target = nums[i];
            }
        }
        for(int i = 1 ; i < nums.size() ; i++)
        {
            if(nums[i] != i)
                return i;
        }
        return nums.size();
    }
};
