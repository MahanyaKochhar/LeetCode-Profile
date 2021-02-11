class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int>mp1,mp2;
        int e=0;
        for(auto x:s)
        {
            mp1[x]++;
        }
        for(auto x:t)
        {
            mp2[x]++;
        }
        for(char ch='a';ch<='z';ch++)
        {
        if(mp2[ch]==mp1[ch])
            continue;
            else
            e=1;
            
        }
        if(e!=1)
            return true;
        else
            return false;
        
    }
};
