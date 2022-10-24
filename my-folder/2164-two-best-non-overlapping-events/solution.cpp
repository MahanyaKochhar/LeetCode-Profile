class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events)
    {
        vector<pair<int,pair<int,int>>>pa;
        for(int i=0;i<events.size();i++)
        {
            pa.push_back({events[i][0],{events[i][1],events[i][2]}});
        }
        sort(pa.begin(),pa.end());
        vector<int>st,et,val;
        for(int i=0;i<pa.size();i++)
        {
            st.push_back(pa[i].first);
            et.push_back(pa[i].second.first);
            val.push_back(pa[i].second.second);
        }
        vector<int>maxi(val.size()+1,0);
        for(int j=val.size()-1;j>=0;j--)
            maxi[j]=max(maxi[j+1],val[j]);
        int fin=0;
        for(int i=0;i<st.size();i++)
        {
            int ans=val[i];
            int end=et[i];
            auto it=upper_bound(st.begin(),st.end(),end);
            if(it!=st.end())
            {
                int idx=it-st.begin();
                ans+=maxi[idx];
            }
            fin=max(fin,ans);
        }
        return fin;
    }
};
