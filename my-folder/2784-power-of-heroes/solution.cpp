const int mod = 1e9 + 7;
int binaryexp(long long int a , long long int b)
{
    long long int res = 1 ;
    while(b > 0)
    {
        if(b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b = b / 2;
    }
    return (int)res;
}
class Solution {
public:
    int sumOfPower(vector<int>& nums)
    {
        vector<long long int>nums1;
        for(int i = 0 ; i < nums.size() ; i++)
            nums1.push_back(nums[i]);
       sort(nums1.begin() , nums1.end());
       long long int ans = 0;
       long long int prev = 0;
       for(int i = 0 ; i < nums1.size() ; i++)
       {
           if(i == 0)
           {
                ans = (ans + binaryexp(nums1[i] , 3)) % mod;
                prev =  0;
           }
            else
            {
                ans = (ans + (((nums1[i] * nums1[i]) % mod * (nums1 [i] + nums1[i - 1] + prev * 2)  ) % mod )) % mod;
                prev = (nums1[i - 1] + prev * 2 ) % mod;
            }

       }
       return (int)ans; 
    }
};
