class Solution {
public:
    long long minInversionCount(vector<int>& nums, int k)
    {
        using ll = long long;
        vector<int>tmp;
        for(auto& x : nums)
        {
            tmp.push_back(x);
        }
        sort(tmp.begin(),tmp.end());
        map<int,int>mp;
        int idx = 1;
        for(auto& x : tmp)
        {
            if(!mp.contains(x))
            {
                mp[x] = idx;
                idx++;
            }
        }
        for(int i = 0 ; i < nums.size(); i++)
        {
            nums[i] = mp[nums[i]];
        }
        vector<ll>pre(1e5 + 2,0);

        auto update = [&](int idx,int opt) -> void {

            while(idx < pre.size())
            {
                pre[idx] += opt;
                idx += (idx & -idx);
            }
        };

        auto find = [&](int idx) -> ll {
            ll res = 0;
            while(idx > 0)
            {
                res += pre[idx];
                idx -= (idx & -idx);
            }
            return res;
        };

        ll ans = 1e18;
        ll curr = 0;
        for(int i = 0 ; i < k; i++)
        {
            int v = nums[i];
            curr += find(1e5 + 1) - find(v);
            update(v,1);
        }
        ans = min(ans,curr);
        for(int i = k ; i < nums.size(); i++)
        {
            curr -= find(nums[i - k] - 1);
            update(nums[i - k],-1);
            curr += find(1e5 + 1) - find(nums[i]);
            update(nums[i],1);
            ans = min(ans,curr);
        }
        return ans;
    }
};
