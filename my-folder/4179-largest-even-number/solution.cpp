class Solution {
public:
    string largestEven(string s)
    {
        int r = s.length() - 1;
        while(r >= 0 && s[r] == '1')
        {
            r--;
        }
        return r == -1 ? "" : s.substr(0,r + 1);
    }
};
