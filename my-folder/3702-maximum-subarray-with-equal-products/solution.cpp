class Solution {
public:
    int maxLength(vector<int>& nums)
    {
        int ans = 0;
        int maxiLCM = 1 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9 * 10;
        for(int i = 2 ; i <= nums.size(); i++)
        {
                for(int j = 0 ; j <= nums.size() - i ; j++)
                {
                    int b = j, e = j + i - 1;
                    long long int pro = nums[b] * nums[b + 1],gc = __gcd(nums[b],nums[b + 1]);
                    long long int lc = pro / gc;
                    for(int l = j + 2 ; l <= e ; l++)
                    {
                        if(pro > maxiLCM)
                        {
                            break;
                        }
                        pro = pro * nums[l];
                        gc = __gcd(gc,(long long int)nums[l]);
                        lc = (lc * nums[l]) / (__gcd(lc,(long long int)nums[l]));
                    }
                    if(pro == gc * lc)
                    {
                        ans = i;
                    }
                }
        }
        return ans;
    }
};
