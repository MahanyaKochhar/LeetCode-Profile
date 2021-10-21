class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold)
    {
        vector<vector<int>>pr(mat.size(),vector<int>(mat[0].size(),0));
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[i].size();j++)
            {
                if(i-1>=0)
                    pr[i][j]+=pr[i-1][j];
                if(j-1>=0)
                    pr[i][j]+=pr[i][j-1];
                if(i-1>=0&&j-1>=0)
                    pr[i][j]-=pr[i-1][j-1];
                pr[i][j]+=mat[i][j];
            }
        }
       int sq= min(mat.size(),mat[0].size());
        
        for(int k=sq;k>=1;k--)
        {
            for(int i=0;i<mat.size();i++)
            {
                for(int j=0;j<mat[i].size();j++)
                {
                    int a=i;
                    int b=j;
                    int A=i+k-1;
                    int B=j+k-1;
                    if(A<mat.size()&&B<mat[0].size())
                    {
                        int ans=pr[A][B];
                        if(a-1>=0)
                    ans-=pr[a-1][B];
                if(b-1>=0)
                    ans-=pr[A][b-1];
                if(a-1>=0&&b-1>=0)
                  ans+=pr[a-1][b-1];
                   if(ans<=threshold)
                       return k;
                    }
                }
}
            }
        return 0;
        }
    };
