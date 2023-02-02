bool cmp(const pair<int,int>&a , const pair<int,int>&b)
{
    if(a.first==b.first)
        return a.second<b.second;
    return a.first<b.first;
}
class Solution{
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages)
    {
        vector<pair<int,int>>p;
        for(int i=0;i<scores.size();i++)
        {
            p.push_back({ages[i],scores[i]});
        }
        int ans=0;
        sort(p.begin(),p.end(),cmp);
        vector<int>dp(p.size());
        for(int i=0;i<p.size();i++)
        {
            dp[i]=p[i].second;
            for(int j=i-1;j>=0;j--)
            {
                if(p[j].first==p[i].first)
                    dp[i]=max(dp[i],dp[j]+p[i].second);
                else if(p[j].second<=p[i].second) 
                    dp[i]=max(dp[i],dp[j]+p[i].second);
            }
            ans=max(ans,dp[i]);
        }
        return ans;

    }
};
