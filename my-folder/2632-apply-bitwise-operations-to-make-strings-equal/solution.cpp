class Solution {
public:
    bool makeStringsEqual(string s, string target)
    {
        int cnts=0,cntt=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='1')
                cnts++;
            if(target[i]=='1')
                cntt++;
        }
        if(cnts==0&&cntt==0)
            return true;
        else if(cnts==0||cntt==0)
        {
            return false;
        }
        else
            return true;
    }
};
