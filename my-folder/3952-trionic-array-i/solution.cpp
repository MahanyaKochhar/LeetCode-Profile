class Solution {
public:
    bool isTrionic(vector<int>& nums)
    {
        bool ans = false;
        for(int i = 1; i < nums.size() - 1; i++)
        {
            for(int j = i + 1 ; j < nums.size() - 1; j++)
            {
                bool curr = true;
                for(int k = 1 ; k <= i ; k++)
                {
                    if(nums[k] <= nums[k - 1])
                    {
                        curr = false;
                    }
                }
                for(int k = i + 1; k <= j ; k++)
                {
                    if(nums[k] >= nums[k - 1])
                    {
                        curr =  false;
                    }
                }
                for(int k = j + 1; k < nums.size();k++)
                {
                    if(nums[k] <= nums[k - 1])
                    {
                        curr =  false;
                    }
                }
                ans |= curr;
            }
        }
        return ans;
    }
};
