class Solution {
public:
    bool primeSubOperation(vector<int>& nums)
    {
        vector<bool> isPrime(1001, true);
        isPrime[1] = false;
        for(int i = 2 ; i <= 1000 ; i++)
        {
            for(int j = 2 ; j*j <= i ; j++)
            {
                if(i % j == 0)
                {
                    isPrime[i] = false;
                }
            }
        }
        
        for(int i = nums.size() - 2 ; i >= 0 ; i--)
        {
            if(nums[i] < nums[i + 1])
                continue;
            int e = 0;
            for(int j = 2 ; j <= nums[i] - 1 ; j++)
            {
                if(isPrime[j])
                {
                    int val = nums[i] - j;
                    if(val < nums[i + 1])
                    {
                        nums[i] = val;
                        e = 1;
                        break;
                    }
                }
            }
            if(e == 0)
                return false;
        }
        
        return true;
    }
};
