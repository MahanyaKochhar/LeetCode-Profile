class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int>index;
        for(int i=0;i<s.length();i++)
        {
        if(s[i]==c)
        {
        index.push_back(i);
        }
        }
        vector<int>ans(s.length(),INT_MAX);
        for(int i=0;i<s.length();i++)
        {
        auto it=lower_bound(index.begin(),index.end(),i);
        if(it!=index.end())
        {
         ans[i]=min((*it)-i,ans[i]);
         if(it!=index.begin())
         {
         it--;
         ans[i]=min(i-*it,ans[i]);
        }
        }
        else
        {
        it--;
        ans[i]=min(i-*it,ans[i]);
        }
        }
      return ans;
    }
};
