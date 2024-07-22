class Solution {
public:
    static bool cmp(const pair<int,string>& a , const pair<int,string>& b)
    {
        return a.first >= b.first;
    }

    vector<string> sortPeople(vector<string>& names, vector<int>& heights)
    {
        vector<pair<int,string>> peopleHeights;
        for(int i = 0 ; i < names.size() ; i++)
        {
            peopleHeights.push_back({heights[i],names[i]});
        }
        sort(peopleHeights.begin(),peopleHeights.end(),cmp);
        vector<string>ans;
        for(auto& x : peopleHeights)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
};
