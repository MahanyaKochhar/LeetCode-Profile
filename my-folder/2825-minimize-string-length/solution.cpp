class Solution {
public:
    int minimizedStringLength(string s)
    {
        set<char>s1;
        for(int i = 0 ; i < s.length() ; i++)
            s1.insert(s[i]);
        return s1.size();
    }
};
