class Solution {
public:
    int makeTheIntegerZero(int num1, int num2)
    {
        using ll = long long;
        int maxi = 100;
        for(int i = 1; i <= maxi ; i++)
        {
            ll res = (ll)(num1) - (ll)((ll)i * (ll)num2);
            if(res <= 0 || (res == 1 && i > res))
            {
                return -1;
            }
            int cnt = 0;
            while(res != 0)
            {
                if(res & 1)
                {
                    cnt++;
                }
                res = res / 2;
            }
            if(cnt <= i)
            {
                return i;
            }
        }
        return -1;
    }
};
