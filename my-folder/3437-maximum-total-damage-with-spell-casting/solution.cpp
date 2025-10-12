class Solution {
public:
    long long maximumTotalDamage(vector<int>& power)
    {
        using ll = long long;
        map<int,int>mp;
        for(int i = 0 ; i < power.size();i++)
        {
            mp[power[i]]++;
        }
        vector<int>tmp;
        for(auto [k,v] : mp)
        {
            tmp.push_back(k);
        }
        vector<ll>dp(tmp.size());
        for(int i = 0 ; i < tmp.size();i++)
        {
            ll curr = tmp[i];
            ll fq = mp[curr];
            dp[i] = fq * curr;
            auto it = lower_bound(tmp.begin(),tmp.end(),curr - 2);
            int idx = it - tmp.begin();
            idx--;
            dp[i] += ((idx >= 0) ? dp[idx] : 0);
            for(int j = idx + 1; j < i ; j++)
            {
                dp[i] = max(dp[i],dp[j]);
            }
        }
        return dp[tmp.size() - 1];
    }
};
