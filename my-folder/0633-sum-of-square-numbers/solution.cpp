#include <cmath>
class Solution {
public:
    bool judgeSquareSum(int c)
    {
        int maxA = sqrt(c);
        for(int i = 0; i <= maxA; i++)
        {
            int rem = c - (i * i);
            int possB = sqrt(rem);
            if (possB * possB == rem)
            {
                return true;
            }
        }
        return false;
    }
};
