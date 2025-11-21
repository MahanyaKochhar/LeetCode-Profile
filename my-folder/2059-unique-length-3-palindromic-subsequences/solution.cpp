class Solution {
public:
    int countPalindromicSubsequence(string s)
    {
        map<int,vector<int>>occ;
        for(int i = 0 ; i < s.length(); i++)
        {
            occ[s[i] - 'a'].push_back(i);
        }
        int ans = 0;
        for(auto [k,v] : occ)
        {
            if(v.size() != 0)
            {
                int fo = v[0];
                int lo = v[v.size() - 1];
                set<int>st;
                for(int j = fo + 1 ; j < lo ; j++)
                {
                    st.insert(s[j] - 'a');
                }
                ans += st.size();
            }
        }
        return ans;
    }
};
