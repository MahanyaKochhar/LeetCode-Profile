class Solution {
public:
    int minLength(string s)
    {
        for(int i = 0 ; i < 100 ; i++)
        {
            string res = "";
            for(int j = 0 ; j < s.length() ; j++)
            {
                if(s[j] == 'B')
                {
                    if(j > 0 && s[j - 1] == 'A')
                        res.pop_back();
                    else
                        res.push_back('B');
                }
                else if(s[j] == 'D')
                {
                    if(j > 0 && s[j - 1] == 'C')
                        res.pop_back();
                    else
                        res.push_back('D');
                }
                else
                    res.push_back(s[j]);
            }
            s = res;
            
        }
        return s.length();
    }
};
