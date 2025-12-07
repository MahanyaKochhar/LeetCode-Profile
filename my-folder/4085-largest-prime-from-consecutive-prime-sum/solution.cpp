class Solution {
public:
    int largestPrime(int n)
    {
        vector<bool>isPrime(n + 1,true);
        isPrime[1] = false;
        for(int i = 2 ; i * i <= n ; i++)
        {
            if(isPrime[i])
            {
                for(int j = i * i ; j <= n ; j += i)
                {
                    isPrime[j] = false;
                }
            }
        }
        set<int>s;
        int cnt = 0;
        for(int i = 1 ; i <= n ; i++)
        {
            if(isPrime[i])
            {
                cnt += i;
                if(cnt > n)
                {
                    break;
                }
                if(isPrime[cnt])
                {
                    s.insert(cnt);
                }
            }
        }
        if(s.size() == 0)
        {
            return 0;
        }
        else
        {
            return *s.rbegin();
        }
    }
};
