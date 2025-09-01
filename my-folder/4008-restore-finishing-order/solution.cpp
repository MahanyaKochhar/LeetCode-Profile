class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends)
    {
        set<int>s(friends.begin(),friends.end());
        vector<int>ans;
        for(auto& x : order)
        {
            if(s.contains(x))
            {
                ans.push_back(x);
            }
        }
        return ans;
    }
};
