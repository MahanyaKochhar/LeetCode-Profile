class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries)
    {
        int n = nums.size();
        map<int,set<int>>mp;
        vector<int>ans;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            mp[nums[i]].insert(i);
            mp[nums[i]].insert(i + n);
            mp[nums[i]].insert(i + 2 * n);
        }
        for(int i = 0 ; i < queries.size();i++)
        {
            int idx = queries[i];
            int val = nums[idx];
            set<int>&s = mp[val];
            auto it = s.lower_bound(idx + n);
            auto itb = it, itf = it;
            int curr = 1e6;
            if(it != s.begin() && s.size() > 3)
            {
                itb--;
                curr = min(abs(*itb - (idx + n)),curr);
            }
            itf++;
            if(itf != s.end() && s.size() > 3)
            {
                curr = min(curr,abs(*itf - (idx + n)));
            }
            ans.push_back(curr == 1e6 ? -1 : curr);
        }
        return ans;
    }
};
