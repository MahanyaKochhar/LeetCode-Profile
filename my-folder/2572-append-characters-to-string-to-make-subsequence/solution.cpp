class Solution {
public:
    int appendCharacters(string s, string t)
    {
        int pos=0;
        for(int i=0;i<s.length();i++)
        {
            if(pos==t.length())
                break;
            if(s[i]==t[pos])
            {
                pos++;
            }
        }
        return t.length()-pos;
    }
};
