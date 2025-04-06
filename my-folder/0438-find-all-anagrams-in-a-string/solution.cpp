class Solution {
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> ans;
        vector<int> cnt(26,0);
        auto checkIfValid = [&] (int idx) -> void {
            int e = 1;
            for(int i = 0 ; i < 26; i++)
            {
                if(cnt[i] == 0)
                {
                    continue;
                }
                else
                {
                    e = 0;
                    break;
                }
            }
            if(e == 1)
            {
                ans.push_back(idx);
            }
        };

        if(p.length() > s.length())
        {
            return {};
        }
        
        for(int i = 0 ; i < p.length();i++)
        {
            cnt[p[i] - 'a']++;
        }
        for(int i = 0 ; i < p.length();i++)
        {
            cnt[s[i] - 'a']--;
        }

        checkIfValid(0);

        for(int i = p.length() ; i < s.length();i++)
        {
            cnt[s[i - p.length()] - 'a']++;
            cnt[s[i] - 'a']--;
            checkIfValid(i - p.length() + 1);
        }

        return ans;

    }
};
