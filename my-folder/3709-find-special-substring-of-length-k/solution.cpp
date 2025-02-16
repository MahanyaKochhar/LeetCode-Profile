class Solution {
public:
    bool hasSpecialSubstring(string s, int k)
    {
        for(int i = 0 ; i <= s.length() - k ; i++)
        {
            int m = i , n = i + k - 1;
            int e = 0;
            for(int o = m + 1 ; o <= n ; o++)
            {
                if(s[o] != s[m])
                {
                    e = 1;
                    break;
                }
            }
            if(e == 1)
            {
                continue;
            }
            else
            {
                if(m - 1 >= 0)
                {
                    if(s[m - 1] == s[m])
                    {
                        continue;
                    }
                }
                if(n + 1 < s.length())
                {
                    if(s[n + 1] == s[m])
                    {
                        continue;
                    }
                }
                return true;
            }
        }
        return false;
    }
};
