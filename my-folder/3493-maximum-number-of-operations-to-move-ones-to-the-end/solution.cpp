class Solution {
public:
    int maxOperations(string s)
    {
        int ans = 0;
        int cnt = 0;
        int prev = 0;
        for(int i = s.length() - 1; i >= 0 ; i--)
        {
            if(s[i] == '0')
            {
                cnt++;
            }
            else
            {
                if(cnt == 0)
                {
                    ans += prev;
                }
                else
                {
                    prev += 1;
                    ans += prev;
                }
                cnt = 0;
            }
        }
        return ans;
    }
};
