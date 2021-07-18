class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters)
    {
        map<int,int>mp;
        mp.clear();
        for(int i=0;i<brokenLetters.size();i++)
        {
            char ch=brokenLetters[i];
            int x=int(ch)-97;
            mp[x]=1;
        }
        int e=0,cnt=0;
        for(int i=0;i<text.size();i++)
        {
            char ch=text[i];
            int x=int(ch)-97;
            if(mp[x]==1)
                e=1;
            if(text[i]==' '||i==text.size()-1)
            {
                if(e==0)
                    cnt++;
                e=0;
            }
        }
        return cnt;
    }
};
