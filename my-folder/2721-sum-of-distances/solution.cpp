bool cmp(const pair<long long int,long long int>&a , const pair<long long int ,long long int>&b)
{
    if(a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}
class Solution {
public:
    vector<long long> distance(vector<int>& nums)
    {
        vector<pair< long long int , long long int >> pa;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            pa.push_back({nums[i], i});
        }
        sort(pa.begin(), pa.end(), cmp);
        vector<long long>pre(pa.size());
        vector<long long int>dum;
        for(int i = 0 ; i < pa.size() ; i++)
        {
            if(i == 0)
                pre[i] = pa[i].second;
            else
                pre[i] = pre[i - 1] + pa[i].second;
            dum.push_back(pa[i].first);
        }
        vector<long long>fin(nums.size());
        for(int i = 0 ; i < pa.size() ; i++)
        {
            long long ans = 0;
            long long int no = pa[i].first;
            long long int idx = pa[i].second;
            auto it = upper_bound(dum.begin(),dum.end(), no);
            it--;
            long long int pos1 = it - dum.begin();
            if(i != 0)
                ans += abs(pre[pos1] - pre[i - 1] - (long long)(idx * (pos1 - i + 1)));
            else
                ans += abs(pre[pos1]  - (idx * (pos1 - i + 1)));
            fin[idx] += ans;
            
        }
        for(int i = 0 ; i < pa.size() ; i++)
        {
            long long ans = 0;
            long long int no = pa[i].first;
            long long int idx = pa[i].second;
            auto it2 = lower_bound(dum.begin(),dum.end(), no);
            long long int pos2 = it2 - dum.begin();
            if(pos2 != 0)
            {
                ans += abs(- pre[pos2 - 1] + pre[i] - (long long)(idx * (-pos2 + i + 1)));
            }
            else
                ans += abs( pre[i] - (idx * (long long)(-pos2 + i + 1)));
            fin[idx] += ans;
        }
        return fin;
        
    }
};
