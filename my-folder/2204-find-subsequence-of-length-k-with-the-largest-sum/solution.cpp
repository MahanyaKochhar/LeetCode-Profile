class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k)
    {
        using pii =  pair<int,int>;
        vector<pii>tmp;
        auto cmp = [] (const pii a , const pii b) -> bool {
            return a.first > b.first;
        };
        auto cmp2 = [] (const pii a , const pii b) -> bool {
            return a.first < b.first;
        };
        for(int i = 0 ; i < nums.size();i++)
        {
            tmp.push_back({nums[i],i});
        }
        sort(tmp.begin(),tmp.end(),cmp);
        vector<pii>ans;
        for(int i = 0 ; i < k;i++)
        {
            ans.push_back({tmp[i].second,tmp[i].first});
        }
        sort(ans.begin(),ans.end(),cmp2);
        vector<int>fin;
        for(auto x : ans)
        {
            fin.push_back(x.second);
        }
        return fin;
    }
};
