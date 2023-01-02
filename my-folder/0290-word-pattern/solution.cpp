class Solution {
public:
    bool wordPattern(string pattern, string s)
    {
        string s1="";
        int pat=0;
       map<string,char>mp;
       vector<bool>vis(26,false);
       for(int i=0;i<s.length();i++)
       {
           if(s[i]==' ')
           {
               if(mp.find(s1)==mp.end())
               {
                   if(vis[pattern[pat]-'a'])
                        return false;
                    mp[s1]=pattern[pat];
                    vis[pattern[pat]-'a']=true;
               }
                else
                {
                    if(mp[s1]!=pattern[pat])
                        return false;
                }
                pat++;
               s1="";
           }
           else
           {
               s1.push_back(s[i]);
           }
       }
       if(mp.find(s1)==mp.end())
       {
           if(vis[pattern[pat]-'a'])
                return false;
            mp[s1]=pattern[pat];
       }
        else
        {
            if(mp[s1]!=pattern[pat])
                return false;
        }
        pat++;
        if(pat==pattern.length())
            return true;
        else
            return false;
    }
};
