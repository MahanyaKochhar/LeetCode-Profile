class Solution {
public:
    int lengthAfterTransformations(string s, int t)
    {
        int ans = 0;
        vector<long long int>prevCnt(26,0);
        int mod = 1e9 + 7;
        for(int i = 0 ; i < s.length(); i++)
        {
            prevCnt[s[i] - 'a']++;
        }
        for(int i = 0 ; i < t ; i++)
        {
            vector<long long int>newCnt(26,0);
            for(int i = 0 ; i < 26 ; i++)
            {
                if(i == 25)
                {
                    newCnt[0] += prevCnt[i] % mod;
                    newCnt[1] += prevCnt[i] % mod;
                }
                else
                {
                    newCnt[i + 1] += prevCnt[i] % mod;
                }
            }
            prevCnt = newCnt;
        }
        for(int i = 0 ; i < 26; i++)
        {
            ans = (ans + prevCnt[i]) % mod ;
        }
        return ans;
    }
};
