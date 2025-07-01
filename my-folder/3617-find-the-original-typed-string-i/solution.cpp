class Solution {
public:
    int possibleStringCount(string word)
    {
        int cnt = 1;
        int ans = 0;
        for(int i = 1; i < word.length();i++)
        {
            if(word[i] == word[i - 1])
            {
                cnt++;
            }
            else
            {
                ans += (cnt - 1);
                cnt = 1;
            }
        }
        ans += (cnt - 1);
        ans++;
        return ans;
    }
};
