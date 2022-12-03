class Solution {
public:
    bool closeStrings(string word1, string word2)
    {
        vector<int>cnt1(26,0),cnt2(26,0);
        multiset<int>s;
        for(int i=0;i<word1.length();i++)
        {
            int x=word1[i]-'a';
            cnt1[x]++;

        }
        for(int i=0;i<word2.length();i++)
        {
            int x=word2[i]-'a';
            cnt2[x]++;
        }
        for(int i=0;i<26;i++)
        {
            if(cnt1[i]!=0)
                 s.insert(cnt1[i]);
        }
        for(int i=0;i<26;i++)
        {
            if(cnt1[i]==0&&cnt2[i]==0)
                continue;
            else if(cnt1[i]==0||cnt2[i]==0)
                return false;
            else
            {
                if(s.find(cnt2[i])==s.end())
                    return false;
                else
                {
                    s.erase(s.find(cnt2[i]));
                }
            }

        }
        return true;

    }
};
