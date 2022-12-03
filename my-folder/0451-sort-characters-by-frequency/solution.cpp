bool cmp(const pair<char,int>a,const pair<char,int>b)
{
    return a.second>b.second;
}
class Solution {
public:
    string frequencySort(string s)
    {
        string res="";
        map<char,int>mp;
        vector<pair<char,int>>pa;
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]++;
        }
        for(auto x:mp)
        {
            pa.push_back({x.first,x.second});
        }
        sort(pa.begin(),pa.end(),cmp);
        for(int i=0;i<pa.size();i++)
        {
            char ch=pa[i].first;
            for(int j=0;j<pa[i].second;j++)
            {
                res.push_back(ch);
            }
        }
        return res;
    }
};
