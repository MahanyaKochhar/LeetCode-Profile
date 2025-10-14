class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k)
    {
        for(int i = 0 ; i <= (nums.size() - 2 * k) ; i++)
        {
            int j = i + k;
            int e = 0;
            for(int l = i + 1; l < i + k ; l++)
            {
                if(nums[l] > nums[l - 1])
                {
                    continue;
                }
                else
                {
                    e = 1;
                    break;
                }
            }
            for(int l = j + 1 ; l < j + k;l++)
            {
                if(nums[l] > nums[l - 1])
                {
                    continue;
                }
                else
                {
                    e = 1;
                    break;
                }
            }
            if(e == 0)
            {
                return true;
            }
        }
        return false;
    }
};
