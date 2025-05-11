class Solution {
public:
    int minDeletion(string s, int k)
    {
        vector<int>cnt(26,0);
        set<char>st;
        for(int i = 0 ; i < s.length();i++)
        {
            cnt[s[i] - 'a']++;
            st.insert(s[i]);
        }
        int currSize = st.size();
        if(currSize <= k)
        {
            return 0;
        }
        else
        {
            int ans = 0;
            sort(cnt.begin(),cnt.end());
            for(int i = 0 ; i < 26; i++)
            {
                if(cnt[i] != 0)
                {
                    currSize--;
                    ans += cnt[i];
                }
                if(currSize <= k)
                {
                    break;
                }
            }
            return ans;
        }
        return 0;
    }
};
