class Solution {
public:
    int minChanges(int n, int k)
    {
        if(k > n)
        {
            return -1;
        }
        int cnt = 0;
        while(n != 0)
        {
            int bit = n & 1;
            int bitToCompare = k & 1;
            if(bit == 1 && bitToCompare == 0)
            {
                cnt++;
            }
            else if(bit == 0 && bitToCompare == 1)
            {
                return -1;
            }
            n = n >> 1;
            k = k >> 1;
        }
        return cnt;
    }
};
