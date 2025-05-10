class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2)
    {
        long long sum1 = 0, cnt1 = 0, sum2 = 0, cnt2 = 0;
        for(auto x : nums1)
        {
            sum1 += x;
            if(x == 0)
            {
                cnt1++;
            }
        }
        for(auto y : nums2)
        {
            sum2 += y;
            if(y == 0)
            {
                cnt2++;
            }
        }
        if(sum1 + cnt1 == sum2 + cnt2)
        {
            return sum1 + cnt1;
        }
        else
        {
            if(sum1 + cnt1 > sum2 + cnt2)
            {
                if(cnt2 != 0)
                {
                    return sum1 + cnt1;
                }
                else
                {
                    return -1;
                }
            }
            else
            {
                if(cnt1 != 0)
                {
                    return sum2 + cnt2;
                }
                else
                {
                    return -1;
                }
            }
        }
        return 0;
    }
};
