class Solution {
public:
    string processStr(string s)
    {
        string res = "";
        for(int i = 0 ; i < s.length(); i++)
        {
            if(s[i] >= 97 && s[i] <= 122)
            {
                res.push_back(s[i]);
            }
            else if(s[i] == '*')
            {
                res = res.substr(0,res.length() - 1);
            }
            else if(s[i] == '#')
            {
                res += res;
            }
            else
            {
                reverse(res.begin(),res.end());
            }
        }
        return res;
    }
};
