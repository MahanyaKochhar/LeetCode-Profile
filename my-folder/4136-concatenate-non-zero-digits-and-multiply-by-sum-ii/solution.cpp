class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries)
    {
        
        using ll = long long;
        vector<ll>cnt(s.length() + 1,0);
        vector<ll>sum(s.length() + 1,0);
        vector<ll>res(s.length() + 1,0);
        const int mod = 1e9 + 7;
        for(int i = 1 ; i <= s.length();i++)
        {
            sum[i] += sum[i - 1] + (s[i - 1] - '0');
            cnt[i] += (cnt[i - 1] + ((s[i - 1] == '0') ? 1 : 0));
            if(s[i - 1] != '0')
            {
                res[i] = (res[i - 1] * 10 + s[i - 1] - '0') % mod;
            }
            else
            {
                res[i] = res[i - 1];
            }
        }
        vector<int>ans;
        auto exp = [&](ll a,ll b) -> ll {
            ll res = 1;
            while(b != 0)
            {
                if(b & 1)
                {
                    res = res * a % mod;
                }
                a = a * a % mod;
                b = b / 2;
            }
            return res;
        };
        for(int i = 0 ; i < queries.size() ; i++)
        {
            int l = queries[i][0];
            int r = queries[i][1];
            ll cnt0 = cnt[r + 1] - cnt[l];
            ll len = r - l + 1 - cnt0;
            ll roll = sum[r + 1] - sum[l];
            if(len == 0)
            {
                ans.push_back(0);
            }
            else
            {
                ll residue = (res[r + 1] - ((res[l] * exp(10,len) % mod)) + mod) % mod;
                ans.push_back((residue * roll) % mod);
            }
        }
        return ans;
    }
};
