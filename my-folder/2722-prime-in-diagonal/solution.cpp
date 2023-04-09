class Solution {
public:
    int diagonalPrime(vector<vector<int>>& nums)
    {
        int maxi = 0;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            int m = nums[i][i];
            int n = nums[i][nums.size() - 1 - i];
            auto check = [](int no)->bool
            {
            if(no == 1)
                return false;
            for(int j = 2 ; (j * j) <= no ; j++)
            {
                if(no % j == 0)
                {
                    return false;
                } 
                    
            }
                return true;
            };
            if(check(m) == 1)
                maxi = max(maxi , m);
            if(check(n) == 1)
                maxi = max(maxi, n);
    }
        return maxi;
    }
};
