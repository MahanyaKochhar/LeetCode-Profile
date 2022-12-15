bool cmp(const pair<int,int>&a,const pair<int,int>&b)
{
	return a.second>b.second;
}
class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime)
    {
    	vector<pair<int,int>>pa;
        for(int i=0;i<plantTime.size();i++)
        {
        	pa.push_back({plantTime[i],growTime[i]});
        }
        sort(pa.begin(),pa.end(),cmp);
        int ans=-1;
        int curr_p=0;
        for(int i=0;i<pa.size();i++)
        {
        	ans=max(ans,curr_p+pa[i].first+pa[i].second);
        	curr_p+=pa[i].first;
        }
        return ans;
    }
};
