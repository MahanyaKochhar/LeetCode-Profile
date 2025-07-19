class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder)
    {
        sort(folder.begin(),folder.end());
        set<string>seen;
        for(int i = 0 ; i < folder.size();i++)
        {
            string s = folder[i];
            string curr = "/";
            bool toSkip = false;
            for(int j = 1 ; j < s.length(); j++)
            {
                if(s[j] == '/')
                {
                    if(seen.contains(curr))
                    {
                        toSkip = true;
                        break;
                    }
                }
                curr.push_back(s[j]);
            }
            if(!toSkip)
            {
                seen.insert(curr);
            }
        }
        vector<string>ans(seen.begin(),seen.end());
        return ans;
    }
};
