class Solution {
public:
    long long sumAndMultiply(int n)
    {
        using ll = long long;
        ll sum = 0;
        ll no = 0;
        ll cnt = 0;
        while(n != 0)
        {
            int ld = n % 10;
            if(ld != 0)
            {
                no = ld * pow(10,cnt) + no;
                sum += ld;
                cnt++;
            }
            n = n / 10;
        }
        return sum * no;
    }
};
