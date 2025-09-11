class Solution {
public:
    string sortVowels(string s)
    {
        auto isVowel = [&](int i) -> bool {
            set<char>vSet = {'A','E','I','O','U','a','e','i','o','u'};
            if(vSet.contains(s[i]))
            {
                return true;
            }
            else
            {
                return false;
            }
        };
        vector<char>vws;
        for(int i = 0 ; i < s.length(); i++)
        {
            if(isVowel(i))
            {
                vws.push_back(s[i]);
            }
        }
        sort(vws.begin(),vws.end());
        int j = 0;
        for(int i = 0 ; i < s.length();i++)
        {
            if(isVowel(i))
            {
                s[i] = vws[j];
                j++;
            }
        }
        return s;
    }
};
