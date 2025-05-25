class Solution {
public:
    long long minCuttingCost(int n, int m, int k)
    {
        long long cst = 0;
        int act = max(n,m);
        if(act > k)
        {
            long long l1 = k;
            long long l2 = act - k;
            cst += (long long)(l1 * l2);
        }
        return cst;
    }
};
