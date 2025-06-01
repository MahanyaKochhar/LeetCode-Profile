class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target)
    {
        vector<int>prob;
        for(int i = 1 ; i < (1 << nums.size()) - 1; i++)
        {
            long long curr = 1,curr2 = 1;
            for(int j = 0; j < nums.size(); j++)
            {
                if((1 << j) & i)
                {
                    curr *= (long long)nums[j];
                    if(curr > target)
                    {
                        break;
                    }
                }
                else
                {
                    curr2 *= (long long)nums[j];
                    if(curr2 > target)
                    {
                        break;
                    }
                }
            }
            if(curr == curr2 && curr == target)
            {
                return true;
            }    
        }
        return false;
    }
};
