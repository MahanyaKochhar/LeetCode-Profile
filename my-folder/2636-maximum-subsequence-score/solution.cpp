bool cmp(const pair<int,int>&a,const pair<int,int>&b)
{
    return a.second>b.second;
}
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k)
    {
        vector<pair<int,int>>pa;
        for(int i=0;i<nums1.size();i++)
        {
            pa.push_back({nums1[i],nums2[i]});
        }
        sort(pa.begin(),pa.end(),cmp);
        priority_queue<int>pq;
        long long sum=0,mo=0,ans=0;
        for(int i=0;i<pa.size();i++)
        {
            if(pq.size()<k)
            {
                sum+=pa[i].first;
                mo=pa[i].second;
                pq.push(-pa[i].first);
            }
            else
            {
                ans=max(ans,sum*mo);
                sum+=pq.top();
                pq.pop();
                sum+=pa[i].first;
                mo=pa[i].second;
                pq.push(-pa[i].first);
            }
        }
        ans=max(ans,sum*mo);
        return ans;
    }
};
