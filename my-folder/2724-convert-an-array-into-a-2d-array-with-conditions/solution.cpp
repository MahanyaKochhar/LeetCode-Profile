class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums)
    {
        map< int , int > mp;
        int ans = 0;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            mp[nums[i]]++;
            ans = max(ans , mp[nums[i]]);
        }
        vector<vector<int>> adjlist(ans);
        for(int i = 0 ; i < ans ; i++)
        {
            for(auto x : mp)
            {
                if(x.second != 0)
                {
                    adjlist[i].push_back(x.first);
                    mp[x.first]--;
                }
            }
        }
        return adjlist;
    }
};
