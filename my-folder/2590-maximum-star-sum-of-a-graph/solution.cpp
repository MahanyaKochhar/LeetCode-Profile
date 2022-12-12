vector<int>val2;
    bool cmp(int a,int b)
    {
        return val2[a]>val2[b];
    }
class Solution {
public:
    
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k)
    {
        val2=vals;
        vector<vector<int>>adjlist(vals.size());
        for(int i=0;i<edges.size();i++)
        {
            adjlist[edges[i][0]].push_back(edges[i][1]);
            adjlist[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i=0;i<vals.size();i++)
        {
            sort(adjlist[i].begin(),adjlist[i].end(),cmp);
        }
        int ans=-10001;
        for(int i=0;i<vals.size();i++)
        {
            int cnt=vals[i];
            int no=0;
            for(auto x:adjlist[i])
            {
                if(no<k)
                {
                    ans=max(ans,cnt);
                    cnt+=vals[x];
                    no++;
                }
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};
