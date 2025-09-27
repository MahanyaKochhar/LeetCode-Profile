class Solution {
public:
    string majorityFrequencyGroup(string s)
    {
        vector<int>cnt(26,0);
        vector<string>res(101,"");
        for(auto& x : s)
        {
            cnt[x - 'a']++;
        }
        int maxi = 0;
        for(int i = 0; i < cnt.size(); i++)
        {
            if(cnt[i] != 0)
            {
                res[cnt[i]].push_back(i + 'a');
                maxi = max(maxi,(int)(res[cnt[i]].length()));
            }
        }
        for(int j = res.size() - 1; j >= 0 ; j--)
        {
            if(res[j] != "" && res[j].length() == maxi)
            {
                return res[j];
            }
        }
        return "";
    }
};
