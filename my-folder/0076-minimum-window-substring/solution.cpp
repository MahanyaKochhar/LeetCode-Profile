class Solution {
public:
    string minWindow(string s, string t)
    {
        int ans = INT_MAX,lf,rf;
        vector< int> mp1(52),mp2(52);
        for(int i = 0 ; i < t.length() ; i++)
        {
            if(t[i] >= 97 && t[i] <= 122)
                mp1[t[i] - 'a']++;
            else
                mp1[t[i] - 'A' + 26]++;
        }
        int l = 0 , r = 0;
        while(r < s.size())
        {
             if(s[r] >= 97 && s[r] <= 122)
                mp2[s[r] - 'a']++;
            else
                mp2[s[r] - 'A' + 26]++;
            int e = 0;
            for(int i = 0 ; i < 52 ; i++)
            {
                if(mp2[i] >= mp1[i])
                    continue;
                else
                    e=1;
            }
            if(e == 1)
                r++;
            else
                break;
        }
        while(l < s.size() && r < s.size())
        {
            cout << l <<" "<< r << "\n";
            if(ans > r - l + 1)
            {
                ans = r - l + 1;
                lf = l;
                rf = r;
            }
            if(s[l] >= 97 && s[l] <= 122)
                mp2[s[l] - 'a']--;
            else
                mp2[s[l] - 'A' + 26]--;
            l++;
            while(r < s.size())
            {
                if(s[l - 1] >= 97 && s[l - 1] <= 122)
                {
                if(mp2[s[l-1] - 'a'] >= mp1[s[l-1] - 'a'])
                    break;
                }
                else
                {
                    if(mp2[s[l-1] - 'A' + 26] >= mp1[s[l-1] - 'A' + 26])
                    break;
                }

                r++;
                if(r == s.size())
                    break;
                if(s[r] >= 97 && s[r] <= 122)
                mp2[s[r] - 'a']++;
            else
                mp2[s[r] - 'A' + 26]++;
            }
        }
        if(ans == INT_MAX)
            return "";
        else
            return s.substr(lf , rf - lf + 1);
    }
};
