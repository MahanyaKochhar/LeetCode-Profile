class Solution {
public:
    int findTheLongestBalancedSubstring(string s)
    {
        int ans = 0;
        for(int i = 0 ; i < s.length() ; i++)
        {
            for(int j = i ; j < s.length() ; j++)
            {
                int cnt0 = 0 , cnt1 = 0;
                for(int k = i ; k <= j ; k++)
                {
                    if(s[k] == '0')
                    {
                        if(cnt1 == 0)
                            cnt0++;
                        else
                            break;
                    }
                    else if(s[k] == '1')
                    {
                        if(cnt0 != 0)
                            cnt1++;
                        else
                            break;
                    }
                }
                if(cnt0 == cnt1)
                    ans = max(ans, cnt0 + cnt1);
            }
        }
        return ans;
    }
};
