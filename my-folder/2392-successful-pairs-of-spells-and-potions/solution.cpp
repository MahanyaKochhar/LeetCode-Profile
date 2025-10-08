class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success)
    {
        sort(potions.begin(),potions.end());
        vector<int>ans;
        for(auto& x : spells)
        {
            long long to_search = (success + x - 1) / x;
            if(to_search > (1e5 + 1))
            {
                ans.push_back(0);
                continue;
            }
            auto it = lower_bound(potions.begin(),potions.end(), (int)to_search);
            if(it == potions.end())
            {
                ans.push_back(0);
            }
            else
            {
            int idx = it - potions.begin();
            ans.push_back(potions.size() - idx);
            }
        }
        return ans;
    }
};
