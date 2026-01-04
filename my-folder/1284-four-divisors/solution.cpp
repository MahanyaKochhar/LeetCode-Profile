class Solution {
public:
    int sumFourDivisors(vector<int>& nums)
    {
        int ans = 0;
        for(auto& x : nums)
        {
            int sum = 0, cnt = 0;
            for(int j = 1 ; j * j <= x ; j++)
            {
                if(x % j == 0)
                {
                    if(j * j == x)
                    {
                        sum += j;
                        cnt += 1;
                    }
                    else
                    {
                        sum += j;
                        sum += (x / j);
                        cnt += 2;
                    }
                }
            }
            if(cnt == 4)
            {
                ans += sum;
            }
        }
        return ans;
    }
};
