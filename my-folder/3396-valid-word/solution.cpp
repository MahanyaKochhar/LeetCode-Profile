class Solution {
public:
    bool isValid(string word)
    {
        vector<char>sp = {'@','#','$'};
        vector<char>vowels = {'A','a','E','e','I','i','O','o','U','u'};
        set<char>spSet(sp.begin(),sp.end());
        set<char>vowelsSet(vowels.begin(),vowels.end());
        if(word.length() < 3)
        {
            return false;
        }
        bool v = false, d = false,c = false;
        for(int i = 0 ; i < word.length(); i++)
        {
            if(spSet.contains(word[i]))
            {
                return false;
            }
            else if(vowelsSet.contains(word[i]))
            {
                v = true;
            }
            else if(word[i] >= 48 && word[i] <= 57)
            {
                d = true;
            }
            else
            {
                c = true;
            }
        }
        return v && c;
    }
};
