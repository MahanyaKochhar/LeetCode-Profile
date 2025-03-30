class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        map<char,int>mp;
        int st = 0;
        int ans = 0;
        for(int i = 0 ; i < s.length() ; i++)
        {
            if(mp.find(s[i]) == mp.end())
            {
                mp[s[i]] = i;
            }
            else if(mp[s[i]] + 1 > st)
            {
                ans = max(ans, i - st);
                st = mp[s[i]] + 1 ;
                mp[s[i]] = i;
            }
            else
            {
                mp[s[i]] = i;
            }
        }
        ans = max(ans, (int)s.length() - st);
        return ans;
    }
};
