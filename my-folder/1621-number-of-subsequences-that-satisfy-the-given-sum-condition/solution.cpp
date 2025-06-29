class Solution {
public:
    int numSubseq(vector<int>& nums, int target)
    {
        sort(nums.begin(),nums.end());
        const int mod = 1e9 + 7;
        using ll = long long;
        auto exp = [&](ll a,ll b) -> ll {
            ll res = 1;
            while(b != 0)
            {
                if(b & 1)
                {
                    res = (res * a) % mod;
                }
                b = b >> 1;
                a = (a * a) % mod;
            }
            return res;
        };
        ll ans = 0;
        for(int i = 0 ; i < nums.size(); i++)
        {
            auto it = upper_bound(nums.begin(),nums.end(),target - nums[i]);
            it --;
            int idx = it - nums.begin();
            if(idx >= i)
            {
                int diff = idx - i;
                ans = (ans + exp(2,diff)) % mod;
            }
        }
        return (int)ans;
    }
};
