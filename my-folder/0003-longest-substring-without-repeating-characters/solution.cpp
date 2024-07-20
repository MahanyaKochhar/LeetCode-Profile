class Solution {
public:
    bool good(int mid,string s)
    {
        map<char,int>mp;
        for(int i = 0 ; i < mid; i++)
        {
            mp[s[i]]++;
        }
        int st = 0;
        for(int i = mid ; i < s.length();i++)
        {
            if(mp.size() == mid)
                return true;
            mp[s[st]]--;
            if(mp[s[st]] == 0)
                mp.erase(s[st]);
            mp[s[i]]++;
            st++;
        }
        if(mp.size() == mid)
            return true;
        else
            return false;
    }

    int lengthOfLongestSubstring(string s)
    {
        if (s.length() == 0)
        {
            return 0;
        }

        int l = 1, r = s.length() + 1;
        while(l + 1 < r)
        {
            int mid = (l + r) / 2;
            if(good(mid,s))
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }
        return l;
    }
};
