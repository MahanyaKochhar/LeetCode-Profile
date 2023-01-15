class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& query)
    {
        vector<vector<int>>m(503,vector<int>(503,0));
        vector<vector<int>>pre(503,vector<int>(503,0));
        for(int i=0;i<query.size();i++)
        {
            int r1=query[i][0];
            int c1=query[i][1];
            int r2=query[i][2];
            int c2=query[i][3];
            r1++;
            r2++;
            c1++;
            c2++;
            m[r1][c1]++;
            m[r2+1][c1]--;
            m[r1][c2+1]--;
            m[r2+1][c2+1]++;
        }
        for(int i=1;i<=502;i++)
        {
            for(int j=1;j<=502;j++)
            {
                pre[i][j]=m[i][j]+pre[i][j-1]+pre[i-1][j]-pre[i-1][j-1];
            }
        }
        cout<<pre[2][2];
        vector<vector<int>>ans(n,vector<int>(n));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans[i][j]=pre[i+1][j+1];
            }
        }
        return ans;
        
    }
};
