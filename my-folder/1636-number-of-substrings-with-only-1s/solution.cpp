class Solution {
public:
    int numSub(string s)
    {
        const int mod = 1e9 + 7;
        int ans = 0;
        int curr = 0;
        for(int i = 0; i < s.length(); i++)   
        {
            if(s[i] == '0')
            {
                curr = 0;
            }
            else
            {
                curr++;
                ans = (ans + curr) % mod;
            }
        }
        return ans;
    }
};
