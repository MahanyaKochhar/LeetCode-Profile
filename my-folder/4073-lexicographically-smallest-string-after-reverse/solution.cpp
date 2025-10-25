class Solution {
public:
    string lexSmallest(string s)
    {
        set<string>poss;
        string curr = "";
        for(int j = 0; j < s.length();j++)
        {
            curr.push_back(s[j]);
            string tmp = curr;
            reverse(tmp.begin(),tmp.end());
            string nx = "";
            for(int k = j + 1 ; k < s.length();k++)
            {
                nx.push_back(s[k]);
            }
            string tmp2 = nx;
            reverse(tmp2.begin(),tmp2.end());
            poss.insert(tmp + nx);
            poss.insert(curr + tmp2);
        }
        return *poss.begin();
    }
};
