class Solution {
public:
    string smallestPalindrome(string s)
    {
        vector<int>cnt(26,0);
        string mid = "";
        for(int i = 0 ; i < s.length() ; i++)
        {
            cnt[s[i] - 'a']++;
        }
        for(int i = 0 ; i < 26;i++)
        {
            if(cnt[i] % 2 != 0)
            {
                mid.push_back('a' + i);
                cnt[i]--;
                break;
            }    
        }
        string s1 = "";
        for(int i = 0 ; i < 26; i++)
        {
            while(cnt[i] != 0)
            {
                cnt[i] -= 2;
                s1.push_back(i + 'a');
            }    
        }
        string s2 = s1;
        reverse(s2.begin(),s2.end());
        return s1 + mid + s2;
        
    }
};
