class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score)
    {
        int ans = 0;
        map<char, int> mp;
        for (int i = 0; i < letters.size(); i++)
        {
            mp[letters[i]]++;
        }
        for(int i=0;i<(1<<words.size());i++)
        {
            map<char,int>tmp=mp;
            int sc = 0, e = 0;
            for(int j=0;j<words.size();j++)
            {
                if(i&(1<<j))
                {
                    string s=words[j];
                    for(int k=0;k<s.length();k++)
                    {
                        if(tmp[s[k]]>0)
                        {
                            tmp[s[k]]--;
                            sc+=score[s[k]-'a'];
                        }
                        else
                        {
                            e=1;
                            break;
                        }
                    }
                    if(e==1)
                        break;
                }
            }
            if(e==0)
                ans=max(ans,sc);

        }
        return ans;
    }
};
