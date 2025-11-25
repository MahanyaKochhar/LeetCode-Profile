class Solution {
public:
    int smallestRepunitDivByK(int k)
    {
        if(k % 2 == 0)
        {
            return -1;
        }
        set<int>seen;
        int n = 1;
        int cnt = 1;
        while(true)
        {
            int rem = n % k;
            if(rem == 0)
            {
                return cnt;
            }
            if(seen.contains(rem))
            {
                break;
            }
            seen.insert(rem);
            n = rem * 10 + 1;
            cnt++;
        }
        return -1;
    }
};
