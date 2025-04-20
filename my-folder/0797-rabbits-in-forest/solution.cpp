class Solution {
public:
    int numRabbits(vector<int>& answers)
    {
        map<int,int>mp;
        for(auto x : answers)
        {
            mp[x]++;
        }
        int ans = 0;
        for(auto [key,value] : mp)
        {
            int no = (value + key + 1 - 1) / (key + 1);
            ans += (no * (key + 1));
        }
        return ans;
    }
};
