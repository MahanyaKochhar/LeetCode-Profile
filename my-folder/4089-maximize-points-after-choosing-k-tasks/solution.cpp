class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k)
    {
        using ll = long long;
        vector<pair<ll,int>>comp;
        auto cmp = [](const pair<ll,int>&a, const pair<ll,int>&b) -> bool
        {
            if(a.first == b.first)
            {
                return a.second < b.second;
            }
            return a.first > b.first;
        };
        for(int i = 0 ; i < technique1.size();i++)
        {
            comp.push_back({technique1[i] - technique2[i],i});
        }
        sort(comp.begin(),comp.end(),cmp);
        ll ans = 0;
        for(int i = 0 ; i < k ;i++)
        {
            int idx = comp[i].second;
            ans += technique1[idx];
        }
        for(int i = k ; i < comp.size();i++)
        {
            int idx = comp[i].second;
            if(comp[i].first >= 0)
            {
                ans += technique1[idx];
            }
            else
            {
                ans += technique2[idx];
            }
        }
        return ans;
    }
};
