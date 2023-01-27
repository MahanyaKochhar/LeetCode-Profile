bool cmp(const pair<int,int>&a, const pair<int,int>&b)
{
    return a.first>b.first;
}
class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k)
    {
        vector<pair<int,int>>v;
        for(int i=0;i<score.size();i++)
        {
            v.push_back({score[i][k],i});
        }
        sort(v.begin(),v.end(),cmp);
        vector<vector<int>>ans(score.size(),vector<int>(score[0].size()));
        int cnt=0;
        for(int i=0;i<ans.size();i++)
        {
            for(int j=0;j<ans[i].size();j++)
            {
                ans[i][j]=score[v[cnt].second][j];
            }
            cnt++;
        }
        return ans;
        
    }
};
