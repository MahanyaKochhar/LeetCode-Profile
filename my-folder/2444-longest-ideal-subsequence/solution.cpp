class Solution {
public:
    int longestIdealString(string s, int k)
    {
        map<char,int>mp;
        for(int i=0;i<s.length();i++)
        {
            char ch=s[i];
            int curr=ch-'a';
            
            for(int j=curr;j>=max(0,curr-k);j--)
            {
                mp[ch]=max(mp[ch],mp[j+'a']+1);
            }
            for(int j=curr+1;j<=min(25,curr+k);j++)
            {
                mp[ch]=max(mp[ch],mp[j+'a']+1);
            }
        }
        
        int ans=0;
        for(char ch='a';ch<='z';ch++)
            ans=max(ans,mp[ch]);
        return ans;
    }
};
