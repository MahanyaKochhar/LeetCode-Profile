class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes)
    {
        map<pair<int,int>,int>mp;
        for(int i = 0 ; i < dominoes.size(); i++)
        {
            int u = dominoes[i][0];
            int v = dominoes[i][1];
            int mini = min(u,v);
            int maxi = max(u,v);
            mp[{mini,maxi}]++;
        }
        int ans = 0;
        for(auto [key,value] : mp)
        {
            ans += ((value) * (value - 1)) / 2;
        }
        return ans;
    }
};
