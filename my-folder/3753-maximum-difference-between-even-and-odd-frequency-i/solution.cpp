class Solution {
public:
    int maxDifference(string s)
    {
        vector<int> cnt(26,0);
        int ans = -200;
        for(auto x : s)
        {
            cnt[x - 'a']++;
        }
        for(int i = 0 ; i < 26 ; i++)
        {
            for(int j = 0 ; j < 26 ; j++)
            {
                if(i != j)
                {
                    if(cnt[i] != 0 && cnt[j] != 0 && cnt[i] % 2 != 0 && cnt[j] % 2 == 0)
                    {
                        ans = max(ans,cnt[i] - cnt[j]);
                    }
                }
            }
        }
        return ans;
    }
};
