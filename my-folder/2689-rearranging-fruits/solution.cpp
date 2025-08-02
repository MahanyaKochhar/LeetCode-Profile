class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2)
    {
        using ll = long long;
        ll ans = 0;
        map<int,int>mp;
        int mini = 1e9 + 1;
        for(auto& x : basket1)
        {
            mp[x]++;
            mini = min(mini,x);
        }

        for(auto &x : basket2)
        {
            mp[x]--;
            mini = min(mini,x);
        }
        vector<int>ls;
        for(auto& [k,v] : mp)
        {
            if(abs(v) % 2 != 0)
            {
                return -1;
            }
            for(int i = 0 ; i < abs(v) / 2; i++)
            {
                ls.push_back(k);
            }
        }
        sort(ls.begin(),ls.end());
        for(int i = 0 ; i < ls.size() / 2; i++)
        {
            ans += min(ls[i],2 * mini);
        }
        return ans;

    }
};
