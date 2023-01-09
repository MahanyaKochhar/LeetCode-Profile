class Solution {
public:
    bool isItPossible(string word1, string word2)
    {
        int f[26];
        int g[26];
        memset(f,0,sizeof(f));
        memset(g,0,sizeof(g));
        for(int i=0;i<word1.length();i++)
        {
            f[word1[i]-'a']++;
        }
        for(int i=0;i<word2.length();i++)
        {
            g[word2[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            for(int j=0;j<26;j++)
            {
                if(f[i]!=0&&g[j]!=0)
                {
                    g[j]--;
                    f[i]--;
                    f[j]++;
                    g[i]++;
                    int cnt1=0,cnt2=0;
                    for(int k=0;k<26;k++)
                    {
                        if(f[k]!=0)
                            cnt1++;
                        if(g[k]!=0)
                            cnt2++;
                    }
                    if(cnt1==cnt2)
                        return true;
                    g[j]++;
                    f[i]++;
                    f[j]--;
                    g[i]--;
                }
            }
        }
        return false;
    }
};
