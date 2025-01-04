class Solution {
public:
    bool hasMatch(string s, string p)
    {
        string s1 = "", s2 = "";
        int idx = -1;
        for(int i = 0 ; i < p.length();i++)
        {
            if(p[i] == '*')
            {
                idx = i;
                break;
            }
        }
        for(int i = 0 ; i < idx ; i++)
        {
            s1 += p[i];
        }
        for(int i = idx + 1 ; i < p.length(); i++)
        {
            s2 += p[i];
        }
        
        vector<int>start;
        vector<int>end;
        for(int i = 0 ; i < s.length() ;i++)
        {
            int k = i, l = i;
            int m = 0, n = 0;
            while(m < s1.length() && k < s.length()  && s1[m] == s[k])
            {
                m++;
                k++;
            }
            while(n < s2.length() && l < s.length() && s2[n] == s[l])
            {
                n++;
                l++;
            }
            if(m == s1.length())
            {
                end.push_back(k - 1);
            }
            if(n == s2.length())
            {
                start.push_back(i);
            }
        }

        for(int i = 0 ; i < end.size() ; i++)
        {
            for(int j = 0 ; j < start.size(); j++)
            {
                if(start[j] > end[i])
                {
                    return true;
                }
            }
        }

        if(s1 == "" && start.size() != 0)
        {
            return true;
        }
        if(s2 == "" && end.size() != 0)
        {
            return true;
        }
        return false;
    }
};
