class Solution {
public:
    static bool cmp(const pair<int,pair<int,int>>& a,const pair<int,pair<int,int>>& b)
    {
        return a.first<b.first;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix)
    {
        vector<pair<int,pair<int,int>>>v;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                v.push_back({matrix[i][j],{i,j}});
            }
        }
        sort(v.begin(),v.end(),cmp);
        int dp[201][201];
        memset(dp,0,sizeof(dp));
        int xd[]={-1,1,0,0};
        int yd[]={0,0,1,-1};
        for(int i=0;i<v.size();i++)
        {
            int x=v[i].second.first;
            int y=v[i].second.second;
            for(int j=0;j<4;j++)
            {
                if(x+xd[j]>=0&&x+xd[j]<matrix.size()&&y+yd[j]>=0&&y+yd[j]<matrix[0].size()&&matrix[x+xd[j]][y+yd[j]]<v[i].first)
                    dp[x][y]=max(dp[x][y],1+dp[x+xd[j]][y+yd[j]]);
                else
                    dp[x][y]=max(dp[x][y],1);
            }
            
        }
        int ans=1;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
        
    }
};
