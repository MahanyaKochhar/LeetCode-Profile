class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses)
    {
        map<string,int>mp;
        for(int i = 0 ; i < responses.size() ; i++)
        {
            set<string>s;
            for(int j = 0 ; j < responses[i].size();j++)
            {
                s.insert(responses[i][j]);
            }
            for(auto x : s)
            {
                mp[x]++;
            }
        }
        int maxi = 0;
        string ans = "";
        for(auto [key,value] : mp)
        {
            if(maxi < value)
            {
                ans = key;
                maxi = value;
            }    
        }
        return ans;
    }
};
