class Solution {
public:
    string makeSmallestPalindrome(string s)
    {
        int l = 0 , r = s.length() - 1;
        while(l <= r)
        {
            if(s[l] == s[r])
            {
                l++;
                r-- ;
            }
            else
            {
                if(s[l] > s[r])
                {
                    s[l] = s[r];
                }
                else
                    s[r] = s[l];
                l++;
                r--;
            }
        }
        return s;
    }
};
