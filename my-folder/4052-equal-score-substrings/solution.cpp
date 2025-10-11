class Solution {
public:
    bool scoreBalance(string s)
    {
        vector<int>pre(s.length() + 1,0);
        for(int i = 1 ; i <= s.length();i++)
        {
            pre[i] = pre[i - 1] + (s[i - 1] - 'a' + 1);
        }
        if(pre[s.length()] % 2 != 0)
        {
            return false;    
        }
        
        for(int i = 1; i < s.length();i++)
        {
            if(pre[i] == pre[s.length()] / 2)
            {
                return true;
            }
        }
        return false;
    }
};
