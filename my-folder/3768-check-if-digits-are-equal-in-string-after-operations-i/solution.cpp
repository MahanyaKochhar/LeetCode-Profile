class Solution {
public:
    bool hasSameDigits(string s)
    {
        while(s.length() != 2)
        {
            string tmp = "";
            for(int i = 1 ; i < s.length() ;i++)
            {
                int a = s[i - 1] -'0';
                int b = s[i] - '0';
                int c = (a + b) % 10;
                tmp.push_back(c + '0');
            }
            s = tmp;
        }
        if(s[0] == s[1])
            return true;
        else
            return false;
        
    }
};
