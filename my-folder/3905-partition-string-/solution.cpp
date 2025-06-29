class Solution {
public:
    vector<string> partitionString(string s)
    {
        vector<string>segments;
        string curr = "";
        set<string>seen;
        for(int i = 0 ; i < s.length(); i++)
        {
            curr.push_back(s[i]);
            if(seen.find(curr) == seen.end())
            {
                segments.push_back(curr);
                seen.insert(curr);
                curr = "";
            }    
        }
        return segments;
    }
};
