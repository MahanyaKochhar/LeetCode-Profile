class Solution {
public:
    string reversePrefix(string s, int k)
    {
        string ans = "";
        for(int i = k - 1; i >= 0 ; i--)
        {
            ans.push_back(s[i]);
        }
        for(int i = k ; i < s.length(); i++)
        {
            ans.push_back(s[i]);
        }
        return ans;
    }
};
