class Solution {
public:
    string reverseWords(string s)
    {
        string t = "";
        vector<string>words;
        for(int i = 0 ; i < s.length() ; i++)
        {
            if(s[i] == ' ')
            {
                if(t != "")
                {
                    words.push_back(t);
                    t = "";
                }
            }
            else
                t.push_back(s[i]);
        }
        if(t != "")
        {
            words.push_back(t);
        }
        reverse(words.begin(),words.end());
        string ans = "";
        for(auto x : words)
        {
            if(ans != "")
            {
                ans.push_back(' ');
            }
            for(auto l : x)
            {
                ans.push_back(l);
            }
        }
        return ans;
    }
};
