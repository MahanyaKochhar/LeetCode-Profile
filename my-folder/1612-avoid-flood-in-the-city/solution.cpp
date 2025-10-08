class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains)
    {
        vector<int>ans(rains.size(),0);
        set<int>active;
        map<int,int>mp;
        int lake = -1;
        for(int i = 0; i < rains.size();i++)
        {
            if(rains[i] == 0)
            {
                active.insert(i);
            }
            else
            {
                lake = rains[i];
                if(!mp.contains(rains[i]))
                {
                    mp[rains[i]] = i;
                    ans[i] = -1;
                }
                else
                {
                    auto it = active.upper_bound(mp[rains[i]]);
                    if(it == active.end())
                    {
                        return {};
                    }
                    else
                    {
                        ans[*it] = rains[i];
                        active.erase(it);
                        ans[i] = -1;
                        mp[rains[i]] = i;
                    }
                }
            }
        }
        for(auto x : active)
        {
            ans[x] = lake;
        }
        return ans;
    }
};
