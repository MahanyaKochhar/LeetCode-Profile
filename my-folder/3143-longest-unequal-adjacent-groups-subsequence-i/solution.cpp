class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups)
    {
        vector<bool>sel(groups.size(),false);
        int curr = groups[0];
        sel[0] = true;
        for(int i = 1 ; i < groups.size(); i++)
        {
            if(groups[i] == curr)
            {
                continue;
            }
            else
            {
                sel[i] = true;
                curr = groups[i];
            }
        }
        vector<string>ans;
        for(int i = 0 ; i < sel.size();i++)
        {
            if(sel[i])
            {
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};
