class Solution {
public:
    int longestPalindrome(string s, string t)
    {
        int ans = 0;
        vector<string>s1;
        s1.push_back("");
        vector<string>t1;
        t1.push_back("");
        auto construct = [&](string s, vector<string>& s1) -> void {
            for(int i = 0 ; i < s.size();i++)
            {
                for(int j = i ; j < s.size();j++)
                {
                    string substr = s.substr(i, j - i + 1);
                    s1.push_back(substr);
                }    
            }
        };
        construct(s,s1);
        construct(t,t1);

        for(int i = 0 ; i < s1.size();i++)
        {
            for(int j = 0 ; j < t1.size();j++)
            {
                string con = s1[i] + t1[j];
                int len = con.length();
                int e = 0;
                for(int k = 0 ; k < con.length();k++)
                {
                    if(con[k] == con[len - 1 - k])
                    {
                        continue;
                    }
                    else
                    {
                        e = 1;
                        break;
                    }
                }
                if(e == 0)
                {
                    ans = max(ans,len);
                }    
            }
        }
        return ans;
    }
};
