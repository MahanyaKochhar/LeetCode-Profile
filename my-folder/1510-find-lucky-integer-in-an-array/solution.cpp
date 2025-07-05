class Solution {
public:
    int findLucky(vector<int>& arr)
    {
        int ans = -1;
        map<int,int>mp;
        for(auto x : arr)
        {
            mp[x]++;
        }
        for(auto [key,value] : mp)
        {
            if(key == value)
            {
                ans = key;
            }
        }
        return ans;
    }
};
