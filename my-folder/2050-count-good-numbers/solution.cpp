class Solution {
public:
    int countGoodNumbers(long long n)
    {
        const int mod = 1e9 + 7;
        long long ev = (n + 2 - 1) / 2;
        long long odd = n / 2;
        auto exp = [&] (long long a, long long b) -> long long {
            long long res = 1;
            while(b != 0)
            {
                if(b & 1)
                {
                    res = (res * a) % mod;
                }
                a = ( a * a) % mod;
                b = b >> 1;
            }
            return res;
        };
        return (exp(5,ev) * exp(4,odd)) % mod;
    }
};
